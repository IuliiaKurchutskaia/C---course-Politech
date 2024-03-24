#pragma once
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS

#include <cstdarg>
#include "Base.h"
#include <iostream>
using namespace std;

Base::Base(const Base& bd)
{
	capacity = bd.count + 1;
	pBase = new Pair[capacity];
	count = bd.count;


	for (size_t i = 0; i < bd.count; ++i)
		pBase[i] = bd.pBase[i];
}

Base::Base(Base&& bd):pBase(nullptr),count(0), capacity(0)
{
	
		
		//перемещаем ресурсы из bd в текущий объект
		pBase = bd.pBase;
		count = bd.count;
		capacity = bd.capacity;
		//обнуляем ресурсы в bd

		bd.pBase = nullptr;
		bd.count = 0;
		bd.capacity = 0;

	
}     



std::ostream& operator<<(std::ostream& os, const Base &bd) {

	os << "=========== Data base =========== " << std::endl;
	for (size_t i = 0; i < bd.count; i++) {
		std::cout << "Men number " << i << std::endl << bd.pBase[i];
	}
	std::cout << "=================================" << endl;
	//std::cout << bd.pBase;
	return os;
}
//Base::Base(const Base& bd) {}


MyData& Base::operator[](const char* key) {
	//ищем сотрудника в базе
	size_t i;
	for (i = 0; i < count; i++) {
		if (pBase[i].m_key == key) // if(*pBase[i] == key)
			return pBase[i].m_data;
	}
	//если сотрудник не найден, добавляем (всегда!!!)
	if (count >= capacity) {
		//перераспределяем память
		capacity += 2;

		Pair* new_pBase = new Pair[capacity];
		for (int i = 0; i < count; i++)
		{
			new_pBase[i] = move(pBase[i]);
			//new_pBase[i].m_data = pBase[i].m_data;
			//new_pBase[i].m_key = pBase[i].m_key;// копируем во временный объект
		}


		delete[] pBase;
		pBase = new_pBase;
	}
	//добавляем сотрудника
	
	pBase[count].m_key = key;
	
	count++;
	return pBase[count - 1].m_data;
}


int Base::deletePair(const char* key) {
	size_t i;
	for (i = 0; i < count; ++i)
	{
		if (pBase[i].m_key == key)
			break;
	}

	if (i == count)
	{
		std::cout << key << " not found" << std::endl;
		return count;
	}

	for ( ; i < count; ++i)
	{
		pBase[i] = pBase[i+1];
	}

	count--;

	return count;
};

//
//
//void Base::Sort() {
//	int mid;
//	int start = 0;
//	int end = count;
//	Pair* list = pBase;
//	mergeSort(list, start, end);
//}
//void Base::mergeSort(Pair* list,  int start, int end)
//{
//	int mid;
//
//	if (start < end) {
//
//		mid = (start + end) / 2;
//		mergeSort(list, start, mid);
//		mergeSort(list, mid + 1, end);
//		merge(list, start, end, mid);
//	}
//}
//
//
//void Base::merge(Pair* list, int start, int end, int mid)
//{
//	Pair* mergedList = new Pair[count];
//	int i, j, k;
//	i = start;
//	k = start;
//	j = mid + 1;
//
//	while (i <= mid && j <= end) {
//		if (list[i].m_key < list[j].m_key) {
//			mergedList[k].m_key = list[i].m_key;
//			k++;
//			i++;
//		}
//		else {
//			mergedList[k].m_key = list[j].m_key;
//			k++;
//			j++;
//		}
//	}
//
//	while (i <= mid) {
//		mergedList[k].m_key = list[i].m_key;
//		k++;
//		i++;
//	}
//
//	while (j <= end) {
//		mergedList[k].m_key = list[j].m_key;
//		k++;
//		j++;
//	}
//
//	for (i = start; i < k; i++) {
//		list[i].m_key = mergedList[i].m_key;
//	}
//}

void Base::swap(Pair& a, Pair& b)
{
	auto temp = move(a);
	a = move(b);
	b = move(temp);
}


void Base::Sort() {
	for (size_t i = 0; i < count - 1; ++i)
	{
		for (size_t j = 0; j < count - i - 1; ++j)
		{
			if (pBase[j] > pBase[j + 1])
			{
				swap(pBase[j], pBase[j + 1]);
				//break;
				//auto const tmp = pBase[j];
				//pBase[j] = pBase[j + 1];
				//pBase[j + 1] = tmp;
			}
		}
	}
}