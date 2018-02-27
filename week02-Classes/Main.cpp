#include "Wabbit.h"
#include <iostream>

int main()
{
	//Обект, който е инициализиран с конструктора по подразбиране
	Wabbit FMI;

	//Обект, който е инициализиран с конструктора с параметри
	Wabbit OOP(25, Red, Vampire);

	
	std::cout << FMI.getAge() << std::endl;
	switch (FMI.getColor)
	{
	case Red: std::cout << "Color Red" << std::endl; break;
	case Green: std::cout << "Color Green" << std::endl; break;
	case Blue: std::cout << "Color Blue" << std::endl; break;
	case White: std::cout << "Color White" << std::endl; break;
	case Black: std::cout << "Color Black" << std::endl; break;
	}

	FMI.setGender(Vampire);

	//Трябва да изведе 2 - на това отговаря Vampire в enum-a
	std::cout << FMI.getGender() << std::endl;
	return 0;
}