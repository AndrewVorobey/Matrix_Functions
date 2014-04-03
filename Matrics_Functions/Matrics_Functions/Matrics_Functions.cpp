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

			for(int i = 1; i <= k; i++)
				zc[i-1] = yc[i-1] + a * yc[k - i];

			for(int i = 1;i<= k;i++)
				yc[i-1] = zc[i-1];


			yc[k] = a;
		}
		return y;
	}

	Vector* LevinsonAlgorithm(Vector& matrix, Vector& b)
	{
		Vector* y = matrix.creatSame();
		Vector& yc = (*y);
		Vector* x = matrix.creatSame();
		Vector& xc = (*x);
		Vector* z = matrix.creatSame();
		Vector& zc = (*z);
		Vector* v = matrix.creatSame();
		Vector& vc = (*v);
		yc[0] = -matrix[1];
		xc[0] = b[0];
		TElement betta = 1;
		TElement a = -matrix[1];
		TElement m=0;
		int i;
		for(int k = 0; k < (matrix.size()-1); k++)
		{
			betta = (1 - a*a) * betta;
			m = b[k+1] / betta;
			for( i=0; i<=k; i++)
				m = m-(matrix[i+1] * xc[k-i]) / betta;
			for( i=0; i<=k; i++)
			{
				vc[i] = xc[i] + m * yc[k-i] ;
				xc[i] = vc[i];
			}
			xc[k+1] = m;
			if ( k < (matrix.size() - 2))
			{
				a = -matrix[k+2] / betta ;
				for( i=0; i<=k; i++)
					a = a - (matrix[i+1] * yc[k-i]) / betta ;
				for( i=0; i<=k; i++)
				{
					zc[i] = yc[i] + a * yc[k-i];
					yc[i] = zc[i];
				}
				yc[k+1] = a;
			}
		}
		return x;
	}
	/*	
	Matrix* TrenchAlgorithm(Vector& matrix)
	{

	}*/
}
