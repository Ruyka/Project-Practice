using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows;

namespace Password
{

    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private async void button1_Click(object sender, EventArgs e)
        {
            int[] CheckBox = new int[4] { 0, 0, 0, 0 };
            int Lenght = 0, Save = 0;
            char[] _Result;

            if (PLenghtTB.Text.Length != 0)
            {
                for (int i = 0; i < PLenghtTB.Text.Length;i++ )
                    if (PLenghtTB.Text[i] < '0' || PLenghtTB.Text[i] > '9')
                    {
                        Result.Text = "Invalid input !";
                        return;
                    }
                Save = Lenght = Convert.ToInt32(PLenghtTB.Text);
                _Result = new char[Lenght];

                for (int i = 0; i < Lenght; i++)
                    _Result[i] = ' ';

                Random rnd = new Random();
                for (int i = 0; i < Property_Checklist.Items.Count; i++)
                {
                    if (Property_Checklist.GetItemChecked(i) && Save != 0)
                    {
                        CheckBox[i] = rnd.Next(1,Save);
                        Save -= CheckBox[i];
                    }
                }

                CheckBox[3] = Save;

                for (int i = 0; i < 4; i++)
                {
                    int tmp;
                    while (CheckBox[i] != 0)
                    {
                        tmp = rnd.Next(Lenght);
                        if (_Result[tmp] == ' ')
                        {
                            if (i == 0)
                                _Result[tmp] = Convert.ToChar(rnd.Next(65, 91));
                            else if (i == 1)
                            {
                                _Result[tmp] = Convert.ToChar(rnd.Next(33, 127));
                                while ((_Result[tmp] >= '0' && _Result[tmp] <= '9') || (_Result[tmp] >= 'A' && _Result[tmp] <= 'Z') || (_Result[tmp] >= 'a' && _Result[tmp] <= 'z'))
                                    _Result[tmp] = Convert.ToChar(rnd.Next(33, 127));
                            }
                            else if (i == 2)
                                _Result[tmp] = Convert.ToChar(rnd.Next(48, 58));
                            else
                                _Result[tmp] = Convert.ToChar(rnd.Next(97, 123));
                            CheckBox[i]--;
                        }
                    }
                }

                Result.Text = new string(_Result);

                string mydocpath = Environment.GetFolderPath(Environment.SpecialFolder.Desktop);

                StringBuilder sb = new StringBuilder();

                sb.AppendLine(DateTime.Now.ToString("d/M/yyyy hh:mm:ss tt") + " Password : " + new string(_Result));

                using (StreamWriter outfile = new StreamWriter(mydocpath + @"\Wifi Password.txt", true))
                {
                      await outfile.WriteAsync(sb.ToString());
                }          
            }
        }
    }
}