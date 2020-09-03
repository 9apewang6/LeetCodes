/************************************************************************/
/* 
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]



输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用




 Your CQueue object will be instantiated and called as such:
 CQueue* obj = new CQueue();
 obj->appendTail(value);
 int param_2 = obj->deleteHead();


 解：栈是后进先出， LIFO， 队列是先进先出；

*/
/************************************************************************/

#include "Problems-UnionDef.h"

class CQueue {
public:
	CQueue() {
		
	}

	void appendTail(int value) {
		//
		stackHead.push(value);		
		cout << "	null\n";
	}
	void fetchvalue()
	{
		while (!stackHead.empty())
		{
			stackTail.push(stackHead.top());
			stackHead.pop();
		}
	}
	int deleteHead() {
		int temp = -1;

		if (stackHead.empty())
		{
			if (stackTail.empty())
			{
				return temp;
			}
			else
			{
				temp = stackTail.top();
				stackTail.pop();

				return temp;
			}
		}
		else if (!stackHead.empty())
		{
			if (stackTail.empty())
			{
				fetchvalue();
				
			}

			temp = stackTail.top();
			stackTail.pop();

			return temp;
		}
	}
private:
	stack<int> stackHead;
	stack<int> stackTail;
};


int main()
{
	vector<string> _msgs;
	string input_string;
	array<int, 1> input_value;
	CQueue *_cqueue = nullptr;
	cout << "Enter right command like CQueue、 appendTail、deleteHead" << endl;
	while (getline(cin,input_string))
	{
		if (input_string == "quit")break;
		
	
		 if (input_string == "CQueue")
		{
			if (_cqueue == nullptr)
				_cqueue = new CQueue();
			else continue;
		}
		else if (input_string == "appendTail")
		{
			char input_value;
			cout << "Enter a interger please :" << endl;
			if (!cin.get(input_value))
			{
				cin.clear();
				continue;
			}
			if (input_value > '9' || input_value < '0')
			{
				cout << "please inut a valid interger ;\n";
				continue;
			}		
			else
			{
				if (_cqueue)_cqueue->appendTail((input_value - '0'));
				else cout << "Please input CQueue first to initialize the queue ;\n";
			}
		}
		else if (input_string == "deleteHead")
		{
			if (_cqueue)cout <<_cqueue->deleteHead()<<endl;
			else cout << "Please input CQueue first to initialize the queue ;\n";
		}
	
		_msgs.push_back(input_string);
		if (_msgs.size() >= 20)break;
	}
	system("pause");
	return 0;
}