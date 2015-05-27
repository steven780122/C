
/* 
**********************************************************************
* $Header$
*
*  Copyright (c) 2000-2013 Vivotek Inc. All rights reserved.
*
*  +-----------------------------------------------------------------+
*  | THIS SOFTWARE IS FURNISHED UNDER A LICENSE AND MAY ONLY BE USED |
*  | AND COPIED IN ACCORDANCE WITH THE TERMS AND CONDITIONS OF SUCH  |
*  | A LICENSE AND WITH THE INCLUSION OF THE THIS COPY RIGHT NOTICE. |
*  | THIS SOFTWARE OR ANY OTHER COPIES OF THIS SOFTWARE MAY NOT BE   |
*  | PROVIDED OR OTHERWISE MADE AVAILABLE TO ANY OTHER PERSON. THE   |
*  | OWNERSHIP AND TITLE OF THIS SOFTWARE IS NOT TRANSFERRED.        |
*  |                                                                 |
*  | THE INFORMATION IN THIS SOFTWARE IS SUBJECT TO CHANGE WITHOUT   |
*  | ANY PRIOR NOTICE AND SHOULD NOT BE CONSTRUED AS A COMMITMENT BY |
*  | VIVOTEK INC.                                                    |
*  +-----------------------------------------------------------------+
*
* $History$
*
  ***********************************************************************
 */

/*!
 ***********************************************************************
 * Copyright 2000-2013 Vivotek, Inc. All rights reserved.
 *
 * \file
 * ArrayCount.cpp      
 *
 * \brief
 * compute the mean and max of a matrix
 *
 * \date
 * 2013/11/01
 *
 * \author
 * Steven Hsiao
 *
 *
 **********************************************************************
 */

#include "stdafx.h"
#include <stdlib.h>

#define ROW 3
#define COLUMN 5

double ComputeEachMean(double *dMatrix, int row , int column )
{	
	double dResult = 0;

	for (int i = 0; i < column; i = i + 1)
	{
		dResult = dResult + *(dMatrix + (row - 1) * column);		//���Ц첾���row
		dMatrix = dMatrix + 1;										
	}
	
	return dResult/column;
}

double ComputeTotalMean(double *dMatrix, int row , int column )
{
	double dResult = 0;

	for (int i = 0; i < (row * column); i = i + 1)
	{
		dResult = dResult + *dMatrix;		
		dMatrix = dMatrix + 1;			
	}
	
	return dResult/(row * column);
}

double ComputeMax(double *dMatrix, int row, int column)					//�Τ@�Ӥ@�Ӥ񪺤覡�Dmatrix���̤j��
{
	double dMax = 0;
	dMax = *dMatrix;

	for(int i = 0; i < (row * column); i = i + 1)
	{
		if (*dMatrix > dMax)
		{
			dMax = *dMatrix;
			dMatrix = dMatrix + 1;
		}
		else
		{
			dMatrix = dMatrix + 1;
		}

	}

	return dMax;
}

int main()
{	
	double dMatrix[ROW][COLUMN];
	double dMean1 = 0, dMean2 = 0, dMean3 = 0, dTotalmean = 0, dMax = 0;

	printf("�п�J�Ĥ@��5��double�Ʀr:\n");
	for (int i = 0; i < COLUMN; i = i + 1)
	{
		scanf("%lf",&dMatrix[0][i]);
	}
	printf("�п�J�ĤG��5��double�Ʀr:\n");
	for (int i = 0; i < COLUMN; i = i + 1)
	{
		scanf("%lf",&dMatrix[1][i]);
	}
	printf("�п�J�ĤT��5��double�Ʀr:\n");

	for (int i = 0; i < COLUMN; i = i + 1)
	{
		scanf("%lf",&dMatrix[2][i]);
	}

	dMean1 = ComputeEachMean(&dMatrix[0][0], 1, COLUMN); 
	dMean2 = ComputeEachMean(&dMatrix[0][0], 2, COLUMN); 
	dMean3 = ComputeEachMean(&dMatrix[0][0], 3, COLUMN); 

	printf("�Ĥ@��5��double�Ʀr��������: %f\n", dMean1);        //�令%.1f ��X�ܤp���I��Ĥ@��
	printf("�ĤG��5��double�Ʀr��������: %f\n", dMean2);
	printf("�ĤT��5��double�Ʀr��������: %f\n", dMean3);

	dTotalmean = ComputeTotalMean(&dMatrix[0][0], ROW, COLUMN); 
	
	printf("�����������Ȭ� %f:\n", dTotalmean);

	dMax = ComputeMax(&dMatrix[0][0], ROW, COLUMN); 
	printf("�������̤j�Ȭ� %f:\n", dMax);

	system("pause");
	return 0;
}
