#ifndef PROBLEM205_H_INCLUDED
#define PROBLEM205_H_INCLUDED
#include "public_def.h"


namespace solution205
{

	class MyStack {
	public:
		/** Initialize your data structure here. */
		MyStack() {
			
		}

		/** Push element x onto stack. */
		void push(int x) {
			m_stack.push(x);
			if (temp_stack.empty())
			{
				while (!m_stack.empty())
				{
					temp_stack.push(m_stack.front());
					m_stack.pop();
				}

			}
			else if(!temp_stack.empty())
			{
				while (!temp_stack.empty())
				{
					m_stack.push(temp_stack.front());
					temp_stack.pop();

				}
				while (!m_stack.empty())
				{
					temp_stack.push(m_stack.front());
					m_stack.pop();
				}
			}
		}

		/** Removes the element on top of the stack and returns that element. */
		int pop() {
			if (temp_stack.empty())return 0;
			int value = temp_stack.front();
			temp_stack.pop();
			return value;
		}


// 		void reversequeue(queue<int>& thisqueue)
// 		{
// 			int *p = new int[thisqueue.size()];
// 			int i = 0;
// 			while (!thisqueue.empty())
// 			{
// 				p[i] = thisqueue.front();
// 				thisqueue.pop();
// 				i++;
// 			}
// 			i--;
// 			for (int j = i; j >=0; j--)
// 			{
// 				thisqueue.push(p[j]);
// 			}
// 			delete[] p;
// 			p = nullptr;
// 		}

		/** Get the top element. */
		int top() {
			if (temp_stack.empty())return 0;
			
 			return temp_stack.front();
		}

		/** Returns whether the stack is empty. */
		bool empty() {
			return getsize() == 0 ;
		}

		int getsize()
		{
			return temp_stack.size() + m_stack.size();
		}
	private:
		queue<int> m_stack;
		queue<int> temp_stack;
	};

	/**
	* Your MyStack object will be instantiated and called as such:
	* MyStack* obj = new MyStack();
	* obj->push(x);
	* int param_2 = obj->pop();
	* int param_3 = obj->top();
	* bool param_4 = obj->empty();
	*/

}


#endif // PROBLEM205_H_INCLUDED