#include <string>
#include <iostream>

int main()
{
	std::string str1 = "Hello"; // Initializing with a string literal
	std::string str2("World");	// Initializing with constructor
	std::string str3(5, 'x');	// Initializing with 5 'x' characters

	std::string result = str1 + str2;
	char firstChar = str1[0];				  // Accessing individual characters
	int length = str1.length();				  // Length of the string
	std::string sub = str1.substr(1, 3);	  // Extracting a substring from index 1 to 3
	size_t pos = str1.find("e");			  // Finding substring in the string
	str1.append(" World");					  // Appending to the string
	str1.erase(2, 3);						  // Erase 3 characters from index 2
	str1.replace(1, 3, "XYZ");				  // Replace characters from index 1 to 3 with "XYZ"
	int num = std::stoi(str1);				  // Convert string to integer
	std::string strNum = std::to_string(num); // Convert integer to string

	for (char c : str1)
	{
		// Loop through each character
	}

	const char *cstr = str1.c_str(); // c_str çevirme
	std::string cppStr(cstr);		 // cpp string çevirme

	// Empty string
	std::string emptyStr;

	// C-style string to std::string
	const char *cstr = "Hello, C++";
	std::string str4 = cstr;

	// Input from user
	std::string userInput;
	std::cout << "Enter a string: ";
	std::cin >> userInput;

	return 0;
}
