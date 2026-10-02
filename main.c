// =============================
// ====== Entrega de N°II ======
// =============================
// ===== Fabricio Coutinho =====
// ====== Matheus Mendes =======
// =============================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// retorna o termo n (comecando em 1) da sequencia escolhida
// 1 = PA | 2 = PG |( 3 = Fibonacci | 4 = Primos
int seqnum(int sq, int n)
{
    int new = 0, a = 1, b = 1, i, j, cont, primo;

    if (sq == 1)
    {
        new = 5 + (n - 1) * 3;
    }
    else if (sq == 2)
    {
        new = 2;
        for (i = 1; i < n; i++)
            new = new * 2;
    }
    else if (sq == 3)
    {
        new = 1;
        for (i = 3; i <= n; i++)
        {
            new = a + b;
            a = b;
            b = new;
        }
    }
    else
    {
        cont = 0;
        i = 1;
        while (cont < n)
        {
            i++;
            primo = 1;
            for (j = 2; j * j <= i; j++)
                if (i % j == 0)
                    primo = 0;
            if (primo)
                cont++;
        }
        new = i;
    }
    return new;
}

const char *cipher(int sh, char txt[16], int sq)
{
    char alfb[52] = {'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f', 'G', 'g', 'H', 'h', 'I', 'i', 'J', 'j', 'K', 'k', 'L', 'l', 'M', 'm', 'N', 'n', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', 'r', 'S', 's', 'T', 't', 'U', 'u', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'y', 'Z', 'z'};
    static char new[16];
    int i, pos, desl;

    for (i = 0; i < strlen(txt); i++)
    {
        pos = 0;
        while (alfb[pos] != txt[i])
            pos++;
        // deslocamento total = SHIFT + sequencia[i]
        desl = (sh + seqnum(sq, i + 1)) % 26;
        if (desl < 0)
            desl = desl + 26;
        // pos/2 = letra (0 a 25) | pos%2 = maiuscula ou minuscula
        new[i] = alfb[((pos / 2 + desl) % 26) * 2 + pos % 2];
    }
    new[i] = '\0';
    return new;
}

int main()
{
    char sct[16], res[16];
    int shift, sq;
    FILE *arq;

    printf("Palavra secreta: ");
    fgets(sct, sizeof(sct), stdin);
    sct[strcspn(sct, "\n")] = '\0';
    system("cls||clear");
    printf("digite um shift: ");
    scanf("%d", &shift);
    system("cls||clear");
    while (1)
    {
        printf("[1]Progressao Aritmetica\n[2]Progressao Geometrica\n[3]Sequencia de Fibonacci\n[4]Numeros Primos\n");
        scanf("%d", &sq);
        if (sq > 0 && sq <= 4)
        {
            break;
        }
        else
        {
            system("cls||clear");
            printf("Erro: opcao invalida\n");
        }
    }
    system("cls||clear");
    strcpy(res, cipher(shift, sct, sq));
    printf("Palavra codificada: %s | SHIFT: %d | Tipo: %d | Letras: %d\n", res, shift, sq, (int)strlen(res));

    // arquivo com o resultado
    arq = fopen("resultado_criptografia.txt", "w");
    fprintf(arq, "Palavra codificada: %s | SHIFT: %d | Tipo: %d | Letras: %d\n", res, shift, sq, (int)strlen(res));
    fclose(arq);

    // log de execucao
    arq = fopen("log_execucao.txt", "a");
    fprintf(arq, "Palavra: %s | SHIFT: %d | Tipo: %d | Resultado: %s\n", sct, shift, sq, res);
    fclose(arq);
    return 0;
}