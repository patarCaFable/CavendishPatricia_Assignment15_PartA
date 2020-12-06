/*Patricia Cavendish
CIS 1202 502
DUE 12/6/2020
12/5/2020*/


#include <iostream>
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
	
}


//SET CHARACTER																	
//Letter class constructor.														
Letter::Letter()
{
	start = 65;
	offset = 0;
}

//SET CHARACTER																	 
//Letter class mutator function. Accepts two parameters. Sets the value of nuChar.
void Letter::setCharacter(char start, int offset)
{
	nuChar = start + offset;	
}

//SET CHARACTER																	
//Letter class accessor function. Accepts no parameters. Returns the value of nuChar.
char Letter::getCharacter()
{
	return nuChar;
}
