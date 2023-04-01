#include "Animal.h"

const std::string &Animal::getSpecies() {
    return species;
}
void Animal::setSpecies(const std::string &species) {
    Animal::species = species;
}
const std::string &Animal::getName()  {
    return name;
}
void Animal::setName(const std::string &name) {
    Animal::name = name;
}
unsigned int Animal::getAge() {
    return age;
}
void Animal::setAge(unsigned int age) {
    Animal::age = age;
}
Person* Animal::getOwner(){
    return owner;
}
void Animal::setOwner(Person *owner) {
    Animal::owner = owner;
}