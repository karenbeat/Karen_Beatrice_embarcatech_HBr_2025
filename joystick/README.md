# Projetos de Sistemas Embarcados - EmbarcaTech 2025

**Autora:** Karen Beatrice Souza Gonçalves  
**Turma:** HBr - Brasília  
**Instituição:** EmbarcaTech  

---

## 📚 Sobre este repositório

Este repositório reúne os projetos desenvolvidos durante a fase de residência tecnológica do curso de Sistemas Embarcados (EmbarcaTech 2025). Cada projeto possui sua própria pasta com código-fonte, documentação e imagens de demonstração.

Os projetos utilizam a placa BitDogLab, baseada no microcontrolador RP2040 (Raspberry Pi Pico), com foco em práticas reais de leitura de sensores, controle de dispositivos e exibição de dados em tempo real.

---

## 📂 Lista de Projetos

| Projeto | Descrição |
|--------|-----------|
| Joystick com Display OLED | Leitura contínua dos eixos X e Y do joystick via ADC, com exibição dos valores no display OLED SSD1306 através do barramento I2C |

---

## ⚙️ Detalhes do Projeto: Joystick com Display OLED

Este projeto implementa a leitura dos sinais analógicos dos eixos X e Y de um joystick conectado aos pinos ADC0 (GPIO26) e ADC1 (GPIO27) da BitDogLab. Esses sinais são convertidos digitalmente e exibidos em tempo real em um display OLED SSD1306 conectado via I2C aos pinos GPIO14 (SDA) e GPIO15 (SCL).

O código em linguagem C utiliza as bibliotecas `hardware/adc.h` e `hardware/i2c.h` da SDK do Pico, além de uma biblioteca customizada para controle do display. A cada 200ms, os valores lidos são atualizados na tela, permitindo monitoramento contínuo da posição do joystick.

Este projeto é útil como base para futuras aplicações que envolvam controle por joystick, como seleção de modos, navegação de interface ou jogos interativos embarcados.

---

## 🛠 Tecnologias e ferramentas utilizadas

- Raspberry Pi Pico (BitDogLab)
- Linguagem C
- SDK do Raspberry Pi Pico (CMake)
- Comunicação I2C
- Leitura via ADC
- VS Code com extensão oficial do Pico
- Display OLED SSD1306

---

## 📜 Licença

Este repositório utiliza a licença [GNU GPL-3.0](https://choosealicense.com/licenses/gpl-3.0/).
