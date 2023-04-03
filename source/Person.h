#pragma once
#include <string>
#include "Animal.h"

class Animal;
class Person {
public:
    Person(const Person& person): name(person.name), surname(person.surname), age(person.age), gender(person.gender), pet(person.pet), petFlag(person.petFlag){}
    Person() : name(""), surname(""), age(0), gender(""), pet(nullptr), petFlag(false) {}
    ~Person(){
        name = "";
        surname = "";
        age = 0;
        gender = "";
        pet = nullptr;
        petFlag = false;
    }
    const std::string &getName();
    const std::string &getSurname();
    unsigned int getAge();
    const std::string &getGender();
    Animal *getPet();
    bool isPetFlag();
    void setName(const std::string &name);
    void setSurname(const std::string &surname);
    void setAge(unsigned int age);
    void setGender(const std::string &gender);
    void setPet(Animal *pet);
    void setPetFlag(bool petFlag);

private:
    std::string name;
    std::string surname;
    unsigned int age;
    std::string gender;
    Animal* pet;
    bool petFlag;
};

void create(Person**& p_arr, const size_t size);
Person* create(const Person& person);
void del(Person**& p_arr, size_t& size);
void del(Person**& p_arr, size_t& size, unsigned int index);
void view(Person* p);
void edit(Person* const* const p_arr, const size_t ind);
double getAverage_age(Person** p_arr, size_t size);
void view(Person** p_arr, const size_t size);
void gen_data(Person* person);
void ini(Person* person);
void ini_pet(Person* const* const p_arr, const size_t size, Animal* const a_arr, const size_t a_size);
void n_ini_pet(Person* const* const p_arr, Animal* const a_arr, size_t size, size_t a_size);
void d_ini_pet(Person* const* const p_arr, const size_t size);
void d_ini_pet(Person* const* const p_arr, const size_t size, Animal* const a_arr, const unsigned int ind);
void ini(Person* const* const p_arr, const size_t size);
void copy(Person** p_arr, Person**& tmp, const size_t size);
void add(Person**& p_arr, size_t& size);
unsigned int counter(Person** p_arr, const size_t size, const std::string p_name);
unsigned int counter(Person** p_arr, const size_t size, const unsigned int p_age);
void search(Person** p_arr, const size_t size, const std::string p_name);
void search(Person** p_arr, const size_t size, const unsigned int p_age);
void sort(Person**& p_arr, size_t size, bool flag);
void create(Person*& person);





