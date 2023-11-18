#pragma once
#include"Apartment.h"

class House {
public:
    Apartment** apartments;
    size_t numberOfApartments;

    House(size_t capacity) :
        apartments(new Apartment* [capacity]), numberOfApartments(0) {}

    // Конструктор копирования
    House(const House& obj) :
        apartments(new Apartment* [obj.numberOfApartments]),
        numberOfApartments(obj.numberOfApartments) {
        for (int i = 0; i < numberOfApartments; ++i) {
            apartments[i] = new Apartment(*obj.apartments[i]);
        }
    }
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