#pragma once
#include "Pair.h"
#include <iostream>

class Base {
	Pair* pBase = nullptr;; //������ ���
	size_t count=0; //���������� ��������� � ����
	size_t capacity=10; //������� ����
public:
	//���������, ��� �� ������������� ���� ������ ���� �������������
	Base() {

		pBase = new Pair[capacity];
	};
	~Base() {
		delete[] pBase;
	};

	
	Base(const Base& bd);

	Base& operator=(const Base& bd) {
		
			//delete[] pBase;
		if (this != &bd) {
			if (capacity < bd.count) {
				delete[] pBase;
				capacity = bd.count + 1;
				pBase = new Pair[capacity];
			}
				count = bd.count;

				for (size_t i = 0; i < bd.count; ++i)
					pBase[i] = bd.pBase[i];
			
		}
		return  *this;
	};
	
	 //����������������!!!
	Base(Base&& bd);   

	Base& operator=(Base&& bd) {
		if (count != 0)
			delete[] pBase;
		pBase = bd.pBase;
		bd.pBase = nullptr;
		count = bd.count;
		capacity = bd.capacity;

		

		return  *this;
	}
	//��������� �� ����
	MyData& operator[](const char* key);//����� ������
	int deletePair(const char* key);
	friend std::ostream& operator<<(std::ostream& os, const Base& bd);
	//������ �� ??� ������� ������
		//��� �����-���� ������� �� �������
	friend std::ostream& operator<<(std::ostream& os, const Base& bd);

	//void mergeSort(Pair* list, int start, int end);
	//void Sort();
	//void merge(Pair* list, int start, int end, int mid);


	void swap(Pair& a, Pair& b);


	void Sort();



};


