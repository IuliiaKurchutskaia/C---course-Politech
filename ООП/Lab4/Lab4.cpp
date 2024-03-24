// Темы:
// Перегрузка операторов.
// Встроенные объекты 

//#include "stdafx.h"	//если Вы используете предкомпиляцию заголовочных
					//файлов, раскомментируйте эту строчку
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include <cstdarg>

#include <algorithm>
#include <ctype.h>
#include <cctype>
#include <iostream>


#include "Base.h"
#define	  stop __asm nop

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	
	MyData data;
	const char* profession = "engineer";
	MyData dat1(MyData::Sex::MALE,22, profession ,2222);
	
	//std::cout << dat1 << std::endl;
	//Pair p1;
	//std::cout << p1 << std::endl;
	const char* surname = "Ivanov";
	Pair p2(surname, dat1);
	
	//Pair p2("Ivanov", dat1);
	//std::cout << p2 << std::endl;
	
//	MyString check = "left";
	//MyString check2 = "left";

	//bool c=(check == check2);
//	std::cout << "comporison"<<c << std::endl;

	//std::cout << check << endl;
		//Задание 1. Разработать "базу данных" о сотрудниках посредством ассоциативного
		//массива. Ключом является фамилия (ключ в задании уникален, поэтому нескольких Ивановых
		//в базе быть не может), а данными: пол, возраст, должность, зарплата...
		//Реализуйте:
		//добавление сотрудников в базу
		//исключение сотрудника из базы
		//вывод информации о конкретном сотруднике
		//вывод всей (или интересующей) информации о всех сотрудниках
		//(подсказки по реализации базы в файле "База_данных-ооп.pdf")
		//Например:
	
	Base bd1;	//создание пустой базы
	//std::cout << bd1;
			//добавляем сотрудников в базу
			bd1["Ivanov"] = MyData( MyData::Sex::MALE, 24, profession, 2222);
			bd1["Petrova"] = MyData( MyData::Sex::MALE,25, profession, 5555);
			bd1["Sidorov"] = MyData( MyData::Sex::MALE, 44, profession, 10000);
		
		
			//std::cout << bd1; //выводим информацию обо всех сотрудниках
			//std::cout << "-----------"; //
			//std::cout << bd1["Ivanov"]; //выводим информацию о сотруднике
			//std::cout << "-----------"; //
			//bd1.deletePair("Petrova"); //исключаем сотрудника
		//	std::cout << "-----------"; //
			//std::cout << bd1; //выводим информацию обо всех сотрудниках  из базы bd1

		//Задание 2. Разработайте необходимые методы для того, чтобы код,
		// приведенный ниже выполнялся корректно

		//Задание 2.1. создайте 2 копии  базы  bd1
			Base bd2 = bd1;
		//std::cout << bd2; //выводим информацию обо всех сотрудниках  из базы bd2
		Base bd3 = bd1;
		//std::cout << bd3; //выводим информацию обо всех сотрудниках  из базы bd3

		bd1.deletePair("Petrova");
		//std::cout << bd1;
		//Задание 2.2.
		//добавьте сотрудников в базу  bd2
		//std::cout << bd2; //выводим информацию обо всех сотрудниках  из базы bd2
		bd1=bd2;   //  из "большой" в "маленькую"
		//std::cout << bd2; //выводим информацию обо всех сотрудниках  из базы bd1
		bd1["lala"] = MyData(MyData::Sex::MALE, 44, profession, 10000);
		bd1["aadfghjh"] = MyData(MyData::Sex::MALE, 44, profession, 10000);
		//Задание 2.3.
		// std::cout << bd1;
		// std::cout << bd3;
	//	bd1=bd3;   //  из "маленькой"  в "большую"
	//	std::cout << bd1; //выводим информацию обо всех сотрудниках  из базы bd1


		//Задание 3. вспоминаем про семантику перемещения
		//Задание 3.1. создайте копию  базы  bd1
		Base bd4 = move(bd2);
		//std::cout << bd4; //выводим информацию обо всех сотрудниках  из базы bd4
		//std::cout << bd2; //выводим информацию обо всех сотрудниках  из базы bd2

		//Задание 3.2.
		bd3["dfghjh"] = MyData(MyData::Sex::MALE, 44, profession, 10000);
		//std::cout << bd3;
		bd3 = move(bd4);
		
	//	std::cout << bd3; //выводим информацию обо всех сотрудниках  из базы bd3
		//std::cout << bd4; //выводим информацию обо всех сотрудниках  из базы bd4
		
		//Задание 4.  Сортировка

		//Задание 4.1. Разработайте сортировку базы данных  по возрастанию ключа
		//подумайте, что надо перегрузить в классе MyString

		//Задание 4.2.Отсортируйте любую базу данных и выведите результат


			std::cout << bd1 << endl;
		bd1.Sort();
		cout << bd1 << endl;
	

	return 0;
}//endmain