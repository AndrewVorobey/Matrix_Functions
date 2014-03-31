#include "stdafx.h"
#include "Matrics_Functions.h"

namespace Toplitz_Matrix
{

	Vector* DurbinAlgorithm(Vector& matrix ,const TElement& alpha)
	{
		Vector* y = matrix.creatSame();
		Vector& yc = (*y);
		Vector* z = matrix.creatSame();
		Vector& zc = (*z);
		yc[0] = -matrix[1];
		TElement b = 1;
		TElement a = -matrix[1];

		for(int k = 1; k < matrix.size(); k++)
		{
			b = (1 - a*a) * b;
			TElement sum=0;
			for(int i = 1; i <= k; i++)
				if(k-i+1 != matrix.size() )
					sum+=matrix[k-i+1]*yc[i-1];
				else
					sum+=alpha*yc[i-1];

			if(k+1 != matrix.size() )
				a = -(matrix[k+1] + sum)/b;
			else 
				a = -(alpha + sum)/b;

			for(int i = 1; i < k; i++)
				zc[i-1] = yc[i-1] + a * yc[k - i];

			for(int i = 1;i<= k;i++)
				yc[i-1] = zc[i-1];


			yc[k] = a;
		}
		return y;
	}

	Vector* LevinsonAlgorithm(Vector& matrix, Vector& b)
	{
		return &b;
	}
	/*	
	Matrix* TrenchAlgorithm(Vector& matrix)
	{

	}*/
}