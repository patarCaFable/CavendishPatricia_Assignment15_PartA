#pragma once
class Letter
{
private:
	char start, target;
	int offset;
public:
	Letter();
	void setCharacter(char start, int offset);
	char getCharacter();
	//exception class for a non-alphabetical character
	class invalidCharacterException {};
	//exception class for an invalid range
	class invalidRangeException {};
	//exception class for case-to-case transition
	class invalidCaseException {};
};

