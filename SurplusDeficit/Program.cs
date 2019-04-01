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

            Console.Write("MAIOR: " + max);

            Console.ReadKey();
        }

        public static void SurplusDeficit(int[] vetor, int index, int s, int d)
        {
            int aux = 0;
            int soma = 0;

            if (index == 12)
            {
                
            }
            else
            {
                vetor[index] = s;
                SurplusDeficit(vetor, index + 1, s, d);

                vetor[index] = -d;
                SurplusDeficit(vetor, index + 1, s, d);
            }


            //if (index == n)
            //{
            //    Console.Write(cont++ + ": " + vetor[0]);

            //    for (int i = 1; i < n; i++)
            //    {
            //        Console.Write(vetor[i]);
            //    }
            //    Console.WriteLine();
            //}
            //else
            //{
            //    for (int i = 1; i <= n; i++)
            //    {
            //        bool ok = true;

            //        for (int j = 0; j < index; j++)
            //        {
            //            if (vetor[j] == i)
            //            {
            //                ok = false;
            //                break;
            //            }

            //            int diff = index - j;
            //            if (vetor[j] == i - diff || vetor[j] == i + diff)
            //            {
            //                ok = false;
            //                break;
            //            }
            //        }

            //        if (ok)
            //        {
            //            vetor[index] = i;
            //            SurplusDeficit(vetor, index + 1, n);
            //        }
            //    }
            //}
        }
    }
}
