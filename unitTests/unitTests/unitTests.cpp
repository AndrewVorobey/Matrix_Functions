// unitTests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "../../Matrics_Functions/Matrics_Functions/Matrics_Functions.cpp"
//В этом файле хранится файл для тестирования. Он будет активен при сливании. 

using std::cout;
using std::cin;


void tests();

int main()
{
	Matrix_Functions::Function();//пример вызова функции из тестируемой библиотеки
	return 0;
}

void tests()
{
	//тут должны быть вызваны функции-юнит тестов.
	//Каждый юнит тест должен быть в отдельной функции. Тут только вызовы. 
}

