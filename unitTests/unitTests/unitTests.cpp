// unitTests.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include "../../Matrics_Functions/Matrics_Functions/Matrics_Functions.cpp"
//� ���� ����� �������� ���� ��� ������������. �� ����� ������� ��� ��������. 

using std::cout;
using std::cin;


void tests();
void testVector1();

int main()
{
	setlocale(LC_ALL, "Russian");
	tests();
	int a;
	cin>>a;
	Toplitz_Matrix::Vector* vec = new Toplitz_Matrix::RamVector();
	return 0;
}

void tests()
{
	testVector1();
	//��� ������ ���� ������� �������-���� ������.
	//������ ���� ���� ������ ���� � ��������� �������. ��� ������ ������. 
}
void testVector1()
{
	Toplitz_Matrix::Vector* vec1 = new Toplitz_Matrix::RamVector();
	bool f=TRUE;
	for (int i=0;i<20000;i++)
	{
		(*vec1).push_back ((int)sin(i)*1000);
	}
	if ((*vec1).size()!=20000)
	{
		cout<<"������ � ������ push_back";
		f=FALSE;
	}
	for (int i=0; i<20000;i++)
	{

		if ((*vec1)[i] != (int)sin(i)*1000 )
		{
			cout<<"������ � ������� � �������� � ��������" <<i;
			f=FALSE;
		}
		
	}
	if(f) cout <<"�������� ������ �������";
}

