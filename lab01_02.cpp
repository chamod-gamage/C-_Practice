/*
Student Name: Chamod Gamage
Student Number:    20830088
SYDE 121 Lab: 01
Assignment: 01
Filename: lab01_02.cpp
I hereby declare that this code, submitted for credit for the course SYDE121,
is a product of my own efforts.  This coded solution has not been plagiarized
from other sources and has not been knowingly plagiarized by others.
Project:  POPULATION
Purpose:  Output population estimate for 4 different years using exponential formula
Due Date:  Friday, September 13, 2019
*/

/*
Test Cases
      Year: |   2018 |    2025 |     2050 |    2100 |
Population: | 8.5998 | 9.89233 |  16.3097 | 44.3343 |


Valid range of values: {2018,2025,2050,2100}

*/

/*
Store each year in a constant array
In a for loop, input each year into a formula and output population estimate to console

*/
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int YEARS[4] = { 2018,2025,2050,2100 };
	
	//For loop: Enter year into formula and output population estimate to console
	for (int x = 0; x < 4; x++) {

		double population = 6.0 * exp(0.02 * (YEARS[x] - 2000.0));
		cout << "The population estimate for " << YEARS[x] << " is " << population << " billion.\n";
	}
	return 0;
}
