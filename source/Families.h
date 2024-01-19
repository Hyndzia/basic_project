#pragma once

#include "Person.h"
#include "gen.h"

#include <vector>

class Person;

class Families {
public:
    Families(size_t size){
        families.reserve(size);
        for (size_t i = 0; i < size; i++) {
            size_t nsize = size_t_gen(1, 10);
            families.push_back(std::make_unique<Family>(nsize));
        }
        famCount= size;
    }
    Families(){
        famCount = 0;
    }
    ~Families(){
        families.clear();
        famCount = 0;
    }
    Families& operator[](unsigned int ind);
    void ini(std::shared_ptr<Person> person);
    void ini_familyname();
    void ini();
    void view();
    void view(std::shared_ptr<Person> p);
    void save();
    void load();
    int getFamCount();
    Person& operator[](size_t index);
    Families& operator=(const Families& fam);
    void operator<<(std::string filename);
    void operator>>(std::string filename);
    void clear();
private:
    int famCount;
    class Family{
    public:
        friend class Families;
        Family(): f_size(0), osoby(), familyName(""){};
        Family(const size_t size){
            create_p(size);
            familyName="";
            f_size = size;
        }
        ~Family() {
            osoby.clear();
            f_size = 0;
            familyName = "";
        }
        const size_t &get_fSize();
        void ini();
        void ini_familyname();
        void view();
        void view(std::shared_ptr<Person>& p);
        std::shared_ptr<Person>& operator[](size_t ind);
        std::vector<std::shared_ptr<Person>> getOsoby();
        void setOsoby(std::vector<std::shared_ptr<Person>> osoby);
        const std::string &getFamilyName();
        void setFamilyName(const std::string &familyName);
        void setFSize(size_t fSize);
        std::shared_ptr<Person> getOsoba(size_t ind); //inaczej destruktor klasy Families nie zadziala
        void setOsoba(size_t ind, std::shared_ptr<Person> osoba);
        void ini(std::shared_ptr<Person> person);
        void create_p(size_t size);
    private:
        std::vector<std::shared_ptr<Person>> osoby;
        //Animal* zwierzeta;
        std::string familyName;
        size_t f_size;
    };
    std::vector<std::shared_ptr<Family>> families;
};



