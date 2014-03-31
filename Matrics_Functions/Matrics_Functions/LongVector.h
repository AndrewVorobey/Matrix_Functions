#pragma once
#include <vector> 
namespace Toplitz_Matrix
{
	typedef int TIndex;
	typedef double TElement;
	class Vector
	{
		
	public:
		Vector();
		~Vector(void);
		virtual TElement& operator[](const TIndex& i) = 0;
		virtual void push_back(const TElement& el) = 0;
		virtual int size() = 0;
		virtual Vector* creatSame() = 0;
	};
}
