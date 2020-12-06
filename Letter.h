#pragma once
class Letter
{
private:
	char start, nuChar;
	int offset;
public:
	Letter();
	void setCharacter(char start, int offset);
	char getCharacter();
	//exception class
	class invalidCharacterException {};
	//exception calss
	class invalidRangeException {};
};

