using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace Lab7Sp
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        CalculatorFramework framework;
        Calculator calculator;
        bool flag;

        public MainPage()
        {
            this.InitializeComponent();
            framework = new CalculatorFramework();
            calculator = new Calculator();
            flag = false;
            foreach (UIElement c in grid.Children)
            {
                Button button = c as Button;

                if (button != null)
                {
                    if (button.Name != "btnInvertor" || button.Name != "BttnEqual" || button.Name != "BtnSeparator")
                        button.Click += Btn_Click;
                }
            }
        }

       

        private void btnPaneHide_Click(object sender, RoutedEventArgs e)
        {
            splitView.IsPaneOpen = !splitView.IsPaneOpen;
            btnPaneHide.Icon = splitView.IsPaneOpen == true ? new SymbolIcon(Symbol.ClosePane) : new SymbolIcon(Symbol.OpenPane);
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            op1.Content = "^(1⁄2)";
            op2.Content = "log";
            op3.Content = "^";
            op4.Content = "";
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            op1.Content = "+";
            op2.Content = "-";
            op3.Content = "/";
            op4.Content = "*";
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            op1.Content = "sin";
            op2.Content = "cos";
            op3.Content = "tn";
            op4.Content = "cot"; 
        }
        private void Btn_Click(object sender, RoutedEventArgs e)
        {
            String buttonText = (String)((Button)e.OriginalSource).Content;

            switch (buttonText)
            {
                case "0":
                    if (flag == true)
                    {
                        txtBoxInput.Text = "";
                    }
                    flag = false;
                    txtBoxInput.Text += buttonText;
                    break;
                case "1":
                    if (flag == true)
                    {
                        txtBoxInput.Text = "";
                    }
                    flag = false;
                    txtBoxInput.Text += buttonText;
                    break;
                case "2":
                    if (flag == true)
                    {
                        txtBoxInput.Text = "";
                    }
                    flag = false;
                    txtBoxInput.Text += buttonText;
                    break;
                case "3":
                    if (flag == true)
                    {
                        txtBoxInput.Text = "";
                    }
                    flag = false;
                    txtBoxInput.Text += buttonText;
                    break;
                case "4":
                    if (flag == true)
                    {
                        txtBoxInput.Text = "";
                    }
                    flag = false;
                    txtBoxInput.Text += buttonText;
                    break;
                case "5":
                    if (flag == true)
                    {
                        txtBoxInput.Text = "";
                    }
                    flag = false;
                    txtBoxInput.Text += buttonText;
                    break;
                case "6":
                    if (flag == true)
                    {
                        txtBoxInput.Text = "";
                    }
                    flag = false;
                    txtBoxInput.Text += buttonText;
                    break;
                case "7":
                    if (flag == true)
                    {
                        txtBoxInput.Text = "";
                    }
                    flag = false;
                    txtBoxInput.Text += buttonText;
                    break;
                case "8":
                    if (flag == true)
                    {
                        txtBoxInput.Text = "";
                    }
                    flag = false;
                    txtBoxInput.Text += buttonText;
                    break;
                case "9":
                    if (flag == true)
                    {
                        txtBoxInput.Text = "";
                    }
                    flag = false;
                    txtBoxInput.Text += buttonText;
                    break;
                case "+":
                    flag = true;
                    try
                    {
                        calculator.FirstOperand = framework.ParseString(txtBoxInput.Text);
                    }
                    catch (Exception)
                    {
                        txtBoxInput.Text = "Error of parsing";
                    }
                    calculator.Operation = Operation.Addition;
                    break;
                case "-":
                    flag = true;
                    try
                    {
                        calculator.FirstOperand = framework.ParseString(txtBoxInput.Text);
                    }
                    catch (Exception)
                    {
                        txtBoxInput.Text = "Error of parsing";
                    }
                    calculator.Operation = Operation.Subtraction;
                    break;
                case "/":
                    flag = true;
                    try
                    {
                        calculator.FirstOperand = framework.ParseString(txtBoxInput.Text);
                        calculator.Operation = Operation.Division;
                    }
                    catch (Exception)
                    {
                        txtBoxInput.Text = "Error";
                    }
                    break;
                case "*":
                    flag = true;
                    try
                    {
                        calculator.FirstOperand = framework.ParseString(txtBoxInput.Text);
                    }
                    catch (Exception)
                    {
                        txtBoxInput.Text = "Error of parsing";
                    }
                    calculator.Operation = Operation.Multiplication;
                    break;
                case "^":
                    flag = true;
                    try
                    {
                        calculator.FirstOperand = framework.ParseString(txtBoxInput.Text);
                    }
                    catch (Exception)
                    {
                        txtBoxInput.Text = "Error of parsing";
                    }
                    calculator.Operation = Operation.Pow;
                    break;
                case "sin":
                    flag = true;
                    try
                    {
                        calculator.FirstOperand = framework.ParseString(txtBoxInput.Text);
                    }
                    catch (Exception)
                    {
                        txtBoxInput.Text = "Error of parsing";
                    }
                    calculator.Operation = Operation.Sin;
                    calculator.Calculate();
                    txtBoxInput.Text = framework.CorrectResult(calculator.Result.ToString());
                    break;
                case "cos":
                    flag = true;
                    try
                    {
                        calculator.FirstOperand = framework.ParseString(txtBoxInput.Text);
                    }
                    catch (Exception)
                    {
                        txtBoxInput.Text = "Error of parsing";
                    }
                    calculator.Operation = Operation.Cos;
                    calculator.Calculate();
                    txtBoxInput.Text = framework.CorrectResult(calculator.Result.ToString());
                    break;
                case "tn":
                    flag = true;
                    try
                    {
                        calculator.FirstOperand = framework.ParseString(txtBoxInput.Text);
                    }
                    catch (Exception)
                    {
                        txtBoxInput.Text = "Error of parsing";
                    }
                    calculator.Operation = Operation.Tn;
                    calculator.Calculate();
                    txtBoxInput.Text = framework.CorrectResult(calculator.Result.ToString());
                    break;
                case "cot":
                    flag = true;
                    try
                    {
                        calculator.FirstOperand = framework.ParseString(txtBoxInput.Text);
                    }
                    catch (Exception)
                    {
                        txtBoxInput.Text = "Error of parsing";
                    }
                    calculator.Operation = Operation.Cot;
                    calculator.Calculate();
                    txtBoxInput.Text = framework.CorrectResult(calculator.Result.ToString());
                    break;
                case "^(1⁄2)":
                    flag = true;
                    try
                    {
                        calculator.FirstOperand = framework.ParseString(txtBoxInput.Text);
                    }
                    catch (Exception)
                    {
                        txtBoxInput.Text = "Error of parsing";
                    }
                    calculator.Operation = Operation.Sqrt;
                    calculator.Calculate();
                    txtBoxInput.Text = framework.CorrectResult(calculator.Result.ToString());
                    break;
                case "log":
                    flag = true;
                    try
                    {
                        calculator.FirstOperand = framework.ParseString(txtBoxInput.Text);
                    }
                    catch (Exception)
                    {
                        txtBoxInput.Text = "Error of parsing";
                    }
                    //calculator.Operation = Operation.Factorial;
                    calculator.Operation = Operation.Log;
                    calculator.Calculate();
                    txtBoxInput.Text = framework.CorrectResult(calculator.Result.ToString());
                    break;
                case "CL":
                    if (txtBoxInput.Text.Length > 0)
                    {
                        txtBoxInput.Text = txtBoxInput.Text.Substring(0, txtBoxInput.Text.Length - 1);
                    }
                    break;
                case "C":
                    txtBoxInput.Text = "";
                    calculator.FirstOperand = 0;
                    calculator.SecondOperand = 0;
                    calculator.Result = 0;
                    break;
                case ",":
                    if (flag == true)
                    {
                        txtBoxInput.Text = "";
                    }
                    flag = false;
                    txtBoxInput.Text = framework.AddPeriod(txtBoxInput.Text);
                    break;
                case "+/-":
                    txtBoxInput.Text = framework.Invert(txtBoxInput.Text);
                    break;
                case "=":
                    try
                    {
                        calculator.SecondOperand = framework.ParseString(txtBoxInput.Text);
                        calculator.Calculate();


                    }
                    catch (Exception)
                    {
                        txtBoxInput.Text = "Error";
                    }
                    txtBoxInput.Text = framework.CorrectResult(calculator.Result.ToString());
                    flag = true;
                    break;

            }
        }
        public void Check()
        {
            if (flag == true)
            {
                txtBoxInput.Text = "";
            }
        }

    }
}
