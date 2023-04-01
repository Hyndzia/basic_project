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
void Person::setPet(Animal *pet) {
    Person::pet = pet;
}
void Person::setPetFlag(bool petFlag) {
    Person::petFlag = petFlag;
}
Animal *Person::getPet() {
    return pet;
}
bool Person::isPetFlag() {
    return petFlag;
}