// Matrics_Functions.cpp: ���������� ���������������� ������� ��� ���������� DLL.
//

#include "stdafx.h"

namespace Toplitz_Matrix
{
	template <class vec>
	vec* Durbin(vec matrix);

	template <class vec>
	vec* Levinson(vec matrix, vec b);

	template <class vec,class mass>
	mass* Trench (vec matrix);

	//������ ����������, �� ���������� ����������� 
	namespace Detail
	{ 

	}
}

