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
	int sum = 0;
	

	for (it = can.begin(); it < can.end(); ++it)
	{
		sum += (*it).votes;
	}

	for (auto it = can.begin(); it < can.end(); ++it)
	{

		cout << setw(2) << " ";
		cout << left << (*it).candidate;
		cout << setw(2) << " ";
		cout << left << setw(20) << (*it).party;
		cout << left << setw(10) << (*it).district;
		cout << left << setw(9) << (*it).num;
		cout << left << setw(16) << (*it).date;
		cout << left << setw(9) << fixed<< setprecision(2) <<(*it).rating;
		cout << left << setw(6) << (*it).votes << endl;
		
	}
	cout << endl;
	Color(12);
	cout << "Final sum of votes are  " << sum << endl;
	Color(7);
	
	//--------------------------------------------

	//---------------search by surname(lambda func.)--------
	/*cout << "\n\nEnter surname of candidate to edit his info" << endl;
	string name;
	cin >> name;
	it = find(can.begin(), can.end(),name);

	TableCap();
	cout << setw(2) << " ";
	cout << left << (*it).candidate;
	cout << setw(2) << " ";
	cout << left << setw(20) << (*it).party;
	cout << left << setw(10) << (*it).district;
	cout << left << setw(9) << (*it).num;
	cout << left << setw(16) << (*it).date;
	cout << left << setw(9) << fixed << setprecision(1) << (*it).rating;
	cout << left << setw(6) << (*it).votes << endl;
	cout << endl;*/
	//--------------------------------------------------

	//--------------search by party------------
	//cout << "Enter party and you will see all candidates of this pаrty" << endl;
	//string part;
	//double suma = 0;	
	//getline(cin,part);
	//
	//for (it = can.begin(); it != can.end(); it++) 
	//{
	//	if (_stricmp((*it).party.c_str(), part.c_str()) == 0)
	//	{		
	//		suma += (*it).votes;
	//	}
	//	
	//   }
	//if (suma == 0)
	//{
	//	cout << "Wrong party! " << endl;
	//	_getch();
	//}
	//
	//int col;
	//
	//for (it = can.begin(), col = 119; it != can.end(); col+=34, it++)
	//{
	//	sort(can.begin(), can.end(), [](const Candidate& lhs, const Candidate& rhs)
	//	{
	//			return lhs.candidate.surname< rhs.candidate.surname;
	//	});//in alphabetical order.		
	//		if (_stricmp((*it).party.c_str(), part.c_str()) == 0)
	//		{	
	//			cout << setw(2) << " ";
	//			cout << left << (*it).candidate;
	//			cout << setw(2) << " ";
	//			cout << left << setw(10) << (*it).district;
	//			cout << left << setw(9) << (*it).num;
	//			cout << left << setw(16) << (*it).date;
	//			cout << left << setw(9) << fixed << setprecision(1) << (*it).rating;
	//			cout << left << setw(6) << (*it).votes << endl;
	//			//percent = (*it).votes * 100 / suma;
	//			//cout << (*it).candidate << "  " << (*it).votes << " "<<(*it).district;
	//			//cout << endl;
	//			//for (int i = 0; i < percent / 3; i++)
	//			//{
	//			//	Color(col);
	//			//	cout << " ";
	//			//	Color(7);
	//			//}
	//			//cout << endl;
	//		}
	//		
	//}
	//cout << endl;
	//Color(12);	
	//cout << "Sum of votes for this party is " << suma << endl;
	//Color(7);
	//-------------------------------------

	//--------------sort by party------------

	//string	parties[8] = { "Зелені дуби", "Наше майбутнє","Проти всіх","Бурштиновий рух",
	//	"Народний союз","Сині обличчя","Невпевненість","Багаті депутати" };

	//TableCap();

	//for (int i = 0; i < 8; i++)
	//{
	//	cout << "\n                            ----------Партія \<<" << parties[i];
	//	cout << "\>>----------\n" << endl;

	//	for (it = can.begin(); it != can.end(); it++)
	//	{
	//		sort(can.begin(), can.end(), [](const Candidate& lhs, const Candidate& rhs)
	//			{
	//				return lhs.candidate.surname < rhs.candidate.surname;
	//			});//in alphabetical order.		

	//		if (_stricmp((*it).party.c_str(), parties[i].c_str()) == 0)
	//		{
	//			cout << setw(2) << " ";
	//			cout << left << (*it).candidate;
	//			cout << setw(2) << " ";
	//			cout << left << setw(20) << (*it).party;
	//			cout << left << setw(10) << (*it).district;
	//			cout << left << setw(9) << (*it).num;
	//			cout << left << setw(16) << (*it).date;
	//			cout << left << setw(9) << (*it).rating;
	//			cout << left << setw(6) << (*it).votes << endl;
	//		}
	//	}
	//}

	//----------end sort by party---------------


	//--------------search by district------------
	cout << "Enter district and you will see all candidates of this district" << endl;
	int distr=0;
	double s = 0;//find sum;
	double max = 0;//find max;
	double t = 0;
	cin >> distr;
	
	for (it = can.begin(); it != can.end(); it++)
	{
		
		if ((*it).district == distr)
		{			
			s += (*it).votes;

		}
	}
	
	//TableCap();
	int col;
	
	for (it = can.begin(), col = 119; it != can.end(); col += 34, it++)
	{
		sort(can.begin(), can.end(), [](const Candidate& lhs, const Candidate& rhs)
				{
				return lhs.rating > rhs.rating;
				});	

		if ((*it).district == distr)
		{
			
			cout << setw(2) << " ";
			cout << left << (*it).candidate;
			cout << setw(2) << " ";
			cout << left << setw(20) << (*it).party;
			cout << left << setw(9) << (*it).num;
			cout << left << setw(9) <<fixed << setprecision(2) << (*it).rating;
			cout << left << setw(6) << (*it).votes << endl;
			(*it).rating = (*it).votes * 100 / s;
			t += (*it).rating;
			for (int i = 0; i < (*it).rating / 3; i++)
			{
				Color(col);
				cout << " ";
				Color(7);
			}
			cout << endl;

			
		}		
	}
	cout << endl;
	cout << " Sum of votes of this district is  " << s << endl;
	cout << t << endl;

	for (it = can.begin(); it != can.end(); it++)
	{		
		if ((*it).district == distr)
		{
			
			if (max < (*it).rating)
			{
				max = (*it).rating;
			}

		}
		if ((*it).rating == max)
		{
			cout << " The winner from this district is " << (*it).candidate << endl;
		}

	}
	//----------------------------------------


    //----------finally tabel----------
    
	// ------------count of results--------------

	//cout << "There are" << count_if(begin(can), end(can), [distr](const Candidate& cur)
	//	{ return cur.district == distr; })<<"res";
	//cout << endl;
    
	//----------output winners--------------
    /*const int size_dist=5;
   	int	res[size_dist] = {234,235,236,237,238};
	double max[size_dist] ;

	for (int i = 0; i <size_dist; i++)
	{
		cout << "-------------------Округ номер:  \<<" << res[i] << "\>>-----------------" << endl;

		for (it = can.begin(); it != can.end(); it++)
		{
			sort(can.begin(), can.end(), [](const Candidate& lhs, const Candidate& rhs)
				{
					return lhs.candidate.surname < rhs.candidate.surname;
				});
			
				if ((*it).district == res[i])
				{
					cout << (*it).candidate << " " << (*it).rating << endl;
					

					if (max[i] < (*it).rating)
					{
						max[i] = (*it).rating;

					}

				}			
				
				
		}
		
		for (it = can.begin(); it != can.end(); it++)
		{
			if ((*it).district == res[i])
			{
				if ((*it).rating == max[i])
				{
					cout << "The winner from this district is " << max[i] <<" "<<(*it).candidate<< endl;
					
				}

			}

		}		
		
		
	}*/
	//-------------------------------
	



	//-----add new candidate-----	
	//c1.Add(can);	 
	//---------------------------


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
	 //		return a.district < b.district;
	 //	});

	 //---------sort by surname-----
	 //sort(can.begin(), can.end(),compare_by_surname);


	 //-----------out to console vector------------
	 /*TableCap();

	  for (auto it = can.begin(); it < can.end(); ++it)
	 {

		 cout << setw(2) << " ";
		 cout << left << (*it).candidate;
		 cout << setw(2) << " ";
		 cout << left << setw(20) << (*it).party;
		 cout << left << setw(10) << (*it).district;
		 cout << left << setw(9) << (*it).num;
		 cout << left << setw(16) << (*it).date;
		 cout << left << setw(9) << (*it).rating;
		 cout << left << setw(6) << (*it).votes << endl;

	 }
	 cout << endl;*/
	
	 //----------------------------


	 //----------------save to file----------
	 ofstream top("new.txt", ios_base::trunc);
	 copy(can.begin(), can.end(), ostream_iterator<Candidate>(top));
	 top.close();
	 


}
