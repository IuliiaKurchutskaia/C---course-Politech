#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "bochka.h"
using namespace std;



void Bochka::Pereliv(Bochka& barrel, double sizeOfCap)
{
	this->m_concentration = (barrel.m_concentration + this->m_size * this->m_concentration) / (this->m_size + sizeOfCap);
	this->m_size = this->m_size + sizeOfCap;
	barrel.m_size = barrel.m_size - sizeOfCap;
}