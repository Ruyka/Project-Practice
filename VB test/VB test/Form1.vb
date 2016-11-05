Public Class Form1
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles btn_click.Click
        tb_click.TextAlign = HorizontalAlignment.Left
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles btn_right.Click
        tb_click.TextAlign = HorizontalAlignment.Right
    End Sub

    Private Sub btn_mid_Click(sender As Object, e As EventArgs) Handles btn_mid.Click
        tb_click.TextAlign = HorizontalAlignment.Center
    End Sub
End Class
