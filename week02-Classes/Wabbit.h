#pragma once // �� ����������!!! - Visual Studio ����������� ���� �� �������� ��� .h �������, �� ��� :)
#include <random> // �� ��������� rand()

enum Color
{
	Red,
	Green,
	Blue,
	White,
	Black,
};
const int colorsInTotal = 5;
enum Gender
{
	Male,
	Female,
	Vampire,
};
const int gendersInTotal = 3;

// ����� ���� Wabbit - ��������� ��� ����, ����� ����� � ������
// ��� ��� �������� ������������: ������ - ���� ������������� �����
//								  ��� - �����, ������, ������ 
//								  ���� - ������, �����, ���, ���, �����
class Wabbit
{
private:
	unsigned int m_Age;
	Color m_Color;
	Gender m_Gender;
public:

	// ����������� ������������
	Wabbit();

	// ����������� � ���������
	Wabbit(const unsigned int&, const Color&, const Gender&);

	// Advanced: ����������� � ��������� � ������������ � ����
	// Wabbit(const unsigned int& = 0, 
	//		const Color& = static_cast<Color>(rand() % colorsInTotal),
	//		const Gender& = static_cast<Gender>(rand() % gendersInTotal));


	// �������� �� ��������
	// ���� � ���� unsigned int getAge() const;
	const unsigned int& getAge() const;

	// ������� �� ��������
	// ���� � ���� void setAge(unsigned int);
	void setAge(const unsigned int&);


	// �������� �� �����
	// ���� � ���� Color getColor() const;
	const Color& getColor() const;

	// ������� �� �����
	// ���� � ���� void setColor(Color);
	void setColor(const Color&);

	// ������� �� ����
	// ���� � ���� Gender getGender() const;
	const Gender& getGender() const;

	// �������� �� ����
	// ���� � ���� void setGender(Gender);
	void setGender(const Gender&);
};