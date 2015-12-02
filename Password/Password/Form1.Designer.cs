namespace Password
{
    partial class Form1
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
            this.Generate_Button = new System.Windows.Forms.Button();
            this.Property_Checklist = new System.Windows.Forms.CheckedListBox();
            this.PLenght = new System.Windows.Forms.Label();
            this.PLenghtTB = new System.Windows.Forms.TextBox();
            this.instruct = new System.Windows.Forms.Label();
            this.Result = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // Generate_Button
            // 
            this.Generate_Button.Location = new System.Drawing.Point(108, 122);
            this.Generate_Button.Name = "Generate_Button";
            this.Generate_Button.Size = new System.Drawing.Size(75, 23);
            this.Generate_Button.TabIndex = 0;
            this.Generate_Button.Text = "Generate";
            this.Generate_Button.UseVisualStyleBackColor = true;
            this.Generate_Button.Click += new System.EventHandler(this.button1_Click);
            // 
            // Property_Checklist
            // 
            this.Property_Checklist.CheckOnClick = true;
            this.Property_Checklist.FormattingEnabled = true;
            this.Property_Checklist.Items.AddRange(new object[] {
            "Upper case",
            "Special symbol",
            "Number"});
            this.Property_Checklist.Location = new System.Drawing.Point(12, 12);
            this.Property_Checklist.Name = "Property_Checklist";
            this.Property_Checklist.Size = new System.Drawing.Size(120, 49);
            this.Property_Checklist.TabIndex = 1;
            // 
            // PLenght
            // 
            this.PLenght.AutoSize = true;
            this.PLenght.Location = new System.Drawing.Point(13, 86);
            this.PLenght.Name = "PLenght";
            this.PLenght.Size = new System.Drawing.Size(98, 13);
            this.PLenght.TabIndex = 2;
            this.PLenght.Text = "Password Lenght : ";
            // 
            // PLenghtTB
            // 
            this.PLenghtTB.AllowDrop = true;
            this.PLenghtTB.Location = new System.Drawing.Point(117, 83);
            this.PLenghtTB.Name = "PLenghtTB";
            this.PLenghtTB.Size = new System.Drawing.Size(76, 20);
            this.PLenghtTB.TabIndex = 3;
            // 
            // instruct
            // 
            this.instruct.AutoSize = true;
            this.instruct.Location = new System.Drawing.Point(211, 86);
            this.instruct.Name = "instruct";
            this.instruct.Size = new System.Drawing.Size(44, 13);
            this.instruct.TabIndex = 4;
            this.instruct.Text = "0~9999";
            // 
            // Result
            // 
            this.Result.Location = new System.Drawing.Point(16, 162);
            this.Result.Name = "Result";
            this.Result.Size = new System.Drawing.Size(256, 20);
            this.Result.TabIndex = 5;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 225);
            this.Controls.Add(this.Result);
            this.Controls.Add(this.instruct);
            this.Controls.Add(this.PLenghtTB);
            this.Controls.Add(this.PLenght);
            this.Controls.Add(this.Property_Checklist);
            this.Controls.Add(this.Generate_Button);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Generate_Button;
        private System.Windows.Forms.CheckedListBox Property_Checklist;
        private System.Windows.Forms.Label PLenght;
        private System.Windows.Forms.TextBox PLenghtTB;
        private System.Windows.Forms.Label instruct;
        private System.Windows.Forms.TextBox Result;
    }
}

