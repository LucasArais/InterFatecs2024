# InterFatecs2024 - Chave de Silas

**Autor:** Prof. Me. Erico de Souza Veríssimo (Instituto Federal de São Miguel Paulista)

## Descrição do Problema

Vinícius e Alex desenvolveram um jogo cujo cenário pode ser representado por um vetor bidimensional. O protagonista, chamado Silas, é um jovem em busca da chave do tesouro. O cenário é composto por:

- Silas (ponto inicial)
- A chave (destino final)
- Monstros de diversos níveis de força
- Bloqueios e paredes intransponíveis

O desafio é determinar se Silas consegue alcançar a chave e, caso consiga, calcular o número mínimo de passos necessários.

### Regras:
- Silas pode derrotar monstros com força menor ou igual à dele.
- Silas pode se mover apenas na horizontal e vertical.
- O cenário é representado por:
  - `S`: Posição inicial de Silas
  - `K`: Posição da chave
  - `.`: Espaço livre
  - `#`: Bloqueio
  - Números inteiros: Força dos monstros

## Entrada

- **Linha 1:** Um valor inteiro `P` (1 ≤ P ≤ 10000), representando a força de Silas.
- **Linha 2:** Dois valores inteiros `X` e `Y` (1 ≤ X, Y ≤ 80), representando as dimensões do cenário.
- **Próximas X linhas:** Cada linha contém `Y` valores separados por espaço, representando os elementos do cenário.

## Saída

- Uma única linha contendo:
  - A letra `N` caso Silas não consiga alcançar a chave.
  - O número mínimo de passos necessários para Silas chegar à chave, caso contrário.

## Exemplo de Entrada e Saída

### Exemplo 1:

**Entrada:**
```
10
4 7
S . . 2 . . .
. . 3 . # . .
. . . # . . .
. . 1 . 1 . K
```

**Saída:**
```
9
```

### Exemplo 2:

**Entrada:**
```
1
4 4
S . . 2
. . 3 .
. . . #
. . 2 K
```

**Saída:**
```
N
```

## Solução

A solução pode ser implementada utilizando busca em largura (BFS) para determinar o menor número de passos necessários para Silas alcançar a chave. O algoritmo considera:

1. A força de Silas ao avaliar se ele pode derrotar monstros.
2. Os bloqueios e os limites do cenário ao determinar movimentos válidos.
3. O objetivo final de encontrar a menor rota até a chave.

### Algoritmos Implementados

- **C**: Implementação em C utilizando matrizes e filas para a BFS.
- **Python**: Implementação equivalente com listas e `deque` para gerenciar a fila.

## Como Executar

### Compilando e Executando o Código (C):

1. Compile o programa:
   ```bash
   gcc -o silas silas.c
   ```
2. Execute o programa:
   ```bash
   ./silas < input.txt
   ```

### Executando o Código em Python:

1. Execute o programa:
   ```bash
   python3 silas.py < input.txt
   ```
