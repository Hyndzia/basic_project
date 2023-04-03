#include <string>
#include<iostream>
#include "Family.h"
#include "Families.h"

void Families::Family::view(Person*& p) {
    std::cout << "\n===================================================\n";
    std::cout << "\n   imie:  " << p->getName() << "\n   nazwisko:  " << p->getSurname() << "\n   wiek: " << p->getAge() << "\n   plec: " << p->getGender();
    std::cout << "\n\n";
}
void Families::Family::create_p(const size_t size) {
    osoby = new Person * [size];
    for (size_t i = 0; i < size; i++) {
        osoby[i] = new Person();
    }
    f_size = size;
}
void Families::Family::view() {
    std::cout << "Rodzina: " << familyName << ".\n";
    for (int i= 0; i < f_size; i++) {
        view(osoby[i]);
    }
}
void Families::Family::ini_familyname() {
    for (size_t i = 0; i < f_size; i++) {
        std::string fname = surname_gen();
        familyName = fname;
        if (osoby[i]->getSurname() != fname)osoby[i]->setSurname(fname);
    }
}
const size_t &Families::Family::get_fSize() {
    return f_size;
}
void Families::Family::ini() {
    for (int i = 0; i < f_size; ++i) {
            ini(osoby[i]);
    }
}
void Families::Family::ini(Person* person) { gen_data(person); }

Person **Families::Family::getOsoby() {
    return osoby;
}
 Person* Families::Family::getOsoba(size_t ind){
    return osoby[ind];
}
void Families::Family::setOsoby(Person **osoby) {
    Families::Family::osoby = osoby;
}
void Families::Family::setOsoba(size_t ind, Person *osoba) {
    Families::Family::osoby[ind] = osoba;
}

const std::string &Families::Family::getFamilyName(){
    return familyName;
}

void Families::Family::setFamilyName(const std::string &familyName) {
    Families::Family::familyName = familyName;
}

void Families::Family::setFSize(size_t fSize) {
    f_size = fSize;
}
