using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Topic10_WF_1351039_VS2013
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void FormMain_Load(object sender, EventArgs e)
        {
            string Time = DateTime.Now.ToString("dd/mm/yyyy hh:mm:ss");

            this.Text = "1351039 - Kim Thanh - First Windows Form C# - " + Time;
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            DialogResult resultMsgBox;
            resultMsgBox = MessageBox.Show("Bạn muốn ứng dụng không?","Thông báo",MessageBoxButtons.YesNo);

            if (resultMsgBox == DialogResult.Yes)
                Application.Exit();
        }

        private void aboutUsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormAboutUs frm = new FormAboutUs();

            frm.ShowDialog();
        }

        private void manageEmployeeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            FormManageEmployee frm = new FormManageEmployee();

            frm.ShowDialog();
        }
    }
}
