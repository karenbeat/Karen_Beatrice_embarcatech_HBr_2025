#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/i2c.h"
#include "inc/ssd1306.h"

#define I2C_SDA 14
#define I2C_SCL 15
#define BAR_WIDTH 40
#define ADC_MAX ((1 << 12) - 1)
#define STABLE_THRESHOLD 15  // Mínima variação para atualizar valor

uint16_t media_adc(uint input) {
    adc_select_input(input);
    uint32_t soma = 0;
    for (int i = 0; i < 8; i++) {
        soma += adc_read();
        sleep_us(300); // Delay entre leituras
    }
    return soma / 8;
}

int main() {
    stdio_init_all();
    sleep_ms(2000);

    adc_init();
    adc_gpio_init(26);  // Y - ADC0
    adc_gpio_init(27);  // X - ADC1

    i2c_init(i2c1, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    ssd1306_init();

    struct render_area frame_area = {
        .start_column = 0,
        .end_column = ssd1306_width - 1,
        .start_page = 0,
        .end_page = ssd1306_n_pages - 1
    };
    calculate_render_area_buffer_length(&frame_area);
    uint8_t ssd[ssd1306_buffer_length];

    uint16_t x_anterior = 0, y_anterior = 0;

    while (1) {
        uint16_t y = media_adc(0);
        uint16_t x = media_adc(1);

        // Verifica se houve variação real significativa
        bool atualiza = (abs(x - x_anterior) > STABLE_THRESHOLD) ||
                        (abs(y - y_anterior) > STABLE_THRESHOLD);

        if (atualiza) {
            x_anterior = x;
            y_anterior = y;

            uint bar_x = x * BAR_WIDTH / ADC_MAX;
            uint bar_y = y * BAR_WIDTH / ADC_MAX;

            // Terminal
            printf("\rX: [");
            for (uint i = 0; i < BAR_WIDTH; ++i)
                putchar(i == bar_x ? 'o' : ' ');
            printf("]  Y: [");
            for (uint i = 0; i < BAR_WIDTH; ++i)
                putchar(i == bar_y ? 'o' : ' ');
            printf("]    ");

            // OLED
            memset(ssd, 0, ssd1306_buffer_length);
            char linha1[20], linha2[20];
            sprintf(linha1, "X: %4d", x);
            sprintf(linha2, "Y: %4d", y);
            ssd1306_draw_string(ssd, 0, 0, linha1);
            ssd1306_draw_string(ssd, 0, 10, linha2);
            render_on_display(ssd, &frame_area);
        }

        sleep_ms(100);
    }

    return 0;
}
