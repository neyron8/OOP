#pragma once

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>


using namespace std;

static int change_count = 0;

template <typename T>
class Father
{
protected:
	int num;
	T points;
	string nick;
	string race;
	T rating;
	T argument;

public:
	Father();
	Father(int n,T point, string nickname, string race_pl, T rat, T argum);
	virtual ~Father() {};
	virtual void show() = 0;
	virtual void show_type() = 0;
	virtual void print_assistance() = 0;
};

template <typename T>
class Nick : public Father<T>
{

public:
	Nick();
	Nick(int n,T point, string nickname, string race_pl, T rat, T argum);
	void print_assistance();
	void show_type();
	void set_Nick();
	void show();
	~Nick();
};

template <typename T>
class Points : public Nick<T>
{

public:
	Points();
	Points(int n ,T point, string nickname, string race_pl, T rat, T argum);
	void set_Points();
	void print_assistance();
	void show_type();
	void show();
	~Points();
};

template <typename T>
class Base : public Points<T>
{
protected:
	Father<T>* nick1;
	Father<T>* points1;
	vector<Base> date_base; // Нужно для добавления в базу данных. Нужно изменить функцию добавления в базу данных и редактирования полей
public:
	void set_race();
	Base();
	Base(int n,T point, string nickname, string race_pl, T rat, T argum);
	Base(T argument);
	void set();
	void show();
	void add();
	void menu();
	void show_vec();
	void rating_score();
	void check_cin();
	void print_help();
	void exit_to_OS();
	void clear_screen();
	void delete_base();
	void delete_from_base(int num);
	void red_base(int num);
	void changes();
	~Base();
};

/*
	Father
*/

template <typename T>
Father<T> :: Father() : num(0),
						points(0),
						nick("No_name"),
						race("Unknown"),
						rating(0),
						argument(0) {}

template <typename T>
Father<T> :: Father(int n,T point, string nickname, string race_pl, T rat, T argum)
					  : points(point),
						nick(nickname),
						race(race_pl),
						rating(rat),
						argument(argum),
						num(n){}

/*
	Nick
*/

template <typename T>
Nick<T>::Nick(int n,T point, string nickname, string race_pl, T rat, T argum):

	Father<T>(n,point,nickname, race_pl, rat, argum) {}

template <typename T>
Nick<T>::Nick() : Father<T>() {}

template <typename T>
void Nick<T>::show_type()
{	
	cout << setw(17);
	cout << "Nickname" << '\t';
}

template <typename T>
void Nick<T>::print_assistance()
{
	cout << "Enter Nick:" << endl;
}

template <typename T>
void Nick<T>::set_Nick()
{
	getline(cin, this->nick);
}

template <typename T>
void Nick<T>::show()
{
	cout << this->nick << endl;
}

template <typename T>
Nick<T>::~Nick() {}


/*
	Points
*/

template <typename T>
void Points<T>::set_Points()
{
	while (1)
	{
		if (!Isright(&this->points))
			continue;
		else {
			return;
		}
	}
}

template <typename T>
Points<T>::Points(int n,T point, string nickname, string race_pl, T rat, T argum) :

	Nick<T>(n,point, nickname, race_pl, rat, argum){}

template <typename T>
Points<T>::Points() : Nick<T>()
{
}

template <typename T>
Points<T>::~Points()
{
}

template <typename T>
void Points<T>::print_assistance()
{
	cout << "Enter points of person:" << endl;
}

template <typename T>
void Points<T>::show_type()
{
	cout << setw(10);
	cout << "Points";
}

template <typename T>
void Points<T>::show()
{
	cout << this->points << endl;
}

/*
	Base
*/

template <typename T>
Base<T>::Base() : Points<T>()
{
	nick1 = new Nick<T>();
	points1 = new Points<T>();
}

template <typename T>
Base<T>::Base(int n,T point, string nickname, string race_pl, T rat, T argum) : Points<T>()
{
	nick1 = new Nick<T>();
	points1 = new Points<T>();
}

template <typename T>
Base<T>::Base(T argument)
{
	nick1 = new Nick<T>();
	this->argument = argument;
	points1 = new Points<T>();
}

template <typename T>
Base<T>::~Base() {}

