#include "Header.h"

void main()
{
	Ukr();
	Candidate c1;
	Candidate c2;
	Candidate c3;
	Candidate c4;
	vector<Candidate> can;
	vector<Candidate>::iterator it;

	/*c1.CreateCandidate(14, 1, 2019, 2, "Корейці України", "Кім", "Чонг", "Ха", 13, 50, 15954);
	c2.CreateCandidate(18, 10, 2018, 3, "Зануди", "Муденко", "Леонард", "Кирилович", 11, 1, 4);
	c3.CreateCandidate(18, 10, 2018, 4, "Петрики", "Лапки", "Гусячі", "Кирилович", 31, 1, 4);
	c4.CreateCandidate(20, 20, 1900, 5, "Янукович", "Віктор", "Федорович", "Лижи", 25, 22, 8);
	*/
	//read from file	
	ifstream file;
    readFile(can, file);


	/*fstream ifs("new.txt",ios_base::in);
	copy(istream_iterator<Candidate>(ifs),istream_iterator<Candidate>(),back_inserter(can));
	ifs.close();*/
	/*can.push_back(c1);
	can.push_back(c2);
	can.push_back(c3);
	can.push_back(c4);*/

	

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
	int pos;
	cout << "Enter position for delete";
	cin >> pos;
	can.erase(can.begin() + pos - 1);

	 //delete to argument
	/* can.erase(remove_if(can.begin(),can.end(), [temp](const Candidate& c) { return c.district ==temp;}), end(can));*/

	
	
	 //out to console vector after operations.
	TableCap();
	for (it = can.begin(); it < can.end(); ++it)
	{
		cout << *it << endl;//out to console vector.
	}
	cout << endl;


	//sort(can.begin(), can.end(),
	//	[](const Candidate& a, const Candidate& b) -> bool
	//	{
	//		return a.district > b.district;
	//	});

	

	//save to file
	ofstream top("new.txt", ios_base::trunc);
	copy(can.begin(), can.end(), ostream_iterator<Candidate>(top));
	top.close();

	
	
}
