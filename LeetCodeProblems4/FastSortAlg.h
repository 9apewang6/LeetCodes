#pragma once
/*
��������
ƽ��ʱ�临�Ӷ� nlogn
�ռ临�Ӷ�logn
��1��������������һ��Ԫ�أ���Ϊ ��׼ pivot;
��2�������������У�����Ԫ�رȻ�׼С�ķŻ�׼ֵǰ�棬����Ԫ�رȻ�׼ֵ��İ��ڻ�׼���� ����ֵͬ��������һ�ߣ�����������˳�֮�󣬸û�׼�ʹ������е��м�λ�ã������Ϊ����(partition)����;

 (3) �ݹ��(recursive) ��С�ڻ�׼ֵԪ�ص������кʹ��ڻ�׼ֵԪ�ص�����������


*/
#include "SortCommon.h"

void swap(int* data, int i, int j)
{
	if (i == j) return;
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;

}
//����
int partition(int data[],int length,int start,int end)
{
	

}