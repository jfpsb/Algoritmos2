#include <iostream>
#include <stdio.h>

double coinChange( int moedas[], int sizeMoedas, int tabela[], int n )
{
// Inicializa a tabela com 0 até o valor n
    for(int i=0; i<=n; i++)
        tabela[i] = 0;

// Caso base: valor 0 apenas de uma forma
    tabela[0] = 1;

// Atualiza a tabela, para cada tipo de moeda
    for(int i=0; i<sizeMoedas; i++)
        for(int j=moedas[i]; j<=n; j++)
            tabela[j] += tabela[j-moedas[i]];
// Ao final, tabela[i] possui o somatório de todas as formas
// diferentes de somar i com as moedas informadas

    return tabela[n];
}

int main()
{
    int moedas[] = {1, 5, 10, 25, 50};
    int num;
    int tabela[7490];

    while(scanf("%d", &num) != EOF) {
        printf("%.0f\n", coinChange(moedas, 5, tabela, num));
    }

    return 0;
}
