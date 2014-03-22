#pragma once
#include "longvector.h"


namespace Toplitz_Matrix
{

	class RamVector :
		public Vector
	{
	private:
		std::vector<TElement> data;
	public:
		RamVector(void);
		RamVector(int);
		~RamVector(void);
		virtual TElement& operator[](const TIndex& i);
		virtual void push_back(const TElement& el) ;
		virtual int size() { return data.size(); }
	};

}
