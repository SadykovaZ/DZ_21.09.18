// DZ_21.09.18.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;
string type[3] = { "Птица", "Скот", "Человек" };
ifstream my_file;
int t;

struct Animal
{
	int t_index;
	int skorost_peredvij;
	string color;
	string name;
	union
	{
		double skorost_poleta;
		bool parnokop;
		int IQ;
	};
	void add()
	{
		my_file >> t_index;
		my_file >> color;
		my_file >> skorost_peredvij;
		switch (t_index)
		{
		case 0:

			my_file >> name;
			my_file >> skorost_poleta;
			break;
		case 1:

			my_file >> name;
			my_file >> parnokop;
			break;
		case 2:

			my_file >> name;
			my_file >> IQ;
			break;
		}

	}
	void fill()
	{

		cout << " 0 - Птица; \n 1 - Скот; \n 2 - Человек;" << endl;
		cin >> t_index;
		cout << "Введите цвет: ";
		cin >> color;
		cout << "Введите скорость передвижения: ";
		cin >> skorost_peredvij;

		switch (t_index)
		{
		case 0:
			cout << "Введите вид птицы: ";
			cin >> name;
			cout << "Введите скорость полета: ";
			cin >> skorost_poleta;
			break;
		case 1:
			cout << "Введите вид скота: ";
			cin >> name;
			cout << "Является ли животное парнокопытным ( 1 - да, 0 - нет) ";
			cin >> parnokop;

			/*cout << "Скот, парнокопытное " << endl;*/
			break;
		case 2:
			cout << "Введите имя человека: ";
			cin >> name;
			cout << "Введите IQ: ";
			cin >> IQ;
			break;
		}

	}


	void print()
	{
		cout << type[t_index] << " ";
		cout << "Цвет: ";
		cout << color << endl;
		cout << "Скорость передвижения: ";
		cout << skorost_peredvij << endl;

		switch (t_index)
		{
		case 0:
			cout << "Вид птицы: " << name << endl;
			cout << "Скорость полета  = " << skorost_poleta << endl;
			break;
		case 1:
			cout << "Вид скота: " << name << endl;
			if (parnokop)
				cout << "Парнокопытное. " << endl;
			else
				cout << "Не парнокопытное. " << endl;
			break;
		case 2:
			cout << "Имя человека: " << name << endl;
			cout << "IQ = " << IQ << endl;
			break;
		}

	}

};
void search_by_name(Animal* a)
{
	string poisk;
	cout << "Введите имя животного которое хотите изменить: ";
	cin >> poisk;
	for (int i = 0; i < t; i++)
	{
		if (a[i].name == poisk)
		{
			a[i].fill();
			break;
		}
	}
}
void search1(Animal *a)
{
	cout << "Кого вы хотите найти : "<<endl;
	cout << " 0 - Птица; \n 1 - Скот; \n 2 - Человек;" << endl;
	int x;
	cin >> x;
	double p_a;
	bool pp;
	int p_iq;

	switch (x)
	{
	case 0:
		cout << "Введите скорость полета: ";
		cin >> p_a;
		break;
	case 1:
		cout << "Является ли животное парнокопытным ( 1 - да, 0 - нет) ";
		cin >> pp;
		break;
	case 2:
		cout << "Введите IQ: ";
		cin >> p_iq;
		break;
	}

	for (int i = 0; i < t; i++)
	{
		switch (x)
		{
		case 0:
	
			if (a[i].skorost_poleta == p_a)
				cout << a[i].name;

			break;
		case 1:
			
			if (a[i].parnokop == pp)
				cout << a[i].name;

			break;
		case 2:
			
			if (a[i].IQ == p_iq)
				cout << a[i].name;
			break;
		}
	}

}

int main()
{
	setlocale(LC_ALL, "Rus");
	my_file.open("in.txt", ios::in);

	my_file >> t;
	Animal * a;
	a = new Animal[t];
	
	for (int i = 0; i < t; i++)
	{
		a[i].add();
	}
	while (true)
	{
		cout << "1 - Печать, 2 - Редактировать, 3 - Поиск по характеристике" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			for (int i = 0; i < t; i++)
			{
				a[i].print();
			}
			break;
		case 2: search_by_name(a);
			break;
		case 3: search1(a);
			break;
		}
	}


	delete[] a;

	return 0;
}

