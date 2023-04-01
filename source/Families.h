#pragma once
#include "Family.h"

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
    void create_p(Person**& p_arr, const size_t size);
private:
    unsigned int famCount;
    Family** families;
};



