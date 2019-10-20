// OS_Assignment_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <thread>
#include <mutex>
#include <ctime>
#include <chrono>
#include <vector>
#include <omp.h>

using namespace std;
using namespace std::chrono;

//Global matrix and value declarations
const uint64_t Dim = 1000;
const uint64_t rand_max = 1000000000;
vector<vector<uint64_t>> matrix_a;  //Random Matrix 1
vector<vector<uint64_t>> matrix_b;	//Random Matrix 2
vector<vector<uint64_t>> matrix_c;	//Parallel Product Matrix (1x2)
vector<vector<uint64_t>> matrix_d;	//Sequential Product Matrix (1x2)


//Function declarations
void print_matrix(vector<vector<uint64_t>> given_matrix);
void sequential_matrix_multiplication(int mode, uint64_t row, uint64_t column);
void parallel_matrix_multiplication(uint64_t start, uint64_t stop);
void construct_matricies();

int main()
{
	//Construct and initialize matrix
	construct_matricies();


	//Get a printout to double check the initialization matrix
	print_matrix(matrix_a);
	print_matrix(matrix_b);
	print_matrix(matrix_c);
	print_matrix(matrix_d);


	//Start Sequential Matrix Multiplication
	cout << "#######Start Sequential Operation " << endl;
	auto start = high_resolution_clock::now();
	for (int current_row = 0; current_row < Dim; current_row++) {
		for (int current_column = 0; current_column < Dim; current_column++) {
			sequential_matrix_multiplication(0, current_row, current_column);
		}
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Sequential Multiplication Time: " << duration.count() << endl;


	//Start Parallel Matrix Multiplication
	int from = 0;
	int to = 0;
	int workload = Dim / 4;
	int dim1 = workload;
	int dim2 = workload * 2;
	int dim3 = workload * 3;
	int dim4 = Dim - 1;

	cout << "#######Start Parallel Operation " << endl;
	start = high_resolution_clock::now();

	//Create threads, and join them
	std::thread thread_1(parallel_matrix_multiplication, 0, dim1);
	std::thread thread_2(parallel_matrix_multiplication, (dim1 + 1), dim2);
	std::thread thread_3(parallel_matrix_multiplication, (dim2 + 1), dim3);
	std::thread thread_4(parallel_matrix_multiplication, (dim3 + 1), dim4);
	thread_1.join(); thread_2.join(); thread_3.join(); thread_4.join();

	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Parallel time in microseconds: " << duration.count() << endl;


	//Print c and d to ensure the multiplication is correct
	print_matrix(matrix_c);
	print_matrix(matrix_d);


	//End
	return 0;
}


//Parallel Matrix Multiplication Function
void parallel_matrix_multiplication(uint64_t start, uint64_t stop) {
	for (uint64_t current_row = start; current_row <= stop; current_row++) {
		for (uint64_t column = 0; column < Dim; column++) {
			sequential_matrix_multiplication(1, current_row,column);
		}
	}
}


//Sequential Matrix Multiplication function
//Pass it a desired row and column product, and it will return the product for it
void sequential_matrix_multiplication(int mode, uint64_t row, uint64_t column) {
	uint64_t sum = 0;
	for (int i = 0; i < Dim; i++) {
		sum += matrix_a[row][i] * matrix_b[i][column];
	}

	if (mode == 0) {
		matrix_c[row][column] = sum;
	}
	else {
		matrix_d[row][column] = sum;
	}
}


//Function to print out the given array
void print_matrix(vector<vector<uint64_t>> given_matrix) {
	//this function prints the first and last 10 rows and columns.
	//precondition: need to make sure that the vectors have at least 10X10 rows and columns.
	uint64_t count;
	if (given_matrix.size() > 10) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++)
			{
				cout << setw(7) << given_matrix[i][j] << " ";

			}
			cout << endl;
		}

		cout << "--------------------------------" << endl;
	}
	else
	{////printing vectors
		for (int i = 0; i < given_matrix.size(); i++) {
			for (int j = 0; j < given_matrix.size(); j++)
			{
				cout << setw(7) << given_matrix[i][j] << " ";

			}
			cout << endl;
		}

		cout << "--------------------------------" << endl;

	}
}




//Use to initialize the matricies and input random numbers to a and b
void construct_matricies() {

	//Set up srand
	srand(time(nullptr));

	//Loop through first dimension
	for (int i = 0; i < Dim; i++) {
		matrix_a.push_back(vector<uint64_t>(Dim));
		matrix_b.push_back(vector<uint64_t>(Dim));
		matrix_c.push_back(vector<uint64_t>(Dim));
		matrix_d.push_back(vector<uint64_t>(Dim));

		//Loop through second dimension
		for (int j = 0; j < Dim; j++) {
			matrix_a[i][j] = rand() % (rand_max + 1);
			matrix_b[i][j] = rand() % (rand_max + 1);
			matrix_c[i][j] = 0;
			matrix_d[i][j] = 0;
		}
	}
}