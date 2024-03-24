#pragma once
#include <iostream>
using namespace std;
#include "Pair.h"

std::ostream& operator<<(std::ostream& os, const Pair& pair) {
	return  os <<  endl << pair.m_key << pair.m_data << endl;
	//return  os << "key: " << "праар";
}


bool Pair::operator == (const Pair& right) const {
    return this->m_key.GetString() == right.m_key.GetString();
}

bool Pair::operator < (const Pair& right) const {

    return this->m_key.GetString() < right.m_key.GetString();
}

bool Pair::operator > (const Pair& right) const {

    return this->m_key.GetString() > right.m_key.GetString();
}