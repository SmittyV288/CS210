/**
*This program displays the current time in both 12 and 24 hour formats and updates every second.
* It also shows a menu option that allows the user to press a corresponding key to add one hour, one minute, one second, or exit program.
*
*author: Matt Smith
*Date: 11/01/2022
*/

#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;

class Clock { // creates Clock class
private:

	string strings[4] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" }; // create string array for menu

	// create variables to handle time variables for setters and getters
	int s = 0;
	int m = 0;
	int h = 0;
	int second = 0;
	int minute = 0;
	int hour = 0;

public:

	// function to get current local time and set the hour, minute, and second.
	void setTime() {
		struct tm currTime; // define variable for time struct
		time_t currSecs = time(0); // gets time in seconds and assigns to variable
		localtime_s(&currTime, &currSecs); // Converts value of currSecs into local time and stores values in currTime

		setSecond(currTime.tm_sec); // Calls setSecond function and sends current second value of currTime
		setMinute(currTime.tm_min); // Calls setMinute function and sends current minute value of currTime
		setHour(currTime.tm_hour); // Calls setHour function and sends current hour value of currTime
	}

	// function to set second to variable
	void setSecond(int s) {
		second = s; // Takes value sent to function and assigns to second variable
	}

	// function to get current second value
	int getSecond() {
		return second; // returns current value of second variable.
	}

	// function to set minute to variable
	void setMinute(int m) {
		minute = m; // Takes value sent to function and assigns to minute variable.
	}

	// function to get current minute value
	int getMinute() {
		return minute; // Returns current value of minute variable
	}

	// function to set hour to variable
	void setHour(int h) {
		hour = h; // Takes value sent to function and assigns to hour variable
	}

	// function to get current hour value
	int getHour() {
		return hour; // Returns current value of hour variable.
	}

	/**
	 * Formats a number as 2 digits, with a leading 0 if needed
	 * This method can be useful when converting a time like 9 hours, 12 minutes and 3 seconds to "09:12:03"
	 *
	 * @param n number to format, assumed between 0 and 59, inclusive
	 * @return two digit string representation of number
	 */
	string twoDigitString(int n) {
		string strN; // Create variable for string N

		// loop to convert n varible to string and add a leading 0 if less than 10
		if (n < 10) {
			strN = "0" + to_string(n);
		}
		else {
			strN = to_string(n);
		}

		return strN; // Return the two digit string representation of n
	}

	/**
	 * Returns a string of length n, each character a c.
	 * @param n string length, >=0
	 * @return string of n c's
	 */
	string nCharString(size_t n, char c) {
		string strN; // creates string variable for printing characters

		// loop that adds character to string for the length of n
		for (int i = 0; i < n; i++) {
			strN = strN + c;
		}

		return strN; // return the n character string
	}

	/**
	 * Formats the time in military format
	 *
	 * @param h, hours 0 to 23
	 * @param m, minutes 0 to 59
	 * @param s, seconds 0 to 59
	 *
	 * @return hh:mm:ss
	 */
	string formatTime24(int h, int m, int s) {
		// Calls function three times to convert ints to string then assigns to string variable
		string time = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);

