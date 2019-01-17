using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LR5
{
    class PhoneCall
    {
        private byte hours;
        private byte minutes;
        private byte seconds;

        public PhoneCall(byte hours, byte minutes, byte seconds)
        {
            if (hours < 0 || hours > 23)
            {
                throw new PhoneCallException("Hour should be in range [0-23]");
            }

            if (minutes < 0 || minutes > 59)
            {
                throw new PhoneCallException("Minute value should be in range [0-59]");
            }

            if (seconds < 0 || seconds > 59)
            {
                throw new PhoneCallException("Seconds value should be in range [0-59]");
            }

            this.hours = hours;
            this.minutes = minutes;
            this.seconds = seconds;
        }

        public string GetTime()
        {
            string day = Convert.ToString(this.hours);
            string month = Convert.ToString(this.minutes);
            string year = Convert.ToString(this.seconds);
            string date = hours + "." + month + "." + year;

            return date;
        }
    }
}
