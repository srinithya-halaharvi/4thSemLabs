using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace studentform
{
    public partial class Form1 : Form
    {
        public static string Text1 = "";
        public static string Text2 = "";
        public static string Text3 = "";
        public static string Text4 = "";
        public static string Text5 = "";
        public static string Text6 = "";
        public static string Text7 = "";
        public static string Text8 = "";
        public static string Text9 = "";
        public static string Text10 = "";
        public static string Text11 = "";
        public static string Text12 = "";
        public static string Text13= "";
        public static string Text14 = "";
        public static string Text15 = "";
        public static string Text16 = "";
        public static bool ch1;
        public static bool ch2;
        public static bool ch3;
        public static bool ch4;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comboBox1.Items.Add("CCE");
            comboBox1.Items.Add("CSE");
            comboBox1.Items.Add("ECE");
            comboBox1.Items.Add("IT");
            comboBox1.Items.Add("CSE-AI ML");
            comboBox1.Items.Add("DSC");
            comboBox1.Items.Add("EEE");
            comboBox1.Items.Add("EIE");
            comboBox1.Items.Add("CIVIL");
            comboBox1.Items.Add("MECHX");
            comboBox1.Items.Add("BIOMED");
            comboBox1.Items.Add("AUTOMOBILE");
        }

        private void ok_button_Click(object sender, EventArgs e)
        {
            Text1 = textBox1.Text;
            Text2 = textBox2.Text;
            Text3 = textBox3.Text;
            Text4 = textBox4.Text;
            Text5 = textBox5.Text;
            Text6 = textBox6.Text;
            Text7 = textBox7.Text;
            Text8 = textBox8.Text;
            Text9 = comboBox1.Text;
            Text12 = checkBox1.Text;
            Text13 = checkBox2.Text;
            Text14 = checkBox3.Text;
            Text15 = checkBox4.Text;
            bool istrue1 = radioButton1.Checked;
            bool istrue2 = radioButton2.Checked;
            bool istrue3 = radioButton3.Checked;
            Text10=istrue1?(radioButton1.Text):(istrue2?(radioButton2.Text):(radioButton3.Text));
            ch1 = checkBox1.Checked;
            ch2 = checkBox2.Checked;
            ch3 = checkBox3.Checked;
            ch4 = checkBox4.Checked;
            Text16 = textBox9.Text;
            Text11 = dateTimePicker2.Text;
            Form2 frm = new Form2();
            frm.Show();
        }
    }
}
