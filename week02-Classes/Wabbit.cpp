#include "Wabbit.h"

// ����������� ������������
// ������� 1 - ����������������
// ��������� ����� � static_cast<Color>(rand() % colorsInTotal)
// ������ �� ������� �������� ����� � �������� 0 �� <����� �� ��������� � enum-a Color> - 1
// ��� 1, �� ������ ������ ������� � ��������� � �����
// �������� - ��� ����� �� ����� �� �������� � ����� ����� ��������, ����� ���������������� �� 0, ���� ���� �� ������!
// ���������� ���� �� ��������� �� enum � int, �� �� int � �num ��, ������ ����������� �� �������� � �������� static_cast ��� �����
Wabbit::Wabbit() : m_Age(0), m_Color(static_cast<Color>(rand() % colorsInTotal)), m_Gender(static_cast<Gender>(rand() % gendersInTotal))
{
	
}
/* ������� 2
Wabbit::Wabbit() 
{
	m_Age = 0;
	m_Color = static_cast<Color>(rand() % colorsInTotal);
	m_Gender = static_cast<Gender>(rand() % gendersInTotal);
}*/

// ����������� � ���������
// ������� 1 - ����������������
Wabbit::Wabbit(const unsigned int& age, const Color& color, const Gender& gender) : m_Age(age), m_Color(color), m_Gender(gender)
{

}

/* Advanced: ����������� � ��������� � ������������ � ����
Wabbit::Wabbit(const unsigned int& m_Age,
					const Color& m_Color,
					const Gender& m_Gender) : m_Age(m_Age), m_Color(m_Color), m_Gender(m_Gender)
{

}
*/

// �������� �� ��������
// ���� � ���� unsigned int getAge() const;
// ������ ������ ������, ���� �� �� ��������� � � body-�� �� �����
const unsigned int& Wabbit::getAge() const
{
	return m_Age;
	//���� �������, ����� � ���� � ���: return this->m_Age; 
}

// ������� �� ��������
// ���� � ���� void setAge(unsigned int);
void Wabbit::setAge(const unsigned int& m_Age)
{
	this->m_Age = m_Age;
	//��� ����� �� ���������� � ��������� �� ���� ������� ���� ����� �� ������ ���� �����
	//���� � ��� this
}


// �������� �� �����
// ���� � ���� Color getColor() const;
const Color& Wabbit::getColor() const
{
	return m_Color;
	//���� �������, ����� � ���� � ���: return this->m_Color; 
}

// ������� �� �����
// ���� � ���� void setColor(Color);
void Wabbit::setColor(const Color& m_Color)
{
	this->m_Color = m_Color;
	//��� ����� �� ���������� � ��������� �� ���� ������� ���� ����� �� ������ ���� �����
	//���� � ��� this
}

// ������� �� ����
// ���� � ���� Gender getGender() const;
const Gender& Wabbit::getGender() const
{
	return m_Gender;
	//���� �������, ����� � ���� � ���: return this->m_Gender; 
}

// �������� �� ����
// ���� � ���� void setGender(Gender);
void Wabbit::setGender(const Gender& m_Gender)
{
	this->m_Gender = m_Gender;
	//��� ����� �� ���������� � ��������� �� ���� ������� ���� ����� �� ������ ���� �����
	//���� � ��� this
}