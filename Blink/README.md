# Projetos de Sistemas Embarcados - EmbarcaTech 2025

**Autora:** Karen Beatrice Souza Gonçalves  
**Turma:** HBr - Brasília  

## 📚 Sobre este repositório

Este repositório reúne os projetos desenvolvidos durante o curso de Sistemas Embarcados do programa EmbarcaTech - Fase 2.

---

## 📂 Projetos

| Projeto | Descrição |
|--------|------------|
| [Blink] | Piscar o LED embutido da Pico W usando arquitetura modular em C |

---

## 🛠️ Kit utilizado

- Raspberry Pi Pico W  
- BitDogLab Base  
- VS Code com extensão Pico SDK

  # Blink – LED embutido com Raspberry Pi Pico W

## 🎯 Objetivo

Piscar o LED embutido da Raspberry Pi Pico W utilizando estrutura modular (HAL, drivers e app) com o SDK da Raspberry Pi em C.

## 🔧 Componentes usados

| Componente             | Conexão       |
|------------------------|---------------|
| Raspberry Pi Pico W    | USB-C         |

## 💾 Como compilar e executar

```bash
cd build
cmake -G "Ninja" ..
ninja

