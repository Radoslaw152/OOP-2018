#include "Wabbit.h"
#include <iostream>

int main()
{
	//�����, ����� � ������������� � ������������ �� ������������
	Wabbit FMI;

	//�����, ����� � ������������� � ������������ � ���������
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

	//������ �� ������ 2 - �� ���� �������� Vampire � enum-a
	std::cout << FMI.getGender() << std::endl;
	return 0;
}