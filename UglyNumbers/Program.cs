using System;
using System.Collections.Generic;

namespace UglyNumbers
{
    class Program
    {
        static void Main(string[] args)
        {
            IDictionary<int, int> uglyNumbers = new Dictionary<int, int>();

            uglyNumbers.Add(0, 1);

            int index_2 = 0, index_3 = 0, index_5 = 0;

            int proximo_ugly_2 = 2;
            int proximo_ugly_3 = 3;
            int proximo_ugly_5 = 5;

            for (int i = 1; i < 1500; i++)
            {
                int proximo_ugly = Math.Min(proximo_ugly_2, proximo_ugly_3);
                proximo_ugly = Math.Min(proximo_ugly, proximo_ugly_5);

                uglyNumbers.Add(i, proximo_ugly);

                if (proximo_ugly == proximo_ugly_2)
                {
                    index_2++;
                    proximo_ugly_2 = uglyNumbers[index_2] * 2;
                }

                if (proximo_ugly == proximo_ugly_3)
                {
                    index_3++;
                    proximo_ugly_3 = uglyNumbers[index_3] * 3;
                }

                if (proximo_ugly == proximo_ugly_5)
                {
                    index_5++;
                    proximo_ugly_5 = uglyNumbers[index_5] * 5;
                }
            }

            Console.Write("The 15000'th ugly number is " + uglyNumbers[1499]);

            Console.ReadKey();
        }

        static bool IsUgly(int numero)
        {
            while (numero % 2 == 0)
                numero /= 2;

            while (numero % 3 == 0)
                numero /= 3;

            while (numero % 5 == 0)
                numero /= 5;

            if (numero == 1)
                return true;

            return false;
        }
    }
}
