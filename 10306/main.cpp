#include <iostream>

using namespace std;

int memo[301][301];
int X[41], Y[41];
int m;

int minCoins(int sumX, int sumY, int value)
{
    int menor = INT_MAX;

    if(memo[sumX][sumY] != -10)
        return memo[sumX][sumY];

    int e = sumX * sumX + sumY * sumY;

    if(e > value * value)
    {
        return -10;
    }
    else if(e == value)
    {
        memo[sumX][sumY] = 0;
        return 1;
    }
    else
    {
        for(int i = 0; i < m; i++)
        {
            memo[sumX + X[i]][sumY + Y[i]] = 1;

            int aux = minCoins(sumX + X[i], sumY + Y[i], value);

            if(aux < 0) {
                continue;
            }
            else {
                memo[sumX + X[i]][sumY + Y[i]] += memo[sumX][sumY];
            }
            else if(aux < menor) {
                menor = aux;
            }
        }
    }

    if(menor == INT_MAX) {
        memo[sumX][sumY] = -10;
        return -10;
    }

    return menor;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int S;
        cin >> m >> S;

        for(int i=0; i<m; i++)
            cin >> X[i] >> Y[i];

        for(int i=0; i<301; i++)
            for(int j=0; j<301; j++)
                memo[i][j]=-10;

        int aux = minCoins(0, 0, S);
        if(aux<0)
            cout << "not possible" << endl;
        else
            cout << aux << endl;
    }
}

/*#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int emodulus(int x, int y)
{
    x *= x;
    y *= y;

    return x + y;
}

int minMoeda(int memo[][301], int valor_conv[40], int valor_info[40], int x, int y, int m, int s, int num_moeda)
{
    int result = INT_MAX;

    if(x * x + y * y > s * s)
        return result;

    if(memo[x][y] != -1)
    {
        return memo[x][y];
    }

    for(int i = 0; i < m; i++)
    {
        int e = emodulus(x + valor_conv[i], y + valor_info[i]);

        if(e < (s * s))
        {
            int aux = minMoeda(memo, valor_conv, valor_info, x + valor_conv[i], y + valor_info[i], m, s, num_moeda + 1);

            if(aux < result)
            {
                result = aux;
            }
        }
        else if(e == (s * s))
        {
            if(num_moeda < result)
                result = num_moeda;
        }
    }

    memo[x][y] = result;
    return result;
}

int main()
{
    int n, m, s, valor_conv[40], valor_info[40], memo[301][301];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &m, &s);

        for(int j = 0; j < m; j++)
        {
            scanf("%d%d", &valor_conv[j], &valor_info[j]);
        }

        for(int y = 0; y < 301; y++)
        {
            for(int u = 0; u < 301; u++)
            {
                memo[y][u] = -1;
            }
        }

        int result = minMoeda(memo, valor_conv, valor_info, 0, 0, m, s, 1);

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
}*/
