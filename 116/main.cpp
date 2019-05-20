#include <stdio.h>


int path[100];

int peso(int matriz[10][100], int lin, int col, int lin_max, int col_max)
{
    if(col == col_max - 1)
    {
        return matriz[lin][col];
    }

    int peso_atual = matriz[lin][col];
    int acima = lin - 1, meio = lin, abaixo = lin + 1;
    int valor_acima, valor_meio, valor_abaixo;
    int menor;

    if(lin == 0)
        acima = lin_max - 1;

    if(lin == lin_max - 1)
        abaixo = 0;

    valor_acima = peso(matriz, acima, col + 1, lin_max, col_max);
    valor_abaixo = peso(matriz, abaixo, col + 1, lin_max, col_max);
    valor_meio = peso(matriz, meio, col + 1, lin_max, col_max);

    menor = valor_acima;

    if(valor_abaixo < menor)
        menor = valor_abaixo;

    if(valor_meio < menor)
        menor = valor_meio;

    return peso_atual + menor;
}

int caminho(int matriz[10][100], int lin, int col, int lin_max, int col_max)
{
    if(col == col_max - 1)
    {
        return matriz[lin][col];
    }

    int peso_atual = matriz[lin][col];
    int acima = lin - 1, meio = lin, abaixo = lin + 1;
    int valor_acima, valor_meio, valor_abaixo;
    int menor;

    if(lin == 0)
        acima = lin_max - 1;

    if(lin == lin_max - 1)
        abaixo = 0;

    valor_acima = peso(matriz, acima, col + 1, lin_max, col_max);
    valor_abaixo = peso(matriz, abaixo, col + 1, lin_max, col_max);
    valor_meio = peso(matriz, meio, col + 1, lin_max, col_max);

    menor = valor_acima;

    if(valor_abaixo < menor)
        menor = valor_abaixo;

    if(valor_meio < menor)
        menor = valor_meio;

    return peso_atual + menor;
}

int main()
{
    int m, n;
    int matriz[10][100];
    int LIN = 0;
    int path[100];

    scanf("%d%d", &m, &n);

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    int t = peso(matriz, 0, 0, m, n);

    for(int i = 1; i < m; i++)
    {
        int aux = peso(matriz, i, 0, m, n);

        if(aux < t)
        {
            t = aux;
            LIN = i;
        }
    }

    caminho(matriz, path, t, LIN, 0, m, n);

    printf("%d\n", t);

    return 0;
}
