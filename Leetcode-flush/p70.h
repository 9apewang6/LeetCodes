#pragma once
#include "public_def.h"
// ÅÀÂ¥Ìİ 
// analysis :
/*
input :1 
output :1 
input: 2
output: 2
input :3 
output 3

*/
// an = an-1+an-2;
namespace p70
{
	class solution70 {
	public :
		int climbStairs(int n)
		{
			if (n == 0)return 0;
			if (n == 1) return 1;
			if (n == 2)return 2;
			int selast = 1;
			int last = 2;
			int cur = 0;
			for (int j = 2; j < n; j++)
			{
				cur = last + selast;
				
				selast = last;
				last = cur;
			}
			return cur;
		}

	};
}