#include <cstdio>

int calculaTermos(int *memo, int numero) {
    int termos = 1;

    if(memo[numero] != -1)
        return memo[numero];

    if(numero == 0)
        return 0;

    for(int i = 1; i < numero; i++) {
        int potencia = i * i;
        if(potencia > numero) {
            termos += calculaTermos(memo, numero - potencia);
        }
    }

    memo[numero] = termos;
    return termos;
}

int main()
{
    int casos;
    int numeros[10000];
    int memo[10000];

    for(int i = 0; i < 10000; i++) {
        memo[i] = -1;
    }

    scanf("%d", &casos);

    for(int i = 0; i < casos; i++) {
        scanf("%d", &numeros[i]);
    }

    for(int i = 0; i < casos; i++) {
        printf("%d", calculaTermos(memo, numeros[i]));
    }

    return 0;
}
