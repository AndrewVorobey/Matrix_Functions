// Matrics_Functions.cpp: определ€ет экспортированные функции дл€ приложени€ DLL.
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

	//детали реализации, не €вл€ющиес€ интерфейсом 
	namespace Detail
	{ 

	}
}

