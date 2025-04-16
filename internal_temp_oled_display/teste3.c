#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"

// Definição dos pinos
#define LED_R 15      // Pino do LED RGB (vermelho)
#define LED_G 14      // Pino do LED RGB (verde)
#define LED_B 13      // Pino do LED RGB (azul)
#define BUZZER 12     // Pino do buzzer
#define TOUCH 11      // Pino do sensor de toque

// Configuração dos tempos (em milissegundos)
#define TEMPO_INSPIRAR 4000  // 4 segundos
#define TEMPO_SEGURAR  7000  // 7 segundos
#define TEMPO_EXPIRAR  8000  // 8 segundos

// Função para acender o LED RGB com uma cor específica
void set_led_color(bool r, bool g, bool b) {
    gpio_put(LED_R, r);
    gpio_put(LED_G, g);
    gpio_put(LED_B, b);
}

// Função para emitir um breve beep com o buzzer
void beep() {
    gpio_put(BUZZER, 1);
    sleep_ms(200);
    gpio_put(BUZZER, 0);
}

// Função para um ciclo completo de respiração
void ciclo_respiracao() {
    printf("Iniciando ciclo de respiração...\n");

    // Inspirar (LED Azul)
    set_led_color(0, 0, 1);
    beep();
    sleep_ms(TEMPO_INSPIRAR);

    // Segurar o ar (LED Verde)
    set_led_color(0, 1, 0);
    beep();
    sleep_ms(TEMPO_SEGURAR);

    // Expirar (LED Vermelho)
    set_led_color(1, 0, 0);
    beep();
    sleep_ms(TEMPO_EXPIRAR);

    // Apagar LEDs antes de reiniciar
    set_led_color(0, 0, 0);
    sleep_ms(1000);
}

// Função principal
int main() {
    stdio_init_all();

    // Configuração dos pinos
    gpio_init(LED_R);
    gpio_init(LED_G);
    gpio_init(LED_B);
    gpio_init(BUZZER);
    gpio_init(TOUCH);

    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_set_dir(LED_B, GPIO_OUT);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_set_dir(TOUCH, GPIO_IN);

    printf("CalmBreath iniciado. Toque no sensor para começar.\n");

    while (1) {
        // Aguarda o toque para iniciar um novo ciclo
        if (gpio_get(TOUCH)) {
            ciclo_respiracao();
        }
    }

    return 0;
}