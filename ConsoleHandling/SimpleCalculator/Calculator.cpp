#include <iostream>
#include <array>


bool checkIfStringInArray(std::string string, std::string arrayOfStrings[], int length)
{
	for (int i = 0; i < length; i++)
	{
		std::string temp_string = arrayOfStrings[i];
		if (temp_string == string)
		{
			return true;
		}
	}
	return false;
}

std::array<int, 2> askForTwoNumbers()
{
	int number_o, number_t;
	std::array<int, 2> result;
	std::cout << "Please, provide two integers:\n";
	std::cin >> number_o >> number_t; 
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Please, provide correct integers:\n";
		std::cin >> number_o >> number_t;
	}
	result = { number_o, number_t };
	return result;
}

int main()
{
	std::string operation;
	std::array<int, 2> numbers;
	int number_one, number_two;
	std::array<std::string, 4> available_operations = {"add", "subtract", "multiply", "divide"};
	while (true)
	{
		std::cout << "What operation do you want to perform?\n";
		std::cout << "Type: 'add', 'subtract', 'multiply', 'divide':\n";
		std::cin >> operation;
		if (!checkIfStringInArray(operation, available_operations.data(), 4)) continue;
		numbers = askForTwoNumbers();
		number_one = numbers[0];
		number_two = numbers[1];
		if (operation == "add")
		{
			std::cout << number_one << " + " << number_two << " = " << (number_one + number_two) << std::endl;
		}
		else if (operation == "subtract")
		{
			std::cout << number_one << " - " << number_two << " = " << (number_one - number_two) << std::endl;
		}
		else if (operation == "multiplication")
		{
			std::cout << number_one << " * " << number_two << " = " << (number_one * number_two) << std::endl;
		}
		else
		{
			if (number_two != 0)
			{
				std::cout << number_one << " / " << number_two << " = " << (number_one / number_two) << std::endl;
			}
			else
			{
				std::cout << "Can't divide by 0!" << std::endl;
			}
		}
	}
}