template <typename T>
void Base<T>::set()
{
	nick1->print_assistance();
	this->set_Nick();
	points1->print_assistance();
	this->set_Points();
	this->rating_score();
	this->set_race();
}


template <typename T>
void Base<T>::show()
{
	cout << setw(15);
	cout << this->nick << '\t';
	cout << setw(10);
	cout << this->points << '\t';
	cout << setw(10);
	cout << this->rating << '\t';
	cout << setw(10);
	cout << this->race << '\t';
}

template <typename T>
void Base<T>::add()
{
	Base *base = new Base<T>(3);
	
	base->set();
	
	date_base.push_back(*base);
	change_count++;
}

template <typename T>
void Base<T>::show_vec()
{
	cout << "№";
	nick1->show_type();
	points1->show_type();
	cout << setw(16);
	cout << "Experience";
	cout << setw(16);
	cout << "Race" << endl;
	int i = 0; 
	for (;i < date_base.size(); i++ )
	{
		cout << i + 1 << ". ";
		date_base[i].show();
		cout << endl;
	}
}

template<typename T>
void Base<T>::rating_score()
{
	this->rating = this->points / this->argument;
}

template<typename T>
void Base<T>::clear_screen()
{
	system("cls");
}

template<typename T>
void Base<T>::exit_to_OS()
{
	exit(EXIT_FAILURE);
}

template<typename T>
void Base<T>::print_help()
{
	cout << " МЕНЮ:\n";
	cout << "  1.Добавить запись в базу данных\n";
	cout << "  2.Просмотр всей БД\n";
	cout << "  3.Редактирование данных:\n";
	cout << "    31.очистить БД\n";
	cout << "    32.удалить запись\n";
	cout << "    33.редактировать строку\n";
	cout << "  4.Очистить экран\n";
	cout << "  5.Выход\n";
	cout << "  6.Показать количество изменений в базе данных\n\n";
}

template<typename T>
void Base<T>::delete_base()
{
	date_base.erase(date_base.begin(), date_base.end());
}

template<typename T>
void Base<T>::delete_from_base(int num)
{
	if (num <= 0 || (num - 1) > date_base.size() || date_base.size() == 0) {
		cout << "Ничего не найдено" << endl;
		return;
	}
	date_base.erase(date_base.begin() + (num - 1));
	cout << "Номер " << num << " удален"  << endl;
	change_count++;
}

template<typename T>
void Base<T>::red_base(int num)
{
	if (num <= 0 || (num - 1) > date_base.size() || date_base.size() == 0) {
		cout << "Ничего не найдено" << endl;
		return;
	}
	date_base[num - 1].set();
	cout << "Номер " << num << " изменён" << endl;
	change_count++;
}

template<typename T>
void Base<T>::changes()
{
	cout <<"Всего изменений в базе: " << change_count << endl;
}


template<typename T>
void Base<T>::check_cin()
{
	int c,k;
	while (1)
	{
		if (!Isright(&c))
			continue;
		else {
			switch (c)
			{
			case 1:
				clear_screen();
				add();
				clear_screen();
				menu();
				break;
			case 2:
				clear_screen();
				show_vec();
				menu();
				break;
			case 31:
				clear_screen();
				delete_base();
				cout << "База очищена" << endl;
				menu();
				break;
			case 32:
				clear_screen();
				cout << "Введите номер строки: ";
				while (1)
				{
					if (!Isright(&k))
						continue;
					else
						break;
				}
				delete_from_base(k);
				menu();
				break;
			case 33:
				clear_screen();
				cout << "Введите номер строки: ";
				while (1)
				{
					if (!Isright(&k))
						continue;
					else
						break;
				}
				red_base(k);
				menu();
				break;
			case 4:
				clear_screen();
				menu();
				break;
			case 5:
				exit_to_OS();
				break;
			case 6:
				clear_screen();
				changes();
				menu();
				break;
			default:
				cout << "NOO!!!" << endl;
				clear_screen();
				menu();
			}
		}

	}
}

template<typename T>
void Base<T>::menu()
{
	print_help();

	check_cin();

}

bool Isright(int* num)
{
	cin >> *num;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Wrong value" << endl;
		return false;
	}
	else {
		return true;
	}
}

template <typename T>
void Base<T>:: set_race()
{
	cout << "Enter race of character" << endl;
	getline(cin,this->race);
}
