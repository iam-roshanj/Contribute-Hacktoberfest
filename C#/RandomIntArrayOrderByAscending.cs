using System;

namespace ConsoleTest
{
    class Program
    {
        static void Main(string[] args)
        {
            Random rand = new Random();

            int vLength = rand.Next(6, 12);

            int[] vIntArray = new int[vLength];
            int[] vResult = new int[vLength];

            //Fill Array
            Console.WriteLine(">>>>>>>> Initial Array ");
            for (int i = 0; i < vIntArray.Length; i++)
            {
                vIntArray[i] = rand.Next(1, 99);
                Console.Write($@"{vIntArray[i]:00}");
            }
            Console.WriteLine();
            Console.WriteLine();

            Console.WriteLine("Ascending Order...");
            Console.WriteLine();

            //Sorting
            vResult = vIntArray;
            Array.Sort(vResult);

            //Result
            Console.WriteLine(">>>>>>>> Result ");
            for (int i = 0; i < vResult.Length; i++)
            {
                Console.Write($@"{vResult[i]:00} ");
            }
            Console.WriteLine();

            Console.ReadKey();
        }
    }
}
