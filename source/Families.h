#pragma once
#include "Family.h"
#include "Person.h"
#include "gen.h"

class Families {
public:

    Families(size_t& size){
        families = new Family * [size];
        for (size_t i = 0; i < size; i++) {
            size_t nsize = size_t_gen(1, 10);
            families[i] = new Family;
            Person** p_arr = nullptr;
            create(p_arr, nsize);
            families[i]->setOsoby(p_arr);
            families[i]->setFSize(nsize);
        }
        famCount= size;
    }
    ~Families(){
        for (size_t i = 0; i < famCount; i++) {
            for (size_t j = 0; j < families[i]->get_fSize(); ++j) {
                delete families[i]->getOsoba(j);
                families[i]->setOsoba(j, nullptr);
            }
            delete[] families[i]->getOsoby();
        }
        delete[] families;
        families = nullptr;
        famCount = 0;
    }
    void ini(Person* person);
    void ini_familyname();
    void ini();
    void view();
    void view(Person* p);
private:
    friend class Family;
    class Family{
    public:
        Family(): f_size(0), osoby(nullptr), familyName(""){};
        Family(const size_t size) {
            osoby=nullptr;
            create_p(size);
            familyName = "";
            f_size = size;
        }
        ~Family() {
            for (size_t i = 0; i < f_size; i++) {
                delete osoby[i];
                osoby[i] = nullptr;
            }
            f_size = 0;
            familyName = "";
        }
        const size_t &get_fSize();
        void ini();
        void ini_familyname();
        void view();
        void view(Person*& p);
        Person **getOsoby();
        void setOsoby(Person **osoby);
        const std::string &getFamilyName();
        void setFamilyName(const std::string &familyName);
        void setFSize(size_t fSize);
        Person* getOsoba(size_t ind); //inaczej destruktor klasy Families nie zadziala
        void setOsoba(size_t ind, Person *osoba);
        void ini(Person* person);
        void create_p(size_t size);
    private:
        Person** osoby;
        //Animal* zwierzeta;
        std::string familyName;
        size_t f_size;
    };
    int famCount;
    Families::Family** families;
};



