#include "STUD.h"
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "rus");


	STUD<Stud1>M1;
	STUD<Stud1>M2;
	Stud1 stud{ "Petrov", "F.Skaryny, 20", 5.5 };
	Stud1 stud1{ "Ivanov", "Oktabriskaya, 10", 100000 };

	Stud2 stud2{ "Sidorov" };

	M1.Push(stud);
	M1.Push(stud1);

	fstream in1("Ob1.bin", ios::in | ios::out);
	M1.WriteData(in1); cout << M1;

	fstream in2("Ob1.bin", ios::in | ios::out);
	M2.ReadData(in2); cout << M2;

	return 0;
}