#include "FootballTeam/Player.h"
#include "FootballTeam/Coach.h"
#include "FootballTeam/Team.h"
#include "FootballTeam/Human.h"
// #include "LapLich/Algorithm.cpp"
#include "Match/Match.h"
#include "Match/HistoryMatch.h"
#include "Algorithm.h"
#include "CTDL/String.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>
// #include "mylib.h"
// using namespace std;
int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void printCentered(String text,int check  = 1) {
    // Lấy độ rộng của màn hình console
    int screenWidth = getConsoleWidth(); // Đặt độ rộng màn hình console của bạn tại đây

    // Tính độ dài của dòng văn bản
    int textLength = static_cast<int>(text.size());

    // Tính toán vị trí để in ra giữa màn hình
    int padding = (screenWidth - textLength) / 2;
    
   cout << screenWidth << " " << textLength << " " << padding << endl;
    // In ra khoảng trắng đầu tiên để căn giữa
    cout << right << setw(padding + textLength) << text ;
    if(check) cout << endl;
}

String drawBorder(int size) {
   String tmp = "";
   for(int i=1;i<=size;i++) {
      tmp = tmp + "-";
   }
   return tmp;
}
String drawOption(String opt,int size) {
   opt = String("|") + opt;
   String tmp = "";
   for(int i=1;i<(size-opt.size());i++) {
      tmp = tmp + " ";
   }
   opt = opt + tmp + "|";
   return opt;
}
// String drawSelectOption(String opt,int size) {
//    String tmp = "";
//    for(int i=1;i<=(size-opt.size());i++) {
//       tmp = tmp + " ";
//    }
//    return opt + tmp;
// }
void func1() {
   cout << "abc" << endl;
}
int main() {
    // Ví dụ sử dụng hàm in dòng văn bản ở giữa màn hình
   String tmp = drawBorder(50);
   String lc1 = drawOption("1. KHOI TAO GIAI DAU.",50);
   String lc2 = drawOption("2. QUAN LY GIAI DAU.",50);
   String lc3 = drawOption("0. THOAT.",50);
   String lc  = "Nhap lua chon cua ban: ";
   Coach c("123","Ngo Van D","13/10/2004","Korean","MC");
   do {
   printCentered(" ");
	cout << endl;
   printCentered("KHOI TAO GIAI DAU/Lap lich thi dau");
   printCentered(tmp);
   printCentered(lc1);
   printCentered(lc2);
   printCentered(lc3);
   printCentered(tmp);
   printCentered(lc,0);
   c.show();
   }while(0);
   getchar();
   // //  return 0;
    printCentered(drawBorder(50));
    printCentered(drawOption("1. KHOI TAO GIAI DAU.", 50));
    printCentered(drawOption("2. QUAN LY GIAI DAU.", 50));
    printCentered(drawOption("0. THOAT.", 50));
    printCentered(drawBorder(50));
    printCentered("Nhap lua chon cua ban: ", 0);
    

    return 0;
}