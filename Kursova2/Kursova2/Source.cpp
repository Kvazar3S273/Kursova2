#include "Header.h"

void main()
{
	Ukr();
	Candidate c1;
	Candidate c2;

	c1.CreateCandidate(14, 1, 2019, 1, "Корейці України", "Кім", "Чонг", "Ха", 13, 50, 15954);
	c2.CreateCandidate(18, 10, 2018, 2, "Зануди", "Муденко", "Леонард", "Савович", 11, 1, 4);

	//c.ShowCandidate();

	vector<Candidate> can;
	int col = 0;
	can.push_back(c1);
	can.push_back(c2);

	TableCap();
	cout << can[0];
	cout << can[1];

}
