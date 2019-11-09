/*
Student Name: Chamod Gamage
Student Number:  20830088
SYDE 121 Lab: 05
Assignment: 01
Filename: lab05_01.cpp
I hereby declare that this code, submitted for credit for the course SYDE121,
is a product of my own efforts.  This coded solution has not been plagiarized
from other sources and has not been knowingly plagiarized by others.
Project:  SCALABLE VECTOR GRAPHICS
Purpose:  Take in information from a input text file and generate a text file with scalable vector graphics text drawing a bar graph
Due Date: Tuesday, October 29, 2019
*/

/*
Testing:

*/

#include <iostream>
#include <string>
#include <numeric>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


void make_logo();
// PURPOSE: Writes SVG file for SYDE logo designed by me
// INPUTS: NONE
// RETURNS: Writes SVG text file


void run_SVG();
// PURPOSE: Begins the creation process of an SVG graph
// INPUTS: NONE
// RETURNS: Ultimately builds an SVG graph

void build_graph(vector <int>& rect_dimensions, vector<string> colours);
// PURPOSE: Takes variable information and outputs string in SVG format that would build the graph to external file
// INPUTS: rect_dimensions (vector containing the dimensions of each rectangle (height, width))
//		   colours (string vector contianing list of colours for each vector)
// RETURNS: Outputs string containing all SVG text required to build the graph to external file

void read_from_file(string names[5], vector<int>& values);
// PURPOSE: Reads information from text file containing formatted data (name, value) and stores data in array
// INPUTS: names (string array to contain the list of names in the input text file)
//		   values (int array to contain the list of values for each name in the input text file)
// RETURNS: Inserts names and sizes into corresponding arrays

void calc_dimensions(const string NAMES[5], vector<int>& VALUES, vector <int>& dimensions);
// PURPOSE: Reads information from text file containing formatted data (name, value) and stores data in array
// INPUTS: NAMES (string array to contain the list of names in the input text file)
//		   VALUES (int array to contain the list of values for each name in the input text file)
//		   dimensions (vector to contain the dimensions of each rectangle (height, width for each rectangle))
// RETURNS: Calculates and places dimensions of each rectangle in dimensions vector



int main()
{
	run_SVG();//Graph 
	make_logo();//SYDE logo 
	return 0;

}

void read_from_file(string names[5], vector<int>& values) {
	// [setup] initialize corresponding variables
	string cur_pair;

	// [INPUT] handle file inputs
	ifstream my_ifstream; // create ifstream instance	
	my_ifstream.open("input.txt"); // open the input file

	if (!my_ifstream.fail()) { // check for failure
		// [PROCESSING] extract and print individual values
		for (int index = 0; index < 5 ; ++index) { // read (key,value) pairs
			
			getline(my_ifstream, cur_pair); // read one line at time
			if (cur_pair.empty()) {
				break;
			}
			cout << index << endl;
			// separate into tokens; skip comma and space
			names[index] = cur_pair.substr(0, cur_pair.find(',', 0));
			values.push_back(atoi(cur_pair.substr(cur_pair.find(',', 0) + 2).c_str()));
			cout << values[index];
		}

		// [OUTPUT] close the file
		my_ifstream.close(); // close the output file
	}
	cout << "Successful file read.\n";
}

void calc_dimensions(const string NAMES[5], vector<int>& VALUES, vector <int>& dimensions) {

	// [setup] initialize corresponding variables
	const int MAX_PX = 390; //NO elements can extend beyond a 390 x 390 box
	const int MAX_VAL = *max_element(VALUES.begin(), VALUES.end()); //Maximum value in VALUES
	const double H_SCALE = (double)MAX_PX / (double)MAX_VAL; //The conversion rate between values and their corresponding height
	int height; //Variable to contain the height of each rectangle temporarily
	int width = int(MAX_PX / (2 * VALUES.size() + 1));//Width of each bar is the same; must leave bar space on left of first bar and right of last

	for (int index = 0; index < VALUES.size(); index++) { //Build dimensions vector

		height = int(VALUES[index] * H_SCALE);
		cout << height << endl;
		dimensions.push_back(height);
		dimensions.push_back(width);

	}

}

