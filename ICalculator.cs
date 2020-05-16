using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab7Sp
{
    public interface ICalculator
    {
        void Calculate();
        void MemorySave(double operand);
        double MemoryRead();
        void MemoryClear();
        double FirstOperand { set; }
        double SecondOperand { set; }
        Operation Operation { get; set; }
        double Result { get; }
    }
}
