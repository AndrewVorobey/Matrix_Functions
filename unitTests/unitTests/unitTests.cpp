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
	//тут должны быть вызваны функции-юнит тестов.
	//Каждый юнит тест должен быть в отдельной функции. Тут только вызовы. 
}
void testVector1()
{
	Toplitz_Matrix::Vector* vec1 = new Toplitz_Matrix::RamVector();
	bool f=TRUE;
	for (int i=0;i<(*vec1).size();i++)
	{
		(*vec1)[i]= (int)sin(i)*1000;
	}
	for (int i=0; i<(*vec1).size();i++)
	{
		if ((*vec1)[i] != (int)sin(i)*1000 )
		{
			cout<<"Ошибка в доступе к элементу с индексом" <<i;
			f=FALSE;
		}
		
	}
	if(f) cout <<"Проверка доступа к элементу вектора прошла успешно";
}