void build_graph(vector <int>& rect_dimensions, vector<string> colours) {

	// [setup] initialize corresponding variables
	const int MAX_PX = 390; //NO elements can extend beyond a 390 x 390 box
	int curr_x = rect_dimensions[1] + 10;//contains initial x-ordinate of current rectangle
	int curr_y;//contains initial y-ordinate of current rectangle
	int colour = 0; //index in colours array

	ofstream my_ofstream; // create ofstream instance
	my_ofstream.open("graph.svg"); // open the output file


	if (!my_ofstream.fail()) { // check for failure

		//OUTPUT 1
		my_ofstream << "<?xml version=\"1.0\"?>\n"; // output svg content to a file
		my_ofstream << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" ";
		my_ofstream << "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
		my_ofstream << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"500\" height=\"500\">\n";

		//PROCESSING & OUTPUT 2
		for (int index = 0; index < rect_dimensions.size(); index += 2) { //Bars

			curr_y = MAX_PX - rect_dimensions[index];


			my_ofstream << "<rect x=\"" << curr_x << "\" y=\"" << curr_y << "\"";
			my_ofstream << " width=\"" << rect_dimensions[index + 1] << "\" height=\"" << rect_dimensions[index];
			my_ofstream << "\" style=\"fill:" << colours[colour] << ";\"/>\n";

			curr_x += rect_dimensions[1] * 2;
			colour += 1;

		}

		//OUTPUT 3 (axes)
		my_ofstream << "<line x1=\"10\" y1=\"390\" x2=\"400\" y2=\"390\" style=\"stroke:purple;stroke-width:2\"/>\n";
		my_ofstream << "<line x1=\"10\" y1=\"0\" x2=\"10\" y2=\"390\" style=\"stroke:purple;stroke-width:2\"/>\n";
		my_ofstream << "</svg>\n";
		my_ofstream.close(); // close the output file

		cout << "Successful file write.";
	}

}

void run_SVG() {

	// [setup] initialize corresponding variables
	string the_names[5] = {}; //Will contain names 
	vector<int> the_values = {}; //Will contain values
	vector<int> the_dimensions = {}; //Will contain height and width of each rectangle
	vector<string> the_colours = { "blue", "red", "black", "yellow", "orange" };

	//PROCESSING & OUTPUT
	read_from_file(the_names, the_values);
	calc_dimensions(the_names, the_values, the_dimensions);
	build_graph(the_dimensions, the_colours);

}

void make_logo() {

	// [setup] initialize corresponding variables
	ofstream my_ofstream; // create ofstream instance
	my_ofstream.open("syde_logo_c2gamage.svg"); // open the output file


	if (!my_ofstream.fail()) { // check for failure

		//[OUTPUT] write to file
		my_ofstream << "<?xml version= \"1.0\"?>\n";
		my_ofstream << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
		my_ofstream << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"500\" height=\"500\">\n";

		//2024
		my_ofstream << "<style>\n";
		my_ofstream << "     .year{ font: italic 80px serif; fill: red; }";
		my_ofstream << "</style>\n";
		my_ofstream << "<text x=\"45\" y=\"460\" class=\"year\"> 2024 </text>\n";

		//S
		my_ofstream << "<rect x=\"45\" y=\"40\" width=\"20\" height=\"80\" style=\"fill:blue;\"/>\n";
		my_ofstream << "<rect x=\"45\" y=\"40\" width=\"80\" height=\"20\" style=\"fill:blue;\"/>\n";
		my_ofstream << "<rect x=\"45\" y=\"120\" width=\"80\" height=\"20\" style=\"fill:blue;\"/>\n";
		my_ofstream << "<rect x=\"105\" y=\"120\" width=\"20\" height=\"80\" style=\"fill:blue;\"/>\n";
		my_ofstream << "<rect x=\"45\" y=\"200\" width=\"80\" height=\"20\" style=\"fill:blue;\"/>\n";

		//Y
		my_ofstream << "<rect x=\"105\" y=\"220\" width=\"20\" height=\"80\" style=\"fill:green;\"/>\n";
		my_ofstream << "<rect x=\"105\" y=\"300\" width=\"80\" height=\"20\" style=\"fill:green;\"/>\n";
		my_ofstream << "<rect x=\"165\" y=\"220\" width=\"20\" height=\"80\" style=\"fill:green;\"/>\n";
		my_ofstream << "<rect x=\"135\" y=\"320\" width=\"20\" height=\"80\" style=\"fill:green;\"/>\n";

		//D
		my_ofstream << "<rect x=\"165\" y=\"40\" width=\"20\" height=\"180\" style=\"fill:red;\"/>\n";
		my_ofstream << "<rect x=\"245\" y=\"40\" width=\"20\" height=\"180\" style=\"fill:red;\"/>\n";
		my_ofstream << "<rect x=\"165\" y=\"40\" width=\"80\" height=\"20\" style=\"fill:red;\"/>\n";
		my_ofstream << "<rect x=\"165\" y=\"200\" width=\"80\" height=\"20\" style=\"fill:red;\"/>\n";

		//E
		my_ofstream << "<rect x=\"245\" y=\"220\" width=\"20\" height=\"180\" style=\"fill:purple;\"/>\n";
		my_ofstream << "<rect x=\"245\" y=\"220\" width=\"80\" height=\"20\" style=\"fill:purple;\"/>\n";
		my_ofstream << "<rect x=\"245\" y=\"380\" width=\"80\" height=\"20\" style=\"fill:purple;\"/>\n";
		my_ofstream << "<rect x=\"245\" y=\"300\" width=\"50\" height=\"20\" style=\"fill:purple;\"/>\n";

		my_ofstream << "</svg>\n";
		my_ofstream.close(); // close the output file
	}
}