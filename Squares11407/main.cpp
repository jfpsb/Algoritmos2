#include <cstdio>
#include <limits.h>

int potenciaMaisProxima(int n)
{
    for(int i = 1; i <= n; i++)
    {
        if((i * i) > n)
            return (i - 1);
    }
}

int calculaTermos(int memo[], int numero)
{
    int termos = INT_MAX, t;
    int p, resto, pow;

    if(numero == 0)
        return 0;

    if(numero <= 3)
        return numero;

    if(memo[numero] != -1)
        return memo[numero];

    p = potenciaMaisProxima(numero);

    for(int i = p; i > 0; i--) {
        t = 0;
        pow = i * i;
        resto = numero - pow;

        t += calculaTermos(memo, resto);

        if(t < termos)
            termos = t;
    }

    memo[numero] = termos + 1;
    return termos + 1;
}

int main()
{
    int casos;
    int numeros[10001];
    int memo[10001];

    for(int i = 0; i < 10001; i++)
    {
        memo[i] = -1;
    }

    scanf("%d", &casos);

    for(int i = 0; i < casos; i++)
    {
        scanf("%d", &numeros[i]);
    }

    for(int i = 0; i < casos; i++)
    {
        printf("%d\n", calculaTermos(memo, numeros[i]));
    }

    return 0;
}
