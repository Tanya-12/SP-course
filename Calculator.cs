using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab7Sp
{
    class Calculator
    {
        public void Calculate()
        {
            switch (Operation)
            {
                case Operation.Addition:
                    Result = FirstOperand + SecondOperand;
                    break;
                case Operation.Subtraction:
                    Result = FirstOperand - SecondOperand;
                    break;
                case Operation.Multiplication:
                    Result = FirstOperand * SecondOperand;
                    break;
                case Operation.Division:
                    if (SecondOperand != 0)
                    {
                        Result = FirstOperand / SecondOperand;
                    }
                    else
                    {
                        throw new Exception();
                    }
                    break;
                case Operation.Sin:
                    Result = Math.Sin(FirstOperand);
                    break;
                case Operation.Cos:
                    Result = Math.Cos(FirstOperand);
                    break;
                case Operation.Tn:
                    Result = Math.Tan(FirstOperand);
                    break;
                case Operation.Cot:
                    Result = 1 / Math.Tan(FirstOperand);
                    break;
                case Operation.Sqrt:
                    Result = Math.Pow(FirstOperand, 0.5);
                    break;
                case Operation.Pow:
                    Result = Math.Pow(FirstOperand, SecondOperand);
                    break;
                case Operation.Log:
                    Result = Math.Log(FirstOperand);
                    break;
                default:
                    throw new ArgumentOutOfRangeException();
                    break;
            }
        }

        public void MemorySave(double operand)
        {
            throw new NotImplementedException();
        }

        public double MemoryRead()
        {
            throw new NotImplementedException();
        }

        public void MemoryClear()
        {
            throw new NotImplementedException();
        }
        /// <summary>
        /// Cвойства для работы калькулятора
        /// </summary>

        public double FirstOperand
        {
            get;
            set;
        }

        public double SecondOperand
        {
            get;
            set;
        }

        public Operation Operation
        {
            get;
            set;

        }

        public double Result
        {
            set;
            get;
        }
    }
}
