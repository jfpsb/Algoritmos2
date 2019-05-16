#include <stdio.h>

int caminho(int matriz[10][100], int lin, int col, int col_max)
{
    if(col == col_max - 1)
        return matriz[lin][col];

    int caminho_atual = matriz[lin][col];
    int acima = lin - 1;
    int meio = lin;
    int abaixo = lin + 1;
    int valor_acima, valor_meio, valor_abaixo;
    int menor;

    if(lin == 0)
        acima = col_max - 1;

    if(lin == col_max - 1)
        abaixo = 0;

    valor_acima = caminho(matriz, col + 1, acima, col_max);
    valor_abaixo = caminho(matriz, col + 1, abaixo, col_max);
    valor_meio = caminho(matriz, col + 1, meio, col_max);

    menor = valor_acima;

    if(valor_abaixo < menor)
        menor = valor_abaixo;

    if(valor_meio < menor)
        menor = valor_meio;

    return caminho_atual + menor;
}

int main()
{
    int m, n;
    int matriz[10][100];

    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    int t = caminho(matriz, 0, 0, n);

    for(int i = 1; i < m; i++) {
        int aux = caminho(matriz, i, 0, n);

        if(aux < t) {
            t = aux;
        }
    }

    printf("%d", t);

    return 0;
}
