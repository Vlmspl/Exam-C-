#include "Text.h"
#include <iostream>
using namespace std;


Text create(const char* text)
{
	Text newText;

	size_t length = strlen(text);
	newText.length = length;

	newText.text = new char[length + 1];
	strcpy_s(newText.text, length+1, text);

	return newText;
}

void print(const Text& text)
{
	printf("%s\n", text.text);
}

void append(Text& text, const char* a)
{
	size_t length = strlen(text.text);
	size_t appendLength = strlen(a);

	char* newText = new char[length + appendLength + 1];
	strcpy_s(newText, length + appendLength + 1, text.text);
	strcpy_s(newText + length, appendLength + 1, a);

	newText[length + appendLength] = '\0';

	delete[] text.text;
	text.text = newText;
	text.length = length + appendLength;
}

void remove(Text& text)
{
	delete[] text.text;
}