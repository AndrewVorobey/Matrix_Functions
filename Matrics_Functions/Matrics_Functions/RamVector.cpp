#include "stdafx.h"
#include "RamVector.h"


namespace Toplitz_Matrix
{
	RamVector::RamVector(void)
	{
	}

	RamVector::RamVector(int size):data(size)
	{

	}

	RamVector::~RamVector(void)
	{
	}

	TElement& RamVector::operator[](const TIndex& i)
	{
		return data[i];
	}

	void RamVector::push_back(const TElement& el) 
	{
		data.push_back(el);
	}
}