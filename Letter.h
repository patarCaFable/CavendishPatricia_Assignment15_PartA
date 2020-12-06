#pragma once
class Letter
{
private:
	char start, target;
	int offset;
public:
	void setStart(char start);
	char getStart();
	void setOffset(int offset);
	int getOffset();
	void setTarget(char start, int offset);
	char getTarget();
	//exception class for a non-alphabetical character
	class InvalidCharacterException {};
	//exception class for an invalid range
	class InvalidRangeException {};
	//exception class for case-to-case transition
	class InvalidCaseException {};
};