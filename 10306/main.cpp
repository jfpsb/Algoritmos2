#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

#define p INT_MAX

int emodulus(int x, int y)
{
    x *= x;
    y *= y;

    return x + y;
}

int calculo(int memo[], int valor_conv[40], int valor_info[40], int x, int y, int m, int s, int num_moeda)
{
    //if(memo[s * s] != -1)
        //return memo[s * s];

    int result = INT_MAX;

    for(int i = 0; i < m; i++)
    {
        int e = emodulus(x + valor_conv[i], y + valor_info[i]);

        printf("--i: %d; e: %d; s: %d\n", i, e, s);

        if(e < (s * s))
        {
            int aux = calculo(memo, valor_conv, valor_info, x + valor_conv[i], y + valor_info[i], m, s, num_moeda + 1);

            if(aux < result)
            {
                result = aux;
                //memo[e] = result;
            }
        }
        else if(e == (s * s))
        {
            result = num_moeda;
            //memo[e] = result;
            break;
        }
    }

    //memo[s * s] = result;
    return result;
}

int main()
{
    int n, m, s, valor_conv[40], valor_info[40], memo[300001];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &m, &s);

        for(int j = 0; j < m; j++)
        {
            scanf("%d%d", &valor_conv[j], &valor_info[j]);
        }

        for(int w = 0; w < 300001; w++)
        {
            memo[w] = -1;
        }

        int result = calculo(memo, valor_conv, valor_info, 0, 0, m, s, 1);

        if(result == INT_MAX)
        {
            printf("not possible\n");
        }
        else
        {
            printf("%d\n", result);
        }
    }

    return 0;
}
