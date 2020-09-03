#pragma once
#include "public_def.h"
namespace p104
{
	// ������
	// ��ȡ�����������ȣ� �����ı��� ,
	// ������ȣ�ֻ��ά��һ�� 
	class Solution {
	public:
		int dfs(TreeNode* head,int depth,int &maxvalue)
		{
			if (head)depth++;
			else if (head == nullptr)
			{
				if (maxvalue <= depth) maxvalue = depth;
				return 0;
			}
			dfs(head->left,depth,maxvalue);
			dfs(head->right, depth,maxvalue);
			return 0;
		}
		int maxDepth(TreeNode* root) {
			int maxvlaue = 0;
			dfs(root, 0,maxvlaue);
			return maxvlaue;
		}
		void testtreenode()
		{
			string inputtree;
			TreeNode* head = nullptr;
			while (getline(cin, inputtree))
			{
				head = stringToTreeNode(inputtree);
				cout <<maxDepth(head)<<endl;
			}
		}

	};
}
