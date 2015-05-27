
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
 * ArrayCopy.c
 *
 * \brief
 * copy the array by array storage and pointer
 *
 * \date
 * 2013/11/04
 *
 * \author
 * Steven Hsiao
 *
 *
 **********************************************************************
 */
#include "stdafx.h"
#include <stdlib.h>
#define iLength 6

int main()
{
	int iaArray[iLength] = {1, 2, 3, 4, 5, 6};
	int iaBrray[iLength];   //����l�� �Ϋ��жǨ�Ƶ{��
	int *piPtr = iaArray;		//���ɼgarray �Ϋ���
	int iIndex = 0;

	//
	printf("��l�}�C:\n");

	for (iIndex = 0; iIndex < iLength; iIndex = iIndex + 1)
	{
		printf("%d", iaArray[iIndex]);
	}
	
	printf("\n");
	
	for (iIndex = 0; iIndex < iLength; iIndex = iIndex + 1)
	{
		iaBrray[iIndex] = iaArray[iIndex];
	}
	

	printf("�ƻs�}�Cby�}�C�x�s:\n");									//�ΰƵ{�����g!!

	for (iIndex = 0; iIndex < iLength; iIndex = iIndex + 1)
	{
		printf("%d", iaBrray[iIndex]);
	}
	

	for (iIndex = 0; iIndex < iLength; iIndex = iIndex + 1)			//�ΰƵ{�����g  �ӥB�n��piptr++���覡
	{
		*(piPtr + iIndex) = iaArray[iIndex];
	}

	printf("\n");
	printf("�ƻs�}�Cby���л��W��l:\n");

	for (iIndex = 0; iIndex < iLength; iIndex = iIndex + 1)
	{
		printf("%d", *(piPtr + iIndex));
	}

	system("pause");
	return 0;
}
