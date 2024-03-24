#include "other.h"
#include <iostream>
#include <cstdarg>

///////////////////////////////////////////////////

//void print(int A[][M], int n) {
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; i < M; j++) {
//			std::cout << A[i] << " ,";
//		}
//		
//	}
//	std::cout << std::endl;
//}

void print(int(*a)[M], int n)
{
	// количество столбцов или элементов в каждом подмассиве

	for (int i=0; i < n; i++)
	{
		for (int j=0; j < M; j++)
		{
			std::cout << a[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}



void print_din(int** A, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << A[i][j] << " ,";
		}

		std::cout << std::endl;
	}

}

int isLeepYear(size_t year) {
	if ((year % 400) == 0 || ((year % 4) == 0 && (year % 100) != 0)) { 
		return 1;
	}
	else return 0;
	
}

size_t DayOfYear(size_t day, size_t month, size_t  year, int(*nDayTab)[12], int n) {
	size_t day_number=0;
	if (isLeepYear(year) == 0) {
	
			for (size_t j = 0; j < month - 1; j++)
			{
				day_number = day_number + nDayTab[0][j];
			

			}
			day_number = day_number + day;
			return day_number;
		
	}
	else {
		
		for (size_t i = 0; i < 1; i++) {
			for (size_t j = 0; j < month - 1; j++)
			{
				day_number = day_number + nDayTab[1][j];
			
			}
		
			day_number = day_number + day;
			
			return day_number;
		}
	}

}

void DayOfMonth(size_t numDay, size_t year, int(*nDayTab)[12], int n, size_t& day1, size_t& month1) {

	size_t yearres = isLeepYear(year);
	size_t i = 0;
	if (yearres) {
		while (nDayTab[1][i] < numDay) {
			numDay = numDay - nDayTab[1][i];
			i++;
			
		}
		month1 = i + 1;

		day1 = numDay;
	}
	else {
		while (nDayTab[0][i] < numDay) {
			numDay = numDay - nDayTab[0][i];
			i++;
			
		}
		month1 = i + 1;
		day1 = numDay;

		
	}



	
}



//Подсказка-заготовка для задания 5а
//Без использования макросов

void VarArgs(int arg1, ...)
{
	int number = 0;	//счетчик элементов
	/*Объявите указатель на int и инициализируйте его адресом
	первого аргумента*/
	int* arg = &arg1;

	while (*arg != 0) {
		cout << "arg=" << *arg << std::endl;
		*arg++;
		number++;
	};
	//Пока не достигнут конец списка:
	// а) печать значения очередного аргумента
	// б) модификация указателя (он должен указывать на
	//следующий аргумент списка)
	// в) увеличить счетчик элементов

	cout << "count number" << number << std::endl;
	std::cout << "----------" << std::endl;

	//Печать числа элементов*/

}


void VarArgs1(int arg1, ...)
{
	  va_list p;
    va_start(p, arg1);
	std::cout << arg1 << std::endl;
	int count = 1;
    while (int ar = va_arg(p, int)) {
		std::cout << "args= " << ar<<", "<< std::endl;
		count++;
    }
    std::cout << "count args="<<count << std::endl;
	std::cout << "----------" << std::endl;
    va_end(p);
	
}

double  my_sum(double a, double b) { return (a + b); };
double my_minus(double a, double b) { return a - b; };
double my_mux(double a, double b) { return a * b; };
double my_del(double a, double b) { return a / b; };
double my_pow(double a, double b) { return pow(a, b); };


void calc(double a, double b, char oper, double* sum, double* sub, double* del, double* mul, double* pow1) {
	//bool inp = 1;

	//while (inp==1) {
	//	std::cout << "Do you want caclucation? Input '1' if you want to continue " << std::endl;
	//	std::cin >> inp;
	//	//if (inp==1) {
			
	double sum1;
	double sub1;
	double mul1;
	double del1;
	double pow11;
			std::cout << "Input a,operation,b" << std::endl;
			std::cin >> a >> oper >> b;
			switch (oper)
			{
			case '+':
				
				*sum = my_sum(a,b);
				sum1 = *sum;
				std::cout << "sum = " << sum1<<"\n";
				break;
			case '-':
				*sub = my_minus(a, b);
				sub1 = *sub;
				std::cout << "sub = " << sub1 << "\n";
				break;
			case '/':
				*del = my_del(a, b);
				if (b == 0) {
					std::cout << "Error!b=0!" <<  "\n";
					break;
				}
				del1 = *del;
				std::cout << "del = " << del1 << "\n";
				break;
			case '*':
				*mul = my_mux(a, b);
				mul1 = *mul;
				std::cout << "mul = " << mul1 << "\n";
				break;
			case '^':
				*pow1 = my_pow(a, b);
				pow11 = *pow1;
				std::cout << "pow = " << pow11 << "\n";
				break;
			default:
				std::cout << "operation is undefined" << "\n";
				break;
			}
	//	}
	//	if(inp==2) {
		/*	std::cout << exit << std::endl;
			break;*/
		//}
//	}
	//std::cout << exit << std::endl;
	
}

///////////////////////////////////////////////////


//
void Sort(char* pcFirst, int nNumber, int size,
	void(*SwapInt)(void*, void*), int(*CmpInt)(void*, void*))
{
	int i;
	for (i = 1; i < nNumber; i++)
		for (int j = nNumber - 1; j >= i; j--)
		{
			char* pCurrent = pcFirst + j * size;
			char* pPrevious = pcFirst + (j - 1) * size;
			if ((*CmpInt)(pPrevious, pCurrent) > 0)//требуется
				//переставить
				(*SwapInt)(pPrevious, pCurrent);
		}
}


int CmpInt(void* pPrevious, void* pCurrent)
{
	int p1 = *(int*)pPrevious;
	int p2 = *(int*)pCurrent;
	

	if (p1 > p2) { return 1; }
	if (p1 == p2) {return 0; };
	 
	return -1;

}


void SwapInt(void* p1, void* p2)
{
	int tmp = *(int*)p1;
	*(int*)p1 = *(int*)p2;
	*(int*)p2 = tmp;
}

void print_1(int *a, int n)
{
	// количество столбцов или элементов в каждом подмассиве
	std::cout << "Massiv for sort:" << "\t";
	for (int i = 0; i < n; i++)
	{
		
			std::cout << a[i]<<", " ;
		
		
	}
	std::cout << std::endl;
}

void SortDouble(char* pcFirst, int nNumber, int size,
	void(*SwapDouble)(void*, void*), int(*CmpDouble)(void*, void*))
{
	int i;
	for (i = 1; i < nNumber; i++)
		for (int j = nNumber - 1; j >= i; j--)
		{
			char* pCurrent = pcFirst + j * size;
			char* pPrevious = pcFirst + (j - 1) * size;
			if ((*CmpDouble)(pPrevious, pCurrent) > 0)//требуется
				//переставить
				(*SwapDouble)(pPrevious, pCurrent);
		}
}
void SwapDouble(void* p1, void* p2) {
	double tmp = *(double*)p1;
	*(double*)p1 = *(double*)p2;
	*(double*)p2 = tmp;
}

int CmpDouble(void* p1, void* p2) {
	double n1 = *(double*)p1;
	double n2 = *(double*)p2;
	if (n1 > n2) {
		return 1;
	}
	if (n1 == n2) {
		return 0;
	}
	return -1;
}


int CmpStr(void* p1, void* p2) {
	char* a = *static_cast<char**>(p1);
	char* b = *static_cast<char**>(p2);
	while (*a != '\0' && *a == *b) {
		a++;
		b++;
	}
	return *a - *b;
}

void SwapStr(void* p1, void* p2) {
	char* tmp = *static_cast<char**>(p1);
	*(char**)p1 = *static_cast<char**>(p2);
	*(char**)p2 = tmp;
}



//-----------------------------------------------------------------------
const char* GetString1()
{
	return "Hello";
}
//-----------------------------------------------------------------------
const char* GetString2()
{
	return "Hello1";
	//char* str = "Book";
	//return str;
}
//-----------------------------------------------------------------------
const char* GetString3()
{
	return "Hello2";
	//char str[] = "Little";
	//return str;
}
//-----------------------------------------------------------------------
const char* GetString4()
{
	return "Hello3";
	//static char str[] = "world";
	//return str;
}
//-----------------------------------------------------------------------
const char* GetString5()
{
	return "Hello3";
	/*char* str = new char[strlen("time") + 1];
	return str;*/
}


int* insert(int* pn, int Nn, int NN)// N - количество элементов, NN - введенное пользователем значение
{
	int* temp;
	int a = 1; //проверка на дубль

	for (int i = 0; i < Nn; i++)
	{
		if (pn[i] == NN)
		{
			a = 0;
			std::cout << "error" << std::endl;
			return pn;
		}
	}
	if (a)//если не дубль
	{
		temp = new int[Nn + 1]; // создаем новый динамический массив, больше старого на один элемент
		for (int i = 0; i < Nn; i++)
		{
			temp[i] = pn[i]; // копируем во временный объект
		}
	
		temp[Nn] = NN;
		return temp;
	}
	delete[] pn;
	pn = 0;
}