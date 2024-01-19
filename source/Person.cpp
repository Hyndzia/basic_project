#include "Person.h"


 const std::string &Person::getName(){
    return name;
}
const std::string &Person::getSurname() {
    return surname;
}
unsigned int Person::getAge() {
    return age;
}
const std::string &Person::getGender(){
    return gender;
}
void Person::setName(const std::string &name) {
    Person::name = name;
}
void Person::setSurname(const std::string &surname) {
    Person::surname = surname;
}
void Person::setAge(unsigned int age) {
    Person::age = age;
}
void Person::setGender(const std::string &gender) {
    Person::gender = gender;
}
void Person::setPet(std::shared_ptr<Animal> pet) {
    Person::pet = pet;
}
void Person::setPetFlag(bool petFlag) {
    Person::petFlag = petFlag;
}
std::shared_ptr<Animal> Person::getPet() {
    return pet;
}
bool Person::isPetFlag() {
    return petFlag;
}
void Person::setMoney(std::shared_ptr<Item>& money){
   Person::money = money;
}
std::shared_ptr<Item> Person::getMoney(){
    return money;
}

void Person::setId(std::string id){
    Person::id = id;
}
std::string Person::getId(){
    return id;
}
void Person::setPass(unsigned int p){
    Person::password = p;
}
unsigned int Person::getPass(){
    return password;
}
std::ostream& Person::operator<< (std::ostream& output) {
    output << "\n===================================================\n";
    output << "\n   imie:  " << this->getName() << "\n   nazwisko:  " << this->getSurname() << "\n   wiek: " << this->getAge()<< "\n   plec: " <<this->getGender();
    output << "\n\n";
    return output;
}