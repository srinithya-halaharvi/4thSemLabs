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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }
      
        private void Form2_Load(object sender, EventArgs e)
        {
            labela.Text = Form1.Text1;
            labelb.Text = Form1.Text2;
            labelc.Text = Form1.Text9;
            labeld.Text = Form1.Text10;
            labele.Text = Form1.Text11;
            labelf.Text = Form1.Text3;
            labelg.Text = Form1.Text4;
            labelh.Text = Form1.Text5;
            labeli.Text = Form1.Text6;
            labelj.Text = Form1.Text7;
            labelk.Text = Form1.Text8; 
            if (Form1.ch1) {
                label14.Text = Form1.Text12;
            }
            if (Form1.ch2)
            {
                label15.Text = Form1.Text13;
            }
            if (Form1.ch3)
            {
                label16.Text = Form1.Text14;
            }
            if (Form1.ch4)
            {
                label17.Text = Form1.Text15;
            }
            label18.Text = Form1.Text16;
        }
    }
}
