# 🏥 Sistema Hospitalar em Linguagem C

## 📖 Sobre o Projeto

O **Sistema Hospitalar** é uma aplicação desenvolvida em **linguagem C** com o objetivo de simular o gerenciamento básico de pacientes em um ambiente hospitalar.

O projeto foi criado como forma de aplicar conceitos fundamentais estudados durante a disciplina, envolvendo:

* Estruturas de dados;
* Modularização de código;
* Manipulação de memória;
* Organização de arquivos;
* Boas práticas de programação.

O sistema permite o cadastro, organização e atendimento de pacientes de acordo com a prioridade e o tipo de atendimento necessário, reproduzindo de maneira simplificada o fluxo operacional encontrado em hospitais e unidades de saúde.

Além das funcionalidades principais, foram implementadas melhorias como:

* Classificação automática por gravidade;
* Registro temporal dos atendimentos;
* Testes de desempenho;
* Análise estática do código.

---

# 🎯 Objetivos

O principal objetivo do projeto é simular o funcionamento de um sistema hospitalar capaz de organizar pacientes de forma eficiente utilizando diferentes estruturas de dados.

### Funcionalidades

* Cadastro de pacientes;
* Classificação por gravidade;
* Encaminhamento automático para emergência;
* Atendimento de pacientes;
* Transferência entre setores;
* Visualização de pacientes cadastrados;
* Emissão de relatórios;
* Controle de horários de entrada e atendimento;
* Testes de desempenho das estruturas de dados.

---

# 🛠 Tecnologias Utilizadas

* Linguagem C
* Visual Studio Code
* GCC (GNU Compiler Collection)
* PowerShell
* Git
* GitHub

