# 🔐 Sistema de Criptografia por Sequências

Projeto desenvolvido em **linguagem C** para a **Entrega nº II**, com o objetivo de implementar um sistema simples de criptografia utilizando um valor de `SHIFT` combinado com diferentes sequências matemáticas.

## Autores

* **Fabricio Coutinho**
* **Matheus Mendes**

---

## Sobre o projeto

O programa recebe uma palavra ou texto, um valor de **SHIFT** e uma sequência matemática escolhida pelo usuário.

Para cada caractere do texto, é calculado um deslocamento utilizando:

```text
Deslocamento = SHIFT + valor da sequência
```

O resultado é aplicado sobre o alfabeto, mantendo a diferença entre letras **maiúsculas e minúsculas**.

O programa também salva o resultado da criptografia e um histórico das execuções em arquivos `.txt`.

---

## Sequências disponíveis

O usuário pode escolher entre quatro opções:

| Opção | Sequência             | Exemplo               |
| ----- | --------------------- | --------------------- |
| 1     | Progressão Aritmética | `5, 8, 11, 14...`     |
| 2     | Progressão Geométrica | `2, 4, 8, 16...`      |
| 3     | Fibonacci             | `1, 1, 2, 3, 5, 8...` |
| 4     | Números Primos        | `2, 3, 5, 7, 11...`   |

Cada posição do texto utiliza um valor diferente da sequência, fazendo com que o deslocamento varie entre os caracteres.

---

## Funcionamento

O fluxo básico do programa é:

```text
Início
  ↓
Informar palavra secreta
  ↓
Informar SHIFT
  ↓
Escolher sequência
  ↓
Validar opção
  ↓
Calcular valor da sequência
  ↓
Aplicar SHIFT + sequência
  ↓
Gerar palavra codificada
  ↓
Salvar resultado e log
  ↓
Fim
```

---

## Principais funções

### `seqnum()`

Calcula o valor da sequência escolhida para determinada posição.

```c
int seqnum(int *sq, int *n)
```

É responsável pelas quatro possibilidades:

* Progressão Aritmética;
* Progressão Geométrica;
* Fibonacci;
* Números Primos.

### `cipher()`

Realiza a criptografia do texto.

```c
const char *cipher(int *sh, char *txt[16], int *sq)
```

Para cada caractere, o programa calcula o deslocamento com base no `SHIFT` e no valor correspondente da sequência.

### `main()`

Controla a execução do programa, realizando:

* Entrada dos dados;
* Validação da sequência;
* Chamada da criptografia;
* Exibição do resultado;
* Criação dos arquivos de saída.

---

## Arquivos gerados

### `resultado_criptografia.txt`

Armazena o resultado da última criptografia executada.

Exemplo:

```text
Palavra codificada: XXXXX | SHIFT: 3 | Tipo: 1 | Letras: 5
```

### `log_execucao.txt`

Mantém um histórico das execuções realizadas.

Exemplo:

```text
Palavra: XXXXX | SHIFT: 3 | Tipo: 1 | Resultado: XXXXX
```

O arquivo é aberto no modo `append`, permitindo adicionar novos registros sem apagar os anteriores.

---

## Tecnologias utilizadas

* **C**
* `stdio.h`
* `stdlib.h`
* `string.h`
* Manipulação de strings
* Funções
* Vetores
* Estruturas condicionais
* Estruturas de repetição
* Manipulação de arquivos
* compilador **GCC**

---

## Exemplo de utilização

```text
Palavra secreta: ABC

digite o shift: 2

[1] Progressao Aritmetica
[2] Progressao Geometrica
[3] Sequencia de Fibonacci
[4] Numeros Primos

1

Palavra codificada: ...
```

---

## Conceitos aplicados

O projeto utiliza conceitos fundamentais de programação em C, incluindo:

* Funções e modularização;
* Ponteiros;
* Manipulação de caracteres;
* Strings;
* Laços de repetição;
* Condicionais;
* Operações matemáticas;
* Sequências numéricas;
* Manipulação de arquivos;
* Algoritmo para identificação de números primos.

---

## Status

**Projeto acadêmico da UNICID — Entrega nº II**
