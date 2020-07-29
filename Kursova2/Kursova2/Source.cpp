#include "Header.h"

void main()
{
	Ukr();
	Candidate c1;
	Candidate c2;
	vector<Candidate> can;
	vector<Candidate>::iterator it;

	c1.CreateCandidate(14, 1, 2019, 1, "Корейці України", "Кім", "Чонг", "Ха", 13, 50, 15954);
	c2.CreateCandidate(18, 10, 2018, 2, "Зануди", "Муденко", "Леонард", "Кирилович", 11, 1, 4);

	//read from file	
	fstream ifs("sss.txt",ios_base::in);
	copy(istream_iterator<Candidate>(ifs),istream_iterator<Candidate>(),back_inserter(can));

	can.push_back(c1);
	can.push_back(c2);
	

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


	//save to file
	/*ofstream out("sss.txt", ios_base::trunc || ios_base::out);
	copy(can.begin(), can.end(), ostream_iterator<Candidate>(out));*/


}
