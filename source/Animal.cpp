#include "Animal.h"

#include <memory>

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
std::shared_ptr<Person> Animal::getOwner(){
    return owner;
}
void Animal::setOwner(std::shared_ptr<Person> owner) {
    Animal::owner = owner;
}
void Animal::setToy(std::shared_ptr<Item>& toy){
    Animal::toy = toy;
}
std::shared_ptr<Item> Animal::getToy(){
    return toy;
}
void Animal::setCollar(std::shared_ptr<Item>& collar){
    Animal::collar_ = collar;
}
std::shared_ptr<Item> Animal::getCollar(){
    return collar_;
}
std::shared_ptr<Item>& Animal::getItem() {
    static std::shared_ptr<Item> collar = std::make_shared<Collar>("Obroza", 1); // Statyczny obiekt klasy collar
    return collar;
}