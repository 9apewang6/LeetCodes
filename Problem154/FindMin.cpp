// 旋转数组最小元素
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int minArray(vector<int>& numbers) {
		if (numbers.size() == 0)return 0;
		if (numbers.size() == 1) return numbers.at(0);
		if (numbers.size() == 2) return min(numbers.at(0), numbers.at(1));
		
		int vector_size = numbers.size();
		int minvalue = numbers.at(0);
		int left_index = 0;
		int right_index = numbers.size() - 1;
		int mid_index = (vector_size-1) / 2;
	
		do{
			if (numbers.at(mid_index) > minvalue)
			{
				left_index = mid_index;
				mid_index = (left_index + right_index) / 2;
			}
			else if(numbers.at(mid_index)<minvalue)
			{
				minvalue = numbers.at(mid_index);
				right_index = mid_index;
				mid_index = (left_index + right_index) / 2;
			}
			else if (numbers.at(mid_index) == minvalue)
			{
				left_index++;
				minvalue = numbers.at(left_index);
				mid_index = (left_index + right_index) / 2;
			}
		} while ((right_index-left_index)>1);
		if (minvalue > numbers.at(right_index))minvalue = numbers.at(right_index);
		return minvalue;
	}
};
int main(int argc, char* argv[])
{
	vector<int> testvec{1,3};
	Solution s;
	cout<<s.minArray(testvec)<<endl;
	system("pause");
	return 0;
}