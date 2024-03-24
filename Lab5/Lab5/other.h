//Прототипы используемых в данном задании функций:


//double a;
extern double& ref;

int square(const int &x);

int IncByValue(int x);

void IncByPointer(int& x);

void IncByReference(int* p);

void Swap_r(int* a, int* b);

void Swap_r1(int& a, int& b);


void PrintArray(int ar[], int n);

int MinArray(int ar[], int n);


int MyStrCmp(const char* str1, const char* str2);

char const *NameOfMonth(const int n);



int* min_elem(int* ar, int n);
