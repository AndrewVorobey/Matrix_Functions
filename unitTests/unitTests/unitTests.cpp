// unitTests.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include "../../Matrics_Functions/Matrics_Functions/Matrics_Functions.cpp"

//� ���� ����� �������� ���� ��� ������������. �� ����� ������� ��� ��������. 

using std::cout;
using std::cin;


void tests();
void testVector1()
{
	Toplitz_Matrix::Vector* vec1 = new Toplitz_Matrix::RamVector();
	int k;
	for (int i=0;i<(*vec1).size;i++)
	{
		k=rand() % 10000 + (-10000);
		(*vec1)[i]= k;
		if ((*vec1)[i] != k )
			cout<<"������ � ������� � �������� � ��������" <<i;
	}
}

int main()
{
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

