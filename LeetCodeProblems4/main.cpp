#pragma 
/*
寻找两个正序数组的中位数  

给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



示例：
[1,3]
[2]

中位数，2.0


[1,2]
[3,4]
中位数 (2+3)/2 = 2.5


*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <math.h>
using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::unordered_map;
using std::vector;
using std::make_pair;

class SolutionSortArray {
public:
	//复杂度 O((m+n)^2)
	double findMedianSortedArrays_1(vector<int>& nums1, vector<int>& nums2) {
		int M = nums1.size();
		int N = nums2.size();
		vector<int> ReOrganization;
		int temp = 0;
		ReOrganization.insert(ReOrganization.begin(), nums1.begin(), nums1.end());
		ReOrganization.insert(ReOrganization.end(), nums2.begin(), nums2.end());

		//队列排序
		for (int i = 0; i < M + N - 1; i++)
		{
			for (int j = i; j <= M + N - 1; j++)
			{
				if (ReOrganization.at(i) > ReOrganization.at(j))
				{
					//swap(ReOrganization, i, j);
					if (i == j) continue;
					temp = ReOrganization.at(i);
					ReOrganization.at(i) = ReOrganization.at(j);
					ReOrganization.at(j) = temp;
				}
				
			}
		}
		if ((M+N) % 2 == 0)
		{
			return (ReOrganization.at((M + N) / 2 - 1) + ReOrganization.at((M + N) / 2)) / 2.0f;
		}
		else
		{
			return (ReOrganization.at((M + N - 1) / 2));
		}
	}


	//重组普通排序 复杂度都达不到要求
	//计数排序
	/*
	（1） 找出待排序的数组中最大和最小的元素
	（2） 统计数组中每个元素为i的元素出现的次数， 存入数组C的第i项
	（3）对所有计数累加，从C中第一个元素开始，每一项和前一项相加，

	*/


	//桶排序
	/*
	设置一个定量的数组当作空桶
	遍历输入数据，并把数据一个一个放到对应桶
	每个不是空的桶排序
	不是空的桶中把排好序的数据拼接
	
	*/

	void bucketSort(vector<int>& vec ,int min,int max)
	{
		int length =min>0 ? (max+1) : (max-min+1);  //
		vector<int> buckets(length,0); //准备一堆桶，容器下标 待排序数组的键值
		for (int i = 0; i < vec.size(); i++)
		{
			buckets[vec[i]]++;			
		}
		int index = 0;
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < buckets[i]; j++)
			{
				vec[index++] = i;
			}
		}
	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int M = nums1.size();
		int N = nums2.size();
		if (M == 0)
		{
			if ((M + N) % 2 == 0)
			{
				return (nums2.at((M + N) / 2 - 1) + nums2.at((M + N) / 2)) / 2.0f;
			}
			else
			{
				return (nums2.at((M + N - 1) / 2));
			}
		}
		if (N == 0)
		{
			if ((M + N) % 2 == 0)
			{
				return (nums1.at((M + N) / 2 - 1) + nums1.at((M + N) / 2)) / 2.0f;
			}
			else
			{
				return (nums1.at((M + N - 1) / 2));
			}

		}
		vector<int> ReOrganization;
		int temp = 0;
		
		ReOrganization.insert(ReOrganization.begin(), nums1.begin(), nums1.end());
		ReOrganization.insert(ReOrganization.end(), nums2.begin(), nums2.end());

		int min = *nums1.begin();
		int max = *(nums1.end() - 1);
		if (min > *nums2.begin())
		{
			min = *nums2.begin();
		}
		if (max < *(nums2.end() - 1))
		{
			max = *(nums2.end() - 1);
		}
		
		if (min < 0)
		{
			for (int i = 0; i <= M + N - 1; i++)
			{
				ReOrganization.at(i) = ReOrganization.at(i) - min;
			}
		}
		//队列排序
// 		for (int i = 0; i < M + N - 1; i++)
// 		{
// 			for (int j = i; j <= M + N - 1; j++)
// 			{
// 				if (ReOrganization.at(i) > ReOrganization.at(j))
// 				{
// 					//swap(ReOrganization, i, j);
// 					if (i == j) continue;
// 					temp = ReOrganization.at(i);
// 					ReOrganization.at(i) = ReOrganization.at(j);
// 					ReOrganization.at(j) = temp;
// 				}
// 
// 			}
// 		}
		//桶排序
		bucketSort(ReOrganization,min,max);
		if ((M + N) % 2 == 0)
		{
			if (min < 0)
			{
				return ((ReOrganization.at((M + N) / 2 - 1) + ReOrganization.at((M + N) / 2)) / 2.0f + min);

			}
			else
			{
				return (ReOrganization.at((M + N) / 2 - 1) + ReOrganization.at((M + N) / 2)) / 2.0f;

			}
		}
		else
		{
			if (min <0)
			{
				return ((ReOrganization.at((M + N - 1) / 2))+min);

			}
			else
			{
				return (ReOrganization.at((M + N - 1) / 2));

			}
		}
	}
};
void main()
{
	vector<int> vec1 = {};
	vector<int> vec2 = { 3};
	SolutionSortArray Ssa;
	cout << Ssa.findMedianSortedArrays(vec1, vec2) << endl;
	system("pause");
}
