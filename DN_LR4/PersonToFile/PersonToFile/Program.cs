﻿using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
using System.Runtime.Serialization.Formatters.Binary;

namespace PersonToFile
{
    class Program
    {
        static void Main(string[] args)
        {
            DirectoryInfo dir1 = new DirectoryInfo(@".\PERSON");
            if (!dir1.Exists)
            {
                Console.WriteLine("Folder PERSON does not exist!\nCreating folder PERSON");
                dir1.Create();
            }
            else Console.WriteLine("The folder PERSON exist!");

            FileInfo file = new FileInfo(@".\PERSON\persons.dat");
            if (!file.Exists)
            {
                Console.WriteLine("The file persons.dat does not exist!\nCreating file persons.dat");
                file.Create();
            }
            else
            {
                Console.WriteLine("The file persons.dat exist!");
                Console.WriteLine("***************************");
                Console.WriteLine("File name: {0}", file.Name);
                Console.WriteLine("File size: {0}", file.Length);
                Console.WriteLine("Creation: {0}", file.CreationTime);
                Console.WriteLine("Attributes: {0}", file.Attributes);
                Console.WriteLine("***************************\n");
            }

            ArrayList persons = new ArrayList();

            BinaryFormatter binFormat = new BinaryFormatter();
            FileStream fStream = new FileStream("persons.dat",
                        FileMode.Open, FileAccess.ReadWrite, FileShare.None);
            binFormat.Serialize(fStream, persons);
        }

        void CheckDirAndFile()
        {

        }
    }
}
