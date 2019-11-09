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
		  Also notes any palindromic primes under 10,000 and primes under 100,000 whose digits sum to an odd number
Due Date:  Tuesday, September 24, 2019
*/

/*

Valid range of values: 0 <= upper_bound <= 2147483647

Test Cases:
1 --> User forced to reenter (correct)
2 --> 2 (PALINDROME) (correct)
5 --> 2 (PALINDROME), 3 (PALINDROME) (ODD DIGIT SUM), 5 (PALINDROME) (ODD DIGIT SUM) (correct)
100 --> correct
12000 --> correct
120000 --> correct

*/




#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main()
{

	//Variable declaration
	double upper_bound = 0;
	bool prime = true;
	vector<int> factors = {};
	string user_input = "";

	//Take in upper bound for prime check
	while (upper_bound < 2 || upper_bound != round(upper_bound))  {
		cout << "Enter your integer: ";
		cin >> user_input;
		
		try
		{
			upper_bound = stoi(user_input);
		}
		catch (std::invalid_argument const& e)
		{
		}
		catch (std::out_of_range const& e)
		{
		}
		
		cout << "\nYou entered: " << user_input << "\n";

		if (upper_bound < 2 || upper_bound != round(upper_bound)) {
			cout << "Invalid input; must be integer greater than 1!\n";
		}
	}

	//Outer for loop iterating through each number below the bound
	for (int number = 2; number < upper_bound; number++) {

		prime = true;

		//Inner for loop checking if previous primes are a factor of number being checked
		for (int vector_index = 0; vector_index < factors.size(); vector_index++) {
			if (number % factors[vector_index] == 0) {
				prime = false;

			}
		}

		
		if (prime == true) {
			
			//Adds number to vector containing the discovered primes if it is prime
			factors.push_back(number);
			
			cout << number;

			//Checks whether number is a palindrome
			string string_num = to_string(number);
			string reverse_num = string_num;
			reverse(reverse_num.begin(), reverse_num.end());

			if ((to_string(number) == reverse_num) && (number < 10000)) {
				cout << " (PALINDROME)";
			}

			//Checks whether number's digits sum to an odd number
			int digit_sum = 0;
			for (int digit = 0; digit < string_num.length(); digit++) {
				digit_sum += string_num[digit];
			}
			if ((digit_sum % 2 == 1) && (number < 100000)) {
				cout << " (ODD DIGIT SUM)";
			}

			cout << "\n";
		}
	}
	return 0;
}


