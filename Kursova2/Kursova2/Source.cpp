#include "Header.h"

void main()
{
	Ukr();
	Candidate c1;
	vector<Candidate> can;
	vector<Candidate>::iterator it;
	vector<Candidate>::iterator it2;

	//read from file	
	ifstream file;
    readFile(can, file);		

	//out to console vector
	TableCap();
	for (it = can.begin(); it < can.end(); ++it)
	{
		cout << *it<< endl;
	}
	cout << endl;


	//find in vector depending argument
	//==============================================================================
	 int t;
	 cout << "Enter argument";
	 cin >> t;
	
	 for (int g = 0; g < can.size(); g++)
	 {
		 if (can[g].district == t)
			 cout << can[g].num << " " << can[g].party << " " << can[g].candidate.GetName() << " " << can[g].candidate.GetSurname() << '\n';
	 }
	 //count.
	 cout << count_if(begin(can), end(can), [](const Candidate& cur)
		 { return cur.district==11; });

	 //==================================================================================================
	

	 //----------------------------edit candidate

	 cout << "\n\nEnter district of candidate to edit his info" << endl;
	 int distr;
	 cin >> distr;
	 it = find(can.begin(), can.end(), distr);
	 //cout << (*it).candidate << endl;
	 cout << "What do you want to edit?\n";
	 cout << "1 - date\n";
	 cout << "2 - rating\n";
	 cout << "3 - votes\n";
	 int choice;
	 cin >> choice;
	 switch (choice)
	 {
	 case 1:
	 {
		 cout << "Enter new date\n";
		 string newdate;
		 cin >> newdate;
		 (*it).date = newdate;
		 break;
	 }
	 case 2:
	 {
		 cout << "Enter new rating\n";
		 int newrating;
		 cin >> newrating;
		 (*it).rating = newrating;
		 break;
	 }
	 case 3:
	 {
		 cout << "Enter new votes\n";
		 int newvotes;
		 cin >> newvotes;
		 (*it).votes = newvotes;
		 break;
	 }

	 default:
		 cout << "Wrong choice!";
		 break;
	 }
	 //--------------------------------end of edit candidate


	//delete candidate to position
	/*int pos;
	cout << "Enter position for delete";
	cin >> pos;
	can.erase(can.begin() + pos - 1);*/

	 //delete to argument
	/* can.erase(remove_if(can.begin(),can.end(), [temp](const Candidate& c) { return c.district ==temp;}), end(can));*/

	
	
	 //out to console vector after operations.
	TableCap();
	for (it = can.begin(); it < can.end(); ++it)
	{
		cout << *it << endl;//out to console vector.
	}
	cout << endl;


	//sort(can.begin(), can.end(),// sort by district.
	//	[](const Candidate& a, const Candidate& b) -> bool
	//	{
	//		return a.district > b.district;
	//	});


	//sort(can.begin(), can.end(),compare_by_surname);//sort by surname.	


	//sort(can.begin(), can.end(),compare);//sort by name.
	
	
	//out to console vector after operations.
	//TableCap();
	//for (it = can.begin(); it < can.end(); ++it)
	//{
	//	cout << *it << endl;//out to console vector.
	//}
	//cout << endl;


	//save to file
	ofstream top("new.txt", ios_base::trunc);
	copy(can.begin(), can.end(), ostream_iterator<Candidate>(top));
	top.close();

	
	
}
