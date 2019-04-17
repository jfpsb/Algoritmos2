#include <cstdio>

int calculaTermos(int *memo, int numero) {
    int termos = 1;

    if(numero <= 0)
        return 0;

    if(memo[numero] != -1)
        return memo[numero];

    for(int i = 1; i <= numero; i++) {
        int anterior = (i - 1) * (i - 1);
        int potencia = i * i;

        if(potencia > numero) {
            termos += calculaTermos(memo, numero - anterior);
            break;
        }
    }

    memo[numero] = termos;
    return termos;
}

int main()
{
    int casos;
    int numeros[10001];
    int memo[10001];

    for(int i = 0; i < 10001; i++) {
        memo[i] = -1;
    }

    scanf("%d", &casos);

    for(int i = 0; i < casos; i++) {
        scanf("%d", &numeros[i]);
    }

    for(int i = 0; i < casos; i++) {
        printf("%d\n", calculaTermos(memo, numeros[i]));
    }

    return 0;
}
