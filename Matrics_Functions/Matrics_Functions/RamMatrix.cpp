#include "stdafx.h"
#include "RamMatrix.h"

namespace  Toplitz_Matrix
{
	RamMatrix::RamMatrix(int size)
	{
		length = size;
		data = new (TElement*); 
		for(int i = 0; i<length; i++){
			data[i] = new TElement[length];
		}

	}


	RamMatrix::~RamMatrix(void)
	{
		for(int i = 0; i<length; i++){
			delete data[i];
		}
		delete[] data;
	}

	TElement& RamMatrix::at(int i, int j)
	{
		return data[i][j];
	}
}