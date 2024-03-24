#pragma once
using namespace std;
const int N = 5;
const int M = 2;

void print(int(*a)[M], int n);

void print_din(int**A, int n, int m);

int isLeepYear(size_t year);

size_t DayOfYear(size_t day, size_t month, size_t  year, int(*nDayTab)[12], int n);

void DayOfMonth(size_t numDay, size_t year, int(*nDayTab)[12], int n, size_t &day1, size_t &month1);
void VarArgs(int arg1, ...);
void VarArgs1(int arg1, ...);

void calc(double a, double b, char oper, double* sum, double* sub, double* del, double* mul, double* pow);
void Sort(char* pcFirst, int nNumber, int size,
	void(*SwapInt)(void*, void*), int(*CmpInt)(void*, void*));
void SortDouble(char* pcFirst, int nNumber, int size,
	void(*SwapDouble)(void*, void*),int(*CmpDouble)(void*, void*));


	int CmpInt(void* p1, void* p2);



void SwapInt(void* p1, void* p2);

void print_1(int* a, int n);
int CmpDouble(void* p1, void* p2);



void SwapDouble(void* p1, void* p2);

int CmpStr(void* p1, void* p2);

void SwapStr(void* p1, void* p2);

//-----------------------------------------------------------------------
const char* GetString1();

//-----------------------------------------------------------------------
const char* GetString2();
//-----------------------------------------------------------------------
const char* GetString3();

//-----------------------------------------------------------------------
const char* GetString4();
//-----------------------------------------------------------------------
const char* GetString5();
int* insert(int* pn, int Nn, int NN);