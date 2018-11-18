//Добавить ссылки на mscorlib.dll и System.Windows.Forms.dll.
.assembly extern mscorlib
{
	.publickeytoken = (B7 7A 5C 56 19 34 E0 89 )
	.ver 2:0:0:0
}
.assembly extern System.Windows.Forms
{
	.publickeytoken = (B7 7A 5C 56 19 34 E0 89 )
	.ver 2:0:0:0
}
// Определить однофайловую сборку
.assembly CILCars
{
	.hash algorithm 0x00008004
	.ver 1:0:0:0
}
.module CILCars.dll
	
// Реализация типа CILCars.CILCar.
.namespace CILCars
{
	.class public auto ansi beforefieldinit CILCar extends [mscorlib]System.Object
	{
	// Поля данных CILCar.
		.field public string petName
		.field public int32 currSpeed
		
		// Специальный конструктор просто позволяет
		// вызывающему коду присваивать поля данных.
		.method public hidebysig specialname rtspecialname
		instance void .ctor(int32 c, string p) cil managed
		{
			.maxstack 8
			// Загрузить первый аргумент в стек и вызвать
			//конструктор базового класса.
			ldarg.0 // 'this' object, not the int32!
			call instance void [mscorlib]System.Object::.ctor()
			
			// Загрузить первый и второй аргументы в стек.
			ldarg.0 // 'this' object
			ldarg.1 // int32 arg
			
			//Сохранить самый верхний элемент стека (int 32)
			//в поле currSpeed.
			stfld int32 CILCars.CILCar::currSpeed
			
			// Загрузить строковый аргумент
			//и сохранить в поле petName.
			ldarg.0 // 'this' object
			ldarg.2 // string arg
			stfld string CILCars.CILCar::petName
			ret
		}
	}

.class public auto ansi beforefieldinit CILCarInfo
	extends [mscorlib]System.Object
{
	.method public hidebysig static void
	  Display(class CILCars.CILCar c) cil managed
	{
		.maxstack 8
		// Нам нужна локальная строковая переменная.
		.locals init ([0] string caption)
		
		// Загрузка строки и входного параметра CILCar в стек.
		ldstr "{0}'s speed is:"
		ldarg.0
		
		// Поместить в стек значение поля petName из CILCar
		// и вызвать статический метод String.Format()
		ldfld string CILCars.CILCar::petName
		call string [mscorlib]System.String::Format(string, object)
		stloc.0
			
		// Загрузить значение поля currSpeed и получить его строковое
		// представление (обратите внимание на вызов ToString()).
		ldarg.0
		ldflda int32 CILCars.CILCar::currSpeed
		call instance string [mscorlib]System.Int32::ToString()
		ldloc.0
		
		// Вызвать метод MessageBox.Show() с загруженными значениями.
		call valuetype [System.Windows.Forms]
			System.Windows.Forms.DialogResult
			[System.Windows.Forms]
			System.Windows.Forms.MessageBox::Show(string, string)
		pop
		ret
	}
}
}