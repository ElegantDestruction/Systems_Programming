#include <stdio.h>
#include <string>
#include "customers.h"


customers::customers(std::string id, double balance) {
	this->ID = id;
	this->balance = balance;
};

std::string customers::get_ID() {
	return this->ID;
}

void customers::set_ID(std::string id) {
	this->ID = id;
}

double customers::get_balance(){
	return this->balance;
}

void customers::set_balance(double balance) {
	this->balance = balance;
}
