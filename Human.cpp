#include "Human.h"

char* Human::createName(char const* name)
{
	char* temp = new char[strlen(name) + 1];
	strcpy_s(temp, strlen(name) + 1, name);
	return temp;
}