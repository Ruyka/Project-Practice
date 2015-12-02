using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Data;


namespace Banking_1351039
{
    public partial class addTran : Form
    {
        public addTran()
        {
            InitializeComponent();
        }

        private void btt_add_Click(object sender, EventArgs e)
        {
            String ConnectionString = System.Configuration.ConfigurationSettings.AppSettings["connectionString"].ToString();

            int account_id = Int32.Parse(tb_acc_id.Text);
            int transaction_id = Int32.Parse(tb_tran_id.Text);

            
            SqlConnection cnn = new SqlConnection();
            cnn.ConnectionString = ConnectionString;
            cnn.Open();

            SqlCommand cmd = new SqlCommand("sp_1351039_AddNewTrans", cnn);
            cmd.CommandType = CommandType.StoredProcedure;

            
        }
    }
}
