#include "stdafx.h"
#include "LongVector.h"
#include <math.h>

namespace Toplitz_Matrix
{
	Vector::Vector()
	{
		//TODO
	}

	Vector::~Vector(void)
	{
		//TODO
	}


	bool Vector::isPositive()
	{
		for(int i = 0; i < size(); i++)
			if(computeDetermenant(i+1) <= 0)
				return false;
		return true;
	}

	int Vector::computeDetermenant(int N)
	{
		TElement det = 0;
		TElement secondoryDiag = 1;

		if(N = -1)
			N = size();		
		for(int i = 0; i < N; N++){
			det += std::pow((*this)[i],N);
			secondoryDiag *= (*this)[i];
		}

		det -= N * secondoryDiag; 
		return det;
	}
}