/*
Student Name: Chamod Gamage
Student Number:  20830088
SYDE 121 Lab: 02
Assignment: 02
Filename: lab02_02.cpp
I hereby declare that this code, submitted for credit for the course SYDE121,
is a product of my own efforts.  This coded solution has not been plagiarized
from other sources and has not been knowingly plagiarized by others.
Project:  BASEBALL
Purpose:  Output total distance travelled of falling ball as per physics equation d = (1/2)gt^2
Due Date:  Tuesday, September 24, 2019
*/

/*

Valid range of values: inapplicable (no user input)     
Time taken to fall from 15000m was just over 55.3 seconds. (Duration of measurement was extended as such)

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Variable declarations
	double max_time = 2000;
	double max_distance = 15000;
	double time = 0;
	double distance = 0;
	double old_distance = 0;
	double total_distance = 0;
	const double GRAVITY = 9.80665;
	double resolution_change = 1;

	
	while ((time <= max_time) && (total_distance < max_distance)) {

		//Changes resolution to 0.1 seconds if ball is close to ground
		if (0.5 * GRAVITY * (time + 3) * (time + 3) > max_distance) {
			resolution_change = 0.1;
		}

		//Calculating information
		old_distance = total_distance;
		total_distance = 0.5 * (GRAVITY * time * time);
		distance = total_distance - old_distance;

		//Info output
		cout << "Time(s): " << setprecision(3) << fixed << time;
		cout << "    Interval Distance(m): " << setprecision(3)  << fixed << distance;
		cout << "    Total Distance(m): " << setprecision(3) << fixed << total_distance;
		cout << "\n";

		//Increments time based on resolution
		time += (1 * resolution_change);
	}
	return 0;
}


