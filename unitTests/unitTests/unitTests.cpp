// unitTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include "../../Matrics_Functions/Matrics_Functions/Matrics_Functions.cpp"
//В этом файле хранится файл для тестирования. Он будет активен при сливании. 

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
	//тут должны быть вызваны функции-юнит тестов.
	//Каждый юнит тест должен быть в отдельной функции. Тут только вызовы. 
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
		cout<<"Ошибка в методе push_back";
		f=FALSE;
	}
	for (int i=0; i<20000;i++)
	{

		if ((*vec1)[i] != (int)sin(i)*1000 )
		{
			cout<<"Ошибка в доступе к элементу с индексом" <<i;
			f=FALSE;
		}
		
	}
	(*vec1).push_back(300);
	if((*vec1).size() != 20001)
	{
		cout<<"Ошибка, размер вектора при использовании функции push_back не увеличился";
		f=FALSE;
	}
	if(f) cout <<"Проверка прошла успешно";
}
void testVector2()
{
	bool flag=TRUE;
	Toplitz_Matrix::Vector* vec2 = new Toplitz_Matrix::RamVector(1000);
	if((*vec2).size() != 1000)
	{
		cout<<"Конструктор с параметром работает неверно";
		flag= FALSE;
	}
	else
	{
		for (int i=0; i<1000; i++)
			if ((*vec2)[i]!=0)
			{
				cout<<"Ошибка в работе конструктора с параметром, неверно инициализирован по умолчанию элемент с индексом"<<i;
				flag=FALSE;
			}
	}
	if (flag) 
		cout <<"\nПроверка конструктора прошла успешно";
}
void testDurbin()
{
	Toplitz_Matrix::Vector* A = new Toplitz_Matrix::RamVector(500);
	Toplitz_Matrix::Vector& A1=(*A);
	Toplitz_Matrix::Vector* y=A1.creatSame();
	Toplitz_Matrix::Vector& y1=(*y);
	Toplitz_Matrix::Vector* b =A1.creatSame();
	Toplitz_Matrix::Vector& b1=(*b);
	bool f=FALSE;
	for(int i=0; i<500; i++)
		A1[i] = cos(i)*200;
	y = Toplitz_Matrix::DurbinAlgorithm(A1);
	b= MultMatrixVec(A1,y1);
	for(int j=1; j<500; j++)
	{ if (b1[j]!=(-A1[j]))
	{
		f=TRUE;
		break;
	}
	}
	if (f)
		cout<<"Алгоритм Дурбина работает неккоректно";
	else
		cout << "Алгоритм Дурбина работает корректно";

}
void testLevinson()
{
	Toplitz_Matrix::Vector* A = new Toplitz_Matrix::RamVector(500);
	Toplitz_Matrix::Vector& A1=(*A);
	Toplitz_Matrix::Vector* y=A1.creatSame();
	Toplitz_Matrix::Vector& y1=(*y);
	Toplitz_Matrix::Vector* b =A1.creatSame();
	Toplitz_Matrix::Vector& b1=(*b);
	Toplitz_Matrix::Vector* v =A1.creatSame();
	Toplitz_Matrix::Vector& v1=(*v);
	bool f=FALSE;
	for(int i=0; i<500; i++)
		A1[i] = cos(i)*200;
	for(int i=1; i<500; i++)
		b1[i] = rand();
	y = Toplitz_Matrix::LevinsonAlgorithm(A1,b1);
	v= MultMatrixVec(A1,y1);
	for(int j=1; j<500; j++)
	{ if (b1[j]!=(-v1[j]))
	{
		f=TRUE;
		break;
	}
	}
	if (f)
		cout<<"Алгоритм Левинсона работает неккоректно";
	else
		cout << "Алгоритм Левинсона работает корректно";

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

