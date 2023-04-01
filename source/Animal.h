#pragma once
#include <string>
#include "Person.h"
class Person;
class Animal {
public:
    Animal() : age(0), owner(nullptr), species(""), name("") {}
    ~Animal() {
        age = 0;
        owner=nullptr;
        species = "";
        name = "";
    }
    const std::string &getSpecies();
    void setSpecies(const std::string &species);
    const std::string &getName();
    void setName(const std::string &name);
    unsigned int getAge();
    void setAge(unsigned int age);
    Person *getOwner();
    void setOwner(Person *owner);
private:
    std::string species;
    std::string name;
    unsigned int age;
    Person* owner;
};
void create(Animal*& a_arr, const size_t size);
void del(Animal*& a_arr, size_t& size);
void del(Animal*& a_arr, size_t& size, unsigned int index);
double getAverage_age(Animal* a_arr, size_t size);
void view(Animal a);
void view(Animal*& a_arr, const size_t size);
void gen_data(Animal& animal);
void ini(Animal& animal);
void ini(Animal* const a_arr, const size_t size);
void ini_pet(Person* const* const p_arr, const size_t size, Animal* const a_arr, const size_t a_size);
void n_ini_pet(Person* const* const p_arr, Animal* const a_arr, size_t size, size_t a_size);
void d_ini_pet(Animal* const a_arr, const size_t size);
void d_ini_pet(Animal* const a_arr, const size_t size, Person* const* const p_arr, const unsigned int ind);
void copy(Animal* a_arr, Animal*& tmp_a, const size_t size);
void add(Animal*& a_arr, size_t& size);
unsigned int counter(Animal* a_arr, const size_t size, const unsigned int a_age);
unsigned int counter(Animal* a_arr, const size_t size, const std::string a_name);
void search(Animal* a_arr, const size_t size, const std::string a_name);
void search(Animal* a_arr, const size_t size, const unsigned int a_age);
bool cmp_age_a(Animal p1, Animal p2);
bool cmp_name_a(Animal p1, Animal p2) ;
void sort(Animal*& a_arr, size_t size, bool flag);





