/*
Student Name: Chamod Gamage
Student Number:  20830088
SYDE 121 Lab: 03
Assignment: 01
Filename: lab03_01.cpp
I hereby declare that this code, submitted for credit for the course SYDE121,
is a product of my own efforts.  This coded solution has not been plagiarized
from other sources and has not been knowingly plagiarized by others.
Project:  SOCCER
Purpose:  Randomly generate soccer-related events and output related text and statistics
Due Date: Tuesday, October 8, 2019
*/

/*
Testing:
The program was run over a dozen times
Number of events did not remain the same
Actual statistics/events did not remain the same
Statistics incremented properly each time
Half-time stats and full-time stats outputted correctly each time
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

void print_report(string &statistics, bool full_time);
// PURPOSE: Outputs half-time and full-time statistics to console
// INPUTS: statistics (string that contains the values for each stat) --> see string stats in start_soccer_sim function
//         full_time (boolean that determines whether full-time or part-time stats are to be output)
// RETURNS: Outputs half-time and full-time statistics


void primary_events(string &makeshift_statistics_array);
// PURPOSE: Determines which event occurs according to random number generation and passes information on to a corresponding function
// INPUTS: makeshift_statistics_array (string that contains the values for each stat) --> see string stats in start_soccer_sim function
// RETURNS: Outputs text to console corresponding to event and passes on info to further functions if required


void foul_event(string &makeshift_stat_array, bool team_val, int num_shot_options);
// PURPOSE: Outputs half-time and full-time statistics to console
// INPUTS: makeshift_statistics_array (string that contains the values for each stat) --> see string stats in start_soccer_sim function
//         team_val (boolean that states which team the event is occuring for (0 = A; 1 = B))
//         num_shot_options (states number of event options for shot following (3 for penalty, 4 for free kicks))
// RETURNS: Outputs text to console corresponding to foul event and passes on info to shot function; increments corresponding stats in stat string

void shot_event(string &makeshift_stats_array, bool team_value, int num_options);
// PURPOSE: Outputs half-time and full-time statistics to console
// INPUTS: makeshift_stats_array (string that contains the values for each stat) --> see string stats in start_soccer_sim function
//         team_val (boolean that states which team the event is occuring for (0 = A; 1 = B))
//         num_shot_options (states number of event options for shot following (3 for penalty, 4 for free kicks))
// RETURNS: Outputs text to console corresponding to shot event; increments stats in stat string

void run_soccer_sim(int number_of_events, int halftime);
// PURPOSE: Begins the simulation of a soccer game given the number of events and when halftime occurs
// INPUTS: number_of_events (int containing the number of events in the game), 
//         halftime (int containing the number of events occuring before halftime)
// RETURNS: Uses other functions to output event related text and statsheets at half time and full time.




int main()
{
	srand(time(NULL));

	//Variable declarations
	int num_events = rand() % 30 + 1; //number of events taking place in the game (randomized 1 - 30)
	int half = rand() % num_events + 1; //number of events taking place before half time (randomized 1 - num_events)

	run_soccer_sim(num_events, half);
	return 0;
	
}


void print_report(string &statistics, bool full_time)

{
	//PROCESSING & OUTPUT
	cout << "***********************************************";
	if (full_time == true) {
		cout << "\n\nFULL TIME STAT SHEET\n\n";
	}
	else {
		cout << "\n\nHALF TIME STAT SHEET\n\n";
	}

	//Parsing through the statistics string and outputting information to the console as such
	cout << "SCORE:			TEAM A (" << stoi(statistics.substr(0, 2))  << "-" << stoi(statistics.substr(2, 2))  << ") TEAM B\n\n";
	cout << "SHOTS ON TARGET:	TEAM A (" << stoi(statistics.substr(4, 2))  << "-" << stoi(statistics.substr(6, 2))  << ") TEAM B\n";
	cout << "SHOTS OFF TARGET:	TEAM A (" << stoi(statistics.substr(8, 2))  << "-" << stoi(statistics.substr(10, 2))  << ") TEAM B\n";
	cout << "BLOCKED SHOTS:		TEAM A (" << stoi(statistics.substr(12, 2))  << "-" << stoi(statistics.substr(14, 2))  << ") TEAM B\n";
	cout << "FOULS:			TEAM A (" << stoi(statistics.substr(16, 2))  << "-" << stoi(statistics.substr(18, 2))  << ") TEAM B\n";
	cout << "YELLOW CARDS:		TEAM A (" << stoi(statistics.substr(20, 2))  << "-" << stoi(statistics.substr(22, 2))  << ") TEAM B\n";
	cout << "RED CARDS:		TEAM A (" << stoi(statistics.substr(24, 2))  << "-" << stoi(statistics.substr(26, 2))  << ") TEAM B\n\n";
	cout << "***********************************************\n";
}

void primary_events(string &makeshift_statistics_array) {
	//SETUP
	int event_type = rand() % 6 + 1;
	bool team;
	int shot_options = 4;

	//PROCESSING & OUTPUT
	switch (event_type) {


	case 1: //Initiate shot opportunity for Team A
		cout << "Team A looks like they have a goal scoring opportunity here...\n";
		team = 0;
		shot_event(makeshift_statistics_array, team, shot_options);
		break;


	case 2: //Initiate shot opportunity for Team B
		cout << "Team B looks like they have a goal scoring opportunity here...\n";
		team = 1;
		shot_event(makeshift_statistics_array, team, shot_options);
		break;


	case 3: //Initiate free kick opportunity for Team A and foul for Team B

		cout << "Oof. Some player from Team A is flopping all over the field. The ref has decided to award Team A with a free kick. \n";
		team = 1;
		foul_event(makeshift_statistics_array, team, shot_options);
		break;

	case 4://Initiate free kick opportunity for Team B and foul for Team A
		cout << "Oh no. Some player from Team A has seriously fouled one of Team B's star players. Hopefully he hasn't torn his ACL. \n Anyways, the ref has awarded a free kick to team B. \n";
		team = 0;
		foul_event(makeshift_statistics_array, team, shot_options);
		break;

	case 5: //Initiate penalty kick opportunity for Team A and foul for Team B
		cout << "Someone has just fallen inside Team B's penalty box. The ref's pointed to the spot; it's a penalty shot for Team A!\n";
		shot_options = 3;
		team = 1;
		foul_event(makeshift_statistics_array, team, shot_options);
		break;


	case 6: //Initiate penalty kick opportunity for Team B and foul for Team A
		cout << "Someone has just fallen inside Team A's penalty box. The ref's pointed to the spot; it's a penalty shot for Team B!\n";
		shot_options = 3;
		team = 0;
		foul_event(makeshift_statistics_array, team, shot_options);
		break;


	}
}

void foul_event(string &makeshift_stat_array, bool team_val, int num_shot_options) {

	//SETUP
	string updated_value; //Temporary variable to hold new values for each statistic to be updated
	
	//PROCESSING & OUTPUT
	switch (rand() % 3) {

	
	case 0: //No card; increment fouls for given team in statistics string
		cout << "The ref has decided that the foul was not worthy of a card.\n";
		updated_value = to_string(stoi(makeshift_stat_array.substr(16 + 2 * team_val, 2)) + 1);
		makeshift_stat_array[16 + 2 * team_val] = updated_value[0];
		makeshift_stat_array[16 + 2 * team_val + 1] = updated_value[1];
		break;

	case 1: //Yellow card; increment fouls and yellows for given team in statistics string
		cout << "The ref has reached into his pocket...and pulled out a yellow card. One more for the offending player and he's out! \n";
		updated_value = to_string(stoi(makeshift_stat_array.substr(16 + 2 * team_val, 2)) + 1);
		makeshift_stat_array[16 + 2 * team_val] = updated_value[0];
		makeshift_stat_array[16 + 2 * team_val + 1] = updated_value[1];
		
		updated_value = to_string(stoi(makeshift_stat_array.substr(20 + 2 * team_val, 2)) + 1);
		makeshift_stat_array[20 + 2 * team_val] = updated_value[0];
		makeshift_stat_array[20 + 2 * team_val + 1] = updated_value[1];
		break;

	case 2: //Red card; increment fouls and reds for given team in statistics string
		cout << "In a shocking turn of events, the referee has sent the offending player off with a red card!\n";
		updated_value = to_string(stoi(makeshift_stat_array.substr(16 + 2 * team_val, 2)) + 1);
		makeshift_stat_array[16 + 2 * team_val] = updated_value[0];
		makeshift_stat_array[16 + 2 * team_val + 1] = updated_value[1];
		
		updated_value = to_string(stoi(makeshift_stat_array.substr(24 + 2 * team_val, 2)) + 1);
		makeshift_stat_array[24 + 2 * team_val] = updated_value[0];
		makeshift_stat_array[24 + 2 * team_val + 1] = updated_value[1];
		break;
	}

	shot_event(makeshift_stat_array, !team_val, num_shot_options);
}

void shot_event(string &makeshift_stats_array, bool team_value, int num_options) {
	
	//SETUP
	string updated_val;

	//PROCESSING & OUTPUT
	//Divide into each case based on random number generation
	switch (rand() % num_options) {

	case 0: //Goal scored; increment goals and shots on goal for given team
		cout << "They take their shot...and they score!\n";
		updated_val = to_string(stoi(makeshift_stats_array.substr(2 * team_value, 2)) + 1);
		makeshift_stats_array[2 * team_value] = updated_val[0];
		makeshift_stats_array[2 * team_value + 1] = updated_val[1];

		updated_val = to_string(stoi(makeshift_stats_array.substr(4+ 2 * team_value, 2)) + 1);
		makeshift_stats_array[4 + 2 * team_value] = updated_val[0];
		makeshift_stats_array[4 + 2 * team_value + 1] = updated_val[1];
		break;

	case 1: //Save; increment shots on target for given team
		cout << "They shoot their shot...and get rejected! What a save by the goalkeeper!\n";
		updated_val = to_string(stoi(makeshift_stats_array.substr(4 + 2 * team_value, 2)) + 1);
		makeshift_stats_array[4 + 2 * team_value] = updated_val[0];
		makeshift_stats_array[4 + 2 * team_value + 1] = updated_val[1];
		break;

	case 2: //Miss; increment shots off target for given team
		cout << "They take a shot...it skies over the crossbar. Close, but no cigar. \n";
		updated_val = to_string(stoi(makeshift_stats_array.substr(8 + 2 * team_value, 2)) + 1);
		makeshift_stats_array[8 + 2 * team_value] = updated_val[0];
		makeshift_stats_array[8 + 2 * team_value + 1] = updated_val[1];
		break;

	case 3: //Blocked; increment blocked shots for given team and shots off target
		cout << "They take a shot, but it has been blocked well before reaching the net. Excellent defence. \n";
		
		updated_val = to_string(stoi(makeshift_stats_array.substr(12 + 2 * team_value, 2)) + 1);
		makeshift_stats_array[12 + 2 * team_value] = updated_val[0];
		makeshift_stats_array[12 + 2 * team_value + 1] = updated_val[1];

		updated_val = to_string(stoi(makeshift_stats_array.substr(8 + 2 * team_value, 2)) + 1);
		makeshift_stats_array[8 + 2 * team_value] = updated_val[0];
		makeshift_stats_array[8 + 2 * team_value + 1] = updated_val[1];
		break;
	}
}

void run_soccer_sim(int number_of_events, int halftime) {

	//SETUP
	string stats = "0000000000000000000000000000"; //String containing all statistics about game (see details below)
	//Format of stats string: 
	//Goals, shots on goal, shots off goal, blocked shots, fouls, yellow cards, and red cards from left to right
	//Alternates between team A and B for each stat. 2 digits per stat per team


	//PROCESSING & OUTPUT
	//For loop progresses through game event by event
	for (int event = 0; event < number_of_events; event++) {

		cout << "\n\n";

		if (event == halftime - 1) {
			print_report(stats, false);
		}

		primary_events(stats);
	}
	print_report(stats, true);
}