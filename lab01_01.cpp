/*
Student Name: Chamod Gamage
Student Number:  20830088
SYDE 121 Lab: 01
Assignment: 01
Filename: lab01_01.cpp
I hereby declare that this code, submitted for credit for the course SYDE121,
is a product of my own efforts.  This coded solution has not been plagiarized
from other sources and has not been knowingly plagiarized by others.
Project:  WEIGHTS
Purpose:  Given an object weight, calculates number of various types of WEIGHTS required to weigh the object
Due Date:  Friday, September 13, 2019
*/

/*
Test Cases
Total Weight: | 1048 | 15,297 | 600,000 | 0 | 14 |  666,666,600,000 |
	  150 lb: |    6 |    101 |    4000 | 0 |  0 | 14316557 (wrong) |
	   50 lb: |    2 |      2 |       0 | 0 |  0 |        1 (wrong) |
	   30 lb: |    1 |      1 |       0 | 0 |  0 |        1 (wrong) |
	   15 lb: |    1 |      1 |       0 | 0 |  0 |        1 (wrong) |
		1 lb: |    3 |      2 |       0 | 0 | 14 |        2 (wrong) |
                                                          (OVERFLOW)
Valid range of values: 0 <= total_weight <= 2147483647

*/
/*
Initialize integer containing total weight, array containing types of WEIGHTS, and array that will contain counts of each weight
Iterate through each type of weight in a for loop from heaviest to lightest, adding as many WEIGHTS as possible
Output count of each weight line by line
*/
/*
Student Name: Chamod Gamage
Student Number:  20830088
SYDE 121 Lab: 02
Assignment: 01
Filename: lab02_01.cpp
I hereby declare that this code, submitted for credit for the course SYDE121,
is a product of my own efforts.  This coded solution has not been plagiarized
from other sources and has not been knowingly plagiarized by others.
Project:  PRIMES
Purpose:  Given an integer greater than 1, output all primes less than or equal to integer
		  Also note any palindromic primes under 10,000 and primes under 100,000 whose digits sum to an odd number
Due Date:  Friday, September 20, 2019
*/

/*
Test Cases
Total Weight: | 1048 | 15,297 | 600,000 | 0 | 14 |  666,666,600,000 |
	  150 lb: |    6 |    101 |    4000 | 0 |  0 | 14316557 (wrong) |
	   50 lb: |    2 |      2 |       0 | 0 |  0 |        1 (wrong) |
	   30 lb: |    1 |      1 |       0 | 0 |  0 |        1 (wrong) |
	   15 lb: |    1 |      1 |       0 | 0 |  0 |        1 (wrong) |
		1 lb: |    3 |      2 |       0 | 0 | 14 |        2 (wrong) |
														  (OVERFLOW)
Valid range of values: 0 <= total_weight <= 2147483647

*/
/*
Initialize integer containing total weight, array containing types of WEIGHTS, and array that will contain counts of each weight
Iterate through each type of weight in a for loop from heaviest to lightest, adding as many WEIGHTS as possible
Output count of each weight line by line
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int bound = 0;
	vector<int> factors = {};
	bool prime = true;


	while (bound < 2) {
		cout << "Enter your integer: ";
		cin >> bound;
		cout << "\nYou entered: " << bound;

		if (bound < 2) {
			cout << "Invalid input; integer must greater than 1!";
		}
	}



	for (int x = 1; x < bound; x++) {
		prime = true;
		for (int i = 0; i < factors.size(); i++) {
			if (x % factors[i] == 0) {
				prime = false;
			}
		}

		if (prime == true) {
			factors.push_back(x);
			cout << x;

		}


	}



}



#include <iostream>
using namespace std;
int main()
{
	int total_weight = 1048;
	int WEIGHTS[5] = { 150,50,30,15,1 }; //constant array containing types of weights
	int count[5] = { 0,0,0,0,0 };
	int num_weights = 0;

	//User inputs object weight
	
	cout << "Enter the weight of the object: ";
	cin >> total_weight;
	cout << "\nYou entered: " << total_weight << "\n";

	//Loop to find number of each weight and output result to console
	
	for (int x = 0; x < 5; x++) {
		num_weights = total_weight / WEIGHTS[x];

		//Checks whether there is enough remaining weight for the weight type
		
		if (num_weights * WEIGHTS[x] <= total_weight) {
			total_weight -= num_weights * WEIGHTS[x];
			count[x] = num_weights;
		}

		cout << WEIGHTS[x] << "lb: " << count[x];
		cout << "\n";
	}
	return 0;
}
