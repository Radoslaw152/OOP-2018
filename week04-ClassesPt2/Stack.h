#pragma once
const int InitialSize = 16;
class Stack
{
private:
	int m_Top;
	int m_Size;
	int* m_Stack;
	void Resize();
public:
	Stack();
	Stack(const Stack&);
	Stack& operator=(const Stack&);
	~Stack();
	int top();
	void push(int);
	void pop();
	bool isEmpty() const;
};