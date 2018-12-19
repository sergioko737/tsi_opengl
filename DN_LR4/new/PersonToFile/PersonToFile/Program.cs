using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;

namespace PersonToFile
{
    class Program
    {
        FileInfo file;

        static void Main(string[] args)
        {
            int action = 0;
            bool mainSection = true;
            BinaryFormatter binaryFormatter = new BinaryFormatter();
            ArrayList persons = new ArrayList();
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


                FileStream fileStream = file.Open(FileMode.Open, FileAccess.ReadWrite, FileShare.None);
                persons = (ArrayList)binaryFormatter.Deserialize(fileStream);
                fileStream.Position = 0;
                fileStream.Close();
            }

            while (mainSection)
            {
                Console.WriteLine("Make your choice");
                Console.WriteLine("1. Add new person to list\n2. View persons list\n3. Exit");
                action = Convert.ToInt32(Console.ReadLine());
                switch (action)
                {
                    case 1:
                        {
                            do
                            {
                                Person person = new Person();

                                Console.Write("Enter name: ");
                                person.name = Console.ReadLine();

                                Console.Write("Enter personal code: ");
                                person.persCode = Console.ReadLine();

                                Console.Write("Enter age: ");
                                person.age = Convert.ToByte(Console.ReadLine());
                                Console.WriteLine();
                                persons.Add(person);

                                Console.Write("\nDo you wan't to continue? (y/n)? ");

                            } while (Console.ReadKey().KeyChar == 'y');
                            Console.ReadLine();

                            BinaryFormatter binFormat = new BinaryFormatter();
                            FileStream fStream = new FileStream(@"./person/persons.dat",
                                        FileMode.Open, FileAccess.ReadWrite, FileShare.None);
                            binFormat.Serialize(fStream, persons);
                            fStream.Close();
                            break;
                        }
                    case 2:
                        {

                            if (file.Exists && file.Length > 0)
                            {
                                Console.WriteLine();
                                for (int i = 0; i < persons.Count; i++)
                                {
                                    Person person = (Person)persons[i];
                                    Console.WriteLine("\n{0}. **********", i);
                                    Console.WriteLine("Username: {0}", person.name);
                                    Console.WriteLine("Personal code: {0}", person.persCode);
                                    Console.WriteLine("Age: {0}", person.age);
                                    Console.WriteLine();
                                }
                            }
                            break;
                        }
                    case 3:
                        {
                            mainSection = false;
                            break;
                        }
                }
            }
            Console.WriteLine("Goodbye!");
            Console.ReadLine();
        }

        void outputData()
        {
            Console.WriteLine("***************************");
            Console.WriteLine("File name: {0}", file.Name);
            Console.WriteLine("File size: {0}", file.Length);
            Console.WriteLine("Creation: {0}", file.CreationTime);
            Console.WriteLine("Attributes: {0}", file.Attributes);
            Console.WriteLine("***************************\n");
        }
    }
}
