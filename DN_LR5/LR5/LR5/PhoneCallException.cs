using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LR5
{
    public class PhoneCallException : Exception
    {
        public PhoneCallException() {}

        public PhoneCallException(string message) : base(message) { }
    }
}
