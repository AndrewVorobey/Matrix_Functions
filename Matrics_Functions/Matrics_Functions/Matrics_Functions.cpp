#include "stdafx.h"
#include "Matrics_Functions.h"

namespace Toplitz_Matrix
{

	Vector* DurbinAlgorithm(Vector& matrix)
	{
		Vector* y = matrix.creatSame();
		Vector& yc = (*y);
		Vector* z = matrix.creatSame();
		Vector& zc = (*z);
		yc[1] = -matrix[1];
		TElement b = 1;
		TElement a = -matrix[1];

		for(int k = 1; k < matrix.size() - 1; k++)
		{
			b = (1 - a*a) * b;
			TElement sum=0;
			for(int i = 1; i <= k; i++)
				sum+=matrix[k-i+1]*yc[i];
			a = -(matrix[k+1] + sum)/b;

			for(int i = 1; i < k; i++)
			{
				zc[i] = yc[i] + a * yc[k + 1 - i];
			}

			for(int i =1;i<= k;i++)
			{
				yc[i] = zc[i];
			}
			yc[k+1] = a;
		}
		return y;
	}
/*
	Vector* LevinsonAlgorithm(Vector& matrix, Vector& b)
	{
		return ;
	}
	
	Matrix* TrenchAlgorithm(Vector& matrix)
	{

	}*/
}
