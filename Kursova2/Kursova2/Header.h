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
class Candidate
{
private:
	class Person
	{
	private:
		string surname;
		string name;
		string patronymic;
	};
	class Date
	{
	private:
		int day;
		int month;
		int year;
	public:
		Date(day, month, year)
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
	int num;
	string party;
	Person candidate;
	int district;
	int rating;
	int votes;
	Date dateRegistry;
public:
	Candidate(/*num,candidate,party,district,dateRegistry,rating,votes*/)
	{
		//this->candidate->surname = surname;

	}
	void ShowCandidate()
	{
		cout << "===============================================\n";
		cout << "№ п/п  " << num << endl;
		cout << "ПІБ  " << candidate.surname << " " << candidate.name << " " << candidate.patronymic << endl;
		cout << "Партія  " << party << endl;
		cout << "Округ  " << district << endl;
		cout << "Дата реєстрації  " << dateRegistry.ShowDate() << endl;
		cout << "Рейтинг  " << rating << endl;
		cout << "Віддало голосів  " << votes << endl;
	}
};