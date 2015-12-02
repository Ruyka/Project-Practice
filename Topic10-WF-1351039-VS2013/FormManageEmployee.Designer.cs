namespace Topic10_WF_1351039_VS2013
{
    partial class FormManageEmployee
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
            this.comboboxDSPhong = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonXuatDS = new System.Windows.Forms.Button();
            this.dataGridViewDSNhanVien = new System.Windows.Forms.DataGridView();
            this.buttonThoat = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDSNhanVien)).BeginInit();
            this.SuspendLayout();
            // 
            // comboboxDSPhong
            // 
            this.comboboxDSPhong.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboboxDSPhong.FormattingEnabled = true;
            this.comboboxDSPhong.Location = new System.Drawing.Point(112, 24);
            this.comboboxDSPhong.Name = "comboboxDSPhong";
            this.comboboxDSPhong.Size = new System.Drawing.Size(268, 21);
            this.comboboxDSPhong.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(17, 27);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(89, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Chọn phòng ban:";
            // 
            // buttonXuatDS
            // 
            this.buttonXuatDS.Location = new System.Drawing.Point(112, 62);
            this.buttonXuatDS.Name = "buttonXuatDS";
            this.buttonXuatDS.Size = new System.Drawing.Size(120, 23);
            this.buttonXuatDS.TabIndex = 2;
            this.buttonXuatDS.Text = "Xuất DS nhân viên";
            this.buttonXuatDS.UseVisualStyleBackColor = true;
            this.buttonXuatDS.Click += new System.EventHandler(this.buttonXuatDS_Click);
            // 
            // dataGridViewDSNhanVien
            // 
            this.dataGridViewDSNhanVien.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dataGridViewDSNhanVien.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewDSNhanVien.Location = new System.Drawing.Point(20, 104);
            this.dataGridViewDSNhanVien.Name = "dataGridViewDSNhanVien";
            this.dataGridViewDSNhanVien.Size = new System.Drawing.Size(570, 275);
            this.dataGridViewDSNhanVien.TabIndex = 3;
            // 
            // buttonThoat
            // 
            this.buttonThoat.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonThoat.Location = new System.Drawing.Point(515, 385);
            this.buttonThoat.Name = "buttonThoat";
            this.buttonThoat.Size = new System.Drawing.Size(75, 23);
            this.buttonThoat.TabIndex = 4;
            this.buttonThoat.Text = "Thoát";
            this.buttonThoat.UseVisualStyleBackColor = true;
            this.buttonThoat.Click += new System.EventHandler(this.buttonThoat_Click);
            // 
            // FormManageEmployee
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(602, 427);
            this.Controls.Add(this.buttonThoat);
            this.Controls.Add(this.dataGridViewDSNhanVien);
            this.Controls.Add(this.buttonXuatDS);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.comboboxDSPhong);
            this.Name = "FormManageEmployee";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "FormManageEmployee";
            this.Load += new System.EventHandler(this.FormManageEmployee_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDSNhanVien)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox comboboxDSPhong;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonXuatDS;
        private System.Windows.Forms.DataGridView dataGridViewDSNhanVien;
        private System.Windows.Forms.Button buttonThoat;
    }
}