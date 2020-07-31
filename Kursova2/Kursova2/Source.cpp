#include "Header.h"

void main()
{
	Ukr();
	Candidate c1;
	vector<Candidate> can;
	vector<Candidate>::iterator it;


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
	/* int temp=1;
	 cout << "Enter argument";
	 cin >> temp;*/
	/*
	 it = find_if(can.begin(), can.end(), [temp](const Candidate& c) { return c.district == temp; });
	 cout << *it;//out to console*/


	//delete candidate to position
	/*int pos;
	cout << "Enter position for delete";
	cin >> pos;
	can.erase(can.begin() + pos - 1);*/

	 //delete to argument
	/* can.erase(remove_if(can.begin(),can.end(), [temp](const Candidate& c) { return c.district ==temp;}), end(can));*/

	
	
	 //out to console vector after operations.
	//TableCap();
	//for (it = can.begin(); it < can.end(); ++it)
	//{
	//	cout << *it << endl;//out to console vector.
	//}
	//cout << endl;


	//sort(can.begin(), can.end(),// sort by district.
	//	[](const Candidate& a, const Candidate& b) -> bool
	//	{
	//		return a.district > b.district;
	//	});


	//sort(can.begin(), can.end(),compare_by_surname);//sort by surname.	


	//sort(can.begin(), can.end(),compare);//sort by name.
	
	
	//out to console vector after operations.
	TableCap();
	for (it = can.begin(); it < can.end(); ++it)
	{
		cout << *it << endl;//out to console vector.
	}
	cout << endl;


	//save to file
	ofstream top("new.txt", ios_base::trunc);
	copy(can.begin(), can.end(), ostream_iterator<Candidate>(top));
	top.close();

	
	
}
