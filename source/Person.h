#pragma once

#include <string>
#include "Animal.h"
#include "hashtab.h"


#include <vector>
#include <sstream>
#include <memory>

class PassTable;
class Animal;
class Person {
public:
    Person(const Person& person): id(person.id), name(person.name), surname(person.surname), money(person.money), age(person.age), gender(person.gender), pet(person.pet), petFlag(person.petFlag), password(person.password){}
    Person() : id(""), name(""), surname(""), age(0), gender(""), money(nullptr), pet(nullptr), petFlag(false), password(0) {}
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
    std::shared_ptr<Animal> getPet();
    bool isPetFlag();
    void setName(const std::string &name);
    void setSurname(const std::string &surname);
    void setAge(unsigned int age);
    void setGender(const std::string &gender);
    void setPet(std::shared_ptr<Animal> pet);
    void setPetFlag(bool petFlag);
    void setMoney(std::shared_ptr<Item>& money);
    void setId(std::string id);
    std::string getId();
    std::shared_ptr<Item> getMoney();
    void setPass(unsigned int p);
    unsigned int getPass();
    std::ostream& operator<< (std::ostream& output);
private:
    friend class Families;
    std::string name;
    std::string surname;
    unsigned int age;
    std::string gender;
    std::shared_ptr<Animal> pet;
    bool petFlag;
    std::string id;
    unsigned int password;
    std::shared_ptr<Item> money;
};

void create(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size);
Person* create(const Person& person);
void del(std::vector<std::shared_ptr<Person>>& p_arr, size_t& size);
void del(std::vector<std::shared_ptr<Person>>& p_arr, size_t& size, unsigned int index);
void view(std::shared_ptr<Person> p);
void edit(std::vector<std::shared_ptr<Person>>& p_arr, const size_t ind);
double getAverage_age(std::vector<std::shared_ptr<Person>>& p_arr, size_t size);
void view(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size);
void gen_data(std::shared_ptr<Person>& person);
void ini(std::shared_ptr<Person>& person);
void ini(Person*& person);
void ini_pet(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size, std::vector<std::shared_ptr<Person>> const a_arr, const size_t a_size);
void n_ini_pet(std::vector<std::shared_ptr<Person>>& p_arr, std::vector<std::shared_ptr<Animal>>& a_arr, size_t size, size_t a_size);
void d_ini_pet(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size);
void d_ini_pet(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size, std::vector<std::shared_ptr<Animal>> a_arr, const unsigned int ind);
void ini(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size);
void copy(std::vector<std::shared_ptr<Person>>& p_arr, std::vector<Person*>& tmp, const size_t size);
void add(std::vector<std::shared_ptr<Person>>& p_arr, size_t& size);
unsigned int counter(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size, const std::string p_name);
unsigned int counter(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size, const unsigned int p_age);
void search(std::vector<std::shared_ptr<Person>>& p_arr, const std::string p_name);
std::shared_ptr<Person> search_id(std::vector<std::shared_ptr<Person>>& p_arr, const std::string id);
void search(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size, const unsigned int p_age);
void sort(std::vector<std::shared_ptr<Person>>& p_arr, size_t size, bool flag);
void create(std::shared_ptr<Person>& person);
void login(std::vector<std::shared_ptr<Person>> p_arr, std::shared_ptr<PassTable> passtable, bool passFlag);
std::ostream& operator<<(std::ostream& output, Person& person);