# Sensor de Temperatura Interna com Display OLED  
# Projetos de Sistemas Embarcados - EmbarcaTech 2025

**Autora:** Karen Beatrice Souza Gonçalves  
**Turma:** HBr - Brasília  
**Instituição:** EmbarcaTech - Fase 2  

---

## 🎯 Objetivo do Projeto

Ler a temperatura interna do microcontrolador RP2040 utilizando o canal ADC4 e exibir os valores convertidos em graus Celsius no display OLED SSD1306 via protocolo I2C.

---

## 🔧 Componentes Usados

| Componente             | Conexão                    |
|------------------------|----------------------------|
| Raspberry Pi Pico      | -                          |
| Display OLED SSD1306   | SDA: GPIO14, SCL: GPIO15   |
| Cabos Jumper           | -                          |
| Protoboard (opcional)  | -                          |

---

## ⚡ Pinagem

| Pino do Pico | Função               |
|--------------|----------------------|
| GPIO14       | SDA (I2C - Display)  |
| GPIO15       | SCL (I2C - Display)  |

---

## 🧠 Funcionamento do Código

- O programa inicializa o barramento I2C para comunicação com o display OLED SSD1306.
- Em seguida, o ADC é configurado e o **sensor de temperatura interno do RP2040 (canal 4)** é ativado.
- A cada 1 segundo, o código realiza a leitura bruta do ADC e converte o valor em temperatura usando a fórmula oficial do datasheet:
  
  ```c
  float temp_c = 27.0 - ((voltage - 0.706) / 0.001721);