		return time; // return time as hh:mm:ss
	}

	/**
	 * Formats the time in am/pm format
	 *
	 * @param h, hours 0 to 23
	 * @param m, minutes 0 to 59
	 * @param s, seconds 0 to 59
	 *
	 * @return hh:mm:ss A M or hh:mm:ss P M where hh is between 01 and 12, inclusive
	 */
	string formatTime12(int h, int m, int s) {
		string timeOfDay = "A M"; // variable for time of day assigned to A M

		// loop to convert 24 hour time to 12 hour time and determine if AM or PM
		if (h >= 12) {
			h = h - 12;
			timeOfDay = "P M";
		}
		if (h == 0) {
			h = 12;
		}

		// Calls function three times to convert ints to string then assigns to string variable with time of day
		string time = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " " + timeOfDay;

		return time; // return time as hh:mm:ss A M or hh:mm:ss P M
	}

	/**
	 * Prints menu
	 *
	 * @param strings[], nonempty array of choices
	 * @param width, width of each line, will be comfortably bigger than the longest string
	 *
	 */

	void printMenu(string strings[], int numStrings, char width) {
		string currString; // variable to hold current value of string array

		cout << nCharString(width, '*') << endl; // Calls function to print char at certain width then print and new line

		// loop to print menu options from array
		for (int i = 0; i < numStrings; i++) {
			currString = strings[i]; // set variable to current array element
			size_t remLen = (width - (strings[i].size() + 7)); // determines remaining width by subtracting string size and 7 then assign to variable

			cout << '*' << ' ' << i + 1 << ' ' << '-' << ' ' << strings[i] << nCharString(remLen, ' ') << '*' << endl; // calls function to print menu line
			if (i < 3) { // loop to determine last line of menu to print new line
				cout << endl; // prints new line
			}
		}

		cout << nCharString(width, '*') << endl; // Calls function to print char at certain width then print and new line
	}

	/**
	 * Display the clocks
	 *
	 * @param h, hours 0 to 23
	 * @param m, minutes 0 to 59
	 * @param s, seconds 0 to 59
	 */
	void displayClocks(int h, int m, int s) {
		// cout 27 stars + 3 spaces + 27 stars + endl
		cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;

		// cout 1 star + 6 spaces + 12-HOUR CLOCK + 6 spaces + 1 star + 3 spaces
		cout << nCharString(1, '*') << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << nCharString(3, ' ');

		// cout 1 star + 6 spaces + 24-HOUR CLOCK + 6 spaces + 1 star + endl
		cout << nCharString(1, '*') << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << endl;

		// cout an endl for a blank line
		cout << endl;

		// cout 1 star + 6 spaces + formatTime12(h, m, s) + 7 spaces + 1 star + 3 spaces
		cout << nCharString(1, '*') << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << nCharString(1, '*') << nCharString(3, ' ');

		// cout 1 star + 8 spaces + formatTime24(h, m, s) + 9 spaces + 1 star + endl
		cout << nCharString(1, '*') << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << nCharString(1, '*') << endl;

		// cout 27 stars + 3 spaces + 27 stars + endl
		cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
	}

	/**
	 * Adds one hour
	 */
	void addOneHour() {
		h = getHour(); // Call function to get current hour and assign to variable

		if ((h >= 0) && (h <= 23)) { // determine if variable is within range
			h = h + 1; // add 1 to variable and reassign
			setHour(h); // call function to set hour with variable
		}
		if (h == 24) { // determine if variable is 24
			setHour(0); // call function to set hour to 0
		}
	}

	/**
	 * Adds one minute
	 */
	void addOneMinute() {
		m = getMinute(); // call function to get current minute and assign to variable

		if ((m >= 0) && (m < 59)) { // determine if variable is within range
			m = m + 1; // add 1 to variable and reassign
			setMinute(m); // call function to set minute with variable
		}
		if (m == 59) { // determine if variable is 59
			setMinute(0); // call function to set minute to 0
			addOneHour(); // call function to add one hour
		}
	}

	/**
	 * Adds one second
	 */
	void addOneSecond() {
		s = getSecond(); // call function to get current second and assign to variable

		if ((s >= 0) && (s < 59)) { // determine if variable is within range
			s = s + 1; // add 1 to variable and reassign
			setSecond(s); // call function to set second with variable
		}
		if (s == 59) { // determine if variable is 59
			setSecond(0); // call function to set second to 0
			addOneMinute(); // call function to add one minute
		}
	}

	/**
	* Moves console cursor to position 0,0 to allow screen to be printed over
	*/
	void ClearScreen()
	{
		COORD curPos; // define variable for cursor position
		curPos.X = 0; // set x value to 0
		curPos.Y = 0; // set y value to 0
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curPos); // sets cursor position to 0,0
	}

	/**
	* hides cursor to clean up look of clock
	*/
	void hideCursor() {
		CONSOLE_CURSOR_INFO currInfo; // define variable for cursor information
		currInfo.dwSize = 100; // set percentage of cell to 100
		currInfo.bVisible = false; // set visible value to false
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &currInfo); // Sets console cursor and hides it
	}

	/**
	 * repeats getting the user's choice and taking the appropriate action until the user chooses 4 for exit
	 */
	void mainMenu() {
		int n; // create variable for user choices
		bool repClock = true; // create boolean for clock and menu loop

		hideCursor(); // calls function to hide cursor

		do { // loop that runs until n equals 4
			while (repClock == true) { // runs loops while boolean is true
				ClearScreen(); // calls function to clear console screen
				displayClocks(getHour(), getMinute(), getSecond()); // calls function to display both clocks with function parameters

				cout << endl; // prints new line
				cout << "Please select an option: "; // prints into to user to select option
				cout << endl; // prints new line

				printMenu(strings, 4, 24); // calls function to print menu with parameters

				if ((GetAsyncKeyState(0x31)) || (GetAsyncKeyState(VK_NUMPAD1))) { // checks if user has pressed 1 on keyboard
					n = 1; // sets n variable to 1
					repClock = false; // sets boolean to false to end loop
				}

				if ((GetAsyncKeyState(0x32)) || (GetAsyncKeyState(VK_NUMPAD2))) { // checks if user has pressed 2 on keyboard
					n = 2; // sets n variable to 2
					repClock = false; // sets boolean to false to end loop
				}

				if ((GetAsyncKeyState(0x33)) || (GetAsyncKeyState(VK_NUMPAD3))) { // checks if user has pressed 3 on keyboard
					n = 3; // sets n variable to 3
					repClock = false; // sets boolean to false to end loop
				}

				if ((GetAsyncKeyState(0x34)) || (GetAsyncKeyState(VK_NUMPAD4))) { // checks if user has pressed 4 on keyboard
					n = 4; // sets n variable to 4
					repClock = false; // sets boolean to false to end loop
				}

				addOneSecond(); // calls function to add second
				Sleep(1000); // tells program to sleep for 1 second
			}

			switch (n) { // switch to handle certain values of n
			case 1: // executes if n is 1
				addOneHour(); // call function to add one hour
				ClearScreen(); // call function to clear screen
				displayClocks(getHour(), getMinute(), getSecond()); // calls function to display both clocks with function parameters
				cout << endl; // prints new line
				repClock = true; // sets boolean to true to restart loop that checks for user input
				break; // ends switch

			case 2: // executes if n is 2
				addOneMinute(); // call function to add one minute
				ClearScreen(); // call function to clear screen
				displayClocks(getHour(), getMinute(), getSecond()); // calls function to display both clocks with function parameters
				cout << endl; // prints new line
				repClock = true; // sets boolean to true to restart loop that checks for user input
				break; // ends switch

			case 3: // executes if n is 3
				addOneSecond(); // call function to add one second
				ClearScreen(); // call function to clear screen
				displayClocks(getHour(), getMinute(), getSecond()); // calls function to display both clocks with function parameters
				cout << endl; // prints new line
				repClock = true; // sets boolean to true to restart loop that checks for user input
				break; // ends switch

			case 4:
				cout << "Program finished"; // Prints to user that the is program finished
				break; // ends switch
			}
		} while (n != 4);
	}
};

// initializes program
int main() {
	Clock myClock; // Set class to object

	myClock.setTime(); // Calls setTime function from class object
	myClock.mainMenu(); // Calls mainMenu function from class object
}