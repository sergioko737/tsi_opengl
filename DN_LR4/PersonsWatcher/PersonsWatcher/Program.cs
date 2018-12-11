using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace PersonsWatcher
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("***** The Amazing File Watcher App *****\n");
            // Установить путь к каталогу, за которым нужно наблюдать.
            FileSystemWatcher watcher = new FileSystemWatcher();
            try
            {
                watcher.Path = @".\PERSON";
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine(ex.Message);
                Console.Read();
                return;
            }

            // Указать цели наблюдения.
            watcher.NotifyFilter = NotifyFilters.LastAccess
                                    | NotifyFilters.LastWrite
                                    | NotifyFilters.FileName
                                    | NotifyFilters.DirectoryName;

            // Следить только за текстовыми файлами.
            watcher.Filter = "persons.dat";
            // Добавить обработчики событий.
            watcher.Changed += new FileSystemEventHandler(OnChanged);
            watcher.Created += new FileSystemEventHandler(OnChanged);
            watcher.Deleted += new FileSystemEventHandler(OnChanged);
            watcher.Renamed += new RenamedEventHandler(OnRenamed);
            // Начать наблюдение зa файлом.
            watcher.EnableRaisingEvents = true;
            // Ожидать команды пользователя на завершение программы.
            Console.WriteLine(@"Press q to quit app.");
            while (Console.Read() != 'q') ;
        }
 

    // Следующие два обработчика событий просто сообщают о модификациях файлов:
    static void OnChanged(object source, FileSystemEventArgs e)
        {
            // Показать, что сделано, если файл изменен, создан или удален.
            if (e.ChangeType.ToString() == "Deleted")
            {
                Console.WriteLine("The file {0} is {1}", e.Name, e.ChangeType.ToString().ToLower());
            }
            else
            {
                Console.WriteLine("File : {0} {1}!,", e.FullPath, e.ChangeType);
            }
        }


        static void OnRenamed(object source, RenamedEventArgs e)
        {
        // Показать, что файл был переименован.
        Console.WriteLine("File: {0} renamed to {1}", e.OldFullPath, e.FullPath);
        }
    }
}
