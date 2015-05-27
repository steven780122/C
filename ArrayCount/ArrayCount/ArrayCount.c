
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
 * ArrayCount.c      
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

double ComputeEachMean(double *pdMatrix, int row , int column)					//不用傳遞row!!   重寫下面main  可用陣列 且沒照coding rule
{	
	double dResult = 0;
	int iIndex = 0;

	for (iIndex = 0; iIndex < column; iIndex = iIndex + 1)
	{
		dResult = dResult + *(pdMatrix + iIndex);		//用這樣better
	}
	
	return dResult / column;
}

double ComputeTotalMean(double *pdMatrix, unsigned int uiRow, unsigned int uiColumn)
{
	double dResult = 0;
	unsigned int uiIndex = 0;

	for (uiIndex = 0; uiIndex < (uiRow * uiColumn); uiIndex = uiIndex + 1)
	{
		dResult = dResult + *pdMatrix;		
		pdMatrix = pdMatrix + 1;			
	}
	
	return dResult / (uiRow * uiColumn);
}

double ComputeMax(double *pdMatrix, unsigned int uiRow, unsigned int uiColumn)					//用一個一個比的方式求matrix的最大值
{
	double dMax = 0;
	unsigned int uiIndex = 0;
	dMax = *pdMatrix;

	for (uiIndex = 0; uiIndex < (uiRow * uiColumn); uiIndex = uiIndex + 1)
	{
		if (*pdMatrix > dMax)
		{
			dMax = *pdMatrix;
		}
			pdMatrix = pdMatrix + 1;    //better
	}

	return dMax;
}

int main()
{	
	double dMatrix[ROW][COLUMN];
	double dMean1 = 0, dMean2 = 0, dMean3 = 0, dTotalmean = 0, dMax = 0;
	int iIndex = 0;
	int iRet1 = 0, iRet2 = 0, iRet3 = 0;

	printf("請輸入第一組5個double數字:\n");
	
	for (iIndex = 0; iIndex < COLUMN; iIndex = iIndex + 1)
	{
		iRet1 = scanf("%lf", &dMatrix[0][iIndex]);
		
		if (iRet1 == 0)
		{
			printf("輸入錯誤\n");
			system("pause");
			return 0;
		}
	}
	
	printf("請輸入第二組5個double數字:\n");
	
	for (iIndex = 0; iIndex < COLUMN; iIndex = iIndex + 1)
	{
		iRet2 = scanf("%lf", &dMatrix[1][iIndex]);

		if (iRet2 == 0)
		{
			printf("輸入錯誤\n");
			system("pause");
			return 0;
		}
	}
	
	printf("請輸入第三組5個double數字:\n");

	for (iIndex = 0; iIndex < COLUMN; iIndex = iIndex + 1)
	{
		iRet3 = scanf("%lf", &dMatrix[2][iIndex]);

		if (iRet1 == 0)
		{
			printf("輸入錯誤\n");
			system("pause");
			return 0;
		}
	}

	dMean1 = ComputeEachMean(&dMatrix[0][0], 1, COLUMN); 
	dMean2 = ComputeEachMean(&dMatrix[0][0], 2, COLUMN); 
	dMean3 = ComputeEachMean(&dMatrix[0][0], 3, COLUMN); 
	dTotalmean = ComputeTotalMean(&dMatrix[0][0], ROW, COLUMN); 
	dMax = ComputeMax(&dMatrix[0][0], ROW, COLUMN); 

	printf("第一組5個double數字的平均為: %.1f\n", dMean1);        
	printf("第二組5個double數字的平均為: %.1f\n", dMean2);
	printf("第三組5個double數字的平均為: %.1f\n", dMean3);
	printf("全部的平均值為: %f\n", dTotalmean);
	printf("全部的最大值為: %f\n", dMax);

	system("pause");
	return 0;
}
