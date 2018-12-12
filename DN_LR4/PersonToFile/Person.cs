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
        public String name { get; set; }
        public String persCode { get; set; }
        public byte age { get; set; }
    }
}
