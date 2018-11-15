Public Class NumVB
    Public Function EnterNum() As Integer
        System.Console.Write("Enter second number: ")
        Dim x As Integer = Integer.Parse(Console.ReadLine())
        Return x
    End Function
End Class
