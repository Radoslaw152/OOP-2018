#include "Wabbit.h"

// Конструктор подразбиране
// Вариант 1 - препоръчителният
// Обяснение какво е static_cast<Color>(rand() % colorsInTotal)
// Искаме да получим случайно число в интервал 0 до <Броят на цветовете в enum-a Color> - 1
// Без 1, по същата логика каквато е индексите в масив
// ВНИМАНИЕ - ако дадем за някой от типовете в енъма друга стойност, освен последователната от 0, това няма да работи!
// Имплицитно може да превърнем от enum в int, но от int в еnum не, затова експлицитно го кастваме с оператор static_cast към енъма
Wabbit::Wabbit() : m_Age(0), m_Color(static_cast<Color>(rand() % colorsInTotal)), m_Gender(static_cast<Gender>(rand() % gendersInTotal))
{
	
}
/* Вариант 2
Wabbit::Wabbit() 
{
	m_Age = 0;
	m_Color = static_cast<Color>(rand() % colorsInTotal);
	m_Gender = static_cast<Gender>(rand() % gendersInTotal);
}*/

// Конструктор с параметри
// Вариант 1 - препоръчителният
Wabbit::Wabbit(const unsigned int& age, const Color& color, const Gender& gender) : m_Age(age), m_Color(color), m_Gender(gender)
{

}

/* Advanced: Конструктор с параметри и подразбиране в едно
Wabbit::Wabbit(const unsigned int& m_Age,
					const Color& m_Color,
					const Gender& m_Gender) : m_Age(m_Age), m_Color(m_Color), m_Gender(m_Gender)
{

}
*/

// Селектор за годините
// Може и само unsigned int getAge() const;
// Такива кратки методи, може да се дефинират и в body-то на класа
const unsigned int& Wabbit::getAge() const
{
	return m_Age;
	//друг вариант, който е един и същ: return this->m_Age; 
}

// Мутатор за годините
// Може и само void setAge(unsigned int);
void Wabbit::setAge(const unsigned int& m_Age)
{
	this->m_Age = m_Age;
	//Ако името на параметъра в функцията не беше еднакво като името на нашата член данна
	//Може и без this
}


// Селектор за цвета
// Може и само Color getColor() const;
const Color& Wabbit::getColor() const
{
	return m_Color;
	//друг вариант, който е един и същ: return this->m_Color; 
}

// Мутатор за цвета
// Може и само void setColor(Color);
void Wabbit::setColor(const Color& m_Color)
{
	this->m_Color = m_Color;
	//Ако името на параметъра в функцията не беше еднакво като името на нашата член данна
	//Може и без this
}

// Мутатор за пола
// Може и само Gender getGender() const;
const Gender& Wabbit::getGender() const
{
	return m_Gender;
	//друг вариант, който е един и същ: return this->m_Gender; 
}

// Селектор за пола
// Може и само void setGender(Gender);
void Wabbit::setGender(const Gender& m_Gender)
{
	this->m_Gender = m_Gender;
	//Ако името на параметъра в функцията не беше еднакво като името на нашата член данна
	//Може и без this
}