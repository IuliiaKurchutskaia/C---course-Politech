#include "other.h"
#include <iostream>
///////////////////////////////////////////////////


double a = 1.0;
double& ref = a;

int square(const int &x) {
	int y= x * x;
	return y;
}


int IncByValue(int x) {
	return ++x;
}

void IncByPointer(int& x) {
	 x++;
}

void IncByReference(int * p) {
(*p)++;


}


void Swap_r(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}



void Swap_r1(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void PrintArray(int ar[], int n) {
	for (int i = 0; i < n; i++)
	{

		std::cout << " '" << ar[i] << "',";
	}
	std::cout << std::endl;
}


int MinArray(int ar[], int n) {
	
	
		int el = ar[0];
		for (int i = 1; i < n; ++i)
			if (el > ar[i])
				el = ar[i] ;
		return el;
	
}


//int MyStrCmp(const char* str1, const char* str2) {
//	int i = 0;
//	while (str1[i] || str2[i]) {
//		if ((str1[i] - str2[i]) > 0) { return 1; }
//		else if ((str1[i] - str2[i]) < 0) { return -1; }
//	//	else if (str1[i] == str2[i] ||(str1[i] && str2[i])) { i++; }
//	//	return 0;
//	}
//	return 0;
//}

int MyStrCmp(const char* a, const char* b) {
	int result = 0;
	// ищем первый различающийся символ до тех пор, пока не дойдем до конца одной из строк
	// мы можем не проверять *b != '\0`, поскольку первым условием для продолжения цикла
	// является равенство *a и *b. Если *a равно *b и *a не равно '\0', значит *b тоже не равен '\0'
	while (*a == *b && *a != '\0') {
		a++;
		b++;
	}

	// если обе строки закончились, то они равны
	if (*a == '\0' && *b == '\0') {
		return 0;
	}

	// тут мы сравниваем первый различающийся символ
	if (*a > *b) {
		return 1;
	}
	else {
		return -1;
	}
}


char const *NameOfMonth(const int n) {
	if (n > 12 || n < 1) {
	
		return  "Error";
	}
	int m = n - 1;
	const char *months[] = { "Januar", "Februar", "Marz", "April",
								"Mai","Juni", "Juli","August","September", "October",
								"November", "Dezember", "Error"
							};
	//enum num  { Januar, Februar, Marz, April,
	//						Mai,Juni, Juli,August,October,
	//						November, Dezember	};


return  months[m];
	

}




int *min_elem(int * ar, int n)
{
	int * el = ar;
	for (int i = 1; i < n; ++i)
		if (*el > ar[i])
			el = ar + i;
	return el;
}