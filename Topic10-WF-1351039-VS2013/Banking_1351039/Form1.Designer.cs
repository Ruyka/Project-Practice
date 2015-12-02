namespace Banking_1351039
{
    partial class addTran
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.tb_date = new System.Windows.Forms.TextBox();
            this.tb_tran_id = new System.Windows.Forms.TextBox();
            this.tb_acc_id = new System.Windows.Forms.TextBox();
            this.tb_amount = new System.Windows.Forms.TextBox();
            this.tb_desc = new System.Windows.Forms.TextBox();
            this.btt_add = new System.Windows.Forms.Button();
            this.lb_error = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(79, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(139, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "ADD NEW TRANSACTION";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(46, 62);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(30, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Date";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(46, 88);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(77, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Transaction ID";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(46, 114);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(61, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "Account ID";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(46, 140);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(43, 13);
            this.label5.TabIndex = 4;
            this.label5.Text = "Amount";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(46, 166);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(60, 13);
            this.label6.TabIndex = 5;
            this.label6.Text = "Description";
            // 
            // tb_date
            // 
            this.tb_date.Location = new System.Drawing.Point(135, 55);
            this.tb_date.Name = "tb_date";
            this.tb_date.Size = new System.Drawing.Size(133, 20);
            this.tb_date.TabIndex = 6;
            // 
            // tb_tran_id
            // 
            this.tb_tran_id.Location = new System.Drawing.Point(135, 81);
            this.tb_tran_id.Name = "tb_tran_id";
            this.tb_tran_id.Size = new System.Drawing.Size(133, 20);
            this.tb_tran_id.TabIndex = 7;
            // 
            // tb_acc_id
            // 
            this.tb_acc_id.Location = new System.Drawing.Point(135, 107);
            this.tb_acc_id.Name = "tb_acc_id";
            this.tb_acc_id.Size = new System.Drawing.Size(133, 20);
            this.tb_acc_id.TabIndex = 8;
            // 
            // tb_amount
            // 
            this.tb_amount.Location = new System.Drawing.Point(135, 133);
            this.tb_amount.Name = "tb_amount";
            this.tb_amount.Size = new System.Drawing.Size(133, 20);
            this.tb_amount.TabIndex = 9;
            // 
            // tb_desc
            // 
            this.tb_desc.Location = new System.Drawing.Point(135, 159);
            this.tb_desc.Name = "tb_desc";
            this.tb_desc.Size = new System.Drawing.Size(133, 20);
            this.tb_desc.TabIndex = 10;
            // 
            // btt_add
            // 
            this.btt_add.Location = new System.Drawing.Point(102, 185);
            this.btt_add.Name = "btt_add";
            this.btt_add.Size = new System.Drawing.Size(75, 23);
            this.btt_add.TabIndex = 11;
            this.btt_add.Text = "Add";
            this.btt_add.UseVisualStyleBackColor = true;
            this.btt_add.Click += new System.EventHandler(this.btt_add_Click);
            // 
            // lb_error
            // 
            this.lb_error.AutoSize = true;
            this.lb_error.ForeColor = System.Drawing.Color.Red;
            this.lb_error.Location = new System.Drawing.Point(46, 214);
            this.lb_error.Name = "lb_error";
            this.lb_error.Size = new System.Drawing.Size(0, 13);
            this.lb_error.TabIndex = 12;
            // 
            // addTran
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(295, 255);
            this.Controls.Add(this.lb_error);
            this.Controls.Add(this.btt_add);
            this.Controls.Add(this.tb_desc);
            this.Controls.Add(this.tb_amount);
            this.Controls.Add(this.tb_acc_id);
            this.Controls.Add(this.tb_tran_id);
            this.Controls.Add(this.tb_date);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "addTran";
            this.Text = "Add new transaction";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox tb_date;
        private System.Windows.Forms.TextBox tb_tran_id;
        private System.Windows.Forms.TextBox tb_acc_id;
        private System.Windows.Forms.TextBox tb_amount;
        private System.Windows.Forms.TextBox tb_desc;
        private System.Windows.Forms.Button btt_add;
        private System.Windows.Forms.Label lb_error;
    }
}

