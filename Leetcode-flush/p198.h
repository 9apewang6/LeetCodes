#pragma once
/*
方法一：动态规划 + 滚动数组
首先考虑最简单的情况。如果只有一间房屋，则偷窃该房屋，可以偷窃到最高总金额。如果只有两间房屋，则由于两间房屋相邻，不能同时偷窃，只能偷窃其中的一间房屋，因此选择其中金额较高的房屋进行偷窃，可以偷窃到最高总金额。

如果房屋数量大于两间，应该如何计算能够偷窃到的最高总金额呢？对于第 k~(k > 2)k (k > 2) 间房屋，有两个选项：

偷窃第 kk 间房屋，那么就不能偷窃第 k - 1k−1 间房屋，偷窃总金额为前 k - 2k−2 间房屋的最高总金额与第 kk 间房屋的金额之和。

不偷窃第 kk 间房屋，偷窃总金额为前 k - 1k−1 间房屋的最高总金额。

在两个选项中选择偷窃总金额较大的选项，该选项对应的偷窃总金额即为前 kk 间房屋能偷窃到的最高总金额。

用 dp[i]dp[i] 表示前 ii 间房屋能偷窃到的最高总金额，那么就有如下的状态转移方程：

\textit{ dp }[i] = \max(\textit{ dp }[i - 2] + \textit{ nums }[i], \textit{ dp }[i - 1])
dp[i] = max(dp[i−2] + nums[i], dp[i−1])

边界条件为：

\begin{ cases } \textit{ dp }[0] = \textit{ nums }[0] & 只有一间房屋，则偷窃该房屋 \\ \textit{ dp }[1] = \max(\textit{ nums }[0], \textit{ nums }[1]) & 只有两间房屋，选择其中金额较高的房屋进行偷窃 \end{ cases }
{
	dp[0] = nums[0]
		dp[1] = max(nums[0], nums[1])
		​

		只有一间房屋，则偷窃该房屋
		只有两间房屋，选择其中金额较高的房屋进行偷窃
		​


		最终的答案即为 \textit{ dp }[n - 1]dp[n−1]，其中 nn 是数组的长度
*/
#include "public_def.h"
namespace p198
{
	// 盗窃， 同一晚入侵相邻，则报警
	// F(n) = max{F(n-2)+an,F(n-1) };
	class solution198 {
	public:
// 		int bfs() {
// 		
// 		}
		// 动态规划  ,状态转换方程
		int rob(vector<int>& vec)
		{
// 			int n = vec.size();
// 			if (n % 2 == 0)
// 			{
// 
// 			}
// 			else if (n % 2 == 1)
// 			{
// 				
// 
// 			}
// 
// 			return 0;
			if (vec.empty())return 0;
			int n = vec.size();
			if (n == 1) return vec[0];
			vector<int> dp = vector<int>(n, 0);
			dp[0] = vec[0];
			dp[1] = max(vec[0],vec[1]);
			for (int i = 2; i < n; i++)
			{
				dp[i] = max(dp[i-2]+vec[i],dp[i-1]);
			}
			return dp[n - 1];
		}

	};
}