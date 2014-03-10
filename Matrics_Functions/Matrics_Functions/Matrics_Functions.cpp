// Matrics_Functions.cpp: ���������� ���������������� ������� ��� ���������� DLL.
//

#include "stdafx.h"

namespace Toplitz_Matrix
{
	template <class vec>
	vec* DurbinAlgorithm(vec matrix);

	template <class vec>
	vec* LevinsonAlgorithm(vec matrix, vec b);

	template <class vec,class mass>
	mass* TrenchAlgorithm(vec matrix);

	//������ ����������, �� ���������� ����������� 
	namespace Detail
	{ 

	}
}

