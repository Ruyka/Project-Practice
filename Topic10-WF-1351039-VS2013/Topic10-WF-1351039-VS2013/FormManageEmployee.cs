using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Configuration;
using System.Data.SqlClient;

namespace Topic10_WF_1351039_VS2013
{
    public partial class FormManageEmployee : Form
    {
        public FormManageEmployee()
        {
            InitializeComponent();
        }

        private void buttonThoat_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void FormManageEmployee_Load(object sender, EventArgs e)
        {
            string sConnectionString = ConfigurationManager.AppSettings["QLTVConnectionString"].ToString();

            SqlConnection cnn = new SqlConnection();
            cnn.ConnectionString = sConnectionString;
            cnn.Open();

            string sql = "SELECT DNumber, DName FROM DEPARTMENT ORDER BY DName";

            SqlDataAdapter da = new SqlDataAdapter(sql, cnn);

            DataSet ds = new DataSet();

            da.Fill(ds);

            if (ds.Tables.Count > 0) {
                comboboxDSPhong.DataSource = ds.Tables[0];
                comboboxDSPhong.DisplayMember = "DName";
                comboboxDSPhong.ValueMember = "DNumber";
            }
        }

        private void buttonXuatDS_Click(object sender, EventArgs e)
        {
            int selectedValue = (int) comboboxDSPhong.SelectedValue;

            string sConnectionString = ConfigurationManager.AppSettings["QLTVConnectionString"].ToString();

            SqlConnection cnn = new SqlConnection();
            cnn.ConnectionString = sConnectionString;
            cnn.Open();

            string sql = "SELECT SSN, FName + ' ' + Minit + '. ' + LName AS Fullname, BDate, Sex, Address FROM EMPLOYEE WHERE DNO = " + selectedValue.ToString();

            SqlDataAdapter da = new SqlDataAdapter(sql, cnn);

            DataSet ds = new DataSet();

            da.Fill(ds);

            if (ds.Tables.Count > 0)
            {
                dataGridViewDSNhanVien.DataSource = ds.Tables[0];
            }             

        }
    }
}
