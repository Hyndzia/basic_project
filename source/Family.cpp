#include <string>
#include<iostream>
#include "Family.h"

void Family::view(Person*& p) {
    std::cout << "\n===================================================\n";
    std::cout << "\n   imie:  " << p->getName() << "\n   nazwisko:  " << p->getSurname() << "\n   wiek: " << p->getAge() << "\n   plec: " << p->getGender();
    std::cout << "\n\n";
}
void Family::create_p(const size_t size) {
    osoby = new Person * [size];
    for (size_t i = 0; i < size; i++) {
        osoby[i] = new Person();
    }
    f_size = size;
}
void Family::view() {
    std::cout << "Rodzina: " << familyName << ".\n";
    for (int i= 0; i < f_size; i++) {
        view(osoby[i]);
    }
}
void Family::ini_familyname() {
    for (size_t i = 0; i < f_size; i++) {
        std::string fname = surname_gen();
        familyName = fname;
        if (osoby[i]->getSurname() != fname)osoby[i]->setSurname(fname);
    }
}
const size_t &Family::get_fSize() {
    return f_size;
}
void Family::ini() {
    for (int i = 0; i < f_size; ++i) {
            ini(osoby[i]);
    }
}
void Family::ini(Person* person) { gen_data(person); }

Person **Family::getOsoby() {
    return osoby;
}
 Person* Family::getOsoba(size_t ind){
    return osoby[ind];
}
void Family::setOsoby(Person **osoby) {
    Family::osoby = osoby;
}
void Family::setOsoba(size_t ind, Person *osoba) {
    Family::osoby[ind] = osoba;
}

const std::string &Family::getFamilyName(){
    return familyName;
}

void Family::setFamilyName(const std::string &familyName) {
    Family::familyName = familyName;
}

void Family::setFSize(size_t fSize) {
    f_size = fSize;
}
