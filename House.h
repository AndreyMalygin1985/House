#pragma once
#include"Apartment.h"

class House {
public:
    Apartment** apartments;
    size_t numberOfApartments;

    House(size_t capacity) :
        apartments(new Apartment* [capacity]), numberOfApartments(0) {}

    ~House() {
        for (size_t i = 0; i < numberOfApartments; ++i) {
            delete apartments[i];
        }
        delete[] apartments;
    }

    void addApartment(Apartment* apartment) {
        apartments[numberOfApartments++] = apartment;
    }

    void showChel() const {
        for (size_t i = 0; i < numberOfApartments; ++i) {
            cout << "Квартира № " << i + 1 << ":" << endl;
            apartments[i]->showHuman();
            cout << endl;
        }
    }
};