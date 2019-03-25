using System;

namespace AtividadeNDamas
{
    class Program
    {
        static int cont = 1;

        static void Main(string[] args)
        {
            cont = 1;
            NDamas(new int[8], 0, 8);

            Console.ReadKey();
        }

        public static void PrintVetor(int[] vetor, int index)
        {
            string linha = vetor[0].ToString();

            for (int i = 1; i < index; i++)
            {
                linha += "\t" + vetor[i];
            }

            Console.WriteLine(cont + ": " + linha);
            cont++;
        }

        public static void NDamas(int[] vetor, int index, int n)
        {
            if (index == n + 1)
            {
                PrintVetor(vetor, index);
            }
            else
            {
                bool pelomenosum = false;

                for(int i = 0; i < n; i++)
                {
                    bool ok = true;

                    for(int j = 0; j < index; j++)
                    {
                        if(vetor[j] == i)
                        {
                            ok = false;
                            break;
                        }
                        int diff = index - j;
                        if(vetor[j] == i - diff || vetor[j] == i + diff)
                        {
                            ok = false;
                            break;
                        }
                    }

                    if(ok)
                    {
                        vetor[index] = i;
                        NDamas(vetor, index+1, n);
                        pelomenosum = true;
                    }
                }
            }
        }
    }
}
