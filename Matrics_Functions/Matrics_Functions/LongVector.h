#pragma once
#include <string>
namespace Toplitz_Matrix
{
	typedef int TIndex;
	typedef int TElement;
	class Vector
	{
		
	public:
		Vector();
		~Vector(void);
		virtual TElement& operator[](TIndex) = 0;//������ � ������������� ��������
		virtual void push_back(TElement) = 0;
	};
}
