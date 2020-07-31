#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

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
class Person	//class of person (surname, name, patronymic)
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
	friend ostream& operator<< (ostream& out, const Person& pers);
	friend istream& operator>> (istream& is,  Person& pers);
};

ostream& operator<< (ostream& out, const Person& pers)	//overload of operator << for person
{
	string pib;
	pib = pers.surname + " " + pers.name + " " + pers.patronymic;
	out << left << setw(27) << pib;
	return out;
}

istream& operator>> (istream& is,  Person& pers)	//overload of operator >> for person
{
	is >> pers.surname >> pers.name >> pers.patronymic;
	return is;
}



class Candidate		//class Candidate - the main class!!!
{
public:
	int num;
	string party;
	Person candidate;
	int district;
	int rating;
	int votes;
	string date;
public:
	
	void Setnum()
	{
		this->num = num;
	}

	void Setdistrict()
	{
		this->district = district;
	}

	int Getdistrict()const
	{
		return district;
	}
	
	void CreateCandidate(string date,
		int num, string party,
		string surname, string name, string patronymic,
		int district, int rating, int votes)
	{
		this->date = date;
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
		cout << left << setw(18) << "№ п/п" << num << endl;
		Color(14);
		cout << left << setw(18) << "ПІБ" << candidate.GetSurname() << " " << candidate.GetName() << " " << candidate.GetPatronymic() << endl;
		Color(7);
		cout << left << setw(18) << "Партія" << party << endl;
		cout << left << setw(18) << "Округ" << district << endl;
		cout << left << setw(18) << "Дата реєстрації" << date << endl;
		cout << left << setw(18) << "Рейтинг" << rating << endl;
		cout << left << setw(18) << "Віддало голосів" << votes << endl;
		cout << "=============================================\n";
	}

	friend ostream& operator<< (ostream& out, const Candidate& cand);
	friend istream& operator>> (istream& is,  Candidate& cand);
		
	//================================================================================

	friend bool operator == (const Candidate& c,const int &b)
	 {
		return (c.district == b);		 
	 }
	friend bool operator != (const Candidate& c, const int& b)
	 {
		return (c.district != b);
	 }
	 /*bool operator()(const Candidate& c)const
	 {
		 return c.district == district;
	 }*/

	bool operator()(int val)const
	{
		return val == district;
	}

	 bool operator<(Candidate& c)const
	 {
		 return c.district < district;
	 }
	 //====================================================================================	 
};


bool compare(Candidate& a, Candidate& b) //sort by name.
{
	return a.candidate.GetName() < b.candidate.GetName();

}
bool compare_by_surname(Candidate& a, Candidate& b) //sort by surname.
{
	return a.candidate.GetSurname() < b.candidate.GetSurname();

}
bool right(int val,Candidate &c)
{
	return c.Getdistrict()==val;
}

void readFile(vector <Candidate>& c, ifstream& file)
{
	file.open("new.txt");
	for (Candidate can; file >> can;) 
	{
		c.push_back(can);
	}
	file.close();
}


void TableCap()
{
	cout << "=====================================================================================================\n";
	Color(14);
	cout << "| № п/п |  Прізвище і'мя по-батькові  |      Партія       | Округ | Дата реєстр. | Рейтинг | Голоси |" << endl;
	Color(7);
	cout << "=====================================================================================================\n";
}

   ostream& operator<< (ostream& out, const Candidate& cand)	//overload of operator << for candidate
{
	/*out << "=============================================\n";
	out << left << setw(18) << "№ п/п" << cand.num << endl;
	Color(14);
	out << left << setw(18) << "ПІБ" << cand.candidate << endl;
	Color(7);
	out << left << setw(18) << "Партія" << cand.party << endl;
	out << left << setw(18) << "Округ" << cand.district << endl;
	out << left << setw(18) << "Дата реєстрації" << cand.dateRegistry;
	out << left << setw(18) << "Рейтинг" << cand.rating << endl;
	out << left << setw(18) << "Віддало голосів" << cand.votes << endl;
	out << "=============================================\n";*/
	
	
	out << left << setw(3) << cand.num;
	out << left << cand.candidate;
	out << left << setw(17) << cand.party;
	out << left << setw(4) << cand.district;
	out << left << setw(11) << cand.date;
	out << left << setw(5) << cand.rating;
	out << left << setw(6) << cand.votes << endl;
	

	return out;
}


  istream& operator>>(istream& is, Candidate& cand)
  {
   is >> cand.num >> cand.candidate >> cand.party >> cand.district >> cand.date >> cand.rating >> cand.votes;
   return is;
  }
