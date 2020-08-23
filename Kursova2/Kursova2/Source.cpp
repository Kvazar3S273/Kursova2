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

	string	parties[8] = { "Зелені дуби", "Наше майбутнє","Проти всіх","Бурштиновий рух",
							"Народний союз","Сині обличчя","Невпевненість","Багаті депутати" };

	char choice = ' ';
	char mainMenu = '1';
	while (mainMenu != '8')
	{
		char m = '1';
		while (m != 13)
		{
			if (m == '1')
			{
				Color(12); SetPos(5, 5);	cout << "* ";
			}
			else
			{
				Color(7); SetPos(5, 5); cout << "  ";
			}
			cout << "1. Показати повний список кандидатів\n";

			if (m == '2')
			{
				Color(12); SetPos(5, 6); cout << "* ";
			}
			else
			{
				Color(7); SetPos(5, 6); cout << "  ";
			}
			cout << "2. Сортування по фільтру\n";

			if (m == '3')
			{
				Color(12);	SetPos(5, 7); cout << "* ";
			}
			else
			{
				Color(7);	SetPos(5, 7); cout << "  ";
			}
			cout << "3. Пошук по фільтру\n";

			if (m == '4')
			{
				Color(12);	SetPos(5, 8); cout << "* ";
			}
			else
			{
				Color(7); SetPos(5, 8); cout << "  ";
			}
			cout << "4. Вивести переможців\n";

			if (m == '5')
			{
				Color(12);	SetPos(5, 9); cout << "* ";
			}
			else
			{
				Color(7); SetPos(5, 9); cout << "  ";
			}
			cout << "5. Редагування інформації\n";
			if (m == '6')
			{
				Color(12);	SetPos(5, 10); cout << "* ";
			}
			else
			{
				Color(7);	SetPos(5, 10); cout << "  ";
			}
			cout << "6. Видалити кандидата\n";

			if (m == '7')
			{
				Color(12);	SetPos(5, 11); cout << "* ";
			}
			else
			{
				Color(7); SetPos(5, 11); cout << "  ";
			}
			cout << "7. Додати кандидата\n";

			if (m == '8')
			{
				Color(12);	SetPos(5, 12); cout << "* ";
			}
			else
			{
				Color(7); SetPos(5, 12); cout << "  ";
			}
			cout << "8. Вихід\n";

			m = _getch();
			if (m != 13) { mainMenu = m; }
			system("cls");
			Color(7);
		}

		switch (mainMenu)
		{
		case '1':
		{
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
			Color(14);
			cout << "\n                                                             Всього голосів по всіх округах: ";
			Color(12);
			cout << sum << endl;
			Color(7);
			cout << "\n\n";
			_getch();
			break;
		}
		case '2':
		{
			choice = ' ';
			while (choice != '*')
			{
				Color(12);
				cout << "\nДля виходу з сортування натисніть (*)" << endl;
				Color(15);
				cout << "Для здійснення сортування натисніть (+)" << endl;
				Color(7);
				choice = _getch();
				if (choice == '+')
				{
					cout << "\n\tВиберіть фільтр для сортування:" << endl;
					cout << "\t(1) - по прізвищу" << endl;
					cout << "\t(2) - по партіях" << endl;
					choice = _getch();
					if (choice == '1')
					{
						//--------- sort by surname---- -
						sort(can.begin(), can.end(), compare_by_surname);

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
						Color(14);
						cout << "\n                                                             Всього голосів по всіх округах: ";
						Color(12);
						cout << sum << endl;
						Color(7);
						cout << "\n\n";
					}
					else if (choice == '2')
					{
						//--------------sort by party------------

						TableCap();

						for (int i = 0; i < 8; i++)
						{
							cout << "\n                            ----------Партія \<<" << parties[i];
							cout << "\>>----------\n" << endl;

							for (it = can.begin(); it != can.end(); it++)
							{
								sort(can.begin(), can.end(), [](const Candidate& lhs, const Candidate& rhs)
									{
										return lhs.candidate.surname < rhs.candidate.surname;
									});//in alphabetical order.		

								if (_stricmp((*it).party.c_str(), parties[i].c_str()) == 0)
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
							}
						}
					}
					else
					{
						cout << "Зробіть правильний вибір!";
					}
				}
				_getch();
				system("cls");
			}
			break;
		}
		case '3':
		{
			choice = ' ';
			while (choice != '*')
			{
				Color(12);
				cout << "\nДля виходу з пошуку натисніть (*)" << endl;
				Color(15);
				cout << "Для здійснення пошуку натисніть (+)" << endl;
				Color(7);
				choice = _getch();
				if (choice == '+')
				{
					cout << "\n\tВиберіть фільтр для пошуку:" << endl;
					cout << "\t(1) - по прізвищу" << endl;
					cout << "\t(2) - по партії" << endl;
					cout << "\t(3) - по округу\n" << endl;
					choice = _getch();
					if (choice == '1')
					{
						//---------------search by surname(lambda func.)--------
						Color(12);
						cout << "\t--------------------------------------------------------------" << endl;
						Color(15);
						cout << "\t Введіть прізвище кандидата для перегляду інформації по ньому" << endl;
						Color(12);
						cout << "\t--------------------------------------------------------------" << endl;
						Color(7);
						string name;
						cin >> name;
						//it = find(can.begin(), can.end(), name);

						for (it = can.begin(); it != can.end(); it++)
						{
							if (_stricmp((*it).candidate.surname.c_str(), name.c_str()) == 0)
							{
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
								cout << endl;
							}
						}
					}
					else if (choice == '2')
					{
						//--------------search by party------------
						cout << "\n-----------------------------------------------------------------------------------------";
						Color(14);
						cout << "\n\t\t\tСписок партій, зареєстрованих у виборах:\n" << endl;
						Color(7);
						cout << "  ";
						for (int i = 0; i < 4; i++)
						{
							cout << parties[i] << "\t\t";
						}
						cout << endl;
						cout << "  ";
						for (int i = 4; i < 8; i++)
						{
							cout << parties[i] << "\t\t";
						}
						cout << endl;
						cout << "-----------------------------------------------------------------------------------------\n\n";

						cout << endl;
						Color(12);
						cout << "\t---------------------------------------------------------------------------" << endl;
						Color(15);
						cout << "\t Введіть повну назву партії, щоб переглянути всіх кандидатів з цієї партії" << endl;
						Color(12);
						cout << "\t---------------------------------------------------------------------------" << endl;
						Color(7);
						string part;
						int suma = 0;
						getline(cin, part);

						for (it = can.begin(); it != can.end(); it++)
						{
							if (_stricmp((*it).party.c_str(), part.c_str()) == 0)
							{
								suma += (*it).votes;
							}

						}
						if (suma == 0)
						{
							cout << "Такої партії нема в списку!" << endl;
							_getch();
						}

						int col;
						cout << endl;
						TableCapParty();
						for (it = can.begin(), col = 119; it != can.end(); col += 34, it++)
						{
							sort(can.begin(), can.end(), [](const Candidate& lhs, const Candidate& rhs)
								{
									return lhs.candidate.surname < rhs.candidate.surname;
								});
							if (_stricmp((*it).party.c_str(), part.c_str()) == 0)
							{
								cout << setw(2) << " ";
								cout << left << (*it).candidate;
								cout << setw(4) << " ";
								cout << left << setw(10) << (*it).district;
								cout << left << setw(7) << (*it).num;
								cout << left << setw(16) << (*it).date;
								cout << left << setw(10) << (*it).votes;
								cout << left << setw(7) << fixed << setprecision(1) << (*it).rating << endl;
							}

						}
						cout << endl;
						Color(15);
						cout << "\t\t\t\tСума всіх голосів даної партії   ";
						Color(12);
						cout << suma << endl;
						Color(7);
					}
					else if (choice == '3')
					{
						//--------------search by district------------
						Color(12);
						cout << "\t---------------------------------------------------------------------------" << endl;
						Color(15);
						cout << "\tВведіть номер округу, щоб побачити всіх кандидатів, що по ньому балотуються" << endl;
						cout << "\t                     (доступні округи: 234..238)" << endl;
						Color(12);
						cout << "\t---------------------------------------------------------------------------" << endl;
						Color(7);
						int distr = 0;
						int s2 = 0;//find sum;
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
						for (it = can.begin(), col = 119; it != can.end(); col += 17, it++)
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
								cout << left << setw(9) << fixed << setprecision(2) << (*it).rating;
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
					}
					else
					{
						cout << "Зробіть правильний вибір!";
					}
				}
				_getch();
				system("cls");
			}
			break;
		}
		case '4':
		{
			//----------output winners--------------
			const int size_dist = 5;
			int	res[size_dist] = { 234,235,236,237,238 };
			double max[size_dist];
			Color(12);
			cout << "\----------------------------------------------------------------------" << endl;
			Color(15);
			cout << "\t\t\tПереможці виборів по округах" << endl;
			Color(12);
			cout << "\----------------------------------------------------------------------" << endl;
			Color(7);
			TableCapWinners();
			for (int i = 0; i < size_dist; i++)
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
			}
			_getch();
			break;
		}
		case '5':
		{
			//-------------edit candidate-------

			Color(12);
			cout << "\t---------------------------------------------------------------------------" << endl;
			Color(15);
			cout << "\t Введіть повністю прізвище кандидата для редагування інформації по ньому" << endl;
			Color(12);
			cout << "\t---------------------------------------------------------------------------" << endl;
			Color(7);

			string _surname;
			getline(cin, _surname);
			auto flag = 0;

			for (it = can.begin(); it != can.end(); it++)	 
															 
															
			{
				if (_stricmp((*it).candidate.surname.c_str(), _surname.c_str()) == 0)
				{
					cout << "\n\nЗнайдено по запиту:\n";
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
					cout << endl;
				}
			}

			for (it = can.begin(); it != can.end(); it++)
			{
				if (_stricmp((*it).candidate.surname.c_str(), _surname.c_str()) == 0)
				{
					flag = 1;
					Color(14);
					cout << "\n\n\t----------------------------------" << endl;
					Color(7);
					cout << "\t Що Ви хочете редагувати?\n\n";
					cout << "\t 1 - прізвище, ім'я, по-батькові\n";
					cout << "\t 2 - партію\n";
					cout << "\t 3 - округ\n";
					cout << "\t 4 - номер в списку\n";
					cout << "\t 5 - дату реєстрації\n";
					cout << "\t 6 - кількість отриманих голосів\n";
					Color(14);
					cout << "\t----------------------------------" << endl;
					Color(7);
					int choice;
					cin >> choice;
					switch (choice)
					{
					case 1:
					{
						cout << "\n\tВведіть нове прізвище, ім'я, по-батькові кандидата через Ентер:\n";
						string newsurname, newname, newpatronymic;
						cin >> newsurname >> newname >> newpatronymic;
						(*it).candidate.surname = newsurname;
						(*it).candidate.name = newname;
						(*it).candidate.patronymic = newpatronymic;
						break;
					}
					case 2:
					{
						cout << "\n\tВведіть нову назву партії:\n";
						string newparty;
						cin.ignore(32767, '\n');
						getline(cin, newparty);
						(*it).party = newparty;
						break;
					}
					case 3:
					{
						cout << "\n\tВведіть новий округ:\n";
						int newdistrict;
						cin >> newdistrict;
						(*it).district = newdistrict;
						break;
					}
					case 4:
					{
						cout << "\n\tВведіть новий номер у списку:\n";
						int newnum;
						cin >> newnum;
						(*it).num = newnum;
						break;
					}
					case 5:
					{
						cout << "\n\tВведіть нову дату реєстрації:\n";
						string newdate;
						cin >> newdate;
						(*it).date = newdate;
						break;
					}

					case 6:
					{
						cout << "\n\tВведіть нову кількість голосів:\n";
						int newvotes;
						cin >> newvotes;
						(*it).votes = newvotes;
						break;
					}
					default:
						cout << "\n\tХибний вибір!";
						break;
					}
				}
			}
			if (flag == 0)
			{
				cout << "Кандидата з таким прізвищем не існує!";
			}

			int s3 = 0;//find sum;
			double max3 = 0;//find max;
			double t3 = 0;

			for (it = can.begin(); it != can.end(); it++)
			{
				if ((*it).district == (*it).district)
				{
					s3 += (*it).votes;
				}
			}

			cout << endl;
			for (it = can.begin(); it != can.end(); it++)
			{
				sort(can.begin(), can.end(), [](const Candidate& lhs, const Candidate& rhs)
					{
						return lhs.rating > rhs.rating;
					});

				if ((*it).district == (*it).district)
				{
					(*it).rating = (double)(*it).votes * 100 / s3;
					t3 += (*it).rating;
				}
			}

			for (it = can.begin(); it != can.end(); it++)
			{
				if ((*it).district == (*it).district)
				{
					if (max3 < (*it).rating)
					{
						max3 = (*it).rating;
					}
				}
			}

			//----------------end of edit candidate-------- -
			//_getch();
			break;
		}
		case '6':
		{
			//------------delete by surname----
			string s;
			Color(12);
			cout << "\t------------------------------------------------------" << endl;
			Color(15);
			cout << "\t Введіть прізвище кандидата, якого Ви хочете видалити" << endl;
			Color(12);
			cout << "\t------------------------------------------------------" << endl;
			Color(7);
			cin >> s;
			auto flag = 0;
			for (it = can.begin(); it != can.end(); it++)
			{
				if (_stricmp((*it).candidate.surname.c_str(), s.c_str()) == 0)
				{
					s.front() = toupper(s.front());
					flag = 1;
					cout << "Видалено зі списку кандидата з наступними даними : " << endl;
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
					cout << endl;
				}
			}
			
			for (it = can.begin(); it != can.end(); it++)
			{	
				    s.front() = toupper(s.front());				   
					can.erase(remove_if(can.begin(), can.end(), [s](const Candidate& c)
						{ return c.candidate.surname ==s; }), end(can));			

			}	

			if (flag == 0)
			{
				cout << "Кандидата з таким прізвищем не існує " << endl;
			}

				
			_getch();
			break;
		}
		case '7':
		{
			//	//--------------add new candidate--------------------------------	

			Candidate c;

			Color(12);
			cout << "\n\n\t-------------------------------------------------------------" << endl;
			Color(15);
			cout << "\t Введіть через (Enter) прізвище, ім'я, по-батькові кандидата" << endl;
			Color(12);
			cout << "\t-------------------------------------------------------------" << endl;
			Color(7);
			cin >> c.candidate;

			Color(14);
			cout << "\n\n\t---------------------------------------" << endl;
			Color(7);
			cout << "\t Введіть номер, який відповідає партії\n\n";
			cout << "\t 1 - <<Наше майбутнє>>\n";
			cout << "\t 2 - <<Багаті депутати>>\n";
			cout << "\t 3 - <<Невпевненість>>\n";
			cout << "\t 4 - <<Сині обличчя>>\n";
			cout << "\t 5 - <<Народний союз>>\n";
			cout << "\t 6 - <<Бурштиновий рух>>\n";
			cout << "\t 7 - <<Зелені дуби>>\n";
			cout << "\t 8 - <<Проти всіх>>\n";
			Color(14);
			cout << "\t---------------------------------------" << endl;
			Color(7);
			int result = 0;
			cin >> result;
			switch (result)
			{
			case 1:
			{
				string newname = "Наше майбутнє"; cout << "\n\tВи вибрали партію <<Наше майбутнє>>" << endl; c.party = newname;
				break;
			}
			case 2:
			{
				string newname = "Багаті депутати"; cout << "\n\tВи вибрали партію <<Багаті депутати>>" << endl; c.party = newname;
				break;
			}
			case 3:
			{
				string newname = "Невпевненість"; cout << "\n\tВи вибрали партію <<Невпевненість>>" << endl; c.party = newname;
				break;
			}
			case 4:
			{
				string newname = "Сині обличчя"; cout << "\n\tВи вибрали партію <<Сині обличчя>>" << endl; c.party = newname;
				break;
			}
			case 5:
			{
				string newname = "Народний союз"; cout << "\n\tВи вибрали партію <<Народний союз>>" << endl; c.party = newname;
				break;
			}
			case 6:
			{
				string newname = "Бурштиновий рух"; cout << "\n\tВи вибрали партію <<Бурштиновий рух>>" << endl; c.party = newname;
				break;
			}
			case 7:
			{
				string newname = "Зелені дуби"; cout << "\n\tВи вибрали партію <<Зелені дуби>>" << endl; 	c.party = newname;
				break;
			}
			case 8:
			{
				string newname = "Проти всіх"; cout << "\n\tВи вибрали партію <<Проти всіх>>" << endl; c.party = newname;
				break;
			}
			default:
			{
				cout << "\tНеправильний вибір! ";
				break;
			}
			}

			Color(14); cout << "\n\t---------------------------------------" << endl; Color(7);
			cout << "\tВведіть округ кандидата" << endl;
			Color(14); cout << "\t---------------------------------------" << endl; Color(7);
			cin >> c.district;

			Color(14); cout << "\n\t---------------------------------------" << endl; Color(7);
			cout << "\tВведіть номер кандидата в бюлетені" << endl;
			Color(14); cout << "\t---------------------------------------" << endl; Color(7);
			cin >> c.num;

			Color(14); cout << "\n\t-----------------------------------------------------------" << endl; Color(7);
			cout << "\tВведіть дату реєстрації кандидата у вигляді ДД.ММ.РРРР" << endl;
			Color(14); cout << "\t-----------------------------------------------------------" << endl; Color(7);
			cin >> c.date;

			Color(14); cout << "\n\t---------------------------------------" << endl; Color(7);
			cout << "\tВведіть кількість голосів, відданих за кандидата" << endl;
			Color(14); cout << "\t---------------------------------------" << endl; Color(7);
			cin >> c.votes;
			can.push_back(c);


			int s1 = 0;//find sum;
			double max1 = 0;//find max;
			double t1 = 0;

			for (it = can.begin(); it != can.end(); it++)
			{
				if ((*it).district == c.district)
				{
					s1 += (*it).votes;
				}
			}

			cout << endl;
			for (it = can.begin(); it != can.end(); it++)
			{
				sort(can.begin(), can.end(), [](const Candidate& lhs, const Candidate& rhs)
					{
						return lhs.rating > rhs.rating;
					});

				if ((*it).district == c.district)
				{
					(*it).rating = (double)(*it).votes * 100 / s1;
					t1 += (*it).rating;
				}
			}

			for (it = can.begin(); it != can.end(); it++)
			{
				if ((*it).district == c.district)
				{
					if (max1 < (*it).rating)
					{
						max1 = (*it).rating;
					}
				}
			}

			//--------------end add new candidate--------------------------------	
			break;
		}
		case '8':
		{
			choice = ' ';
			while (choice != '-')
			{
				Color(12);
				cout << "\n\n\n\n\t----------------------------------" << endl;
				Color(15);
				cout << "\t   Бажаєте зберегти всі зміни?" << endl;
				Color(12);
				cout << "\t----------------------------------" << endl;
				Color(14);
				cout << "\t  (+)";
				Color(7);
				cout << " - зберегти і вийти" << endl;
				Color(14);
				cout << "\t  (-)";
				Color(7);
				cout << " - вийти без зберігання" << endl;
				Color(12);
				cout << "\t----------------------------------" << endl;
				Color(7);

				choice = _getch();
				if (choice == '+')
				{
					//----------------save to file----------
					ofstream top("new.txt", ios_base::trunc);
					copy(can.begin(), can.end(), ostream_iterator<Candidate>(top));
					top.close();
					break;
				}
			}
			break;
		}
		default:
		{
			cout << "Зробіть правильний вибір!";
			break;
		}
		}
		if (m == '8') break;
		system("cls");
	}

}