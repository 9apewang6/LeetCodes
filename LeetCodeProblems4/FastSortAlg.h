#pragma once
/*
快速排序
平均时间复杂度 nlogn
空间复杂度logn
（1）从数列中跳出一个元素，称为 基准 pivot;
（2）重新排序数列，所有元素比基准小的放基准值前面，所有元素比基准值大的摆在基准后面 ，相同值可以在人一边，在这个分区退出之后，该基准就处于数列的中间位置，这个称为分区(partition)操作;

 (3) 递归地(recursive) 把小于基准值元素的子数列和大于基准值元素的子数列排序


*/
#include "SortCommon.h"

void swap(int* data, int i, int j)
{
	if (i == j) return;
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;

}
//分区
int partition(int data[],int length,int start,int end)
{
	

}