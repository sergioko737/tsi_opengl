﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LR06
{
    class Program
    {
        static void Main(string[] args)
        {
            class Test { int[] arr = new int[1000000];
                public void Method(int i)
                {
                    Console.WriteLine(i); 
                } 
                ~Test()
                {
                    Console.WriteLine("Object " + this.GetHashCode() + " deleted"); 
                }
            }
        }
    }
}
