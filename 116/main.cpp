#include <stdio.h>

int caminho(int matriz[10][100], int col, int lin, int m)
{
    if(col == m - 1)
        return matriz[lin][col];

    int linha_acima, linha, linha_abaixo;
    int acima, meio, abaixo;
    int peso_atual = matriz[lin][col];
    int menor;

    if(lin == 0)
        linha_acima = m - 1;
    else
        linha_acima = lin - 1;

    if(lin == m - 1)
        linha_abaixo = 0;
    else
        linha_abaixo = lin + 1;

    acima = caminho(matriz, col + 1, linha_acima, m);
    meio = caminho(matriz, col + 1, linha, m);
    abaixo = caminho(matriz, col + 1, linha_abaixo, m);

    menor = acima;

    if(meio < menor)
        menor = meio;

    if(abaixo < menor)
        menor = abaixo;

    return peso_atual + menor;
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

    int t = caminho(matriz, 0, 0, m);
    int linha = 0;

    for(int i = 1; i < m; i++) {
        int aux = caminho(matriz, 0, i, m);

        if(aux < t) {
            t = aux;
        }
    }

    printf("%d", t);

    return 0;
}
