#include "Stack.h"

void Stack::Resize()
{
	if (m_Size == m_Top + 1)
	{
		int* temp = m_Stack;
		m_Stack = new int[m_Size * 2];
		for (int i = 0; i < m_Size; ++i)
		{
			m_Stack[i] = temp[i];
		}
		m_Size *= 2;
		delete[] temp;
	}
}
Stack::Stack() : m_Top(-1),m_Size(InitialSize)
{
	m_Stack = new int[m_Size];
}
Stack::Stack(const Stack& rhs) : m_Top(rhs.m_Top), m_Size(rhs.m_Size)
{
	m_Stack = new int[m_Size];
	for (int i = 0; i <= m_Top; ++i)
	{
		m_Stack[i] = rhs.m_Stack[i];
	}
}
Stack& Stack::operator=(const Stack& rhs)
{
	if (this != &rhs)
	{
		delete[] m_Stack;
		m_Size = rhs.m_Size;
		m_Top = rhs.m_Top;
		m_Stack = new int[m_Size];
		for (int i = 0; i <= m_Top; ++i)
		{
			m_Stack[i] = rhs.m_Stack[i];
		}
	}
	return *this;
}
Stack::~Stack()
{
	delete[] m_Stack;
}
int Stack::top()
{
	if (m_Top != -1)
	{
		return m_Stack[m_Top];
	}
	return 0;
}
void Stack::push(int a)
{
	Resize();
	m_Stack[++m_Top] = a;
}
void Stack::pop()
{
	if (m_Top > -1)
	{
		m_Top--;
	}
}
bool Stack::isEmpty() const
{
	return m_Top == -1;
}