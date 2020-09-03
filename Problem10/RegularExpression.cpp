// Regular Expression matching  -- ������ʽƥ��
//  s����Ϊ�գ���ֻ����a-z��Сд��ĸ
// p ����Ϊ�գ���ֻ����a-z��Сд��ĸ��'.'��'*'
// '.'ƥ�����ⵥ���ַ�
// '*'ƥ���������ǰ��Ԫ��
// ��̬�滮�����ݣ��ַ���
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
	//�ַ���s�� �ַ�����p
	struct node;
	struct rev;
	struct node {//��������״̬�Զ����Ľڵ�
		 rev *revlist;   //״̬ת����
		 node *next;
	};

	struct rev {//������ĳ����Ϊ��������״̬�Զ�����������
		char matchChar;	// ״̬
		 node *matchNode;	//ƥ��ڵ�
		 rev *nextRev; //
	};

	bool match(char *s, struct node *now) {
		if (s[0] == '\0') {//�ַ����������ж��Ƿ�Ϊ���սڵ�
			if (now->revlist->nextRev == NULL) {//�ڵ��Լ�Ϊ��ֹ״̬
				return true;
			}
			else {//�жϽڵ��Ƿ����ͨ��ƥ���ֵ������ֹ״̬
				struct node *temp = now;
				while (temp->next != NULL)
					temp = temp->next;
				if (temp->revlist->nextRev == NULL)
					return true;
				else
					return false;
			}
		}
		else {//��������ڵ����еı�
			struct rev *temp = now->revlist;
			while (temp != NULL) {
				if (temp->matchChar == s[0] || temp->matchChar == '.') {//���ƥ�䣬��ݹ�
					if (match(s + 1, temp->matchNode) == true)
						return true;
				}
				temp = temp->nextRev;
			}
		}
		return false;
	}

	bool isMatch(char * s, char * p) {
		struct node *head = (struct node*)malloc(sizeof(struct node));
		head->revlist = (struct rev*)malloc(sizeof(struct rev));
		head->revlist->matchChar = '\0';
		head->revlist->matchNode = NULL;
		head->revlist->nextRev = NULL;
		head->next = NULL;
		struct node *now = head;
		char *p_ptr = p;
		//��������״̬�Զ���
		while (p_ptr[0] != '\0') {
			if (p_ptr[1] == '*') {//�����*ƥ��
				struct node *newNode = NULL;
				newNode = (struct node*)malloc(sizeof(struct node));
				newNode->revlist = (struct rev*)malloc(sizeof(struct rev));
				newNode->revlist->matchChar = p_ptr[0];
				newNode->revlist->matchNode = newNode;
				newNode->revlist->nextRev = NULL;
				newNode->next = NULL;
				struct node *temp = now;
				struct rev *nowList = NULL;
				while (1) {
					nowList = temp->revlist;
					while (nowList->nextRev != NULL)
						nowList = nowList->nextRev;
					nowList->nextRev = (struct rev*)malloc(sizeof(struct rev));
					nowList = nowList->nextRev;
					nowList->matchChar = p_ptr[0];
					nowList->matchNode = newNode;
					nowList->nextRev = NULL;
					if (temp->next == NULL) {
						temp->next = newNode;
						break;
					}
					temp = temp->next;
				}
				p_ptr += 2;
			}
			else {//�������*ƥ��
				struct node *newNode = NULL;
				newNode = (struct node*)malloc(sizeof(struct node));
				newNode->revlist = (struct rev*)malloc(sizeof(struct rev));
				newNode->revlist->matchChar = '\0';
				newNode->revlist->matchNode = NULL;
				newNode->revlist->nextRev = NULL;
				newNode->next = NULL;
				struct rev *nowList = NULL;
				while (now != NULL) {
					nowList = now->revlist;
					while (nowList->nextRev != NULL)
						nowList = nowList->nextRev;
					nowList->nextRev = (struct rev*)malloc(sizeof(struct rev));
					nowList = nowList->nextRev;
					nowList->matchChar = p_ptr[0];
					nowList->matchNode = newNode;
					nowList->nextRev = NULL;
					now = now->next;
				}
				now = newNode;
				p_ptr += 1;
			}
		}
		//��������״̬�Զ��������û���
		return match(s, head);
	}
