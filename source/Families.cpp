#include <iostream>
#include "Families.h"

void Families::ini(Person* person) { gen_data(person); }

void Families::ini(){
    for(size_t i = 0; i<famCount;++i){
        for(size_t j = 0; j<families[i]->get_fSize();++j){
            ini(families[i]->getOsoba(j));
        }
    }
}
void Families::ini_familyname() {
    for(size_t i = 0;i<famCount; i++) {
        std::string fname = surname_gen();
        families[i]->setFamilyName(fname);
        for (size_t j = 0; j < families[i]->get_fSize(); ++j) {
            if (families[i]->getOsoba(j)->getSurname() != fname)families[i]->getOsoba(j)->setSurname(fname);
        }
    }
}
void Families::view(){
    unsigned int ind = 0;
    for(int i=0; i<famCount; i++) {
        std::cout << " "<<i+1<<". "<<"Rodzina: " << families[i]->getFamilyName() << ".\n";
    }
    std::cout<<"\n\nKtora rodzine wyswietlic?\n";
    std::cin>>ind;
    ind = ind - 1;
    std::cout<<"\n\n";
    std::cout<<"Rodzina: "<<families[ind]->getFamilyName()<<"!\n";
    for(int j= 0; j<families[ind]->get_fSize();j++){
        view(families[ind]->getOsoba(j));
    }
}
void Families::view(Person* p) {
    std::cout << "\n===================================================\n";
    std::cout << "\n   imie:  " << p->getName() << "\n   nazwisko:  " << p->getSurname() << "\n   wiek: " << p->getAge() << "\n   plec: " <<p->getGender();
    std::cout << "\n\n";

}

