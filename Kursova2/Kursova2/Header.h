#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
void Ukr()	
{
	setlocale(LC_CTYPE, "ukr");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

class Person
{
private:
	string surname;
	string name;
	string patronymic;
public:
	string GetSurname()
	{
		return surname;
	}
	string GetName()
	{
		return name;
	}
	string GetPatronymic()
	{
		return patronymic;
	}
	Person(){}
	Person(string surname, string name, string patronymic)
	{
		this->surname = surname;
		this->name = name;
		this->patronymic = patronymic;
	}
	void SetPerson(string surname, string name, string patronymic)
	{
		this->surname = surname;
		this->name = name;
		this->patronymic = patronymic;
	}
};

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date() {}
	Date(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	void SetDate(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	void ShowDate()
	{
		cout << day << "-" << month << "-" << year << endl;
	}
};

class Candidate
{
private:
	int num;
	string party;
	Person _candidate;
	int district;
	int rating;
	int votes;
	Date dateRegistry;
public:
	
	void CreateCandidate(int day, int month, int year, 
						int num, string party, 
						string surname, string name, string patronymic, 
						int district, int rating, int votes)
	{
		dateRegistry.SetDate(day, month, year);
		this->num = num;
		this->party = party;
		this->district = district;
		this->rating = rating;
		this->votes = votes;
		_candidate.SetPerson(surname, name, patronymic);
	}
	void ShowCandidate()
	{
		cout << "=============================================\n";
		cout << left << setw(18) << "№ п/п" << num << endl;
		cout << left << setw(18) << "ПІБ" << _candidate.GetSurname() << " " << _candidate.GetName() << " " << _candidate.GetPatronymic() << endl;
		cout << left << setw(18) << "Партія" << party << endl;
		cout << left << setw(18) << "Округ" << district << endl;
		cout << left << setw(18) << "Дата реєстрації";
		dateRegistry.ShowDate();
		cout << left << setw(18) << "Рейтинг" << rating << endl;
		cout << left << setw(18) << "Віддало голосів" << votes << endl;
		cout << "=============================================\n";
	}
};