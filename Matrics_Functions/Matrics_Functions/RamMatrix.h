#pragma once
#include "longmatrix.h"
namespace  Toplitz_Matrix
{
	class RamMatrix :
		public Matrix
	{
		TElement** data;
		int length;
	public:
		RamMatrix(int size);
		~RamMatrix(void);
		TElement& at(int i, int j);
	};

}