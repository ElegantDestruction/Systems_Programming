#!/bin/bash

for i in {1..10}
do
	echo "Test Run $i" >> cpp_results.txt
	./main.out >> cpp_results.txt
	printf "\n" >> cpp_results.txt
done
