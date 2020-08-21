#include "Header.h"

void main()
{
	srand(time(NULL));
	Ukr();
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
		cout << left << setw(9) << fixed << setprecision(2) << (*it).rating;
		cout << left << setw(6) << (*it).votes << endl;

	}
	/*cout << endl;
	Color(12);
	cout << "Final sum of votes are  " << sum << endl;
	Color(7);*/

	Color(14);
	cout << "\n                                                             Всього голосів по всіх округах: ";
	Color(12);
	cout << sum << endl;
	Color(7);
	cout << "\n\n";


	//--------------add new candidate--------------------------------	

	//Candidate c;

	//cout << "Введіть через ентер прізвище, ім'я, по-батькові кандидата" << endl;
	//cin >> c.candidate;
	//cout << "Введіть номер ,який відповідає партії" << endl;
	//int result = 0;
	//cout << "1 - <<Наше майбутнє >>" << endl;
	//cout << "2 - <<Багаті депутати >>" << endl;
	//cout << "3 - <<Невпевненість >>" << endl;
	//cout << "4 - <<Сині обличчя >>" << endl;
	//cout << "5 - <<Народний союз >>" << endl;
	//cout << "6 - <<Бурштиновий рух >>" << endl;
	//cout << "7 - <<Зелені дуби >>" << endl;
	//cout << "8 - <<Проти всіх >>" << endl;
	//cin >> result;
	//switch (result)
	//{
	//case 1:
	//{
	//	string newname = "Наше майбутнє"; cout << "Ви вибрали партію <<Наше майбутнє>>" << endl; c.party = newname;
	//	break;
	//}
	//case 2:
	//{
	//	string newname = "Багаті депутати"; cout << "Ви вибрали партію <<Багаті депутати>>" << endl; c.party = newname;
	//	break;
	//}
	//case 3:
	//{
	//	string newname = "Невпевненість"; cout << "Ви вибрали партію <<Невпевненість>>" << endl; c.party = newname;
	//	break;
	//}
	//case 4:
	//{
	//	string newname = "Сині обличчя"; cout << "Ви вибрали партію <<Сині обличчя>>" << endl; c.party = newname;
	//	break;
	//}
	//case 5:
	//{
	//	string newname = "Народний союз"; cout << "Ви вибрали партію <<Народний союз>>" << endl; c.party = newname;
	//	break;
	//}
	//case 6:
	//{
	//	string newname = "Бурштиновий рух"; cout << "Ви вибрали партію <<Бурштиновий рух>>" << endl; c.party = newname;
	//	break;
	//}
	//case 7:
	//{
	//	string newname = "Зелені дуби"; cout << "Ви вибрали партію <<Зелені дуби>>" << endl; 	c.party = newname;
	//	break;
	//}
	//case 8:
	//{
	//	string newname = "Проти всіх"; cout << "Ви вибрали партію <<Проти всіх>>" << endl; c.party = newname;
	//	break;
	//}
	//default:
	//{
	//	cout << " Неправильний вибір! ";
	//	break;
	//}
	//}
	//cout << "Введіть округ кандидата" << endl;
	//cin >> c.district;
	//cout << "Введіть номер кандидата в бюлетені" << endl;
	//cin >> c.num;
	//cout << "Введіть дату реєстрації кандидата у вигляді ДД.ММ.РРРР" << endl;
	//cin >> c.date;
	//cout << "Введіть кількість голосів, відданих за кандидата" << endl;
	//cin >> c.votes;
	//can.push_back(c);

	//
	//int s1 = 0;//find sum;
	//double max1 = 0;//find max;
	//double t1 = 0;

	//for (it = can.begin(); it != can.end(); it++)
	//{
	//	if ((*it).district == c.district)
	//	{
	//		s1 += (*it).votes;
	//	}
	//}
	//
	//cout << endl;
	//for (it = can.begin(); it != can.end(); it++)
	//{
	//	sort(can.begin(), can.end(), [](const Candidate& lhs, const Candidate& rhs)
	//		{
	//			return lhs.rating > rhs.rating;
	//		});

	//	if ((*it).district == c.district)
	//	{
	//		(*it).rating = (double)(*it).votes * 100 / s1;
	//		t1 += (*it).rating;
	//	}		
	//}

	//for (it = can.begin(); it != can.end(); it++)
	//{		
	//	if ((*it).district == c.district)
	//	{
	//		if (max1 < (*it).rating)
	//		{
	//			max1 = (*it).rating;
	//		}
	//	}
	//}

	//--------------end add new candidate--------------------------------	



	//---------------search by surname(lambda func.)--------
	/*cout << "\n\nВведіть прізвище кандидата для перегляду інформації по ньому" << endl;
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
	//cout << "Введіть повну назву партії, щоб переглянути всіх кандидатів з цієї партії" << endl;
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

	Color(12);
	cout << "\t---------------------------------------------------------------------------" << endl;
	Color(7);
	cout << "\tВведіть номер округу, щоб побачити всіх кандидатів, що по ньому балотуються" << endl;
	cout << "\t                     (доступні округи: 234..238)" << endl;
	Color(12);
	cout << "\t---------------------------------------------------------------------------" << endl;
	Color(7);
	int distr = 0;
	int s2= 0;//find sum;
	double max2 = 0;//find max;
	double t2 = 0;
	cin >> distr;

	try
	{
		if (distr < 234 || distr>238)
			throw "Ви вийшли за межі рекомендованого діапазону округів!";
	}
	catch (const char* exception)
	{
		cout << exception << endl;
	}

	for (it = can.begin(); it != can.end(); it++)
	{
		
		if ((*it).district == distr)
		{			
			s2 += (*it).votes;
		}
	}
	
	cout << endl;
	TableCapDistrict();
	int col;
	for (it = can.begin(), col= 119; it != can.end(); col += 17, it++)
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
			cout << left << setw(24) << (*it).party;
			cout << left << setw(9) << (*it).num;
			(*it).rating = (double)(*it).votes * 100 / s2;
			cout << left << setw(6) << (*it).votes << "\t";
			cout << left << setw(9) <<fixed << setprecision(2) << (*it).rating;
			t2 += (*it).rating;
			for (int i = 0; i < (*it).rating / 3; i++)
			{
				Color(col);
				cout << " ";
				Color(7);
			}
			cout << endl;

			
		}		
	}
	Color(14);
	cout << "                              Всього голосів по даному округу: ";
	Color(10);
	cout << s2 << endl;
	Color(7);
	

	for (it = can.begin(); it != can.end(); it++)
	{		
		if ((*it).district == distr)
		{
			
			if (max2 < (*it).rating)
			{
				max2 = (*it).rating;
			}

		}
		if ((*it).rating == max2)
		{
			cout << "\n  Переможець в даному окрузі:\t";
			Color(12);
			cout << (*it).candidate;
			Color(7);
			cout << " з результатом: ";
			Color(12);
			cout << (*it).rating << " %" << endl;
			Color(7);
		}

	}


	////----------------------------------------





	//----------output winners--------------
  /*  const int size_dist=5;
	int	res[size_dist] = {234,235,236,237,238};
	double max[size_dist];
	Color(12);
	cout << "\t\t\tПереможці виборів по округах\n" << endl;
	Color(7);
	TableCapWinners();
	for (int i = 0; i <size_dist; i++)
	{
		cout << setw(3) << "  " << res[i] << " ";
		for (it = can.begin(); it != can.end(); it++)
		{
			sort(can.begin(), can.end(), [](const Candidate& lhs, const Candidate& rhs)
				{
					return lhs.candidate.surname < rhs.candidate.surname;
				});
			if ((*it).district == res[i])
			{
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
					cout << setw(3) << " ";
					cout << (*it).candidate;
					cout << setw(3) << " ";
					cout << left << setw(22) << (*it).party;
					cout << (*it).votes << endl;
				}
			}
		}
	}*/
	//-------------------------------


	 //-------------edit candidate-------

	//cout << "\n\nВведіть повністю прізвище кандидата для редагування інформації по ньому" << endl;
	//string _surname;
	//getline(cin, _surname);
	//auto flag = 0;

	//for (it = can.begin(); it != can.end(); it++)
	//{
	//	if (_stricmp((*it).candidate.surname.c_str(), _surname.c_str()) == 0)
	//	{
	//		flag = 1;
	//		cout << "Що Ви хочете редагувати?\n";
	//		cout << "1 - прізвище, ім'я, по-батькові\n";
	//		cout << "2 - партію\n";
	//		cout << "3 - округ\n";
	//		cout << "4 - номер в списку\n";
	//		cout << "5 - дату реєстрації\n";
	//		cout << "6 - кількість отриманих голосів\n";

	//		int choice;
	//		cin >> choice;
	//		switch (choice)
	//		{
	//		case 1:
	//		{
	//			cout << "Введіть нове прізвище, ім'я, по-батькові кандидата через Ентер:\n";
	//			string newsurname, newname, newpatronymic;
	//			cin >> newsurname >> newname >> newpatronymic;
	//			(*it).candidate.surname = newsurname;
	//			(*it).candidate.name = newname;
	//			(*it).candidate.patronymic = newpatronymic;
	//			break;
	//		}
	//		case 2:
	//		{
	//			cout << "Введіть нову назву партії:\n";
	//			string newparty;
	//			cin.ignore(32767, '\n');
	//			getline(cin, newparty);
	//			(*it).party = newparty;
	//			break;
	//		}
	//		case 3:
	//		{
	//			cout << "Введіть новий округ:\n";
	//			int newdistrict;
	//			cin >> newdistrict;
	//			(*it).district = newdistrict;
	//			break;
	//		}
	//		case 4:
	//		{
	//			cout << "Введіть новий номер у списку:\n";
	//			int newnum;
	//			cin >> newnum;
	//			(*it).num = newnum;
	//			break;
	//		}
	//		case 5:
	//		{
	//			cout << "Введіть нову дату реєстрації:\n";
	//			string newdate;
	//			cin >> newdate;
	//			(*it).date = newdate;
	//			break;
	//		}

	//		case 6:
	//		{
	//			cout << "Введіть нову кількість голосів:\n";
	//			int newvotes;
	//			cin >> newvotes;
	//			(*it).votes = newvotes;
	//			break;
	//		}
	//		default:
	//			cout << "Хибний вибір!";
	//			break;

	//		}
	//	}


	//}
	//if (flag == 0)
	//{
	//	cout << "Кандидата з таким прізвищем не існує!";
	//}
	//
	//
	//int s3 = 0;//find sum;
	//double max3 = 0;//find max;
	//double t3 = 0;

	//for (it = can.begin(); it != can.end(); it++)
	//{
	//	if ((*it).district == (*it).district)
	//	{
	//		s3 += (*it).votes;
	//	}
	//}
	//
	//cout << endl;
	//for (it = can.begin(); it != can.end(); it++)
	//{
	//	sort(can.begin(), can.end(), [](const Candidate& lhs, const Candidate& rhs)
	//		{
	//			return lhs.rating > rhs.rating;
	//		});

	//	if ((*it).district == (*it).district)
	//	{
	//		(*it).rating = (double)(*it).votes * 100 / s3;
	//		t3 += (*it).rating;
	//	}		
	//}

	//for (it = can.begin(); it != can.end(); it++)
	//{		
	//	if ((*it).district == (*it).district)
	//	{
	//		if (max3 < (*it).rating)
	//		{
	//			max3 = (*it).rating;
	//		}
	//	}
	//}

	// ----------------end of edit candidate---------


	// ---------delete to argument--------
	/*int temp = 0;
	cout << "Введіть кількість голосів";
	cin >> temp;
	can.erase(remove_if(can.begin(),can.end(), [temp](const Candidate& c) { return c.votes ==temp;}), end(can));*/

	//------------delete to surname----!!!!
	/*string surname;
	cout << "Введіть прізвище кандидата, якого Ви хочете видалити \n";
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

	//for (auto it = can.begin(); it < can.end(); ++it)
	//{

	   // cout << setw(2) << " ";
	   // cout << left << (*it).candidate;
	   // cout << setw(2) << " ";
	   // cout << left << setw(20) << (*it).party;
	   // cout << left << setw(10) << (*it).district;
	   // cout << left << setw(9) << (*it).num;
	   // cout << left << setw(16) << (*it).date;
	   // cout << left << setw(9) << fixed << setprecision(2) << (*it).rating;
	   // cout << left << setw(6) << (*it).votes << endl;

	//}
	//cout << endl;



	TableCap();

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
	cout << endl;

	//----------------------------


	//----------------save to file----------
	ofstream top("new.txt", ios_base::trunc);
	copy(can.begin(), can.end(), ostream_iterator<Candidate>(top));
	top.close();



}
