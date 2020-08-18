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
#include <ctime>

 


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
public:
	string surname;
	string name;
	string patronymic;
public:
	string GetSurname()
	{
		return surname;
	}
	void SetName()
	{
		this->name= name;
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
	friend bool operator ==(const Person& a, const Person& b);
	

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

bool operator == (const Person& c, const Person& b)
{
	/*return(c.num == b);
	return(c.votes == b);
	return (c.district == b);
	return(c.rating == b);*/
	return(c == b);
}



class Candidate		//class Candidate - the main class!!!
{
public:
	int num;
	string party;
	Person candidate;
	int district;
	double rating;
	int votes;
	string date;
//public:

	
	string GetSurname()
	{
		return(candidate.GetSurname());
	}

	void Add(vector<Candidate>& can)
	{
		Candidate c;
	
		cout << "Введіть через ентер прізвище, ім'я, по-батькові кандидата" << endl;
		cin >> c.candidate;
		cout << "Введіть партію кандидата (або безробітний)" << endl;
		cin.ignore(32767, '\n');
		getline(cin, c.party);
		cout << "Введіть округ кандидата" << endl;
		cin >> c.district;
		cout << "Введіть номер кандидата в бюлетені" << endl;
		cin >> c.num;
		cout << "Введіть дату реєстрації кандидата у вигляді ДД-ММ-РРРР" << endl;
		cin >> c.date;		
		cout << "Введіть рейтинг кандидата" << endl;
		cin >> c.rating;
		cout << "Введіть кількість голосів, відданих за кандидата" << endl;
		cin >> c.votes;
		can.push_back(c);

	}
	

	friend ostream& operator<< (ostream& out, const Candidate& cand);
	friend istream& operator>> (istream& is,  Candidate& cand);
	friend bool operator == (const Candidate& c, const int& b);
	
	friend bool operator != (const Candidate& c, const int& b); 
	friend bool operator <(const Candidate& c, const Candidate& b);
	friend bool operator >(const Candidate& c, const Candidate& b);
	bool operator()(int val)const
	{
		return (val == district|| val == num|| 
			val == rating|| val == votes);		
	}	
		
	friend bool operator==(const Candidate& a, const string& b);
	friend bool operator!=(const Candidate& a, const string &b);
	
};

bool operator==(const Candidate& a, const string& b)
{
	return (a.candidate.name == b || a.candidate.patronymic == b || a.candidate.surname == b || a.date == b||a.party==b);

}

 bool operator!=(const Candidate& a, const string& b)
 {
	 return (a.candidate.name != b || a.candidate.patronymic != b || a.candidate.surname != b||
		 a.date != b || a.party != b);

 }

 bool name(Candidate a, Candidate b)//search by surname.
 {
	 return a.candidate.GetSurname() == b.candidate.GetSurname();
 }

bool operator != (const Candidate& c, const int& b)
{
	return (c.district != b);
	return(c.num != b);
	return(c.rating != b);
	return(c.votes != b);
	//return(c.num != b || c.votes != b || c.district != b || c.rating != b);
}
bool operator<(const Candidate& c,const Candidate&b)
{
	/*return (c.district < b.district);
	return(c.num < b.num);
	return(c.rating < b.rating);
	return(c.votes < b.votes);*/
	return(c.num < b.num || c.votes < b.votes || c.district < b.district || c.rating < b.rating);
}
bool operator>(const Candidate& c, const Candidate& b)
{
	//return (c.district > b.district);
	//return(c.num > b.num);
	//return(c.rating > b.rating);
	//return(c.votes > b.votes);
	return(c.num > b.num || c.votes > b.votes || c.district > b.district || c.rating > b.rating);
}


 bool operator == (const Candidate& c, const int& b)
{
	 return(c.num == b);
	 return(c.votes == b);
	 return (c.district == b);
	 return(c.rating == b);
	 //return(c.num == b || c.votes == b || c.district == b || c.rating == b);
}

 

bool compared(Candidate& a, Candidate& b) //sort by name.
{
	return a.candidate.GetName() < b.candidate.GetName();

}

bool compare_by_surname(Candidate& a, Candidate& b) //sort by surname.
{
	return a.candidate.GetSurname() < b.candidate.GetSurname();
	
}


bool compare_by_party(Candidate& a, Candidate& b) //sort by party.
{
	return a.party < b.party;
}

void readFile(vector <Candidate>& c, ifstream& file)
{
	file.open("new.txt",ios::in);
	if (!file)
	{
		cout << "File not open" << endl;
	}
	else
	{	Candidate can;

		while (file>>can.candidate)
        {
			file.ignore();
			getline(file,can.party);
			    file >> can.district,
				file >> can.num,
				file >> can.date,
				file >> can.rating,
				file >> can.votes;
			    file.get();
			
			c.push_back(can);
		}
		file.close();
	}
}




void TableCap()
{
	cout << "========================================================================================================\n";
	Color(14);
	cout << "|      Прізвище, і'мя,       |      Назва        | Округ |  Номер   |     Дата     | Рейтинг |  К-сть  |" << endl;
	cout << "|   по-батькові кандидата    |      партії       |       | в списку |  реєстрації  |    %    | голосів |" << endl;
	Color(7);
	cout << "========================================================================================================\n";

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
	 /*  
	out << setw(2) << " ";
	out << left << cand.candidate;
	out << setw(2) << " ";
	out << left << setw(20) << cand.party;
	out << left << setw(10) << cand.district;
	out << left << setw(9) << cand.num;
	out << left << setw(16) << cand.date;
	out << left << setw(9) << cand.rating;
	out << left << setw(6) << cand.votes << endl;

	return out;*/

	out << cand.candidate.surname<<endl;
	out << cand.candidate.name << endl;
	out << cand.candidate.patronymic << endl;
	out << cand.party<<endl;
	out << cand.district << endl;
	out << cand.num<<endl;
	out << cand.date<<endl;
	out << cand.rating<<endl;
	out << cand.votes << endl;

	return out;


}


  istream& operator>>(istream& is, Candidate& cand)
  {	
	  
	  is >> cand.candidate.surname>>cand.candidate.name>>cand.candidate.patronymic;
	  is >> cand.party;
	  is >> cand.district;
	  is >> cand.num;
	  is >> cand.date;
	  is >> cand.rating;
	  is >> cand.votes;
      return is;
   
  }


  

  