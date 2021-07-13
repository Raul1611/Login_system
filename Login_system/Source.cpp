#include "user.h"
#include<iterator>
#include<filesystem>
#include<fstream>

std::vector<std::string> file_names;
std::vector<std::string> usernames;
std::vector<std::string> passwords;
std::vector<std::string>::iterator it1, it2, it3;

void add_user();
void delete_user(std::string);
void options();
void sec_options(std::string);
void print_info(std::string);

int main()
{
	std::string user_file, username, password;
	std::string f_username, f_password;
	int opt;

	std::string path = "C:/Users/dumit/Desktop/Poli/C++ practice/Login_system/Login_system";

	do
	{
		options();

		std::cout << "Option: ";
		std::cin >> opt;
		std::cout<<std::endl;

		switch (opt)
		{
		case 0:
			exit(0);
			break;

		case 1: 

			file_names.clear();
			usernames.clear();
			passwords.clear();

			for (const auto & entry : std::experimental::filesystem::directory_iterator(path))
			{
				if (entry.path().filename().extension() == "" && entry.path().filename().compare("Debug"))
					file_names.push_back(entry.path().filename().generic_string());
			}

			for (it3 = file_names.begin(); it3 != file_names.end(); it3++)
			{
				user_file = *it3;

				std::ifstream file;
				file.open(user_file, std::ios::in);
				if (file.is_open())
				{
					file >> f_username;
					file >> f_password;

					usernames.push_back(f_username);
					passwords.push_back(f_password);

					file.close();
				}
			}
			
			std::cout << "Username: ";
			std::cin >> username;
			std::cout << "Password: ";
			std::cin >> password;
			std::cout << std::endl;

			it1 = find(usernames.begin(), usernames.end(), username);
			it2 = find(passwords.begin(), passwords.end(), password);

			if (it1 == usernames.end())
				std::cout << "Wrong username! Try again! " << std::endl;
			else if (it2 == passwords.end())
				std::cout << "Wrong password! Try Again! " << std::endl;
			else
			{
				std::cout << "Connected!" << std::endl;
				opt = 0;
				sec_options(username);
				opt = 1;
			}
			break;

		case 2:
			add_user();
		}

	} while (opt);

	system("pause");
	return 0;
}

void add_user()
{
	User user1;
	user1.get_info();
	user1.save_info();
}

void delete_user(std::string user)
{   
	remove(usernames.begin(), usernames.end(), user);

	if (std::experimental::filesystem::remove(user))
		std::cout << "User " << user << " deleted.\n";
	else
		std::cout << "User " << user << " not found.\n";
}

void options()
{
	std::cout << std::endl;
	std::cout << "------Welcome!------" << std::endl << std::endl;
	std::cout << "0. Exit." << std::endl;
	std::cout << "1. Login." << std::endl;
	std::cout << "2. Register." << std::endl;
	std::cout << "--------------------" << std::endl << std::endl;
}

void sec_options(std::string user)
{
	int opt;

	do
	{
		std::cout << std::endl;
		std::cout << "--------------------" << std::endl << std::endl;
		std::cout << "0. Log out." << std::endl;
		std::cout << "1. My info." << std::endl;
		std::cout << "2. Delete account." << std::endl;
		//std::cout << "3. Change password." << std::endl;
		//std::cout << "2. Change username." << std::endl;
		std::cout << "--------------------" << std::endl << std::endl;

		std::cout << "Option: ";
		std::cin >> opt;
		std::cout << std::endl;


		switch (opt)
		{
		case 0: 
			opt = 0;
			break;

		case 1:
			print_info(user);
			break;

		case 2:
			delete_user(user);
			opt = 0;
			break;
		}
	} while (opt);
}

void print_info(std::string user)
{
	std::ifstream file;
	file.open(user, std::ios::in);
	if (file.is_open())
	{
		while (!file.eof())
		{
			std::string data;
			file >> data;
			std::cout << data << std::endl;
		}
		file.close();
	}
}
