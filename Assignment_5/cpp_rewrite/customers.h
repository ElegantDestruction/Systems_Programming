#pragma once

//Customer object meant to reflect the Customer class represented in java version

#include <stdio.h>
#include <string>

class customers {
private:
	std::string ID;
	double balance;
public:
	customers(std::string id, double balance);
	std::string get_ID();
	void set_ID(std::string id);
	double get_balance();
	void set_balance(double balance);



};
