#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;

class Detail
{
public:
	void virtual Installed() = 0; // Установлена
	void virtual DetailWork() = 0; // Деталь работает
	void virtual DetailOnGuarantees() = 0; // Деталь на гарантий
};

class Bought
{
public:
	void virtual FromTheStore() = 0; // Из магазина
	//void virtual FromUnderTheFloor() = 0; // Куплена из под полы
	//void virtual Exchanged() = 0; // Обменена
};

////////////////////////////////////////////////////////////////////////////////

class CPU_LEGAL : public Detail, public Bought
{
public:
	void Installed() override
	{
		cout << "Деталь установлена" << endl;
	}

	void DetailWork() override
	{
		srand(time(0));
		cout << "Проверка работы процессора - сейчас выдаст числа" << endl;

		for (int i = 0; i < 5; i++) // Процесс вычисления процессором
		{
			for (int j = 0; j < 5; j++)
			{
				cout << rand() % 10 << " ";
				Sleep(150);
			}
			cout << endl;
		}
		cout << endl << "Процесс работы процессора" << endl;
	}

	void FromTheStore() override
	{
		cout << "Вы официально купили процессор - вы молодец" << endl;
	}

	void DetailOnGuarantees() override
	{
		cout << "Деталь на гарантий" << endl;
	}
};

class CPU_FOR_BLACK_MARKET : public Detail, public Bought
{
public:
	void Installed() override
	{
		cout << "Детал была установлена с ошибками" << endl;
	}

	void DetailWork() override
	{
		srand(time(0));
		cout << "Проверка работы процессора - сейчас выдаст числа" << endl;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << rand() % 10 << " ";
				Sleep(150);
			}
			cout << "Непридвиденная ошибка " << endl;
			break;
		}
	}

	void FromTheStore() override
	{
		cout << "Вы неофициально купили процессор - вы подлец" << endl;
	}

	void DetailOnGuarantees() override
	{
		cout << "Деталь не на гарантий" << endl;
	}
};

class GPU : public CPU_LEGAL
{
public:

};

class BP : public CPU_LEGAL
{
public:

};

class RAM : public CPU_LEGAL
{
public:
	void Installed() override
	{
		cout << "Деталь установлена" << endl;
	}

	void DetailWork() override
	{
		cout << "Будет подача сигнала к оперативной памяти" << endl;

		for (int i = 0; i < 30; i++)
		{
			cout << rand() % 2 << " ";
			Sleep(100);
		}

		cout << endl << "Память работает" << endl;
	}

};

class MotherBoard : public CPU_LEGAL
{
public:
	bool CPU_LEGAL = true;

	void Installed() override
	{
		cout << "Все делати установлены" << endl;
	}

	void DetailWork() override
	{
		if (CPU_LEGAL)
		{
			cout << "Включение компьютера" << endl;

			for (int i = 1; i <= 10; i++)// Цикл чтобы показать что система загружается
			{
				cout << i * 10 << "%" << " ";
				Sleep(120);
				cout << endl;
			}
			cout << "Компьютер включен" << endl;
		}
	}

	void FromTheStore() override
	{
		if (CPU_LEGAL)
		{
			cout << "Элементы системы куплены официально" << endl;
		}
	}
};

class PC
{
public:
	void Installed_detail(Detail& detail)
	{
		detail.Installed();
	}

	void DetailOnGuarantees(Detail& detail)
	{
		detail.DetailOnGuarantees();
	}

	void GoGame(Detail & detail)
	{
		detail.DetailWork();
	}

	void PrAuthentication(Bought & bought)
	{
		cout << "Идёт процедура проверки процессора" << endl;

		for (int i = 1; i <= 10; i++)
		{
			cout << "Loading..." << i * 10 << "%" << " ";
			Sleep(120);
			cout << endl;
		}

		bought.FromTheStore();
		cout << "Процедура проверки закончена" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	system("color 0A");

	CPU_LEGAL cpu_legal;
	CPU_FOR_BLACK_MARKET cpu_for_black_market;
	RAM ram;
	MotherBoard motherboard;

	PC people;

	//Тут легальный CPU
	people.GoGame(cpu_legal);
	cout << endl;
	people.Installed_detail(cpu_legal);
	people.DetailOnGuarantees(cpu_legal);
	people.PrAuthentication(cpu_legal);
	cout << endl;

	//Тут не легальный CPU
	people.GoGame(cpu_for_black_market);
	cout << endl;
	people.Installed_detail(cpu_for_black_market);
	people.PrAuthentication(cpu_for_black_market);
	cout << endl;

	//Тут RAM
	people.Installed_detail(ram);
	people.GoGame(ram);
	cout << endl;

	//Тут мат.плата
	people.GoGame(motherboard);
	cout << endl;
	people.Installed_detail(motherboard);
	people.PrAuthentication(motherboard);
	cout << endl;

	


	return 0;
}