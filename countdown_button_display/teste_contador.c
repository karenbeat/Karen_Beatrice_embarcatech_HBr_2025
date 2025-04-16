#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/irq.h"
#include "ssd1306.h"  // Adicione a biblioteca SSD1306
#include <stdio.h>

#define PINO_BOTA_A 5  // Pino do Botão A
#define PINO_BOTA_B 6  // Pino do Botão B
#define PINO_LED 12    // Pino do LED (caso precise de feedback visual)

#define INTERVALO_CONTAGEM 1000000  // Intervalo de 1 segundo para contagem (em microssegundos)

// Variáveis globais
volatile int contador = 9;  // Contador que começa em 9
volatile int contador_botoes_b = 0;  // Contador de pressionamentos do Botão B
volatile bool contagem_ativa = false;  // Flag para controlar a contagem

// Função de interrupção para o Botão A (inicia a contagem)
void botao_a_isr() {
    if (!gpio_get(PINO_BOTA_A)) {  // Verifica se o botão A foi pressionado
        contador = 9;  // Reinicia o contador para 9
        contador_botoes_b = 0;  // Zera o contador de Botão B
        contagem_ativa = true;  // Ativa a contagem
    }
}

// Função de interrupção para o Botão B (conta pressionamentos)
void botao_b_isr() {
    if (!gpio_get(PINO_BOTA_B) && contagem_ativa) {  // Verifica se o botão B foi pressionado durante a contagem
        contador_botoes_b++;  // Incrementa o contador de Botão B
    }
}

// Função para exibir as informações no display OLED
void exibir_display(ssd1306_t* display) {
    char contador_str[3];
    char botoes_str[3];

    // Converte os inteiros para strings
    snprintf(contador_str, sizeof(contador_str), "%d", contador);
    snprintf(botoes_str, sizeof(botoes_str), "%d", contador_botoes_b);

    // Exibe os valores no display OLED
    ssd1306_clear(display);
    ssd1306_draw_string(display, 0, 0, "Contador:");
    ssd1306_draw_string(display, 0, 10, contador_str);
    ssd1306_draw_string(display, 0, 20, "Botao B:");
    ssd1306_draw_string(display, 0, 30, botoes_str);
    ssd1306_display(display);
}

// Função principal
int main() {
    stdio_init_all();  // Inicializa as funções de I/O padrão
    gpio_init(PINO_BOTA_A);  // Inicializa o pino do Botão A
    gpio_init(PINO_BOTA_B);  // Inicializa o pino do Botão B
    gpio_init(PINO_LED);     // Inicializa o pino do LED

    gpio_set_dir(PINO_BOTA_A, GPIO_IN);  // Define o Botão A como entrada
    gpio_set_dir(PINO_BOTA_B, GPIO_IN);  // Define o Botão B como entrada
    gpio_set_dir(PINO_LED, GPIO_OUT);   // Define o LED como saída

    gpio_pull_up(PINO_BOTA_A);  // Habilita o resistor pull-up no Botão A
    gpio_pull_up(PINO_BOTA_B);  // Habilita o resistor pull-up no Botão B

    // Configura as interrupções dos botões A e B
    gpio_set_irq_enabled_with_callback(PINO_BOTA_A, GPIO_IRQ_EDGE_FALL, true, botao_a_isr);
    gpio_set_irq_enabled_with_callback(PINO_BOTA_B, GPIO_IRQ_EDGE_FALL, true, botao_b_isr);

    // Inicializa o display OLED
    ssd1306_t display;
    ssd1306_init(&display, 128, 64, 0x3C);

    uint32_t tempo_ultimo_decremento = 0;

    while (1) {
        // Se a contagem estiver ativa, decrementar a cada segundo
        if (contagem_ativa) {
            if (time_us_32() - tempo_ultimo_decremento >= INTERVALO_CONTAGEM) {
                contador--;  // Decrementa o contador
                tempo_ultimo_decremento = time_us_32();  // Atualiza o tempo do último decremento

                if (contador <= 0) {
                    contador = 0;  // Garante que o contador não vá abaixo de 0
                    contagem_ativa = false;  // Desativa a contagem
                }

                exibir_display(&display);  // Atualiza o display OLED
            }
        }
        sleep_ms(50);  // Delay para evitar sobrecarga de CPU
    }

    return 0;
}
