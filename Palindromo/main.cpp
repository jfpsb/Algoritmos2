#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int maxPalindromo(char str[1000])
{
    int palindromo = 0;

    for(int i = 0; i < strlen(str) - 2; i++)
    {
        for(int j = i + 1; j < strlen(str) - 1; j++)
        {
            int aux = 0;
            int ispalindromo = 1;
            for(int p = i; p <= j; p++)
            {
                aux = (j - i) + 1; //Guarda tamanho da substring sendo avaliada
                if(str[p] != str[(j - p) + i])
                {
                    ispalindromo = 0;
                    break;
                }
            }

            if(ispalindromo == 1)
            {
                if(aux > palindromo)
                    palindromo = aux;
            }
        }
    }

    return palindromo;
}

int main()
{
    int casos, tamPalindromo[10000];
    char str[1000];

    scanf("%d", &casos);

    getchar(); //Remove \n deixado pelo scanf para que fgets funcione corretamente

    for(int i = 0; i < casos; i++)
    {
        fgets(str, 1000, stdin);
        tamPalindromo[i] = maxPalindromo(str);
    }

    for(int i = 0; i < casos; i++)
    {
        if(i != 0)
            printf("\n");
        printf("%d", tamPalindromo[i]);
    }

    return 0;
}
