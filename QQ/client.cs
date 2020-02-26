using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QQ
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            textBox1.Text = new Random().Next(1,1000).ToString();
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            if (openFileDialog.ShowDialog()==DialogResult.OK)
            {
                string[] strNames = openFileDialog.SafeFileNames;
                //将文件名添加到 listbox 中
                label1.Text = strNames[0];
                if(strNames.Length>1)
                    label1.Text += "...";
            }
        }
        private void Button1_Click(object sender, EventArgs e)
        {
            WebRequest request = WebRequest.Create("https://github.com/proxyee-down-org/proxyee-down/blob/master/README.md");
            request.Method = "GET";
            StreamReader reader = new StreamReader(request.GetResponse().GetResponseStream());
            string result = reader.ReadToEnd();
            MessageBox.Show(result);
            Task.Run(GetWeb);
        }
        async Task<int> GetWeb()
        {
            Console.WriteLine("1:"+Thread.CurrentThread.ManagedThreadId);
            await Task.Run(()=> {
                Console.WriteLine("2:" + Thread.CurrentThread.ManagedThreadId);
                Thread.Sleep(100);
            });
            Console.WriteLine("5:" + Thread.CurrentThread.ManagedThreadId);
            await Task.Run(() => {
                Thread.Sleep(100);
                Console.WriteLine("3:" + Thread.CurrentThread.ManagedThreadId);
            });
            Console.WriteLine("4:"+Thread.CurrentThread.ManagedThreadId);
            return 1;
        }
    }
}
