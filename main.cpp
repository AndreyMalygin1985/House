#include<iostream>
#include<Windows.h>
#include"Human.h"
#include"House.h"
#include"Apartment.h"

using namespace std;

// Создайте программу, имитирующую многоквартирный дом.
// Необходимо иметь классы “Человек”, “Квартира”, “Дом”.Класс “Квартира” содержит динамический массив
// объектов класса “Человек”.Класс “Дом” содержит массив объектов класса “Квартира”.
// Каждый из классов содержит переменные-члены и функции-члены, которые необходимы для предметной области
// класса.
//
// Обращаем ваше внимание, что память под строковые значения выделяется динамически.Например, для
// ФИО в классе “Человек”.Не забывайте обеспечить классы различными конструкторами деструкторами.
//
// В main протестировать работу полученного набора классов
// ----------------
// необходимо в данное решение добавить конструктор копирования.


int main()
{
    SetConsoleOutputCP(1251);

    Human* person1 = new Human("Иванов Иван Иванович");
    Human* person2 = new Human("Петров Петр Петрович");
    Human* person3 = new Human("Сидоров Сидор Сидорович");

    Apartment* apartment1 = new Apartment(2);
    apartment1->addChel(person1);
    apartment1->addChel(person2);

    Apartment* apartment2 = new Apartment(1);
    apartment2->addChel(person3);

    House* house1 = new House(2);
    house1->addApartment(apartment1);
    house1->addApartment(apartment2);

    House* house2 = new House(*house1);

    std::cout << "Жители дома 1:" << std::endl;
    house1->showChel();
    std::cout << std::endl;

    std::cout << "Жители дома 2:" << std::endl;
    house2->showChel();

    delete house1;
    delete house2;

    return 0;
}