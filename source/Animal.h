#pragma once
#include <string>

#include "Item.h"
#include "Person.h"

#include <memory>
#include <vector>

class Person;
class Animal {
public:
    Animal() : age(0), owner(nullptr), toy(nullptr), collar_(nullptr), species(""), name("") {}
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
    std::shared_ptr<Person> getOwner();
    void setOwner(std::shared_ptr<Person> owner);
    void setToy(std::shared_ptr<Item>& toy);
    std::shared_ptr<Item> getToy();
    void setCollar(std::shared_ptr<Item>& collar_);
    std::shared_ptr<Item> getCollar();
    static std::shared_ptr<Item>& getItem();
private:
    std::string species;
    std::string name;
    unsigned int age;
    std::shared_ptr<Person> owner;
    std::shared_ptr<Item> toy;
    std::shared_ptr<Item> collar_;
};
void create(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size);
void del(std::vector<std::shared_ptr<Animal>>& a_arr, size_t& size);
void del(std::vector<std::shared_ptr<Animal>>& a_arr, size_t& size, unsigned int index);
double getAverage_age(std::vector<std::shared_ptr<Animal>> a_arr, size_t size);
void view(std::shared_ptr<Animal> a);
void view(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size);
void gen_data(std::shared_ptr<Animal>& animal);
void ini(std::shared_ptr<Animal>& animal);
void ini(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size);
void ini_pet(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size, std::vector<std::shared_ptr<Animal>>& a_arr, const size_t a_size);
void n_ini_pet(std::vector<std::shared_ptr<Person>>& p_arr, std::vector<std::shared_ptr<Animal>>& a_arr, size_t size, size_t a_size);
void d_ini_pet(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size);
void d_ini_pet(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size, std::vector<std::shared_ptr<Person>>& p_arr, const unsigned int ind);
void copy(std::vector<std::shared_ptr<Animal>>& a_arr, std::shared_ptr<Animal>& tmp_a, const size_t size);
void add(std::vector<std::shared_ptr<Animal>>& a_arr, size_t& size);
unsigned int counter(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size, const unsigned int a_age);
unsigned int counter(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size, const std::string a_name);
void search(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size, const std::string a_name);
void search(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size, const unsigned int a_age);
bool cmp_age_a(std::shared_ptr<Animal>& p1, std::shared_ptr<Animal>& p2);
bool cmp_name_a(std::shared_ptr<Animal>& p1, std::shared_ptr<Animal>& p2);
void sort(std::vector<std::shared_ptr<Animal>>& a_arr, size_t size, bool flag);





