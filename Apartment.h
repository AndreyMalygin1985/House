﻿#pragma once
#include"Human.h"

using namespace std;

class Apartment {
public:
    Human** chel;
    size_t kol_human;
    Apartment(int capacity) : chel(new Human* [capacity]), kol_human(0) {}

    ~Apartment() {
        delete[] chel;
    }

    void addChel(Human* person) {
        chel[kol_human++] = person;
    }

    void showHuman() const {
        for (int i = 0; i < kol_human; ++i) {
            cout << chel[i]->getFio() << std::endl;
        }
    }
};