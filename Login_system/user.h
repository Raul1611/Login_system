#pragma once
#include<iostream>
class User
{
private:
	std::string password, username, registration_no;
	std::string birthdate, email, phone, first_name, last_name;
	int age;
	char sex;
	struct adress {
		std::string country, city, street;
		int no;
	}adress;
public:
	User();
	void get_info();
	void save_info();
	~User();
};

