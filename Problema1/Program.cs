using System;

namespace Alg2Exer1
{
    class Program
    {
        static void Main(string[] args)
        {
            int casos = 1;
            int[] vetor = new int[200001];

            while (true)
            {
                string[] NeM = Console.ReadLine().Split();

                int n = int.Parse(NeM[0]);
                int m = int.Parse(NeM[1]);

                if (n != 0 || m != 0)
                {
                    for (int i = 0; i < n; i++)
                    {
                        vetor[i] = int.Parse(Console.ReadLine());
                    }

                    BuildMaxHeap(vetor, n);

                    Console.WriteLine("Caso " + casos++ + ":");

                    for (int i = 0; i < m; i++)
                    {
                        string[] input = Console.ReadLine().Split();

                        if (input[0].Equals("I"))
                        {
                            int num = int.Parse(input[1]);
                            vetor[n] = num;

                            SiftUp(vetor, n, (n - 1) / 2);

                            n++;
                        }
                        else if (input[0].Equals("P"))
                        {
                            if (n == 0)
                            {
                                Console.WriteLine("empty");
                            }
                            else
                            {
                                Console.WriteLine(vetor[0]);

                                vetor[0] = vetor[n - 1];

                                n--;

                                Heapify(vetor, n, 0);
                            }
                        }
                    }

                    Console.WriteLine();
                }
                else
                {
                    break;
                }
            }
        }

        public static void BuildMaxHeap(int[] vetor, int n)
        {
            for (int i = n / 2; i >= 0; i--)
                Heapify(vetor, n, i);

            //Troca(vetor, n);
        }

        public static void Heapify(int[] vetor, int n, int index)
        {
            int raiz = index;
            int esquerda = 2 * index + 1;
            int direita = 2 * index + 2;

            if (esquerda < n && vetor[esquerda] > vetor[raiz])
            {
                raiz = esquerda;
            }

            if (direita < n && vetor[direita] > vetor[raiz])
            {
                raiz = direita;
            }

            if (raiz != index)
            {
                int aux = vetor[index];
                vetor[index] = vetor[raiz];
                vetor[raiz] = aux;

                Heapify(vetor, n, raiz);
            }
        }

        public static void SiftUp(int[] vetor, int n, int index)
        {
            int raiz = index;
            int esquerda = 2 * index + 1;
            int direita = 2 * index + 2;

            if (esquerda <= n && vetor[esquerda] > vetor[raiz])
            {
                raiz = esquerda;
            }

            if (direita <= n && vetor[direita] > vetor[raiz])
            {
                raiz = direita;
            }

            if (raiz != index)
            {
                int aux = vetor[index];
                vetor[index] = vetor[raiz];
                vetor[raiz] = aux;

                SiftUp(vetor, n, (index - 1) / 2);
            }
        }

        /// <summary>
        /// Troca as posições do primeiro item do vetor (maior número após buildmaxheap)
        /// para última posição do vetor
        /// </summary>
        /// <param name="vetor">Vetor com elementos</param>
        /// <param name="n">Tamanho da coleção</param>
        public static void Troca(int[] vetor, int n)
        {
            int maior = vetor[0];
            vetor[0] = vetor[n - 1];
            vetor[n - 1] = maior;
        }
    }
}
