/*
Student Name: Chamod Gamage
Student Number:  20830088
SYDE 121 Lab: 04
Assignment: 02
Filename: lab04_02.cpp
I hereby declare that this code, submitted for credit for the course SYDE121,
is a product of my own efforts.  This coded solution has not been plagiarized
from other sources and has not been knowingly plagiarized by others.
Project:  STATISTICS
Purpose:  Given a list of doubles, output max, min, mean, and standard deviation
Due Date: Tuesday, October 22, 2019
*/

/*
Testing:
The program was run over a dozen times
User input system was not broken by any invalid input
Empty arrays were handled correctly
Arrays were maxed out at 20
Done and quit were handled correctly
Maximum, minimum, mean, and strandard deviation were calculated correctly everytime

*/

#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

void run_stat_sim();
// PURPOSE: Begins the statistics collection program which collects double values from user and outputs related stats
// INPUTS: None
// RETURNS: None



void calc_stats(const double DOUBLE_VALUES[21]);
// PURPOSE: Calculate max, min, mean, and standard deviation of list of doubles
// INPUTS: DOUBLE_VALUES (int array containing list of doubles for statistical analysis to be conducted on. 
//                        First value in array is the number of doubles in list, rest of array is list followed by zeroes.) 
// RETURNS: Outputs max, min, mean, and standard deviation to console

void replace_vals(double double_vals[21]);
// PURPOSE: Replace values within array of doubles according to user
// INPUTS: DOUBLE_VALUES (int array containing list of doubles for statistical analysis to be conducted on. 
//                        First value in array is the number of doubles in list, rest of array is list followed by zeroes.) 
// RETURNS: Edits values within double array

bool check_double(string potential_double);
// PURPOSE: Determine whether string passed in can be converted to a double
// INPUTS: potential_double (string that may or may not be converted to a double)
// RETURNS: True if string can be converted to a double; false if not











int main()
{
	run_stat_sim();
	return 0;

}

void run_stat_sim() {

	//SETUP
	double doubles[21] = { 0 }; //Array containing wins for X, wins for O, and ties (in that order)
	
	string input; //string used multiple times to hold user input values

	
	//PROCESSING
	cout << "\nEnter list of doubles, seperated line by line. When finished, enter 'done' or 'd' on a new line.\n";
	do { //Do-while loop collecting user inputted values until they enter 'done'
		
		cin >> input;
		if (input[0] != 'd' && doubles[0] < 20 && check_double(input)) {
			doubles[0]++;
			doubles[int(doubles[0])] = stod(input);
		}


	} while (input[0] != 'd');
	
	//OUTPUT
	calc_stats(doubles); //Calls function to print statistics to console
	replace_vals(doubles);

}



void calc_stats(const double DOUBLE_VALUES[21]) {
	
	double stats_array[4] = { 0 }; //Array to contain maximum, minimum, mean, and standard deviation of given doubles
	vector<double> double_list; //Vector containing only list of double values


	if (DOUBLE_VALUES[0] == 0) {
		cout << "\nNO VALUES IN ARRAY\n";
		return;
	}


	for (int position = 1; position <= int(DOUBLE_VALUES[0]); position++) {
		double_list.push_back(DOUBLE_VALUES[position]);
	}



	stats_array[0] = *max_element(double_list.begin(), double_list.end());
	stats_array[1] = *min_element(double_list.begin(), double_list.end());
	stats_array[2] = accumulate(double_list.begin(), double_list.end(), 0) / DOUBLE_VALUES[0];
	stats_array[3] = sqrt(inner_product(double_list.begin(), double_list.end(), double_list.begin(), 0.0) / DOUBLE_VALUES[0] - stats_array[2] * stats_array[2]);

	cout << "\nThe maximum value is:      " << stats_array[0];
	cout << "\nThe minimum value is:      " << stats_array[1];
	cout << "\nThe mean value is:         " << stats_array[2];
	cout << "\nThe standard deviation is: " << stats_array[3];

	

}

void replace_vals(double double_vals[21]) {
	string user_input; //string used multiple times to hold user input values
	int position; //int representing position in double list where value is to be replaced



	//PROCESSING

	if (double_vals[0] == 0) {
		cout << "\nNO VALUES IN ARRAY\n";
		return;
	}



	cout << "\nEnter position to be replaced (first number is in position 1). \n Then, enter new value on new line. \n When finished, enter 'quit' or 'q' on a new line.\n";
	do { //Do-while loop collecting user inputted values until they enter 'quit' or 'q'

		cout << "\n\n Enter position to replace number at: \n";
		cin >> user_input;
		if (user_input[0] == 'q') {
			continue;
		} else if (!check_double(user_input) || stoi(user_input) < 1 || stoi(user_input) > double_vals[0]) {
			cout << "\nINVALID POSITION. ENTER POSITION AGAIN!\n";
			continue;
		}
		else {
			position = stoi(user_input);
			cout << "\nEnter new value: \n";
			cin >> user_input;
			if (user_input[0] == 'q') {
				continue;
			}
			cout << double_vals[position] << " replaced by " << user_input << " at position " << position << ".\n";
			double_vals[position] = stod(user_input);

		}


	} while (user_input[0] != 'q');
	
	calc_stats(double_vals);
}

bool check_double(string potential_double) {

	//PROCESSING
	try
	{
		stod(potential_double);
	}
	catch (...)
	{
		return false;
	}
	return true;

}