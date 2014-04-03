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
void testVector2();
Toplitz_Matrix::Vector* MultMatrixVec(Toplitz_Matrix::Vector& matrix, Toplitz_Matrix::Vector& vec);
void testDurbin();
void testLevinson();
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
	testVector2();
	testDurbin();
	testLevinson();
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
	(*vec1).push_back(300);
	if((*vec1).size() != 20001)
	{
		cout<<"������, ������ ������� ��� ������������� ������� push_back �� ����������";
		f=FALSE;
	}
	if(f) cout <<"�������� ������ �������";
}
void testVector2()
{
	bool flag=TRUE;
	Toplitz_Matrix::Vector* vec2 = new Toplitz_Matrix::RamVector(1000);
	if((*vec2).size() != 1000)
	{
		cout<<"����������� � ���������� �������� �������";
		flag= FALSE;
	}
	else
	{
		for (int i=0; i<1000; i++)
			if ((*vec2)[i]!=0)
			{
				cout<<"������ � ������ ������������ � ����������, ������� ��������������� �� ��������� ������� � ��������"<<i;
				flag=FALSE;
			}
	}
	if (flag) 
		cout <<"\n�������� ������������ ������ �������";
}

void testDurbin()
{
	Toplitz_Matrix::Vector* A = new Toplitz_Matrix::RamVector(3);
	Toplitz_Matrix::Vector& A1=(*A);
	
	Toplitz_Matrix::TElement param;
	bool f=FALSE;
	A1[0]= 1;
	A1[1]=0.5;
	A1[2]=0.2;
	param=0.1;
	Toplitz_Matrix::Vector& y = *(Toplitz_Matrix::DurbinAlgorithm(A1,param));
	Toplitz_Matrix::Vector& b= *(MultMatrixVec(A1,y));
	for(int j=0; j<b.size()-1; j++)
	{
		if (b[j]!=(-A1[j+1]))
	{
		f=TRUE;
		break;
	}
	}
	if (b[b.size()-1]!=(-param)) f=TRUE;
	if (f)
		cout<<"\n�������� ������� �������� �����������";
	else
		cout << "\n�������� ������� �������� ���������";

}
void testLevinson()
{
	Toplitz_Matrix::Vector* A = new Toplitz_Matrix::RamVector(3);
	Toplitz_Matrix::Vector& A1=(*A);
	Toplitz_Matrix::Vector* b =A1.creatSame();
	Toplitz_Matrix::Vector& b1=(*b);
	bool f=FALSE;
	A1[0]= 1;
	A1[1]=0.5;
	A1[2]=0.2;
	b1[0]= 4;
	b1[1]=-1;
	b1[2]=3;
	Toplitz_Matrix::Vector& y = *(Toplitz_Matrix::LevinsonAlgorithm(A1,b1));
	Toplitz_Matrix::Vector& v = *(MultMatrixVec(A1,y));
	for(int j=0; j<b1.size(); j++)
	{ if (b1[j]!=v[j])
	{
		f=TRUE;
		break;
	}
	}
	if (f)
		cout<<"\n�������� ��������� �������� �����������";
	else
		cout << "\n�������� ��������� �������� ���������";

}

Toplitz_Matrix::Vector* MultMatrixVec(Toplitz_Matrix::Vector& matrix, Toplitz_Matrix::Vector& vec)
{
	Toplitz_Matrix::Vector*b=matrix.creatSame();
	Toplitz_Matrix::Vector&b1=(*b);
	int j,k=matrix.size();
	for(int i=0;i<b1.size();i++)
	{
		j=0;
		for (int g=b1.size()-k; g>0; g--)
		{
			b1[i]+=matrix[g]*vec[j];
			j++;
		}
		for( int l=0; l<k; l++)
		{
			b1[i]+=matrix[l]*vec[j];
			j++;
		}
		k--;
	}
	return b;
}

