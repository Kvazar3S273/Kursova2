#include "Header.h"

void main()
{
	srand(time(NULL));
	Ukr();
	Candidate c1;
	vector<Candidate> can;
	vector<Candidate>::iterator it;


	//-----------read from file	---------
	ifstream file;
	readFile(can, file);


	//-----------out to console vector------------
	TableCap();
	double sum = 0;
	double r,rait = 0;
	int max = 0;
	for (it = can.begin(); it < can.end(); ++it)
	{
		
		/*cout << setw(2) << " ";
		cout << left << (*it).candidate;
		cout << setw(2) << " ";
		cout << left << setw(20) << (*it).party;
		cout << left << setw(10) << (*it).district;
		cout << left << setw(9) << (*it).num;
		cout << left << setw(16) << (*it).date;
		cout << left << setw(9) << (*it).rating;		
		cout << left << setw(6) << (*it).votes << endl;*/
		sum += (*it).votes;	
				
	}
	
	

	for (it = can.begin(); it < can.end(); ++it)
	{
		r = (*it).votes * 100 / sum;//find a percent of all list.
		(*it).rating = r;//assign value.
		cout << setw(2) << " ";
		cout << left << (*it).candidate;
		cout << setw(2) << " ";
		cout << left << setw(20) << (*it).party;
		cout << left << setw(10) << (*it).district;
		cout << left << setw(9) << (*it).num;
		cout << left << setw(16) << (*it).date;
		cout << left << setw(9) << fixed << setprecision(1) << (*it).rating;
		cout << left << setw(6) << (*it).votes << endl; 	
		rait += (*it).rating;//for check(must be 100%).
		if (max < (*it).votes)
			max = (*it).votes;
				
	
	}
	cout << endl;
	Color(12);
	cout << "Final sum of votes are " << fixed << setprecision(0)<< sum << endl;
	Color(10);
	cout << "Final raiting  %  " << rait << endl;
	Color(7);
	cout << "Max value of votes are: " << max << endl;
	

	//---------------search by surname(lambda func.)--------
	/*cout << "\n\nEnter surname of candidate to edit his info" << endl;
	string name;
	cin >> name;
	it = find(can.begin(), can.end(),name);
	cout << *it << endl;*/

	//--------------search by party------------
	//cout << "Enter party and you will see all candidates of this pаrty" << endl;
	//string part;
	//double suma = 0;
	//double percent = 0;
	//getline(cin,part);
	//
	//for (it = can.begin(); it != can.end(); it++) 
	//{
	//	if (_stricmp((*it).party.c_str(), part.c_str()) == 0)
	//	{		
	//				suma += (*it).votes;				
	//	}
	//	
 //   }
	//if (suma == 0)
	//{
	//	cout << "Wrong party! " << endl;
	//	_getch();
	//}
	//
	//for (it = can.begin(); it != can.end(); it++)
	//{
	//	
	//	int n =rand() % 12 ;		
	//	if (_stricmp((*it).party.c_str(), part.c_str()) == 0)
	//	{
	//		
	//		sort(can.begin(), can.end(), compare_by_surname);//in alphabetical order.			
	//		percent = (*it).votes * 100 / suma;
	//		cout << (*it).candidate << "  " << (*it).votes << "  % голосів по округу " << fixed << setprecision(2) << percent << "  ";
	//		
	//		for (int i = 0; i < percent / 2; i++)
	//		{
	//			Color(n);
	//			cout << (char)219;
	//			Color(7);
	//			
	//		}
	//		cout << endl;
	//		
	//	}
	//	
	//}
	//cout << "Sum of votes for this party is " << suma << endl;


	
	//--------------search by district------------
	//cout << "Enter district and you will see all candidates of this district" << endl;
	//int distr=0;
	//cin>>distr;
	//int sum = 0;
	//for (it = can.begin(); it != can.end(); it++)
	//{
	//	sort(can.begin(), can.end(), compare_by_surname);//in alphabetical order.
	//	if ((*it).district == distr)
	//	{			
	//		sum+=(*it).votes ;			
	//		cout << (*it).candidate;
	//		cout << endl;
	//	}		
	//}
	//cout << "Sum of votes is  " << sum << endl;

	// ------------count of results--------------
	//cout << "There are" << count_if(begin(can), end(can), [distr](const Candidate& cur)
	//	{ return cur.district == distr; })<<"res";
	//cout << endl;

	

	//-----add new candidate-----	
	//c1.Add(can);	 

	 //-------------edit candidate-------

	/* cout << "\n\nВведіть повністю прізвище кандидата з великої літери для редагування інформації по ньому" << endl;
	 string _surname;
	 cin >> _surname;

	 it = find(can.begin(), can.end(), _surname);
	 if (it == can.end())
	 {
		cout << "Такого кандидата немає в списках!" << endl;
		return;
	 }
	 cout << "Що Ви хочете редагувати?\n";
	 cout << "1 - прізвище, ім'я, по-батькові\n";
	 cout << "2 - партію\n";
	 cout << "3 - округ\n";
	 cout << "4 - номер в списку\n";
	 cout << "5 - дату реєстрації\n";
	 cout << "6 - рейтинг\n";
	 cout << "7 - кількість отриманих голосів\n";

	 int choice;
	 cin >> choice;
	 switch (choice)
	 {
	 case 1:
	 {
		 cout << "Введіть нове прізвище, ім'я, по-батькові кандидата через Ентер:\n";
		 string newsurname, newname, newpatronymic;
		 cin >> newsurname >> newname >> newpatronymic;
		 (*it).candidate.surname = newsurname;
		 (*it).candidate.name = newname;
		 (*it).candidate.patronymic = newpatronymic;
		 break;
	 }
	 case 2:
	 {
		 cout << "Введіть нову назву партії:\n";
		 string newparty;
		 cin.ignore(32767, '\n');
		 getline(cin, newparty);
		 (*it).party = newparty;
		 break;
	 }
	 case 3:
	 {
		 cout << "Введіть новий округ:\n";
		 int newdistrict;
		 cin >> newdistrict;
		 (*it).district = newdistrict;
		 break;
	 }
	 case 4:
	 {
		 cout << "Введіть новий номер у списку:\n";
		 int newnum;
		 cin >> newnum;
		 (*it).num = newnum;
		 break;
	 }
	 case 5:
	 {
		 cout << "Введіть нову дату реєстрації:\n";
		 string newdate;
		 cin >> newdate;
		 (*it).date = newdate;
		 break;
	 }
	 case 6:
	 {
		 cout << "Введіть новий рейтинг:\n";
		 int newrating;
		 cin >> newrating;
		 (*it).rating = newrating;
		 break;
	 }
	 case 7:
	 {
		 cout << "Введіть нову кількість голосів:\n";
		 int newvotes;
		 cin >> newvotes;
		 (*it).votes = newvotes;
		 break;
	 }
	 default:
		 cout << "Хибний вибір!";
		 break;
	 }*/
	// --------------------------------end of edit candidate


	

	// ---------delete to argument--------
	/*int temp = 0;
	cout << "Enter num in list for delete";
	cin >> temp;
    can.erase(remove_if(can.begin(),can.end(), [temp](const Candidate& c) { return c.num ==temp;}), end(can));*/

	//------------delete to surname----!!!!
	/*string surname;
	cout << "Enter surname for delete";
	cin >> surname;
	can.erase(remove_if(can.begin(), can.end(), [surname](const Candidate& c) 
	{ return c.candidate.surname == surname; }), end(can)); */

	
	//----------sort by district---------
	//sort(can.begin(), can.end(),// sort by district.
	//	[](const Candidate& a, const Candidate& b) -> bool
	//	{
	//		return a.district > b.district;
	//	});

	//---------sort by surname-----
	//sort(can.begin(), can.end(),compare_by_surname);
	
	//---------sort by name------
	//sort(can.begin(), can.end(),compared);

     //------sort by party(all list)-------
	
	//sort(can.begin(), can.end(),compare_by_party);

	
	//----------------save to file----------
	ofstream top("new.txt", ios_base::trunc);
	copy(can.begin(), can.end(), ostream_iterator<Candidate>(top));
	top.close();
	
	
	
}
