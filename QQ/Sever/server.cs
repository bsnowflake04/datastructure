using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Sever
{
    public partial class server : Form
    {
        private Thread thread;
        private TcpListener tcpListener;
        public server()
        {
            InitializeComponent();
            thread = new Thread(new ThreadStart(proc));
            thread.Start();
        }
        private void proc()
        {
            if (this.InvokeRequired)
            {
                this.Invoke(new Action(proc));
            }
            else
            {
                tcpListener = new TcpListener(IPAddress.Any, 1234);
                tcpListener.Server.SetSocketOption(SocketOptionLevel.Socket,SocketOptionName.BlockSource); 
                
                tcpListener.Start(10);
                
                TcpClient client =  tcpListener.AcceptTcpClient();
                
            }
        }

    }
}