## Bibliotecas Utilizadas

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
```

---

# 🔍 Ferramentas de Qualidade

* CppCheck (Análise Estática)
* GCC Warnings
* Benchmark de Desempenho

---

# 📁 Estrutura do Projeto

```text
SistemaHospitalar/
│
├── main.c
├── hospital.c
├── hospital.h
├── benchmark.c
├── benchmark.h
├── pacientes.txt
└── README.md
```

---

# 📄 Arquivos do Projeto

## main.c

Responsável pelo menu principal e interação com o usuário.

### Funções principais

* Exibição do menu;
* Recebimento das opções;
* Controle do fluxo do sistema;
* Chamada das funcionalidades implementadas.

---

## hospital.h

Arquivo de cabeçalho contendo:

* Definição da estrutura do paciente;
* Protótipos das funções;
* Constantes globais;
* Definições das estruturas de dados.

---

## hospital.c

Responsável por toda a lógica do sistema.

### Funcionalidades

* Cadastro de pacientes;
* Atendimento;
* Transferências;
* Relatórios;
* Controle das filas;
* Controle da pilha de emergência;
* Registro temporal dos eventos.

---

## benchmark.c

Módulo responsável pelos testes de desempenho.

### Funções

* Testes de carga;
* Medição de tempo de execução;
* Cálculo de operações por segundo;
* Avaliação de desempenho.

---

# 📚 Estruturas de Dados Utilizadas

## 🚨 Pilha (Emergência)

Pacientes críticos são armazenados em uma pilha.

### Características

* LIFO (Last In, First Out)
* Atendimento prioritário
* Utilizada para casos emergenciais

```c
pilha[++topo] = paciente;
```

---

## 👨‍⚕️ Fila (Consultas)

Utilizada para consultas médicas.

### Características

* FIFO (First In, First Out)
* Atendimento por ordem de chegada
* Organização justa dos pacientes

---

## 🧪 Fila Circular (Exames)

Utilizada para exames laboratoriais e complementares.

### Características

* Reaproveitamento de posições liberadas
* Melhor uso da memória
* Maior eficiência operacional

---

# ⚙️ Funcionamento do Sistema

## Cadastro de Pacientes

Informações registradas:

* Nome;
* Idade;
* Grau de gravidade;
* Tipo de atendimento.

O sistema registra automaticamente:

* Data de entrada;
* Horário de entrada.

---

## Classificação por Gravidade

| Gravidade | Destino           |
| --------- | ----------------- |
| 1 a 3     | Consulta ou Exame |
| 4 ou 5    | Emergência        |

Pacientes com gravidade elevada são encaminhados automaticamente para a pilha de emergência.

---

## Atendimento

### Emergência

* Pilha (LIFO)

### Consulta

* Fila (FIFO)

### Exame

* Fila Circular

Durante o atendimento são registrados:

* Data do atendimento;
* Horário do atendimento.

---

## Transferência de Pacientes

Permite movimentar pacientes entre setores.

São registrados:

* Horário da transferência;
* Setor de origem;
* Setor de destino.

---

# 🕒 Controle Temporal

Cada paciente possui registros de:

* Entrada;
* Atendimento;
* Transferência.

Isso permite acompanhar todo o histórico de movimentação dentro do hospital.

---

# 📊 Relatórios

O sistema possibilita visualizar:

* Pacientes cadastrados;
* Tipo de atendimento;
* Grau de gravidade;
* Horário de entrada;
* Horário de atendimento;
* Informações de transferência.

---

# 🔬 Análise Estática do Código

Foi utilizada a ferramenta **CppCheck** para identificar possíveis falhas.

Problemas detectados:

* Variáveis não inicializadas;
* Possíveis vazamentos de memória;
* Problemas de segurança;
* Más práticas de programação.

Após as correções, o sistema apresentou maior estabilidade e confiabilidade.

---

# 🔐 Segurança Implementada

## Controle de Buffer

```c
scanf(" %49[^\n]", paciente.nome);
```

Essa abordagem evita estouro de memória causado pela inserção de textos maiores que o espaço reservado.

---

# 🚀 Benchmark e Desempenho

O sistema possui um módulo específico para testes de desempenho.

Os benchmarks realizam milhares de operações de:

* Inserção;
* Remoção;
* Consulta.

### Objetivos

* Avaliar eficiência das estruturas;
* Medir tempo de execução;
* Verificar estabilidade sob carga.

Os resultados demonstraram desempenho consistente mesmo sob grande quantidade de operações.

---

# ⚠️ Problemas Encontrados

## Configuração do GCC

Desafios relacionados a:

* Instalação do compilador;
* Variáveis de ambiente;
* Integração com VS Code;
* Execução via PowerShell.

---

## Codificação UTF-8

Problema observado:

```text
Emerg├¬ncia
Relat├│rios
```

### Solução

```c
#include <locale.h>