// 	bool isMatch(string s, string p) {
// 		if (s.length() == 0 || p.length() == 0)return false;
// 		int s_size = s.length();
// 		int p_size = p.length();
// 		int match_length = 0;
// 		int step = 0;
// 		for (int i = 0; i < p_size; i++)
// 		{	
// 			if (p[i] == '.')
// 			{
// 				match_length = match_length + 1;
// 
// 				step = 1;
// 				if (match_length == s_size)
// 				{
// 					if (i < p_size - 1)
// 					{
// 						//	
// 						if (p[p_size - 1] != '*')return false;
// 						int val = 0;
// 						for (int k = (i+1); k < p_size; k++)
// 						{
// 							// ��������'.'��'a'-'z'��ƥ��
// 							if (p[k] == '.' || (p[k] <= 'z'&&p[k] >= 'a'))
// 							{
// 								val++;
// 							}
// 							else if (p[k] == '*')
// 							{
// 								val--;
// 							}
// 							if (val > 1)return false;
// 						}
// 						return true;
// 					}		
// 					else if (i == (p_size - 1))return true;
// 				}
// 				else
// 				{
// 					continue;
// 				}
// 			}
// 			else if (p[i] == '*')
// 			{
// 				if ((i - 1) >= 0)
// 				{
// 					if (p[i - 1] == '.')
// 					{
// 						step = s_size - match_length - i+1;
// 
// 						match_length = s_size - i+1;
// 						if (match_length == s_size)
// 						{
// 							if (i < p_size - 1)
// 							{
// 								//	
// 								if (p[p_size - 1] != '*')return false;
// 								int val = 0;
// 								for (int k = (i + 1); k < p_size; k++)
// 								{
// 									// ��������'.'��'a'-'z'��ƥ��
// 									if (p[k] == '.' || (p[k] <= 'z'&&p[k] >= 'a'))
// 									{
// 										val++;
// 									}
// 									else if (p[k] == '*')
// 									{
// 										val--;
// 									}
// 									if (val > 1)return false;
// 								}
// 								return true;
// 							}
// 							else if (i == (p_size - 1))return true;
// 						}
// 						else
// 						{
// 							continue;
// 						}
// 					}
// 					else if (p[i - 1] == '*')
// 					{
// 						continue;
// 					}
// 					else if (p[i - 1] >= 'a'&&p[i - 1] <= 'z')
// 					{
// 						//n * p[i] ȷ��n
// 						for (auto j = match_length; j < s_size; j++)
// 						{
// 							if (p[i - 1] != s[match_length])
// 							{
// 								step = 0;
// 								break;
// 							}
// 							if (s[j] != s[match_length])
// 							{
// 							//	step = j - match_length + 1;
// 								break;
// 							}
// 							step = j - match_length + 1;
// 						}
// 						if ((i + 1) < p_size)
// 						{
// 							if (p[i - 1] == p[i + 1])
// 							{
// 								step = step - 1;
// 							}
// 						}
// 						match_length = match_length + step;
// 						if (match_length == s_size)
// 						{
// 							if (i < p_size - 1)
// 							{
// 								//	
// 								if (p[p_size - 1] != '*')return false;
// 								int val = 0;
// 								for (int k = (i + 1); k < p_size; k++)
// 								{
// 									// ��������'.'��'a'-'z'��ƥ��
// 									if (p[k] == '.' || (p[k] <= 'z'&&p[k] >= 'a'))
// 									{
// 										val++;
// 									}
// 									else if (p[k] == '*')
// 									{
// 										val--;
// 									}
// 									if (val > 1)return false;
// 								}
// 								return true;
// 							}
// 							else if (i == (p_size - 1))return true;
// 						}
// 						else
// 						{
// 							continue;
// 						}
// 					}
// 				}
// 				else continue;
// 			}
// 			else if (p[i] >= 'a'&&p[i] <= 'z')
// 			{
// 
// 				if (p[i] == s[match_length])
// 				{
// 					match_length++;
// 					if (match_length == s_size)
// 					{
// 						if (i < p_size - 1) return false;
// 						else if (i == (p_size - 1))return true;
// 					}
// 					else
// 					{
// 						continue;
// 					}
// 				}
// 
// 			}
// 			
// 		}
// 		if (match_length == s_size)return true;
// 		return false;
// 	}

bool isMatch(string s, string p) {
	return isMatch(s.c_str(), p.c_str());
}

bool isMatch(const char* s, const char* p) {
	if (*p == 0) return *s == 0;

	auto first_match = *s && (*s == *p || *p == '.');

	if (*(p + 1) == '*') {
		return isMatch(s, p + 2) || (first_match && isMatch(++s, p));
	}
	else {
		return first_match && isMatch(++s, ++p);
	}
}


};
int main(int argc, char* argv[])
{
	string input_s;
	string input_rule;
	Solution s;
	cout << "please input a string to be matched" << endl;
	getline(cin,input_s);
	cin.clear();
	cout << "please input the rule" << endl;
	getline(cin, input_rule);
	if (s.isMatch(const_cast<char*>(input_s.c_str()), const_cast<char*>(input_rule.c_str())))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	system("pause");
	return 0;
}