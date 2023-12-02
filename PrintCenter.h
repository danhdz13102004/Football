#ifndef PC_H
#define PC_H
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "CTDL/String.h"
using namespace std;
int getConsoleWidth();
void printCentered(String text,int check  = 1) ;
String drawBorder(int size);
String drawOption(String opt,int size);
#endif