using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calc
{
    class Program
    {
        static void Main(string[] args)
        {
            NumCPP.NumCPP num1 = new NumCPP.NumCPP();
            NumVB.NumVB num2 = new NumVB.NumVB();
            NumCSharp.NumCSharp num3 = new NumCSharp.NumCSharp();
            int result = num1.EnterNum() + num2.EnterNum() + num3.EnterNum();
            Console.WriteLine("Result = " + result);
            Console.ReadLine();
        }
    }
}
