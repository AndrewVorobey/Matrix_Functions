#pragma once
#include <string>
namespace Toplitz_Matrix
{
	
	template<class TIndex, class TElement>
	class LongVector
	{
		
	public:
		LongVector(std::string FileName = "");
		~LongVector(void);
		TElement& operator[](TIndex);//������ � ������������� ��������
		
		class Iterator
		{
		public:
			Iterator(LongVector* obj):_obj(obj){}
			TElement& at();
			TElement& operator++();
			TElement& operator--();
		private:
			LongVector* _obj;
		};
	};
}
