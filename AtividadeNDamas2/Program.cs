using System;

namespace AtividadeNDamas
{
    class Program
    {
        static int cont = 1;
        static int casos;
        static string[] linhacoluna;

        static void Main(string[] args)
        {
            cont = 1;

            casos = int.Parse(Console.ReadLine());

            int[] linha = new int[casos];
            int[] coluna = new int[casos];

            for (int i = 0; i < casos; i++)
            {
                linhacoluna = Console.ReadLine().Split();
                linha[i] = int.Parse(linhacoluna[0]);
                coluna[i] = int.Parse(linhacoluna[1]);
            }

            Console.WriteLine("SOLN" + '\t' + "   COLUMN");
            Console.WriteLine(" #" + '\t' + "1 2 3 4 5 6 7 8\n");

            for (int i = 0; i < linha.Length; i++)
                NDamas(new int[8], 0, 8, linha[i], coluna[i]);

            Console.ReadKey();
        }

        public static void NDamas(int[] vetor, int index, int n, int linha, int coluna)
        {
            if (index == n)
            {
                Console.Write(" " + cont++ + '\t' + vetor[0]);

                for (int i = 1; i < n; i++)
                {
                    Console.Write(" " + vetor[i]);
                }
                Console.WriteLine();
            }
            else
            {
                for (int i = 1; i <= n; i++)
                {
                    bool ok = true;

                    for (int j = 0; j < index; j++)
                    {
                        if (vetor[j] == i)
                        {
                            ok = false;
                            break;
                        }

                        int diff = index - j;
                        if (vetor[j] == i - diff || vetor[j] == i + diff)
                        {
                            ok = false;
                            break;
                        }
                    }

                    if (ok && (index + 1) == coluna && i != linha)
                        ok = false;

                    if (ok)
                    {
                        vetor[index] = i;
                        NDamas(vetor, index + 1, n, linha, coluna);
                    }
                }
            }
        }
    }
}
