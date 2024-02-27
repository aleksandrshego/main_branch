#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

extern "C" int* __stdcall manual_sorting1(int*, int);
extern "C" int* __cdecl manual_sorting2(int*, int);
extern "C" int* __stdcall manual_sorting3(int*, int);
extern "C" int* __cdecl manual_sorting4(int*, int);
extern "C" int* __fastcall manual_sorting5(int*, int);

void copy_arr(const int* source, int* some_arr, const int& size)
{
	for (int i = 0; i < size; ++i)
		some_arr[i] = source[i];
}

int get_size()
{
	int size = 0;
	cout << "Введите размерность: ";
	while (size <= 0)
		cin >> size;

	return size;
}

void output(const int& size, const int* ar)
{
	for (int i = 0; i < size; ++i)
		cout << ar[i] << " ";
	cout << "\n";
}

void random_input(const int& size, int* ar)
{
	int a, b;
	cout << "Введите интервал:\nот - "; cin >> a;
	cout << "до - "; cin >> b;

	if (a > b)
		swap(a, b);

	srand(time(NULL));
	for (int i = 0; i < size; ++i)
	{
		ar[i] = rand() % (b - a + 1) + a;

		while (ar[i] == 0)
			ar[i] = rand() % (b - a + 1) + a;
	}

	cout << "Полученный массив:\n";
	output(size, ar);
}

void manual_input(const int& size, int* ar)
{
	cout << "Введите элементы:\n";

	for (int i = 0; i < size; ++i)
		cin >> ar[i];

	cout << "Полученный массив:\n";
	output(size, ar);
}

void choice(const int& size, int* ar)
{
	cout << "Выберите один из вариантов заполнения массива:\
			\n1) - ручной ввод;\
			\n2) - автоматический ввод с ограничениями.\n";
	switch (_getch())
	{
	case '1':
	{
		system("cls");
		manual_input(size, ar);
		break;
	}
	case '2':
	{
		system("cls");
		random_input(size, ar);
		break;
	}
	default:
		system("cls");
		cout << "Введена неверная клавиша.\nПопробуйте ещё раз.\n";
		choice(size, ar);
		break;
	}
}

int main()
{
	setlocale(0, "rus");
	int n = get_size();
	
	int* source_arr = new int[n];
	int* arr = new int[n];

	choice(n, source_arr);
	copy_arr(source_arr, arr, n);

	arr = manual_sorting1(arr, n);
	cout << "\nИзменённый массив (with function _manual_sorting1):\n";
	output(n, arr);
	copy_arr(source_arr, arr, n);

	arr = manual_sorting2(arr, n);
	cout << "\nИзменённый массив (with function _manual_sorting2):\n";
	output(n, arr);
	copy_arr(source_arr, arr, n);

	arr = manual_sorting3(arr, n);
	cout << "\nИзменённый массив (with function _manual_sorting3):\n";
	output(n, arr);
	copy_arr(source_arr, arr, n);

	arr = manual_sorting4(arr, n);
	cout << "\nИзменённый массив (with function _manual_sorting4):\n";
	output(n, arr);
	copy_arr(source_arr, arr, n);

	arr = manual_sorting5(arr, n);
	cout << "\nИзменённый массив (with function _manual_sorting5):\n";
	output(n, arr);
	copy_arr(source_arr, arr, n);
}