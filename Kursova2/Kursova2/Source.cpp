#include "Header.h"

void main()
{
	Ukr();
	Candidate c;
	c.CreateCandidate(14, 01, 2019, 1, "������� ����", "�����", "�������", "��������", 13, 50, 15954);
	c.ShowCandidate();

	vector<Candidate> can;
	int col = 0;
	can.push_back(c);
	cout << can[0];

}
