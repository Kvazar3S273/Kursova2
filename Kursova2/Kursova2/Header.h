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
void Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
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
	Person candidate;
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
		candidate.SetPerson(surname, name, patronymic);
	}
	void ShowCandidate()
	{
		cout << "=============================================\n";
		cout << left << setw(18) << "� �/�" << num << endl;
		Color(14);
		cout << left << setw(18) << "ϲ�" << candidate.GetSurname() << " " << candidate.GetName() << " " << candidate.GetPatronymic() << endl;
		Color(7);
		cout << left << setw(18) << "�����" << party << endl;
		cout << left << setw(18) << "�����" << district << endl;
		cout << left << setw(18) << "���� ���������";
		dateRegistry.ShowDate();
		cout << left << setw(18) << "�������" << rating << endl;
		cout << left << setw(18) << "³����� ������" << votes << endl;
		cout << "=============================================\n";
	}
	friend ostream& operator<< (ostream& out, const Candidate& cand);
};

ostream& operator<< (ostream& out, const Candidate& cand)
{
	//out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";

	cout << "=============================================\n";
	cout << left << setw(18) << "� �/�" << cand.num << endl;
	Color(14);
	//cout << left << setw(18) << "ϲ�" << candidate.GetSurname() << " " << candidate.GetName() << " " << candidate.GetPatronymic() << endl;
	Color(7);
	cout << left << setw(18) << "�����" << cand.party << endl;
	cout << left << setw(18) << "�����" << cand.district << endl;
	cout << left << setw(18) << "���� ���������";
	//cand.dateRegistry.ShowDate();
	cout << left << setw(18) << "�������" << cand.rating << endl;
	cout << left << setw(18) << "³����� ������" << cand.votes << endl;
	cout << "=============================================\n";


	return out;
}