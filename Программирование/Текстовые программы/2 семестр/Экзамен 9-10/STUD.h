#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Stud1 {
	char Name[50];
	char Addr[50];
	double Price;

	Stud1() : Name("null"), Addr("null"), Price(0.0)
	{}

	Stud1(string name, string addr, double price)
	{
		for (int i = 0; i < name.size(); ++i)
		{
			Name[i] = name[i];
		}
		Name[name.size()] = '\0';

		for (int i = 0; i < addr.size(); ++i)
		{
			Addr[i] = addr[i];
		}
		Addr[addr.size()] = '\0';
		Price = price;
	}

	friend ostream& operator<<(ostream& out, Stud1& t)
	{
		try
		{
			ofstream out_f("Output.txt", ios::app);

			if (!out_f.is_open())
				throw exception("Файл не открыт.");

			for (int i = 0; ; ++i)
			{
				if (t.Name[i] == '\0')
					break;
				out_f << t.Name[i];
			}
			out_f << " ";

			for (int i = 0; ; ++i)
			{
				if (t.Addr[i] == '\0')
					break;
				out_f << t.Addr[i];
			}
			out_f << " ";

			out_f << t.Price << "\n";

			out_f.close();

			return out;
		}
		catch (exception& ex)
		{
			cout << ex.what() << "\n";
		}
	}
};



struct Stud2 {
	char Name[50];

	Stud2() : Name("null")
	{}

	Stud2(string name)
	{
		for (int i = 0; i < name.size(); ++i)
		{
			Name[i] = name[i];
		}
		Name[name.size()] = '\0';
	}

	friend ostream& operator<<(ostream& out, Stud2& t)
	{
		try
		{
			ofstream out_f("Output.txt", ios::app);
			if (!out_f.is_open())
				throw exception("Файл не открыт.");

			for (int i = 0; ; ++i)
			{
				if (t.Name[i] == '\0')
					break;
				out_f << t.Name[i];
			}
			out_f << " ";

			out_f.close();

			return out;
		}
		catch (exception& ex)
		{
			cout << ex.what() << "\n";
		}
	}
};

struct Stud3 {
	char Name[50];
	char Addr[50];
	char ControlDate[25] = "21 июня 2007г.\0";
	double Price;

	Stud3() : Name("null"), Addr("null"), Price(0.0)
	{}

	Stud3(string name, string addr, double price)
	{
		for (int i = 0; i < name.size(); ++i)
		{
			Name[i] = name[i];
		}
		Name[name.size()] = '\0';

		for (int i = 0; i < addr.size(); ++i)
		{
			Addr[i] = addr[i];
		}
		Addr[addr.size()] = '\0';

		Price = price;
	}

	friend ostream& operator<<(ostream& out, Stud3& t)
	{
		try
		{
			ofstream out_f("Output.txt", ios::app);
			if (!out_f.is_open())
				throw exception("Файл не открыт.");

			for (int i = 0; ; ++i)
			{
				if (t.Name[i] == '\0')
					break;
				out_f << t.Name[i];
			}

			out_f << " ";

			for (int i = 0; ; ++i)
			{
				if (t.Addr[i] == '\0')
					break;
				out_f << t.Addr[i];
			}

			out_f << " ";

			for (int i = 0; ; ++i)
			{
				if (t.ControlDate[i] == '\0')
					break;
				out_f << t.ControlDate[i];
			}

			out_f << t.Price << "\n";

			out_f.close();

			return out;
		}
		catch (exception& ex)
		{
			cout << ex.what() << "\n";
		}
	}

};



template <class Type>
class STUD
{
private:
	int count;
	Type* M;

public:
	STUD();
	STUD(const STUD<Type>& s);
	~STUD();

	int GetCount();
	Type* GetPtr();
	void Push(const Type& data);

	void ReadData(fstream& file);
	void WriteData(fstream& file);

	Type& operator[](int index);
	friend ostream& operator<< (ostream& out, const STUD<Type>& data);
};

template<class Type>
STUD<Type>::STUD()
{
	this->count = 0;
	this->M = nullptr;
}

template<class Type>
STUD<Type>::STUD(const STUD<Type>& s)
{
	this->count = s.GetCount();
	M = new Type[count];

	for (int i = 0; i < count; ++i)
		M[i] = s.M[i];
}

template<class Type>
STUD<Type>::~STUD()
{
	delete[] M;
}

template<class Type>
inline Type* STUD<Type>::GetPtr()
{
	return M;
}

template<class Type>
inline int STUD<Type>::GetCount()
{
	return count;
}

template<class Type>
inline void STUD<Type>::Push(const Type& data)
{
	try
	{
		Type* old_M = M;

		M = new Type[count + 1];
		for (int i = 0; i < count; ++i)
			M[i] = old_M[i];

		M[count] = data;
		count++;

		delete[] old_M;
	}
	catch (exception& ex)
	{
		cout << ex.what() << "\n";
	}
}

template<class Type>
inline void STUD<Type>::ReadData(fstream& file)
{
	try
	{
		if (!file.is_open())
			throw exception("Файл не открыт.");
		if (file.peek() == EOF)
			throw exception("Файл пуст.");

		Type obj;
		while (file.read(reinterpret_cast<char*>(&obj), sizeof Type))
			Push(obj);

		file.close();
	}
	catch (exception& ex)
	{
		cout << ex.what();
	}
}

template<class Type>
inline void STUD<Type>::WriteData(fstream& file)
{
	try
	{
		if (!file.is_open())
			throw exception("Файл не открыт.");

		for (int i = 0; i < count; ++i)
		{
			file.write(reinterpret_cast<char*>(&M[i]), sizeof Type);
		}

		file.close();

	}
	catch (exception& ex)
	{
		cout << ex.what();
	}
}

template<class Type>
inline Type& STUD<Type>::operator[](int index)
{
		return M[index];
}

template<class Type>
ostream& operator<<(ostream& out, STUD<Type>& data)
{
	for (int i = 0; i < data.GetCount(); ++i)
		out << data[i];
	return out;
}