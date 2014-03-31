// Matrics_Functions.cpp: ���������� ���������������� ������� ��� ���������� DLL.
//

#include "stdafx.h"
#include "RamVector.h"
#include "LongMatrix.h"

namespace Toplitz_Matrix
{

	Vector* DurbinAlgorithm(Vector& matrix, const TElement& alpha);

	Vector* LevinsonAlgorithm(Vector& matrix, Vector& b);

	Matrix* TrenchAlgorithm(Vector& matrix);
}

