#include <iostream>
#include <fstream>
#include "Families.h"
#include <assert.h>

void Families::ini(std::shared_ptr<Person> person) { gen_data(person); }

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
void Families::view(std::shared_ptr<Person> p) {
    std::cout << "\n===================================================\n";
    std::cout << "\n   imie:  " << p->getName() << "\n   nazwisko:  " << p->getSurname() << "\n   wiek: " << p->getAge() << "\n   plec: " <<p->getGender();
    std::cout << "\n\n";
}


void Families::operator<<(std::string filename) {
    if (this != nullptr) {
        std::ofstream outfile;
        outfile.open("file.dat", std::ios::binary | std::ios::out);
        outfile.write(reinterpret_cast<const char *>(&famCount), sizeof(famCount));
        for (size_t i = 0; i < famCount; ++i) {
            outfile.write(reinterpret_cast<const char *>(&families[i]->f_size), sizeof(families[i]->f_size));
            size_t familyName_size = families[i]->familyName.size();
            outfile.write(reinterpret_cast<const char *>(&familyName_size), sizeof(familyName_size));
            outfile.write(reinterpret_cast<const char*>(families[i]->familyName.c_str()), familyName_size);
            for (size_t j = 0; j < families[i]->f_size; ++j) {
                std::shared_ptr<Person> tmp = families[i]->osoby[j];
                size_t name_size = tmp->name.size();
                outfile.write(reinterpret_cast<const char *>(&name_size), sizeof(name_size));
                outfile.write(tmp->name.c_str(), name_size);
                size_t surname_size = tmp->surname.size();
                outfile.write(reinterpret_cast<const char *>(&surname_size), sizeof(surname_size));
                outfile.write(tmp->surname.c_str(), surname_size);
                outfile.write(reinterpret_cast<const char *>(&tmp->age), sizeof(tmp->age));
                size_t gender_size = tmp->gender.size();
                outfile.write(reinterpret_cast<const char *>(&gender_size), sizeof(gender_size));
                outfile.write(tmp->gender.c_str(), gender_size);
            }
        }
        outfile.close();
    }
}
void Families::operator>>(std::string filename)  {
    std::ifstream infile;
    size_t tmpf_size, name_size, surname_size, gender_size, familyName_size;
    infile.open(filename, std::ios::binary | std::ios::in);
    infile.read(reinterpret_cast<char *>(&famCount), sizeof(famCount));
    families.reserve(famCount);
    for (size_t i = 0; i < famCount; ++i) {
        infile.read(reinterpret_cast<char *>(&tmpf_size), sizeof(tmpf_size));
        families.push_back(std::make_unique<Family>(tmpf_size));
        infile.read(reinterpret_cast<char*>(&familyName_size), sizeof(familyName_size));
        std::string f_name(familyName_size, '\0');
        infile.read(&f_name[0], familyName_size);
        families[i]->familyName = std::move(f_name);
        for (size_t j = 0; j < families[i]->f_size; ++j) {
            std::shared_ptr<Person> tmp = families[i]->osoby[j];
            infile.read(reinterpret_cast<char *>(&name_size), sizeof(name_size));
            std::string p_name(name_size, '\0');
            infile.read(&p_name[0], name_size);
            tmp->name = std::move(p_name);
            infile.read(reinterpret_cast<char *>(&surname_size), sizeof(surname_size));
            std::string p_surname(surname_size, '\0');
            infile.read(&p_surname[0], surname_size);
            tmp->surname = std::move(p_surname);
            infile.read(reinterpret_cast<char *>(&tmp->age), sizeof(tmp->age));
            infile.read(reinterpret_cast<char *>(&gender_size), sizeof(gender_size));
            std::string p_gender(gender_size, '\0');
            infile.read(&p_gender[0], gender_size);
            tmp->gender = std::move(p_gender);
        }
    }
    infile.close();
}
int Families::getFamCount(){
    return famCount;
}
void Families::clear(){
    families.clear();
}

//Families& Families::operator=(const Families& fam) {
//    if (&fam != this) {
//        families.clear();
//        this->famCount = fam.famCount;
//        families.reserve(famCount);
//        assert(!families.empty());
//        for (unsigned int i = 0; i < famCount; ++i) {
//            families.push_back(fam.families[i]);
//        }
//        return *this;
//    }
//}


