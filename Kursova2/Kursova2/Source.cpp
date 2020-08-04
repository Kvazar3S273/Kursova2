#include "Header.h"

void main()
{
	Ukr();
	Candidate c1;
	vector<Candidate> can;
	vector<Candidate>::iterator it;
	

	//-----------read from file	---------
	ifstream file;
    readFile(can, file);		

	//-----------out to console vector------------
	TableCap();
	for (it = can.begin(); it < can.end(); ++it)
	{
		cout << *it<< endl;
	}
	cout << endl;
	
	
	//---------------search by surname(lambda func.)--------
	//cout << "\n\nEnter district of candidate to edit his info" << endl;
	//string name;
	//cin >> name;
	//it = find(can.begin(), can.end(),name);
	//cout << (*it).candidate.name << endl;

	//-----add new candidate-----	
	//c1.Add(can);



	//-----find in vector depending argument---------	
	/* int t=0;
	 cout << "Enter argument";
	 cin >> t;	
	 for (int g = 0; g < can.size(); g++)
	 {
		 if (can[g].district == t)
			 cout << can[g].num << " " << can[g].party << " " << can[g].candidate.GetName() << " " << can[g].candidate.GetSurname() << '\n';
	 }*/

	// ------------count of results--------------
	/* cout <<"There are"<< count_if(begin(can), end(can), [](const Candidate& cur)
		 { return cur.district==11; });"  results";
	 cout << endl;*/

	 

	 //-------------edit candidate-------

	 cout << "\n\nВведіть повністю прізвище кандидата з великої літери для редагування інформації по ньому" << endl;
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
	 }
	 //--------------------------------end of edit candidate


	//----------delete candidate to position------------
	/*int pos;
	cout << "Enter position for delete";
	cin >> pos;
	can.erase(can.begin() + pos - 1);*/

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
	
	
	//out to console vector after operations.
	 cout << endl;
	TableCap();
	for (it = can.begin(); it < can.end(); ++it)
	{
		cout << *it << endl;//out to console vector.
	}
	cout << endl;


	//----------------save to file----------
	ofstream top("new.txt", ios_base::trunc);
	copy(can.begin(), can.end(), ostream_iterator<Candidate>(top));
	top.close();

	
	
}
