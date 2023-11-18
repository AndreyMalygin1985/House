#pragma once
#include<iostream>

class Human
{
public:
	char* FIO;

	char* createName(char const* name);

	Human(const char* FIO) :
		FIO{ FIO ? new char[strlen(FIO) + 1] : nullptr }
	{
		if (FIO) {
			strcpy_s(this->FIO, strlen(FIO) + 1, FIO);
		}
	};

	Human() : Human(nullptr) {}

	Human(const Human& obj) :
		FIO{ obj.FIO ? new char[strlen(obj.FIO) + 1] : nullptr }
	{
		if (FIO) {
			strcpy_s(this->FIO, strlen(obj.FIO) + 1, obj.FIO);
		}
	}

	~Human() {
		delete[] FIO;
	}

	char const* getFio() {
		return FIO;
	}

	Human& setFio(char const* name) {
		delete[] this->FIO;
		this->FIO = createName(name);
		return *this;
	}
};

