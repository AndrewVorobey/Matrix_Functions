// Matrics_Functions.cpp: ���������� ���������������� ������� ��� ���������� DLL.
//

#include "stdafx.h"
#include "RamVector.h"
#include "LongMatrix.h"

namespace Toplitz_Matrix
{

	Vector* DurbinAlgorithm(Vector& matrix);

	Vector* LevinsonAlgorithm(Vector& matrix, Vector& b);

	Matrix* TrenchAlgorithm(Vector& matrix);

	//Private functions and objects
	namespace Detail
	{ 

	}
}

