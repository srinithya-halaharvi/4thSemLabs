using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator
{
    public partial class Form1 : Form
    {
        string input = string.Empty; //to read the input when clicked
        string Op1 = string.Empty; //First operand
        string Op2 = string.Empty; //Second operand
        char Operator; //Operator
        double res = 0.0; //Final result
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void cmd1_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "1";
            this.textBox1.Text += input;
        }

        private void cmd2_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "2";
            this.textBox1.Text += input;
        }

        private void cmd3_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "3";
            this.textBox1.Text += input;
        }

        private void cmd4_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "4";
            this.textBox1.Text += input;
        }

        private void cmd5_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "5";
            this.textBox1.Text += input;
        }

        private void cmd6_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "6";
            this.textBox1.Text += input;
        }

        private void cmd7_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "7";
            this.textBox1.Text += input;
        }

        private void cmd8_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "8";
            this.textBox1.Text += input;
        }

        private void cmd9_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "9";
            this.textBox1.Text += input;
        }

        private void cmd0_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "0";
            this.textBox1.Text += input;
        }

        private void add_Click(object sender, EventArgs e)
        {
            Op1 = input;
            Operator = '+';
            input = string.Empty;
        }

        private void sub_Click(object sender, EventArgs e)
        {
            Op1 = input;
            Operator = '-';
            input = string.Empty;
        }

        private void mult_Click(object sender, EventArgs e)
        {
            Op1 = input;
            Operator = '*';
            input = string.Empty;
        }

        private void div_Click(object sender, EventArgs e)
        {
            Op1 = input;
            Operator = '/';
            input = string.Empty;
        }
        private void mod_Click(object sender, EventArgs e)
        {
            Op1 = input;
            Operator = '%';
            input = string.Empty;
        }
        private void equal_Click(object sender, EventArgs e)
        {
            Op2 = input;
            double num1, num2;
            double.TryParse(Op1, out num1);
            double.TryParse(Op2, out num2);
            if (Operator == '+')
            {
                res = num1 + num2;
                this.textBox1.Text = res.ToString();
            }
            else if (Operator == '-')
            {
                res = num1 - num2;
                textBox1.Text = res.ToString();
            }
            else if (Operator == '*')
            {
                res = num1 * num2;
                textBox1.Text = res.ToString();
            }
            else if (Operator == '/')
            {
                if (num2 != 0)
                {
                    res = num1 / num2;
                    textBox1.Text = res.ToString();
                }
                else
                {
                    textBox1.Text = "DIV/ZERO";
                }
            }
            else if (Operator == '%')
            {
                res = num1 % num2;
                textBox1.Text = res.ToString();
            }
            input = string.Empty;
        }

        private void sqroot_Click(object sender, EventArgs e)
        {
            Op1 = input;
            double num1,res;
            double.TryParse(Op1, out num1);
            res = Math.Sqrt(num1);
            textBox1.Text = res.ToString();
            input = string.Empty;
        }

        private void sin_Click(object sender, EventArgs e)
        {
            Op1 = input;
            double num1, res;
            double.TryParse(Op1, out num1);
            res = Math.Sin(num1);
            textBox1.Text = res.ToString();
            input = string.Empty;
        }

        private void cos_Click(object sender, EventArgs e)
        {
            Op1 = input;
            double num1, res;
            double.TryParse(Op1, out num1);
            res = Math.Cos(num1);
            textBox1.Text = res.ToString();
            input = string.Empty;
        }

        private void tan_Click(object sender, EventArgs e)
        {
            Op1 = input;
            double num1, res;
            double.TryParse(Op1, out num1);
            res = Math.Tan(num1);
            textBox1.Text = res.ToString();
            input = string.Empty;
        }

        private void fact_Click(object sender, EventArgs e)
        {
            Op1 = input;
            double num1;
            long res=1;
            double.TryParse(Op1, out num1);
            for (int i = 2; i < num1; i++)
            {
                res = res * i;
            }
            textBox1.Text = res.ToString();
            input = string.Empty;
        }

    }

}
