#pragma once // НЕ ЗАБРАВАЙТЕ!!! - Visual Studio обикновенно само го генерира при .h файлове, но пак :)
#include <random> // за функцията rand()

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

// Имаме клас Wabbit - специален вид заек, който живее в Перник
// Той има следните спецификации: години - цяло неотрицателно число
//								  пол - мъжко, женско, вампир 
//								  цвят - червен, зелен, син, бял, черен
class Wabbit
{
private:
	unsigned int m_Age;
	Color m_Color;
	Gender m_Gender;
public:

	// Конструктор подразбиране
	Wabbit();

	// Конструктор с параметри
	Wabbit(const unsigned int&, const Color&, const Gender&);

	// Advanced: Конструктор с параметри и подразбиране в едно
	// Wabbit(const unsigned int& = 0, 
	//		const Color& = static_cast<Color>(rand() % colorsInTotal),
	//		const Gender& = static_cast<Gender>(rand() % gendersInTotal));


	// Селектор за годините
	// Може и само unsigned int getAge() const;
	const unsigned int& getAge() const;

	// Мутатор за годините
	// Може и само void setAge(unsigned int);
	void setAge(const unsigned int&);


	// Селектор за цвета
	// Може и само Color getColor() const;
	const Color& getColor() const;

	// Мутатор за цвета
	// Може и само void setColor(Color);
	void setColor(const Color&);

	// Мутатор за пола
	// Може и само Gender getGender() const;
	const Gender& getGender() const;

	// Селектор за пола
	// Може и само void setGender(Gender);
	void setGender(const Gender&);
};
