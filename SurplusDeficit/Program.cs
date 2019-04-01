using System;

namespace AtividadeNDamas
{
    class Program
    {
        static int cont = 1;
        static int max = 0;

        static void Main(string[] args)
        {
            cont = 1;

            string[] input = Console.ReadLine().Split();

            int s = int.Parse(input[0]);
            int d = int.Parse(input[1]);

            max = 0;

            SurplusDeficit(new int[12], 0, s, d);

            Console.WriteLine(max);

            Console.ReadKey();
        }

        public static void SurplusDeficit(int[] vetor, int index, int s, int d)
        {
            int total = 0;
            int soma = 0;

            if (index == 12)
            {
                for (int i = 0; i < 12; i++)
                {
                    total += vetor[i];

                    if (i >= 4)
                    {
                        for (int j = i; j >= i - 4; j--)
                        {
                            soma += vetor[j];
                        }

                        if(soma > 0)
                        {
                            total = 0;
                            break;
                        }
                    }
                }

                if (total > max)
                    max = total;
            }
            else
            {
                vetor[index] = s;
                SurplusDeficit(vetor, index + 1, s, d);

                vetor[index] = -d;
                SurplusDeficit(vetor, index + 1, s, d);
            }
        }
    }
}
