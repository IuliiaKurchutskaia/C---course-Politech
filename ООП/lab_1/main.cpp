#include "myRect.h"
#include "myString.h"
#include <iostream>

#define stop __asm nop

int main()
{
using namespace std;
/*
	//������� 1.���������� ������. �������� ���������� ������.
	//����� ������� ������. 
	//�������� �������� Class View - (����� �� ������� ����� ������� �
	//������ - ������� Rect � MyString)
	//�������� �������� �� ����������� ����� �� ���� ������ ������ - ���
	//���������� ������������ ������� � ������� ����� ������.

	//����� ����������� ���������� ��� �������� ���������� ������?
	{
		Rect rect;
		stop
	}

	//1a. �������� � ���������� ����������� � ����������� ���
	//������������� ���������� ������. �������� ��������� ������ Rect
	//� ������� ������������ � �����������. ���� ���������� ������
	//������ � ���������� ���������, ��������� - ���� ��� ��
	//�������? ��������� ���������� ������.
	//�������� ������� � ������ ������ �� �����, ����������:
	//� ����� ������ ���������� ����� ������������(������?)?

	//���������*: ������ ���� �� ������ ��� ����, ��� �������������
	//����� ��������� "�����������������", �� ���� m_left>m_right ���/�
	//m_top>m_bottom
	//���������: ������, ��� ������������ ������ ������ ����� ���������
	//� �������� ���������� ����� ��������! ��������:
	
	// Rect rrr(4,3,2,1);
	

	stop
	//1�. ��� ��������������� ������� ����������� ������������ ��� ����������
	//������������� ������������� ���������� ������, ��������, �����

	
	
	stop
	//1�. ��������, ���������� � �������� ����� ������ InflateRect(), 
	//������� ����������� ������� �������������� �� �������� ����������
	//(��������� ������� �� ������ - ������ ������� �� ���� ��������).
	//���������: �������� � ���������� ������ ����� �� ������ "�������",
	//�� � � ������� Wizard-a Class View. ��� �����: �������� ��������
	//ClassView ���� �������, �������� �������� ����� Rect � �������
	//������ ������ ���� - � ����������� ����������� ���� ��������
	//Add/Add Member Function... � ������� ����������� ���������� ������
	//"����� ��������" Wizard-� ��� �������� � ���������� �����.

	

	
	stop
*/
/*
	//������� 2.���������� ������������� � ������� ������.
	//����������� �����������.

	//2�.�������� � ���������� ����������� ����������� � ������ Rect.
	//�������� ������� �� �����, ����������, �����
	//����������� ���������� ��� �������� r1,r2,r3 � r4?
	//���� ����� ���������� ��������� ��������?
		Rect r1;
		Rect r2(1,2,3,4);
		Rect r3 = r1;
		Rect r4(r2);
		stop


  //2�. �������� � ���������� � ������ Rect ����� InflateRect(),
	//������� ��������� ��� ���������, �� ��������� ������ 1, � 
	//���������� ������� �������������� �� �� �������� ����������.
	//��� ����� �������� ���������� ������� InflateRect()?
		r1.InflateRect(1,1);	
		r2.InflateRect(2,2);
	//����� �� ������� InflateRect() ���������� � ������ �� ���� �������?
		r3.InflateRect(2,2,2,2);
		r3.InflateRect(3,3);
		r3.InflateRect(5);
		r3.InflateRect();
	stop
*/

/*	
	//������� 3.������������� �������. ������������. 
	{
	Rect r;
	//���������������� ��������� ������. ��������� ������
	//�����������

//	int tmp = r.m_left;



	//������� � ����� Rect ����� void SetAll(...),
	//������� ����������� ���������� ������ ������������
	//��������. �������� ��������� �����, ��������� ������������. 


	//������� � ����� Rect ������ ����� GetAll(...),
	//������� "�������" �������� private-���������� ������.
	//�������� ��������� �����, ��������� ������������. 

	stop
	}
*/
/*
	//������� 4.�������� ���������� ������ � �������� ���������
	//�������. ����������� ������� ������ �� ��������. ��������
	//�������� � ������������ ����������� ��� �������� ��������
	//�� �����, ����������: � ����� ������ ���������� ���������
	//� ������������ �����������. 
	//�������� ���������� ������� 
	// Rect BoundingRect(Rect, Rect);
	//������� ��������� ��� ������� ������ Rect �� �������� �
	//���������� ������ ������ Rect, ������� �������� ���������������,
	//� ������� ������� �������� ��������������. ��� ����������
	//�������� ���������� � ����������� ������� ������?



	{

		Rect r1(1,2,3,4), r2(5,6,7,8),r3;
		r3= BoundingRect(r1, r2);
	stop
	
	//������� 4�. �������� �������� �� ������.
	//�������� ���������� ������� BoundingRect2, ������� ��������� �� ��
	//������, �������� ��������� �� ������
	//���������� �� ������������ ��� �������� ����������?
	

	r3 = BoundingRect2(r1, r2);
	stop
	}

	//������� 4�.���������� �� �� ������ (BoundingRect) ������� ������
*/

/*
	//������� 5. ����� ���������� ������������ � �����������.
	//�������� � ����������
	//����� ���������� ������. ��������� �������� � 
	//������������ (�������������) � �����������. ����������: ����� ���
	//������� �� �������� ���������� �����������, � ����� - ����������?
	{
		Rect r1;
		Rect*	pR = new Rect(1,2,1,2);	
		{
			Rect r2(r1);
			Rect arRect[2];
			for(int i=0; i<3; i++)
			{
				static Rect r3 (i,i,i,i) ;
				Rect r4(*pR);
				Rect r5(i,i,i,i);
			}
		}
		delete pR;	
		stop
	}
*/
/* 
	//������� 6.����������� + ���������� = ��������������
	// ���������. ����� MyString
	// ����������� ������������ (�������������) � ����������� ����������
	//���������� ������������� � ����������� �������
	//C ������� ��������� ���������� ����� ����������
	//������ � ������������ ������ ��� ������-����� ������
	{
		MyString	str1("It's my string1!");
		//�������� ����� GetString(), ������� ��������� ������ � ���������� ������.
		//� ������� cout � ������ GetString() ������������ ������ ������� str1
		//���������: ���������, ��� ������� ��������� ����������� ����� GetString().

		//��������� 1:
		//����������� ���� ��� ������ ��������:
		std::cout<<str1.GetString()<<std::endl;

		//��������� 2:
		//����������� ���� ��� �� ������ ��������:
		str1.GetString()[1] = 'W';

		//��������� 3:
		//����������� ���� ��� ������ ��������:
		const MyString	str2("It's my string2!");
		std::cout<<str2.GetString()<<std::endl;
	}
	stop
*/
/*
	//6a. ���������������� ��������� ��������. ��������� - �����
	//������������ ��� �������. ���������� ��������� ��������� (���?)
		{
			MyString str1("The first string!");
			MyString str2 = str1;
		}
		stop

	//6�. ���������� ����� SetNewString, ������� ����� �������� ������
	// �� �����

	
	



*/


	//������� 7.  ������ � ������� ������� ��������� ������:
	//���� ��� ����� ���������� ������. � ����� ����� � ��������� ������
	//������� ���������� ����� (96%), � ������ � ����.
	//������� �������� 1� ���������� ���������� ���������� �� ����� �����
	//� ������ ��������� ��������: �� ������ ��������
	//���������� �� ������ ����� -> ������ �� ������
	//���������� �� ������ ����� -> ������ � ������.
	//��������� ���������� ����� ��������, �� ������� ������������ ������ �
	//������ ����� ������ ������ 50%.

	//Bochka spirt(...);
	//Bochka water(...);
	//...
	//	while(������������ ������ � ����� spirt > 50%)
	//	{
	//		spirt.Pereliv(water); //��� spirt.Pereliv(water, �����_������);
	//		water.Pereliv(spirt); // ����������
	//		...

	//	} 159
return 0;

}//end_main

