/*
Student Name: Chamod Gamage
Student Number:  20830088
SYDE 121 Lab: 02
Assignment: 03
Filename: lab02_03.cpp
I hereby declare that this code, submitted for credit for the course SYDE121,
is a product of my own efforts.  This coded solution has not been plagiarized
from other sources and has not been knowingly plagiarized by others.
Project:  HOROSCOPE
Purpose:  Output astrological sign given month of birth and day of birth
Due Date: Tuesday, September 24, 2019
*/

/*

Valid range of values: 1 <= month <= 12; 1 <= day_of_month <= MAX_DAYS[month]
Test Cases
January 1 --> Capricorn
January 19 --> Capricorn
January 20 --> Aquarius
February 30 --> Invalid
November 21 --> Scorpio
November 26 --> Sagitarrius
December 31 --> Capricorn
Non-integer inputs --> User must reenter info

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
	//Variable declarations
	string user_input = "";
	int month = 0;
	int day_of_month = 0;
	int day_of_year = 0;
	int sign = 0;


	//Constant arrays containing information
	const vector<string> MONTHS = { "January","February","March","April","May","June","July",
			"August","September","October","November","December" };
	const vector<int> MAX_DAYS = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	const vector<int> HOROSCOPE_DAYS = { 19,18,20,19,20,20,22,22,22,22,21,21};
	const vector <string> HOROSCOPE = { "Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn"};
	
	
	//Gives potential user inputs corresponding to birth months
	cout << " 1 - January\n";
	cout << " 2 - February\n";
	cout << " 3 - March\n";
	cout << " 4 - April\n";
	cout << " 5 - May\n";
	cout << " 6 - June\n";
	cout << " 7 - July\n";
	cout << " 8 - August\n";
	cout << " 9 - September\n";
	cout << "10 - October\n";
	cout << "11 - November\n";
	cout << "12 - December\n";



	//Takes in valid birth month 
	do {
		
		cout << "Enter VALID number corresponding to month of birth: ";
		
		cin >> user_input;
		try
		{
			month = stoi(user_input);
		}
		catch (invalid_argument)
		{
		}
		catch (out_of_range)
		{
		}
		
	} while (month < 1 || month > 12);
	month -= 1;
	cout << "You entered: " << month + 1 << " (" << MONTHS[month] << ")\n";


	//Takes in valid day in given birth month
	do {
		cout << "Enter VALID date of birth (day of month): \n";
		cin >> user_input;
		try
		{
			day_of_month = stoi(user_input);
		}
		catch (invalid_argument)
		{
		}
		catch (out_of_range)
		{
		}
	} while (day_of_month < 1 || day_of_month > MAX_DAYS[month]);

	cout << "You entered: " << day_of_month << " (" << MONTHS[month] << " " << day_of_month << ")";
	

	//Finds sign given birth day and month
	if (day_of_month <= HOROSCOPE_DAYS[month]) {
		sign = month;
	}
	else {
		sign = month+1;
	}
	
	cout << "\nYour sign is " << HOROSCOPE[sign] << ".\n";

 
	//Gives information based on sign
	//Cases: Capricorn, Aquarius, Pisces, Aries, Taurus, Gemini, Cancer, Leo, Virgo, Libra, Scorpio, Sagittarius, Capricorn (again)
	switch (sign) {
		case 0: cout << "The measured master planner of the horoscope family, Capricorn energy teaches us the power of structure and long-term goals. You are an Earth Sign; compatible with Taurus and Virgo."; break;
		case 1: cout << "The Aquarius zodiac sign is the 11th sign of the zodiac. Aquarius people are original, idealistic, rebellious, independent, inventors, open minded and honest. You are an Air Sign; compatabile with Gemini and Libra."; break;
		case 2: cout << "The dreamer and healer of the horoscope family, Pisces energy awakens compassion, imagination and artistry, uniting us as one. You are a Water Sign; compatible with Cancer and Scorpio."; break;
		case 3: cout << "The pioneer and trailblazer of the horoscope wheel, Aries energy helps us initiate, fight for our beliefs and fearlessly put ourselves out there. You are a Fire Sign; compatible with Leo and Sagitarrius. "; break;
		case 4: cout << "The persistent provider of the horoscope family, Taurus energy helps us seek security, enjoy earthly pleasures and get the job done. You are an Earth Sign; compatible with Virgo and Capricorn. "; break;
		case 5: cout << "The most versatile and vibrant horoscope sign, Gemini energy helps us communicate, collaborate and fly our freak flags at full mast. You are an Air Sign; compatabile with Aquarius and Libra."; break;
		case 6: cout << "The natural nurturer of the horoscope wheel, Cancer energy helps us connect with our feelings, plant deep roots and feather our family nests. You are a Water Sign; compatible with Pisces and Scorpio."; break;
		case 7: cout << "The drama queen and regal ruler of the horoscope clan, Leo energy helps us shine, express ourselves boldly and wear our hearts on our sleeves. You are a Fire Sign; compatible with Aries and Sagitarrius. "; break;
		case 8: cout << "The masterful helper of the horoscope wheel, Virgo energy teaches us to serve, do impeccable work and prioritize wellbeing—of ourselves, our loved ones and the planet. You are an Earth Sign; compatible with Taurus and Capricorn.  "; break;
		case 9: cout << "The balanced beautifier of the horoscope family, Libra energy inspires us to seek peace, harmony and cooperation—and to do it with style and grace. You are an Air Sign; compatabile with Gemini and Aquarius."; break;
		case 10: cout << "The most intense and focused of the horoscope signs, Scorpio energy helps us dive deep, merge our superpowers and form bonds that are built to last. You are a Water Sign; compatible with Pisces and Cancer."; break;
		case 11: cout << "The worldly adventurer of the horoscope wheel, Sagittarius energy inspires us to dream big, chase the impossible and take fearless risks. You are a Fire Sign; compatible with Aries and Leo. "; break;
		case 12: cout << "The measured master planner of the horoscope family, Capricorn energy teaches us the power of structure and long-term goals. You are an Earth Sign; compatible with Taurus and Virgo."; break;
		
	}
	cout << "\n\nInformation taken from https://astrostyle.com/zodiac-signs/ \n";

	return 0;
}


