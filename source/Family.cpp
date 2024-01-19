#include <string>
#include<iostream>
#include <fstream>
#include "Families.h"
#include <memory>

void Families::Family::view(std::shared_ptr<Person>& p) {
    std::cout << "\n===================================================\n";
    std::cout << "\n   imie:  " << p->getName() << "\n   nazwisko:  " << p->getSurname() << "\n   wiek: " << p->getAge() << "\n   plec: " << p->getGender();
    std::cout << "\n\n";
}
void Families::Family::create_p(const size_t size) {
    osoby.reserve(size);
    f_size = size;
    for (size_t i = 0; i < size; i++) {
        osoby.push_back(std::make_shared<Person>(Person()));
    }
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
void Families::Family::ini(std::shared_ptr<Person> person) { gen_data(person); }

std::vector<std::shared_ptr<Person>> Families::Family::getOsoby() {
    return osoby;
}
std::shared_ptr<Person> Families::Family::getOsoba(size_t ind){
    return osoby[ind];
}
void Families::Family::setOsoby(std::vector<std::shared_ptr<Person>> osoby) {
    Families::Family::osoby = osoby;
}
void Families::Family::setOsoba(size_t ind, std::shared_ptr<Person> osoba) {
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
std::shared_ptr<Person>& Families::Family::operator[](size_t index) {
    if (index >= f_size) {
        throw std::out_of_range("Invalid index");
    }
    return osoby[index];
}

