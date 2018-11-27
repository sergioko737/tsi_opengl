using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PersonToFile
{
    [Serializable]
    class Person
    {
        private String name;
        private String persCode;
        private int age;

        public String Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
            }
        }

        public String PersCode
        {
            get
            {
                return persCode;
            }
            set
            {
                persCode = value;
            }
        }
        public int Age
        {
            get
            {
                return age;
            }
            set
            {
                age = value;
            }
        }
    }
}
