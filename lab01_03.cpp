/*
Student Name: Chamod Gamage
Student Number:    20830088
SYDE 121 Lab: 01
Assignment: 01
Filename: lab01_03.cpp
I hereby declare that this code, submitted for credit for the course SYDE121,
is a product of my own efforts.  This coded solution has not been plagiarized
from other sources and has not been knowingly plagiarized by others.
Project:  SUM
Purpose:  Output sum of series of consecutive integers, given user input of start and end
Due Date:  Friday, September 13, 2019
*/

/*
Test Cases
	 Start: |    1 |       1 |            1 |           5 |          777 |  -5 | 1 |
       End: |   10 |     100 |         3000 |      10,000 |       77,777 |   0 | 1 |
       Sum: |   55 |    5050 |    4,501,500 |  50,004,990 |     Overflow | -15 | 1 |


Valid range of values: -2147483647 <= start <= end <= 2147483647 ; end < start + 65535; sum <= 2147483647
*/

/*
Get start and end of series of consecutive integers from user input
Using simplified version of given formula, calculate sum of series
Output sum to console
*/

#include <iostream>
using namespace std;


int main()
{
	double start = 0;
	double end = 0;
	int sum = 0;

	//User inputs start and end of consecutive series
	cout << "Enter starting integer: ";
	cin >> start;
	cout << "You entered: " << start << "\n" ;
	cout << "Enter ending integer: ";
	cin >> end;
	cout << "You entered: " << end << "\n";


	//Sum is calculated and outputted to console
	sum = ((end - start + 1) / 2) * (start + end);
	cout << "The sum of these consecutive integers is: " << sum << "\n";
	return 0;

	
}