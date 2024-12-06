#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include "Inputs.h"




std::vector<int> arr1 = {};
std::vector<int> arr2 = {};

void displayValue(std::vector<int> arr, std::string arrNum) {
	if (arr.size() < 0) return;
	std::cout << "Nums in  " << arrNum << " \n";
	for ( int i:arr) {
		std::cout << i << " \n";
	}
}

int  findMin(std::vector<int> arr) {
	int min = 4444455;
	int pos;
	for (int i = 0; i < arr.size(); i++) {
		
		if (arr[i] <= min) {
			min = arr[i];
			pos = i;
		 
		}
	}

	return pos;
}

void fillArrays() {

	std::string currentCount = "";
	bool toggle = true;
	for (int i = 0; i < strlen(Inputs); i++) {



		if (std::isdigit(Inputs[i])) {

			currentCount += Inputs[i];
		}
		else {
			if (!currentCount.empty()) {
				int currentInput = std::stoi(currentCount);
				if (toggle) {
					arr1.push_back(currentInput);
				}
				else {
					arr2.push_back(currentInput);
				}
			}
			toggle = !toggle;
			currentCount = "";

		}
	}

	if (!currentCount.empty()) {
		int num = std::stoi(currentCount);
		if (toggle) {
			arr1.push_back(num);
		}
		else {
			arr2.push_back(num);
		}
	}
}

int main() {
	std::vector<int> arr1example = {1,2,3,3,3,4};
	std::vector<int> arr2example = { 3,3,3,4,5,9 };
	


	//displayValue(arr1, "array1");
	//displayValue(arr2, "array2");
	fillArrays();

	int distance = 0;
	
	int length = arr1.size();
	for (int i = 0; i < length; i++) {
		 
		int arr1min = findMin(arr1);
		int arr2min = findMin(arr2);

		if (arr1[arr1min] <= arr2[arr2min]) {
			distance += arr2[arr2min] - arr1[arr1min];
		}
		else {
			distance += arr1[arr1min] - arr2[arr2min];
		}


		arr1.erase(arr1.begin() + arr1min);
		arr2.erase(arr2.begin() + arr2min);
		

	}

	std::cout << "total distance is " << distance;

 
	return 0;
}