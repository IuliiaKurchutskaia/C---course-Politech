#include <iostream>
using namespace std;

class a {
	double m_a;
public:
	a(double = 0);
};

class b {
	double m_b;
	a m_a;
public:
	b(double a, double b);
};

int main() {
	cout << "Size of b: " << sizeof(b) << " bytes" << endl;
	return 0;
}