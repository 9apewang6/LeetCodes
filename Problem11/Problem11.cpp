// 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

//说明：你不能倾斜容器，且 n 的值至少为 2。

// label  :  数组 ， 双指针 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
	int getarea(int x1, int x2, int y1, int y2)
	{
		int width = abs(x2 - x1);
		int height =min(y1,y2);
		return width*height;
	}
	int maxArea(vector<int>& height) {
		if (height.size() <= 1) return 0;
		int vecsize = height.size();
		int left = 0;
		int right = vecsize - 1;
		int maxarea = getarea(left, right, height.at(left), height.at(right));
		int currentarea = maxarea;
		while (left < right)
		{		
			currentarea = getarea(left, right, height.at(left), height.at(right));
			if (maxarea <currentarea)
			{
				maxarea = currentarea;
			}
			else
			{
				height.at(left) >= height.at(right) ? right-- : (left++);
			}
		}
		return maxarea;
	}
};
int main(int argc, char* argv)
{
	vector<int>  testVec{ 10,9,8,7,6,5,4,3,2,1 };
	Solution s;
	char key;
	cout << "please input a char to continue: enter 'q' to quit" << endl;
	while (cin >> key)
	{
		cin.clear();
		if (key == 'q')break;
		cout << s.maxArea(testVec) << endl;
	}
	system("pause");
	return 0;
}
