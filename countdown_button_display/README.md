# Contador com Botões e Display OLED
# Projetos de Sistemas Embarcados - EmbarcaTech 2025

**Autor:** Karen Beatrice Souza Gonçalves  
**Turma:** HBr - Brasília  
**Instituição:** EmbarcaTech - Fase 2  


## 🎯 Objetivo do Projeto

Implementar um contador regressivo de 9 até 0 controlado por um botão (Botão A), com exibição no display OLED SSD1306. Durante a contagem, um segundo botão (Botão B) registra cliques, que também são mostrados em tempo real. O sistema congela ao fim da contagem e reinicia apenas com nova pressão do Botão A.

---

## 🔧 Componentes Usados

| Componente           | Conexão          |
|----------------------|------------------|
| Raspberry Pi Pico    | -                |
| Display OLED SSD1306 | SDA: GPIO14, SCL: GPIO15 |
| Botão A              | GPIO5            |
| Botão B              | GPIO6            |
| Jumpers, Protoboard  | -                |

---

---

## ⚡ Pinagem

| Pino do Pico | Função               |
|--------------|----------------------|
| GPIO14       | SDA (I2C OLED)       |
| GPIO15       | SCL (I2C OLED)       |
| GPIO5        | Botão A              |
| GPIO6        | Botão B              |

---

## 📈 Resultados Esperados

- Exibição do contador de 9 até 0 no display OLED.
- Cliques no Botão B contabilizados apenas durante a contagem.
- Display atualizado em tempo real com os dois valores.

---

---

## 📜 Licença

Licença GPL-3.0 - Veja o arquivo LICENSE para mais detalhes.
