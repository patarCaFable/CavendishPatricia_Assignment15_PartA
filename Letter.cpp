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

	//get the target character's starting point
	cout << "Enter the starting letter: ";
	cin >> s;
	cout << "Enter the offset: ";
	cin >> o;
	//store the start value in the Letter object
		try {
			letter1.setStart(s);
			letter1.setOffset(o);
			letter1.setTarget(s, o);
			cout << "New letter: " << letter1.getTarget();
		}
		catch (Letter::InvalidCharacterException) {
			cout << "ERROR! Character entered was not a letter.";
		}
		catch (Letter::InvalidRangeException) {
			cout << "ERROR! Invalid range.";
		}
		catch (Letter::InvalidCaseException) {
			cout << "ERROR! Case-to-case transition not allowed!";
		}
	cout << endl << endl;
	system("PAUSE");
	return 0;
}

//SET START
//Letter class mutator function. Accepts one char parameter. Sets the value of start. Potentially throws exception.
void Letter::setStart(char s)
{
	if (!isalpha(s)) {								//if start is not a letter of the alphabet
		throw InvalidCharacterException();
	}
	start = s;
}

//SET OFFSET
//Letter class mutator function. Accepts one int parameter. Sets the value of offset. Potentially throws exception.
void Letter::setOffset(int o)
{
	if (!isalpha(getStart() + o)) {				//if the target passes outside of the acceptable range
		throw InvalidRangeException();
	}
	offset = o;
}

//SET TARGET																 
//Letter class mutator function. Accepts two parameters of char and int type. Sets the value of target. Potentially throws exception.
void Letter::setTarget(char s, int o)
{
	if (isupper(getStart()) && islower(getStart() + o) || islower(getStart()) && isupper(getStart() + o))
	{											//if case transition occurs
		throw InvalidCaseException();
	}
	target = getStart() + getOffset();
}

//GET TARGET																
//Letter class accessor function. Returns the value of target.
char Letter::getTarget()
{
	return target;
}

//GET START
//Letter class accessor function. Returns the value of start.
char Letter::getStart()
{
	return start;
}

//GET OFFSET
//Letter class accessor function. Returns the value of offset.
int Letter::getOffset() 
{
	return offset;
}