setlocale(LC_ALL, "Portuguese");
```

---

## Manipulação de Ponteiros

Dificuldades relacionadas a:

* Endereçamento de memória;
* Passagem por referência;
* Organização das estruturas de dados;
* Controle das filas e pilhas.

---

## Correção da Emergência

A validação correta do tipo de atendimento corrigiu o encaminhamento para a pilha de emergência.

```c
if (p.tipo_atendimento == 1)
```

---

# ▶️ Como Compilar e Executar

```bash
gcc main.c hospital.c benchmark.c -o hospital
```

Executar:

```bash
./hospital
```

No Windows:

```powershell
hospital.exe
```

---

# ✅ Conclusão

O desenvolvimento do Sistema Hospitalar permitiu aplicar, na prática, diversos conceitos fundamentais da programação em linguagem C.

Durante o projeto foram utilizados conhecimentos relacionados a:

* Estruturas de dados;
* Manipulação de memória;
* Modularização de software;
* Controle temporal;
* Análise estática;
* Avaliação de desempenho.

As melhorias implementadas tornaram o sistema mais robusto, seguro e próximo de um ambiente hospitalar real, contribuindo significativamente para o aprimoramento da lógica de programação, resolução de problemas e desenvolvimento de software utilizando boas práticas da Engenharia de Software.

# Análise de Estresse e Detecção de Erros

## Análise Estática com CppCheck

> “O Cppcheck é uma ferramenta de análise estática para código C/C++. Ele oferece uma análise de código exclusiva para detectar erros, com foco na identificação de comportamentos indefinidos e construções de código perigosas. O objetivo é minimizar os falsos positivos. O Cppcheck foi projetado para analisar seu código C/C++ mesmo que ele apresente sintaxe não padrão (comum em projetos embarcados).”

Fonte: https://cppcheck.sourceforge.io/

Utilizando no código:


Após a utilização da ferramenta CppCheck para análise de erros foi possível detectar alguns erros críticos e outros mais simples. Abaixo seguem os erros encontrados pela ferramenta, e que foram tratados posteriormente.

### 1. Bug Crítico

**Mensagem:**

PRINT 1 AQUI 

Inserção de lixo de memória na pilha, o que pode fazer com que o programa tenha um comportamento inesperado ou feche sozinho.

### 2. Alerta de Segurança

PRINT 2 AQUI 

O comando do scanf aceita qualquer tamanho de nome neste caso, porém na struct ele foi definido com um tamanho de 50, o que irá causar um overflow e a quebra do programa.

Além desses erros, foram encontrados erros de funções que não foram chamadas, porém é um alerta falso porque as funções estão sendo chamadas em outro arquivo.

---

# Análise Dinâmica

Agora para o teste de desempenho e de análise dinâmica foi desenvolvido um código separado. Esse arquivo não interfere na execução do sistema principal e é utilizado exclusivamente para testes (o usuário não consegue acessar).

O benchmark realiza inserções automáticas de pacientes nas três estruturas utilizadas pelo sistema:

* Pilha (Emergência);
* Fila (Consulta);
* Fila Circular (Exames).

Durante os testes, são executadas grandes quantidades de operações para simular situações de carga e verificar o comportamento das estruturas em seus limites de capacidade. O programa mede o tempo de execução utilizando a biblioteca `time.h` e calcula a quantidade de operações realizadas por segundo.

As informações exibidas ao final de cada teste incluem:

* Quantidade de operações executadas;
* Tempo total de execução;
* Taxa de operações por segundo.

Essa abordagem permite verificar a eficiência das operações básicas do sistema, validar o comportamento das estruturas sob carga e complementar a análise estática realizada com o Cppcheck por meio de uma análise dinâmica baseada na execução real do programa.

## Benchmark

### Arquivo com código

`benchmark_windows.c`

### Compilação

```bash
gcc benchmark_windows.c hospital.c -o benchmark.exe
```

### Execução

```bash
.\benchmark.exe
```

---

## Sistema Hospitalar

### Arquivo com código

`hospital.c`

### Compilação

```bash
gcc main.c hospital.c -o hospital.exe
```

### Execução

```bash
.\hospital.exe
```

## Resultados Obtidos

Após a execução do benchmark, foram realizadas 1.000.000 de operações em cada uma das estruturas de dados utilizadas pelo sistema (Pilha, Fila e Fila Circular).

| Estrutura              | Operações | Tempo (s) | Operações por segundo |
| ---------------------- | --------- | --------- | --------------------- |
| Emergência (Pilha)     | 1.000.000 | 1,909     | 523.834               |
| Consulta (Fila)        | 1.000.000 | 1,949     | 513.884               |
| Exames (Fila Circular) | 1.000.000 | 1,926     | 519.211               |

Os resultados demonstram que as três estruturas apresentaram desempenho semelhante, executando aproximadamente 520 mil operações por segundo.

Cada estrutura processou 1 milhão de operações em aproximadamente 2 segundos. Considerando a execução completa do benchmark, foram realizadas 3 milhões de operações distribuídas entre os três testes em cerca de 5,8 segundos.

Como as operações testadas possuem complexidade O(1), o tempo de execução permaneceu estável mesmo com uma grande quantidade de operações, demonstrando a eficiência das estruturas implementadas no projeto.

