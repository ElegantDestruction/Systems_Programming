#include <string>
#include <stdio.h>
#include "customers.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include <ctime>
#include <omp.h>

int main() {
	//Make my vector of customers
	std::vector<customers> master_list;


	//Get the file opened up
	std::string file_name = "accounts.txt";
	std::ifstream input_file;
	input_file.open(file_name);

	//Give error if no file
	if (!input_file) {
		std::cout << "No file here, make account.txt\n";
	}

	//Loop through and grab all of the information we need
	std::string current_id;
	std::string current_balance;
	while (getline(input_file, current_id)) {
		getline(input_file, current_balance);
		master_list.push_back(customers(current_id, stod(current_balance)));		
	}

	input_file.close();

	//Count the balances
	// --Sequential Run ---------------------------------------------------------------
	auto start = std::chrono::high_resolution_clock::now();
	int count = 0;
	for (int i = 0; i < master_list.size(); i++){
		if (master_list[i].get_balance() < 1000) {
			count += 1;
		}
	}
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start);
	
	std::cout << "Number of accounts with less than $1000: " << count << std::endl << "Sequential run: " << duration.count() << std::endl;
	// --END Sequential Run ------------------------------------------------------------
	//
	//
	// --Parallel Run (OMP) ------------------------------------------------------------------
	// Create some setup variables

	start = std::chrono::high_resolution_clock::now();
	count = 0;
	
	//Prep openmp run
	omp_set_dynamic(0);
	omp_set_num_threads(4);
#pragma omp parallel for schedule(static) reduction(+:count)
	for (int j = 0; j < master_list.size(); j++) {
		if (master_list[j].get_balance() < 1000) {
			count += 1;
		}
	}

	// Display results
	duration = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - start);
	
	std::cout << "Number of accounts with less than $1000: " << count << std::endl << "Parallel run: " << duration.count() << std::endl;


	return 0;
}
