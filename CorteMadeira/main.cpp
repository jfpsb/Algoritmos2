#include <stdio.h>
#include <stdlib.h>

int memo[53][53];

int cut(int *v, int esq, int dir) {
    if(memo[esq][dir] != -1)
        return memo[esq][dir];

    if(esq + 1 == dir) {
        memo[esq][dir] = 0;
        return 0;
    }
    else {
        int tamanhoTronco = v[dir] - v[esq];
        //primeiro corte (esq + 1)
        int min = cut(v, esq, esq + 1) + cut(v, esq + 1, dir) + tamanhoTronco;

        for(int i = esq + 2; i < dir; i++) {
            //corte na posicao i
            int aux = cut(v, esq, i) + cut(v, i, dir) + tamanhoTronco;

            if(aux < min)
                min = aux;
        }

        memo[esq][dir] = min;
        return min;
    }
}

int main()
{
    int tam;
    int cortes;
    int v[53];

    while(1) {
        scanf("%d", &tam);

        if(tam == 0)
            break;

        scanf("%d", &cortes);

        v[0] = 0;

        for(int i = 1; i <= cortes; i++) {
            scanf("%d", &v[i]);
        }

        for(int i = 0; i <= cortes + 1; i++) {
            for(int j = 0; j <= cortes + 1; j++) {
                memo[i][j] = -1;
            }
        }

        v[cortes + 1] = tam;

        int out = cut(v, 0, cortes + 1);

        printf("The minimum cutting is %d.\n", out);
    }

    return 0;
}
