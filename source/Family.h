//#pragma once
//#include <string>
//#include "gen.h"
//#pragma once
//
//#include "Animal.h"
//#include "Person.h"
//
//
//class Family{
//public:
//    Family(): f_size(0), osoby(nullptr), familyName(""){};
//    Family(const size_t size) {
//        osoby=nullptr;
//        create_p(size);
//        familyName = "";
//        f_size = size;
//    }
//    ~Family() {
//            for (size_t i = 0; i < f_size; i++) {
//                delete osoby[i];
//                osoby[i] = nullptr;
//            }
//            f_size = 0;
//            familyName = "";
//    }
//    const size_t &get_fSize();
//    void ini();
//    void ini_familyname();
//    void view();
//    void view(Person*& p);
//    Person **getOsoby();
//    void setOsoby(Person **osoby);
//    const std::string &getFamilyName();
//    void setFamilyName(const std::string &familyName);
//    void setFSize(size_t fSize);
//    Person* getOsoba(size_t ind); //inaczej destruktor klasy Families nie zadziala
//    void setOsoba(size_t ind, Person *osoba);
//    void ini(Person* person);
//    void create_p(size_t size);
//private:
//    Person** osoby;
//    //Animal* zwierzeta;
//    std::string familyName;
//    size_t f_size;
//};
