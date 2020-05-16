using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab7Sp
{
    class CalculatorFramework
    {
        /// <summary>
        /// класс, в котором реализуются дополнительные методы. преобразоварие числа, добавление запятой, коррекция знаков после запятой, инвертирование операнда
        /// </summary>
        /// <param name="text"></param>
        /// <returns></returns>
        public String AddPeriod(String text)
        {
            String number = text;
            String separator = CultureInfo.CurrentCulture.NumberFormat.NumberDecimalSeparator;
            if (String.IsNullOrEmpty(number))
            {
                number = "0" + separator;
            }
            else if (number.IndexOf(separator) == -1)
            {
                number += separator;
            }
            return number;
        }
        public String Invert(String text)
        {
            String number = text;
            if (String.IsNullOrEmpty(text) == false)
            {
                if (text[0] == '-')
                {
                    number = text.Substring(1);
                }
                else
                {
                    number = '-' + text;
                }

            }
            return number;
        }
        public Double ParseString(String text)
        {
            Double operand;
            if (!Double.TryParse(text, out operand))
            {
                throw new Exception();
            }

            return operand;
        }
        public String CorrectResult(String text)
        {
            String result = text;
            int index = text.IndexOf(',');
            if (index != -1)
            {
                if (text.Length > index + 3)
                {
                    result = text.Substring(0, index + 3);
                }
            }
            else
            {
                result = text;
            }
            return result;
        }
    }
}

