/*Patricia Cavendish
CIS 1202 502
DUE 12/6/2020
12/5/2020*/

#include <iostream>
#include <cctype>
#include "Letter.h"
using namespace std;

int main() {
	char s;
	int o;
	//create a Letter object
	Letter letter1;
	//get the starting point and offset
	cout << "Enter the starting letter: ";
	cin >> s;
	cout << "Enter the offset: ";
	cin >> o;
	//store these values in the Letter object
	try{
		letter1.setCharacter(s, o);
		cout << "New letter: " << letter1.getCharacter();
	}
	catch (Letter::invalidCharacterException) {
		cout << "Error: An invalid character was entered.\n";
	}
	catch (Letter::invalidRangeException) {
		cout << "Error: An invalid range was enetered.\n";
	}
	catch (Letter::invalidCaseException) {
		cout << "Error: Case-to-case transition not allowed.\n";
	}
	cout << endl << endl;
	system("PAUSE");
	return 0;
}

//SET CHARACTER																	
//Letter class constructor.														
Letter::Letter()
{
	start = 'nu';
	target = 'nu';
	offset = 0;
}

//SET CHARACTER																	 
//Letter class mutator function. Accepts two parameters. Sets the value of target.
void Letter::setCharacter(char start, int offset)
{
	if (!isalpha(start)) {						//if start is not a letter of the alphabet
		throw invalidCharacterException();
	}
	else if (!isalpha(start + offset)) {				//if the target passes outside of the acceptable range
		throw invalidRangeException();
	}
	else if (isupper(start) && islower(start + offset) || 
		islower(start) && isupper(start + offset)) {		//if upper-lower case transition or vice-versa  occurs
		throw invalidCaseException();
	}
	target = start + offset;
}

//SET CHARACTER																	
//Letter class accessor function. Accepts no parameters. Returns the value of target.
char Letter::getCharacter()
{
	return target;
}
