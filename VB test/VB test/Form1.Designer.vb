<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.btn_click = New System.Windows.Forms.Button()
        Me.tb_click = New System.Windows.Forms.TextBox()
        Me.btn_mid = New System.Windows.Forms.Button()
        Me.btn_right = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'btn_click
        '
        Me.btn_click.Location = New System.Drawing.Point(197, 85)
        Me.btn_click.Name = "btn_click"
        Me.btn_click.Size = New System.Drawing.Size(75, 23)
        Me.btn_click.TabIndex = 0
        Me.btn_click.Text = "Left"
        Me.btn_click.UseVisualStyleBackColor = True
        '
        'tb_click
        '
        Me.tb_click.Location = New System.Drawing.Point(197, 59)
        Me.tb_click.Name = "tb_click"
        Me.tb_click.Size = New System.Drawing.Size(337, 20)
        Me.tb_click.TabIndex = 1
        '
        'btn_mid
        '
        Me.btn_mid.Location = New System.Drawing.Point(335, 85)
        Me.btn_mid.Name = "btn_mid"
        Me.btn_mid.Size = New System.Drawing.Size(75, 23)
        Me.btn_mid.TabIndex = 2
        Me.btn_mid.Text = "Mid"
        Me.btn_mid.UseVisualStyleBackColor = True
        '
        'btn_right
        '
        Me.btn_right.Location = New System.Drawing.Point(459, 85)
        Me.btn_right.Name = "btn_right"
        Me.btn_right.Size = New System.Drawing.Size(75, 23)
        Me.btn_right.TabIndex = 3
        Me.btn_right.Text = "Right"
        Me.btn_right.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(873, 449)
        Me.Controls.Add(Me.btn_right)
        Me.Controls.Add(Me.btn_mid)
        Me.Controls.Add(Me.tb_click)
        Me.Controls.Add(Me.btn_click)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents btn_click As Button
    Friend WithEvents tb_click As TextBox
    Friend WithEvents btn_mid As Button
    Friend WithEvents btn_right As Button
End Class
