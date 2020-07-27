#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <vector>

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
	//Candidate(/*num,candidate,party,district,dateRegistry,rating,votes*/)
	//{
	//	//this->candidate->surname = surname;

	//}
	void CreateCandidate()
	{
		dateRegistry.SetDate(12, 10, 2020);
	}
	void ShowCandidate()
	{
		cout << "===============================================\n";
		cout << "№ п/п  " << num << endl;
		cout << "ПІБ  " << _candidate.GetSurname() << " " << _candidate.GetName() << " " << _candidate.GetPatronymic() << endl;
		cout << "Партія  " << party << endl;
		cout << "Округ  " << district << endl;
		cout << "Дата реєстрації  ";
		dateRegistry.ShowDate();
		cout << "Рейтинг  " << rating << endl;
		cout << "Віддало голосів  " << votes << endl;
	}
};