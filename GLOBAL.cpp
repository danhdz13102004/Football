#include "FootballTeam/Player.h"
#include "FootballTeam/Coach.h"
#include "FootballTeam/Team.h"
#include "FootballTeam/Human.h"
#include "Match/Match.h"
#include "Match/HistoryMatch.h"
#include "Algorithm.h"
#include <Windows.h>
#include <iomanip>
#include "PrintCenter.h"
// #include "PrintCenter.h"
using namespace std;

int countLines(const char *filename)
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cerr << "Khong the mo file!" << endl;
		return -1;
	}

	int lineCount = 0;
	String line;
	String::getline(file, line);
	while (!file.eof())
	{
		String::getline(file, line);
		lineCount++;
	}
	file.close();
	return lineCount;
}

bool isFileEmpty(const char *filename)
{
	ifstream file(filename);
	if (!file.is_open())
	{
		cerr << "Khong the mo file!" << endl;
		return false;
	}
	file.seekg(0, ios::end);
	if (file.tellg() == 0)
	{
		file.close();
		return true;
	}
	file.close();
	return false;
}



int main()
{
	int lc;
	do
	{
		system("cls");
		const char *filename1 = "Team.txt";
		const char *filename2 = "Coach.txt";
		const char *filename3 = "Player.txt";
		const char *filename4 = "HistoryMatch.txt";
		const char *filename5 = "Schedule.txt";
		// cout << "1. KHOI TAO GIAI DAU." << endl;
		// cout << "2. QUAN LY GIAI DAU." << endl;
		// cout << "0. Thoat." << endl;
		// cout << "Xin moi nhap lua chon: ";
		printCentered("DO AN QUAN LY GIAI BONG DA");
		cout << endl;
		printCentered(drawBorder(50));
		printCentered(drawOption("1. KHOI TAO GIAI DAU.", 50));
		printCentered(drawOption("2. QUAN LY GIAI DAU.", 50));
		printCentered(drawOption("0. THOAT.", 50));
		printCentered(drawBorder(50));
		printCentered("Nhap lua chon cua ban: ", 0);
		cin >> lc;
		cin.ignore();
		if (lc == 1)
		{
			int lc1;
			do
			{
				system("cls");
				// cout << "KHOI TAO GIAI DAU" << endl
				// 	 << endl;
				// cout << "1. Them mot doi bong." << endl;
				// cout << "2. Lap lich thi dau." << endl;
				// cout << "0. Thoat." << endl;
				// cout << "Xin moi nhap lua chon: ";
				printCentered("KHOI TAO GIAI DAU");
				cout << endl;
				printCentered(drawBorder(50));
				printCentered(drawOption("1. Them mot doi bong.", 50));
				printCentered(drawOption("2. Lap lich thi dau.", 50));
				printCentered(drawOption("0. Thoat.", 50));
				printCentered(drawBorder(50));
				printCentered("Nhap lua chon cua ban: ", 0);
				cin >> lc1;
				cin.ignore();
				if (lc1 == 1)
				{
					int lc11;
					do
					{
						system("cls");
						// cout << "KHOI TAO GIAI DAU/Them mot doi bong" << endl
						// 	 << endl;
						printCentered("KHOI TAO GIAI DAU/Them mot doi bong");
						cout << endl;
						printCentered(drawBorder(50));
						printCentered(drawOption("1. Them doi bong tu ban phim.", 50));
						printCentered(drawOption("2. Them doi bong voi du lieu tu file.", 50));
						printCentered(drawOption("0. Thoat.", 50));
						printCentered(drawBorder(50));
						printCentered("Nhap lua chon cua ban: ", 0);
						// cout << "1. Them doi bong tu ban phim." << endl;
						// cout << "2. Them doi bong voi du lieu tu file." << endl;
						// cout << "0. Thoat." << endl;
						// cout << "Xin moi nhap lua chon: ";
						cin >> lc11;
						cin.ignore();
						if (lc11 == 1)
						{
							Team t;
							t.createNewFootballTeam();
							cout << "Them doi bong thanh cong!" << endl;
							cout << "Nhan Enter de tiep tuc . .";
							getchar();
						}
						else if (lc11 == 2)
						{
							system("cls");
							Team t;
							Player p;
							Coach c;
							t.addTeamFromFile();
							p.addPlayerFromFile();
							c.addCoachFromFile();
							cout << "Them doi bong thanh cong!" << endl;
							cout << "Nhan Enter de tiep tuc . .";
							getchar();
						}
					} while (lc11 != 0);
				}
				else if (lc1 == 2)
				{
					system("cls");
					if (countLines(filename1) <= 1)
					{
						cout << "KHOI TAO GIAI DAU/Lap lich thi dau" << endl
							 << endl;
						cout << "Phai co it nhat 2 doi bong de lap lich!" << endl;
						cout << "Nhan Enter de tiep tuc . . .";
						getchar();
					}
					else
					{
						func();
						cout << endl
							 << "Lap lich thi dau thanh cong!" << endl;
						Match m;
						m.getAllMatchFromFile();
						cout << "Nhan Enter de tiep tuc . . .";
						getchar();
					}
					cout << endl;
				}

			} while (lc1 != 0);
		}
		else if (lc == 2)
		{
			if (isFileEmpty(filename1))
			{
				system("cls");
				cout << "Khoi tao du lieu cho giai dau truoc khi thuc hien chuc nang nay!" << endl;
				cout << "Nhan Enter de tiep tuc ..";
				getchar();
			}
			else
			{
				int lc2;
				do
				{
					system("cls");
					// cout << "QUAN LY GIAI DAU" << endl
					// 	 << endl;
					// cout << "1. Truy van thong tin doi bong, cau thu va HLV." << endl;
					// cout << "2. Cap nhat thong tin doi bong, cau thu va HLV." << endl;
					// cout << "3. Truy van thong tin tran dau." << endl;
					// cout << "4. Cap nhat thong tin tran dau." << endl;
					// cout << "5. Truy van thong tin lich su tran dau." << endl;
					// cout << "6. Cap nhat thong tin lich su tran dau." << endl;
					// cout << "7. Tong ket giai dau." << endl;
					// cout << "0. Thoat." << endl;
					// cout << "Xin moi nhap lua chon: ";
					printCentered("QUAN LY GIAI DAU");
					cout << endl;
					printCentered(drawBorder(50));
					printCentered(drawOption("1. Truy van thong tin doi bong, cau thu va HLV.", 50));
					printCentered(drawOption("2. Cap nhat thong tin doi bong, cau thu va HLV.", 50));
					printCentered(drawOption("3. Truy van thong tin tran dau.", 50));
					printCentered(drawOption("4. Cap nhat thong tin tran dau.", 50));
					printCentered(drawOption("5. Truy van thong tin lich su tran dau.", 50));
					printCentered(drawOption("6. Cap nhat thong tin lich su tran dau.", 50));
					printCentered(drawOption("7. Tong ket giai dau.", 50));
					printCentered(drawOption("0. Thoat.", 50));
					printCentered(drawBorder(50));
					printCentered("Nhap lua chon cua ban: ", 0);
					cin >> lc2;
					cin.ignore();
					if (lc2 == 1)
					{
						int lc21;
						do
						{
							system("cls");
							// cout << "QUAN LY GIAI DAU/Truy van thong tin doi bong, cau thu va HLV" << endl
							// 	 << endl;
							// cout << "1. Truy van thong tin cua mot doi bong." << endl;
							// cout << "2. Truy van thong tin cua HLV." << endl;
							// cout << "3. Truy van thong tin cua cau thu." << endl;
							// cout << "0. Thoat." << endl;
							// cout << "Xin moi nhap lua chon: ";
							printCentered("QUAN LY GIAI DAU/Truy van thong tin doi bong, cau thu va HLV");
							cout << endl;
							printCentered(drawBorder(50));
							printCentered(drawOption("1. Truy van thong tin cua mot doi bong.", 50));
							printCentered(drawOption("2. Truy van thong tin cua HLV.", 50));
							printCentered(drawOption("3. Truy van thong tin cua cau thu.", 50));
							printCentered(drawOption("0. Thoat.", 50));
							printCentered(drawBorder(50));
							printCentered("Nhap lua chon cua ban: ", 0);
							cin >> lc21;
							cin.ignore();
							if (lc21 == 1)
							{
								system("cls");
								Team t;
								t.findTeamByName();
							}
							else if (lc21 == 2)
							{
								int lc212;
								do
								{
									system("cls");
									// cout << "QUAN LY GIAI DAU/Truy van thong tin doi bong, cau thu va HLV/Truy van thong tin cua HLV" << endl
									// 	 << endl;
									// cout << "1. Truy van thong tin HLV theo ten doi bong." << endl;
									// cout << "2. Truy van HLV theo CCCD." << endl;
									// cout << "3. Truy van HLV theo ten HLV." << endl;
									// cout << "0. Thoat." << endl;
									// cout << "Xin moi nhap lua chon: ";
									printCentered("QUAN LY GIAI DAU/Truy van thong tin doi bong, cau thu va HLV/Truy van thong tin cua HLV");
									cout << endl;
									printCentered(drawBorder(50));
									printCentered(drawOption("1. Truy van thong tin HLV theo ten doi bong.", 50));
									printCentered(drawOption("2. Truy van HLV theo CCCD.", 50));
									printCentered(drawOption("3. Truy van HLV theo ten HLV.", 50));
									printCentered(drawOption("0. Thoat.", 50));
									printCentered(drawBorder(50));
									printCentered("Nhap lua chon cua ban: ", 0);
									cin >> lc212;
									cin.ignore();
									Team t;
									if (lc212 == 1)
									{
										t.findCoachByNameFootballTeam();
									}
									else if (lc212 == 2)
									{
										t.findCoachByID();
									}
									else if (lc212 == 3)
									{
										t.findCoachByName();
									}
								} while (lc212 != 0);
							}
							else if (lc21 == 3)
							{
								int lc213;
								do
								{
									system("cls");
									// cout << "QUAN LY GIAI DAU/Truy van thong tin doi bong, cau thu va HLV/Truy van thong tin cua cau thu" << endl
									// 	 << endl;
									// cout << "1. Truy van thong tin cau thu theo ten doi bong." << endl;
									// cout << "2. Truy van cau thu theo ten cau thu." << endl;
									// cout << "3. Truy van cau thu theo CCCD cau thu." << endl;
									// cout << "0. Thoat." << endl;
									// cout << "Xin moi nhap lua chon: ";
									printCentered("QUAN LY GIAI DAU/Truy van thong tin doi bong, cau thu va HLV/Truy van thong tin cua cau thu");
									cout << endl;
									printCentered(drawBorder(50));
									printCentered(drawOption("1. Truy van thong tin cau thu theo ten doi bong.", 50));
									printCentered(drawOption("2. Truy van cau thu theo ten cau thu.", 50));
									printCentered(drawOption("3. Truy van cau thu theo CCCD cau thu.", 50));
									printCentered(drawOption("0. Thoat.", 50));
									printCentered(drawBorder(50));
									printCentered("Nhap lua chon cua ban: ", 0);
									cin >> lc213;
									cin.ignore();
									Team t;
									if (lc213 == 1)
									{
										t.findPlayerByNameFootballTeam();
									}
									else if (lc213 == 2)
									{
										t.findPlayerByName();
									}
									else if (lc213 == 3)
									{
										t.findPlayerById();
									}
								} while (lc213 != 0);
							}
						} while (lc21 != 0);
					}
					else if (lc2 == 2)
					{
						int lc22;
						do
						{
							system("cls");
							// cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV" << endl
							// 	 << endl;
							// cout << "1. Cap nhat thong tin doi bong." << endl;
							// cout << "2. Cap nhat thong tin HLV." << endl;
							// cout << "3. Cap nhat thong tin cau thu." << endl;
							// cout << "4. Xoa doi bong." << endl;
							// cout << "5. Xoa HLV." << endl;
							// cout << "6. Xoa cau thu." << endl;
							// cout << "0. Thoat. " << endl;
							// cout << "Xin moi nhap lua chon: ";
							printCentered("QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV");
							cout << endl;
							printCentered(drawBorder(50));
							printCentered(drawOption("1. Cap nhat thong tin doi bong.", 50));
							printCentered(drawOption("2. Cap nhat thong tin HLV.", 50));
							printCentered(drawOption("3. Cap nhat thong tin cau thu.", 50));
							printCentered(drawOption("4. Xoa doi bong.", 50));
							printCentered(drawOption("5. Xoa HLV.", 50));
							printCentered(drawOption("6. Xoa cau thu.", 50));
							printCentered(drawOption("0. Thoat.", 50));
							printCentered(drawBorder(50));
							printCentered("Nhap lua chon cua ban: ", 0);
							cin >> lc22;
							cin.ignore();
							if (lc22 == 1)
							{
								int lc221;
								do
								{
									system("cls");
									// cout << "QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin doi bong" << endl
									// 	 << endl;
									// cout << "1. Them cau thu vao doi bong." << endl;
									// cout << "2. Chinh sua thong tin doi bong." << endl;
									// cout << "0. Thoat." << endl;
									// cout << "Xin moi nhap lua chon: ";
									printCentered("QUAN LY GIAI DAU/Cap nhat thong tin doi bong, cau thu va HLV/Cap nhat thong tin doi bong");
									cout << endl;
									printCentered(drawBorder(50));
									printCentered(drawOption("1. Them cau thu vao doi bong.", 50));
									printCentered(drawOption("2. Chinh sua thong tin doi bong.", 50));
									printCentered(drawOption("0. Thoat.", 50));
									printCentered(drawBorder(50));
									printCentered("Nhap lua chon cua ban: ", 0);
									cin >> lc221;
									cin.ignore();
									Team t;
									if (lc221 == 1)
									{
										t.addPlayerToTeam();
									}
									else if (lc221 == 2)
									{
										t.updateTeam();
									}
								} while (lc221 != 0);
							}
							else if (lc22 == 2)
							{
								Coach c;
								c.updateCoach();
							}
							else if (lc22 == 3)
							{
								Player p;
								p.updatePlayer();
							}
							else if (lc22 == 4)
							{
								Team t;
								t.deleteTeamById();
							}
							else if (lc22 == 5)
							{
								Coach c;
								c.deleteCoachById();
							}
							else if (lc22 == 6)
							{
								Player p;
								p.deletePlayerById();
							}
						} while (lc22 != 0);
					}
					else if (lc2 == 3)
					{
						if (!isFileEmpty(filename5))
						{
							int lc23;
							Match m;
							do
							{
								system("cls");
								// cout << "QUAN LY GIAI DAU/Truy van thong tin tran dau" << endl
								// 	 << endl;
								// cout << "1. Truy van thong tin tran dau theo ID doi." << endl;
								// cout << "2. Truy van thong tin tran dau theo ngay." << endl;
								// cout << "3. Truy van thong tin tran dau theo ten 1 doi." << endl;
								// cout << "4. Truy van thong tin tran dau theo ten 2 doi." << endl;
								// cout << "5. Truy van thong tin toan bo tran dau cua mua giai." << endl;
								// cout << "0. Thoat." << endl;
								// cout << "Xin moi nhap lua chon: ";
								printCentered("QUAN LY GIAI DAU/Truy van thong tin tran dau");
								cout << endl;
								printCentered(drawBorder(60));
								printCentered(drawOption("1. Truy van thong tin tran dau theo ID doi.", 60));
								printCentered(drawOption("2. Truy van thong tin tran dau theo ngay.", 60));
								printCentered(drawOption("3. Truy van thong tin tran dau theo ten 1 doi.", 60));
								printCentered(drawOption("4. Truy van thong tin tran dau theo ten 2 doi.", 60));
								printCentered(drawOption("5. Truy van thong tin toan bo tran dau cua mua giai.", 60));
								printCentered(drawOption("0. Thoat.", 60));
								printCentered(drawBorder(60));
								printCentered("Nhap lua chon cua ban: ", 0);
								cin >> lc23;
								cin.ignore();
								if (lc23 == 1)
								{
									m.findMatchByIdTeam();
								}
								else if (lc23 == 2)
								{
									m.findMatchByDay();
								}
								else if (lc23 == 3)
								{
									m.findMatchByNameTeam();
								}
								else if (lc23 == 4)
								{
									m.findMatchByTwoNameTeam();
								}
								else if (lc23 == 5)
								{
									// system("cls");
									m.showschedule();
									cout << "Nhan Enter de tiep tuc . .";
									getchar();
								}

							} while (lc23 != 0);
						}
						else
						{
							cout << "Lap lich thi dau truoc khi su dung chuc nang nay" << endl;
							cout << "Nhan Enter de tiep tuc . .";
							getchar();
						}
					}
					else if (lc2 == 4)
					{
						if (!isFileEmpty(filename5))
						{
							int lc24;
							int dem = 0;
							do
							{
								system("cls");
								// cout << "QUAN LY GIAI DAU/Cap nhat thong tin tran dau" << endl
								// 	 << endl;
								// cout << "1. Chinh sua thong tin tran dau." << endl;
								// cout << "2. Them ket qua cho tran dau." << endl;
								// cout << "0. Thoat" << endl;
								// cout << "Xin moi nhap lua chon: ";
								printCentered("QUAN LY GIAI DAU/Cap nhat thong tin tran dau");
								cout << endl;
								printCentered(drawBorder(50));
								printCentered(drawOption("1. Chinh sua thong tin tran dau.", 50));
								printCentered(drawOption("2. Them ket qua cho tran dau.", 50));
								printCentered(drawOption("0. Thoat.", 50));
								printCentered(drawBorder(50));
								printCentered("Nhap lua chon cua ban: ", 0);
								cin >> lc24;
								cin.ignore();
								if (lc24 == 1)
								{
									Match m;
									m.updateInforOfMatch();
								}
								else if (lc24 == 2)
								{
									++dem;
									ofstream f("SavePlayer.txt", std::ios::app);
									if (dem <= 1)
										f << left << setw(10) << "IDV," << setw(10) << "ID Doi," << setw(15) << "Ten doi," << setw(10) << "ID CT," << setw(10) << "Goal" << endl;
									Match m;
									m.enterResultMatch();
								}
							} while (lc24 != 0);
						}
						else
						{
							cout << "Lap lich thi dau truoc khi su dung chuc nang nay" << endl;
							cout << "Nhan Enter de tiep tuc . .";
							getchar();
						}
					}
					else if (lc2 == 5)
					{
						if (!isFileEmpty(filename5))
						{
							int lc25;
							do
							{
								system("cls");
								// cout << "QUAN LY GIAI DAU/Truy van thong tin lich su tran dau" << endl
								// 	 << endl;
								// cout << "1. Truy van thong tin lich su tran dau theo ngay, thang, nam." << endl;
								// cout << "2. Truy van thong tin lich su tran dau theo id mot doi." << endl;
								// cout << "3. Truy van thong tin lich su tran dau theo id hai doi." << endl;
								// cout << "4. Truy van thong tin lich su tran dau theo id vong." << endl;
								// cout << "5. Truy van thong tin lich su tran dau cua toan giai dau." << endl;
								// cout << "0. Thoat." << endl;
								// cout << "Xin moi nhap lua chon: ";
								printCentered("QUAN LY GIAI DAU/Truy van thong tin lich su tran dau");
								cout << endl;
								printCentered(drawBorder(50));
								printCentered(drawOption("1. Truy van thong tin lich su tran dau theo ngay, thang, nam.", 50));
								printCentered(drawOption("2. Truy van thong tin lich su tran dau theo id mot doi.", 50));
								printCentered(drawOption("3. Truy van thong tin lich su tran dau theo id hai doi.", 50));
								printCentered(drawOption("4. Truy van thong tin lich su tran dau theo id vong.", 50));
								printCentered(drawOption("5. Truy van thong tin lich su tran dau cua toan giai dau.", 50));
								printCentered(drawOption("0. Thoat.", 50));
								printCentered(drawBorder(50));
								printCentered("Nhap lua chon cua ban: ", 0);
								cin >> lc25;
								cin.ignore();
								if (lc25 == 1)
								{
									system("cls");
									String datee;
									HistoryMatch h;
									// cout << "QUAN LY GIAI DAU/Truy van thong tin lich su tran dau/Truy van thong tin lich su tran dau theo ngay, thang, nam" << endl
									// 	 << endl;
									printCentered("QUAN LY GIAI DAU/Truy van thong tin lich su tran dau/Truy van thong tin lich su tran dau theo ngay, thang, nam");
									cout << endl;
									cout << "Lich su tran dau da dien ra nam trong cac ngay sau:" << endl;
									h.showdateHM();
									cout << endl;
									cout << "Xin moi nhap ngay, thang, nam(dd/mm/yyyy): ";
									String::getline(cin, datee);
									if (datee[1] == '/')
									{
										String tmp("0");
										datee = tmp + datee;
									}
									if (datee[4] == '/')
										datee.insert(3, "0");
									h.showHMbydate(datee);
									cout << "Nhan Enter de tiep tuc . .";
									getchar();
								}
								else if (lc25 == 2)
								{
									system("cls");
									String id1;
									// cout << "QUAN LY GIAI DAU/Truy van thong tin lich su tran dau/Truy van thong tin lich su tran dau theo id mot doi" << endl
									// 	 << endl;
									printCentered("QUAN LY GIAI DAU/Truy van thong tin lich su tran dau/Truy van thong tin lich su tran dau theo id mot doi");
									cout << endl;
									cout << "Giai dau gom cac doi bong co ID sau:" << endl;
									Team t;
									t.showIDTeam();
									cout << endl;
									cout << "Xin moi nhap ID doi: ";
									String::getline(cin, id1);
									HistoryMatch h;
									h.showHMbyidoneteam(id1);
									cout << "Nhan Enter de tiep tuc . .";
									getchar();
								}
								else if (lc25 == 3)
								{
									system("cls");
									String id1, id2;
									// cout << "QUAN LY GIAI DAU/Truy van thong tin lich su tran dau/Truy van thong tin lich su tran dau theo id hai doi" << endl
									// 	 << endl;
									printCentered("QUAN LY GIAI DAU/Truy van thong tin lich su tran dau/Truy van thong tin lich su tran dau theo id hai doi");
									cout << endl;
									cout << "Giai dau gom cac doi bong co ID sau:" << endl;
									Team t;
									t.showIDTeam();
									cout << endl;
									cout << "Xin moi nhap ID doi thu nhat: ";
									String::getline(cin, id1);
									cout << "Xin moi nhap ID doi thu hai: ";
									String::getline(cin, id2);
									HistoryMatch h;
									h.showHMbyidtwoteam(id1, id2);
									cout << "Nhan Enter de tiep tuc . .";
									getchar();
								}
								else if (lc25 == 4)
								{
									system("cls");
									String idv;
									HistoryMatch h;
									// cout << "QUAN LY GIAI DAU/Truy van thong tin lich su tran dau/Truy van thong tin lich su tran dau theo id vong" << endl
									// 	 << endl;
									printCentered("QUAN LY GIAI DAU/Truy van thong tin lich su tran dau/Truy van thong tin lich su tran dau theo id vong");
									cout << endl;
									cout << "Lich su tran dau da dien ra nam trong cac vong sau:" << endl;
									h.showidvongHM();
									cout << endl;
									cout << "Xin moi nhap ID vong: ";
									String::getline(cin, idv);
									h.showHMbyidround(idv);
									cout << "Nhan Enter de tiep tuc . .";
									getchar();
								}
								else if (lc25 == 5)
								{
									system("cls");
									HistoryMatch h;
									// cout << "QUAN LY GIAI DAU/Truy van thong tin lich su tran dau/Truy van thong tin lich su tran dau cua toan giai dau" << endl
									// 	 << endl;
									printCentered("QUAN LY GIAI DAU/Truy van thong tin lich su tran dau/Truy van thong tin lich su tran dau cua toan giai dau");
									cout << endl;
									h.showHistoryMatch();
									cout << "Nhan Enter de tiep tuc . .";
									getchar();
								}
							} while (lc25 != 0);
						}
						else
						{
							cout << "Lap lich thi dau truoc khi su dung chuc nang nay" << endl;
							cout << "Nhan Enter de tiep tuc . .";
							getchar();
						}
					}
					else if (lc2 == 6)
					{
						if (!isFileEmpty(filename5))
						{
							system("cls");
							// cout << "QUAN LY GIAI DAU/Cap nhat thong tin lich su tran dau" << endl
							// 	 << endl;
							printCentered("QUAN LY GIAI DAU/Cap nhat thong tin lich su tran dau");
							cout << endl;
							HistoryMatch h;
							h.updateHistoryMatch();
							cout << "Nhan Enter de tiep tuc . .";
							getchar();
						}
						else
						{
							cout << "Lap lich thi dau truoc khi su dung chuc nang nay" << endl;
							cout << "Nhan Enter de tiep tuc . .";
							getchar();
						}
					}
					else if (lc2 == 7)
					{
						if (!isFileEmpty(filename5))
						{
							system("cls");
							printCentered("QUAN LY GIAI DAU/Tong ket giai dau");
							cout << endl;
							Team doi;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
							cout << "Bang xep hang cua giai dau: " << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							doi.showTeam();
							cout << "===========================================================================================================================================================================" << endl;
							int line1 = countLines(filename4);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
							cout << "Tong so tran dau da dien ra la: " << line1 << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							HistoryMatch lsd;
							lsd.showHistoryMatch();
							cout << "===========================================================================================================================================================================" << endl;
							int line2 = countLines(filename1);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
							cout << "Tong so doi bong tham gia giai dau la: " << line2 << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							doi.showTeam();
							cout << "===========================================================================================================================================================================" << endl;
							Player ct;
							int line3 = countLines(filename3);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
							cout << "Tong so cau thu tham gia giai dau la: " << line3 << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							ct.showPlayer();
							cout << "===========================================================================================================================================================================" << endl;
							Coach hlv;
							int line4 = countLines(filename2);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
							cout << "Tong so HLV cua giai dau la: " << line4 << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							hlv.showCoach();
							cout << "===========================================================================================================================================================================" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
							cout << "Doi bong vo dich cua mua giai: " << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							doi.showchampion();
							cout << "===========================================================================================================================================================================" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
							cout << "Vua pha luoi cua mua giai: " << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
							ct.showKing();
							cout << "Nhan Enter de tiep tuc . . ";
							getchar();
						}
						else
						{
							cout << "Lap lich thi dau truoc khi su dung chuc nang nay" << endl;
							cout << "Nhan Enter de tiep tuc . .";
							getchar();
						}
					}
				} while (lc2 != 0);
			}
		}
	} while (lc != 0);
}
