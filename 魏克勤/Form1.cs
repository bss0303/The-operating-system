using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace 图片移动
{
    public partial class Form1 : Form
    {
        public static string imgPath = Application.StartupPath.Replace("\\bin\\Debug","\\imgs");
        string[] imgName = { "001.jpg", "002.jpg", "003.jpg", "004.jpg", "005.jpg" };
        int index = 0;
        
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
           
            timer1.Enabled = true;
            timer1.Interval = 1000;//间隔为100毫秒
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            this.pictureBox1.Image = Image.FromFile(imgPath+"\\"+imgName[index++]);
            if(index==4)
            {
                index = 0;
            }
            Random i = new Random();
            int m = i.Next(0, ClientSize.Height);
            int n = i.Next(0, ClientSize.Width);
            
            if(m<0||m>ClientSize.Height-pictureBox1.Size.Height||n<0||n>ClientSize.Width-pictureBox1.Size.Width)
            {
                pictureBox1.Location = new Point(0,0);
            }
            pictureBox1.Location = new Point(m, n);
            pictureBox1.Refresh();//不断刷新
        }

    }
}
