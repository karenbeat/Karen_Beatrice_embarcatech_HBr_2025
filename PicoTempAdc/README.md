# Projetos de Sistemas Embarcados - EmbarcaTech 2025

**Autora:** Karen Beatrice Souza Gonçalves  
**Turma:** HBr - Brasília  

## 📚 Sobre este repositório

Este repositório reúne os projetos desenvolvidos durante o curso de Sistemas Embarcados do programa EmbarcaTech - Fase 2. O repositório contém projetos individuais e coletivos que exploram diversas áreas de sistemas embarcados, com foco no uso do Raspberry Pi Pico W e BitDogLab.

---

## 📂 Projetos

| Projeto           | Descrição                                                                 |
|-------------------|---------------------------------------------------------------------------|
| [PicoTempADC](./PicoTempADC) | Medição de temperatura com o ADC da Raspberry Pi Pico W, convertendo o valor para Celsius. |

---

## 🛠️ Kit utilizado

- Raspberry Pi Pico W  
- BitDogLab Base  
- VS Code com extensão Pico SDK  
- Ambiente de desenvolvimento com CMake e compilador ARM


## 📜 Licença

Este projeto está licenciado sob a Licença MIT. Consulte o arquivo [LICENSE](LICENSE) para mais detalhes.
# PicoTempADC

**PicoTempADC** é um projeto para medir a temperatura usando o ADC interno do Raspberry Pi Pico W. O valor lido do ADC é convertido para a temperatura em graus Celsius, utilizando uma fórmula fornecida pela documentação oficial da Raspberry Pi. Este projeto visa demonstrar como coletar dados analógicos do sensor de temperatura integrado no RP2040 e exibi-los de forma prática.

## Objetivo

O objetivo deste projeto é utilizar o ADC de 12 bits do Raspberry Pi Pico W para medir a temperatura interna e convertê-la para graus Celsius. A medição é feita através do sensor de temperatura embutido na placa, e os resultados são exibidos na saída serial.

## Componentes Usados

- Raspberry Pi Pico W
- Ambiente de desenvolvimento com o SDK do Raspberry Pi Pico
- Conexão serial para monitoramento da saída de temperatura

## Como Compilar e Executar o Código

1. **Instale as dependências**:
   Siga o guia oficial para configurar o [SDK do Raspberry Pi Pico](https://github.com/raspberrypi/pico-sdk).

2. **Clone este repositório**:
   No terminal, clone este repositório para o seu diretório local:

   ```bash
   git clone https://github.com/seu-usuario/PicoTempADC.git
   cd PicoTempADC

