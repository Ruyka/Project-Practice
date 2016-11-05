Module Module1

    Function traodoi(ByRef a As Integer, ByRef b As Integer)
        Dim t As Integer = a
        a = b
        b = t
    End Function

    Function Sapxep(ByVal a As Integer, ByVal b As Integer, ByVal c As Integer, ByVal d As Integer) As String
        Dim s As String

        If (a < b) Then
            traodoi(a, b)
        End If

        If (a < c) Then
            traodoi(a, c)
        End If

        If (a < d) Then
            traodoi(a, d)
        End If

        If (b < c) Then
            traodoi(b, c)
        End If

        If (b < d) Then
            traodoi(b, d)
        End If

        If (c < d) Then
            traodoi(c, d)
        End If

        s = s & a & " " & b & " " & c & " " & d

        Return s
    End Function

    Function SoChinhPhuong(ByVal n As Integer) As String
        Dim i As Integer = 2
        Dim s As String = ""

        While i * i <= n
            s = s & i * i & " "
            i = i + 1
        End While

        Return s
    End Function

    Function BSCNN(ByVal a As Integer, ByVal b As Integer) As String
        Dim s As String = ""
        Dim ucln, bsc As Integer

        If (a = 0 Or b = 0) Then
            ucln = a + b
        Else
            Dim t1, t2 As Integer
            t1 = a
            t2 = b
            While (t1 <> t2)
                If (t1 > t2) Then
                    t1 = t1 - t2
                Else
                    t2 = t2 - t1
                End If
            End While
            ucln = t1
        End If

        bsc = a * b / ucln

        Return bsc
    End Function

    Sub Main()
        Dim n, i, j As Integer
        Dim s As String
        n = 0

        Console.Out.WriteLine(SoChinhPhuong(4))

        While n <= 2
            Dim input As String = Console.ReadLine()
            n = CInt(input)
        End While

        s = ""
        i = 2

        While i <= n
            j = 2
            While (i Mod j <> 0)
                j = j + 1
            End While

            If (j = i) Then
                s = s & i & " "
            End If
            i = i + 1
        End While

        Console.WriteLine(s)
    End Sub

End Module
