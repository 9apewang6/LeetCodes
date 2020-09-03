#pragma once
#include "public_def.h"
namespace p101
{
	class solutionp101
	{
	private:
		queue<int> leftbranch_1;
		vector<int> leftbranch;
		bool change = true;
	//	queue<int> rightbranch;
		public:
			// 深度优先搜索， 广度优先搜索,对称二叉树

			bool dfs(TreeNode* head)
			{
			
				if (head == nullptr)
				{
					return false;
				}
				else
				{
					leftbranch.push_back(head->val);
					leftbranch_1.push(head->val);
				}
				if (change)
				{
					dfs(head->left);
					change=dfs(head->right);
				}
				else
				{
					dfs(head->right);
					dfs(head->left);
				}


				return false;
			}
			bool bfs(TreeNode* head)
			{
				
				return false;
			}
			bool check(TreeNode* left, TreeNode*right)
			{
				if (!left && !right)return true;
				if (!left || !right) return false;
				return left->val == right->val&&check(left->left, right->right) && check(left->right, right->left);
			}
			bool isSymmetric(TreeNode* root) {
				leftbranch.clear();
				change = true;
				dfs(root);
 				cout << "********** leftbranch******** " << endl;
				for (int iter : leftbranch)
				{
					cout << "----" << iter<< endl;
				}
				cout << "********** leftbranch_1******** " << endl;
				while (!leftbranch_1.empty())
				{
					cout << "----" << leftbranch_1.front() << endl;
					leftbranch_1.pop();
				}
				int n = leftbranch.size();
				if (n % 2 == 0)return false;
				else if (n % 2 == 1)
				{
					int k = n / 2;
					for (int j = 1; j < k; j++)
					{
						if (leftbranch[j] != leftbranch[j + k])return false;
					}
				}
				return true;
			}
			string trans(bool state)
			{
				return state ? "true" : "false";
			}
			void testTree()
			{
				string input;
				while (getline(cin, input))
				{
					TreeNode* root = stringToTreeNode(input);
					cout << trans(isSymmetric(root))<<endl;
				}
			}
	};
}