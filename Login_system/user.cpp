#include "user.h"
#include<string>
#include<fstream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<ctype.h>

User::User()
{
}

void User::get_info()
{
	std::cout << "First name: ";
	std::cin >> first_name;
	std::cout << "last name: ";
	std::cin >> last_name;
	std::cout << "Email: ";
	std::cin >> email;
	std::cout << "Phone: ";
	std::cin >> phone;
	std::cout << "Birthdate: ";
	std::cin >> birthdate;

	try 
	{
		std::cout << "Age: ";
		std::cin >> age;
		if (isalpha(age))
			throw std::exception("Age must be numeric!", age);
	}
	catch (std::exception e) 
	{
		do
		{
			std::cout << "Age must be numeric!" << std::endl;
			std::cout << "Age: ";
			std::cin >> age;
		} while (isalpha(age));
	}

	try
	{

		std::cout << "Sex: ";
		std::cin >> sex;
		if (!(sex == 'M' || sex == 'F'))
			throw std::exception("Sex must be F-female or M-male!", sex);
	}
	catch (std::exception e1)
	{
		do
		{
			std::cout << "Sex must be F-female or M-male" << std::endl;
			std::cout << "Sex: ";
			std::cin >> sex;
		} while (!(sex == 'M' || sex == 'F'));
	}
	
	std::cout << "Country: ";
	std::cin >> adress.country;
	std::cout << "City: ";
	std::cin >> adress.city;
	std::cout << "Street: ";
	std::cin >> adress.street;
	std::cout << "Number: ";
	std::cin >> adress.no;
	std::cout << "Username: ";
	std::cin >> username;
	std::cout << "Password: ";
	std::cin >> password;
	std::cout << "Registration number: ";
	std::cin >> registration_no;
}

void User::save_info()
{
	std::string const file_name = username;

	std::ofstream f;
	f.open(file_name, std::ios::out);
	if (f.is_open())
	{
		f << username << std::endl;
		f << password << std::endl;
		f << first_name << std::endl;
		f << last_name << std::endl;
		f << phone << std::endl;
		f << email << std::endl;
		f << birthdate << std::endl;
		f << age << std::endl;
		f << sex << std::endl;
		f << adress.country << std::endl;
		f << adress.city << std::endl;
		f << adress.street << std::endl;
		f << adress.no << std::endl;

		f.close();
	}
	else
		std::cout << "Cannot open the file!" << std::endl;

}

User::~User()
{
}
