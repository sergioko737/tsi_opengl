﻿Public Class HelloVB
    Inherits HelloCPP.HelloCPP
    Public Overrides Sub Hello()
        MyBase.Hello(3)
        System.Console.WriteLine("Hello from Visual Basic")
    End Sub
End Class
