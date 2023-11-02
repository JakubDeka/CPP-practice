#include "Auxiliary.h"

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
