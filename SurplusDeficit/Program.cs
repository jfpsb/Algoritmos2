using System;

namespace AtividadeNDamas
{
    class Program
    {
        static int surplus = 0;

        static void Main(string[] args)
        {
            while (true)
            {
                string[] input = Console.ReadLine().Split();

                int s = int.Parse(input[0]);
                int d = int.Parse(input[1]);

                surplus = 0;

                ChamaSurplusDeficit(new int[12], s, d);

                if (surplus == 0)
                {
                    Console.WriteLine("Deficit");
                }
                else
                {
                    Console.WriteLine(surplus);
                }
            }
        }

        public static void ChamaSurplusDeficit(int[] vetor, int s, int d)
        {
            SurplusDeficit(vetor, 0, s, d, 0);
        }

        public static void SurplusDeficit(int[] vetor, int index, int s, int d, int soma)
        {
            int total = 0;

            if (index == 12)
            {
                for (int i = 0; i < 12; i++)
                {
                    total += vetor[i];
                }

                if (total > surplus)
                    surplus = total;
            }
            else
            {
                bool ok = true;

                if (index > 4)
                {
                    if (soma > 0)
                    {
                        ok = false;
                    }
                    else
                    {
                        soma -= vetor[index - 5];
                    }
                }

                if (ok)
                {
                    vetor[index] = s;
                    SurplusDeficit(vetor, index + 1, s, d, soma + vetor[index]);

                    vetor[index] = -d;
                    SurplusDeficit(vetor, index + 1, s, d, soma + vetor[index]);
                }
            }
        }
    }
}
