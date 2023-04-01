#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include "Animal.h"
#include "Person.h"
#include "Family.h"
#include "gen.h"

void create(Person*& person) {
    person = new Person();
}

void create(Animal*& a_arr, const size_t size) {
    a_arr = new Animal[size];
}

void create(Person**& p_arr, const size_t size) {
    p_arr = new Person * [size];
    for (size_t i = 0; i < size; i++) {
        p_arr[i] = new Person();
    }
}

Person* create(const Person& person) {
    return new Person(person);
}

void del(Animal*& a_arr, size_t& size){
    delete[] a_arr;
    a_arr = nullptr;
    size = 0;
}

void del(Person**& p_arr, size_t& size) {
    for (size_t i = 0; i < size; i++) {
        delete p_arr[i];
    }
    delete[] p_arr;
    p_arr = nullptr;
    size = 0;
}

void del(Animal*& a_arr, size_t& size, unsigned int index) {
    index = index - 1;
    if (index <= size) {
        auto temp = new Animal [size - 1];
        int j = -1;
        for (size_t i = 0; i < size; ++i)
            if (i != index) {
                ++j;
                temp[j] = a_arr[i];
            }
        delete[] a_arr;
        a_arr = temp;
        --size;
    }
}

void del(Person**& p_arr, size_t& size, unsigned int index) {
    index = index - 1;
    if (index <= size) {
        auto temp = new Person * [size - 1];
        int j = -1;
        for (size_t i = 0; i < size; ++i)
            if (i != index) {
                ++j;
                temp[j] = p_arr[i];
            }
        delete[] p_arr;
        p_arr = temp;
        --size;
    }
}

void view(Person* p) {
    std::cout << "\n===================================================\n";
    std::cout << "\n   imie:  " << p->getName() << "\n   nazwisko:  " << p->getSurname() << "\n   wiek: " << p->getAge()<< "\n   plec: " <<p->getGender();
    std::cout << "\n\n";

}

void view(Person** p_arr, const size_t size) {
    std::cout << "\n###################################################\n\n";
    for (int i = 0; i < size; i++) {
        if (i != 0) std::cout << "\n===================================================\n";
        std::cout << " " << i + 1 << ". " << "\n   imie:  " << p_arr[i]->getName() << "\n   nazwisko:  " << p_arr[i]->getSurname() << "\n   wiek: " << p_arr[i]->getAge() << "\n   plec: " <<p_arr[i]->getGender();
        if(p_arr[i]->getPet()!=nullptr)std::cout<<"   pet: "<<p_arr[i]->getPet()->getName()<<"\n\n";
        else std::cout<<"   pupil: -brak-\n\n";
    }
    std::cout<<"\nsredni wiek osob: "<<getAverage_age(p_arr, size)<<"\n";
    std::cout << "\n###################################################\n";
    std::cout << "\n";
}

void view(Animal a) {
    std::cout << "\n   gatunek: "<<a.getSpecies()<<"\n   imie:  " << a.getName() << "\n   wiek: " << a.getAge() << "\n";
    std::cout << "\n\n";
}

void view(Animal*& a_arr, const size_t size) {
    std::cout << "\n###################################################\n\n";
    for (int i = 0; i < size; i++) {
        if (i != 0) std::cout << "\n===================================================\n";
        std::cout << " " << i + 1 << ". " <<"\n   gatunek: " << a_arr[i].getSpecies()<< "\n   imie:  " << a_arr[i].getName() << "\n   wiek: " << a_arr[i].getAge();
        if(a_arr[i].getOwner() != nullptr) std::cout << "\n   wlasciciel: " << a_arr[i].getOwner()->getName()<< "\n\n";
        else if(a_arr[i].getOwner() == nullptr) std::cout<<"\n   wlasciciel: -brak-\n\n";
    }
    std::cout<<"\nsredni wiek zwierzat: "<<getAverage_age(a_arr, size)<<"\n";
    std::cout << "\n###################################################\n";
    std::cout << "\n";

}


void gen_data(Person* person) {
    person->setName(name_gen());
    person->setSurname(surname_gen());
    person->setGender(gender_gen(person->getName()));
    person->setAge(age_gen());
    person->setPet(nullptr);
    person->setPetFlag(false);
}

void gen_data(Animal& animal) {
    animal.setName(petName_gen());
    animal.setSpecies(species_gen());
    animal.setAge(a_age_gen());
    animal.setOwner(nullptr);
}

void ini(Person* person) {gen_data(person);}

void ini(Animal& animal) {gen_data(animal);}


//void ini(Family** f_arr, size_t f_arrsize){
//    for(int i = 0; i<f_arrsize;++i){
//        for(int j = 0; j<f_arr[i]->f_size;++j){
//            ini(f_arr[i]->osoby[j]);
//        }
//    }
//}
//void ini_familyname(Family* const* const family, const size_t size) {
//    for(size_t i = 0;i<size; i++) {
//        std::string fname = surname_gen();
//        family[i]->familyName = fname;
//        for (size_t j = 0; j < family[i]->f_size; ++j) {
//            if (family[i]->osoby[j]->surname != fname)family[i]->osoby[j]->surname = fname;
//        }
//    }
//}
//void ini_familyname(Family* const family, const size_t size, std::string fname) {
//    family->familyName = fname;
//    for(size_t i = 0;i < size;++i){
//        if(family->osoby[i]->surname != fname)family->osoby[i]->surname = fname;
//    }
//}
//void ini_familyname(Family* const family, const size_t size) {
//    std::string fname = surname_gen();
//    family->familyName = fname;
//    for(size_t i = 0;i < size;++i){
//        if(family->osoby[i]->surname != fname)family->osoby[i]->surname = fname;
//    }
//}
void ini(Animal* const a_arr, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        gen_data(a_arr[i]);
    }
}
void ini_pet(Person* const* const p_arr, const size_t size, Animal* const a_arr, const size_t a_size) {
    if (p_arr != nullptr && a_arr != nullptr && p_arr[0]->getAge() != 0 && a_arr[0].getAge() != 0) {
        for (size_t i = 0; i < size; i++) {
            size_t random = size_t_gen(0, 1);
            bool loop1 = true;
            unsigned int cnt = 0;
            while (loop1) {
                unsigned int random4 = size_t_gen(0, a_size-1);
                if (random == 1 && p_arr[i]->getPet() == nullptr && a_arr[random4].getOwner() == nullptr) {
                    p_arr[i]->setPet(&a_arr[random4]);
                    p_arr[i]->setPetFlag(true);
                    a_arr[random4].setOwner(p_arr[i]);
                    loop1 = false;
                }
                ++cnt;
                if (cnt == a_size) loop1 = false;
            }
        }
    }
}

void n_ini_pet(Person* const* const p_arr, Animal* const a_arr, size_t size, size_t a_size){
    if(p_arr != nullptr) {
        for (size_t i = 0; i < size; ++i) {
            if(p_arr[i]->isPetFlag()){
                for(size_t j = 0; j<a_size;j++) {
                    if(a_arr[j].getOwner() == p_arr[i])p_arr[i]->setPet(&a_arr[j]);
                }
            }
        }
    }
}
void d_ini_pet(Person* const* const p_arr, const size_t size){
    for (size_t i = 0; i < size; i++){
        if(p_arr[i]->getPet() != nullptr) {
            p_arr[i]->setPet(nullptr);
        }
    }
}
void d_ini_pet(Animal* const a_arr, const size_t size){
    for (size_t i = 0; i < size; i++){
        if(a_arr[i].getOwner()!= nullptr) {
            a_arr[i].setOwner(nullptr);
        }
    }
}
void d_ini_pet(Animal* const a_arr, const size_t size, Person* const* const p_arr, const unsigned int ind){
    for(size_t i = 0; i<size;i++){
        if(a_arr[i].getOwner() != nullptr) {
            if (a_arr[i].getOwner() == p_arr[ind - 1]) {
                a_arr[i].setOwner(nullptr);
                break;
            }
        }
    }

}
void d_ini_pet(Person* const* const p_arr, const size_t size, Animal* const a_arr, const unsigned int ind){
    for(size_t i = 0; i<size;i++){
        if(p_arr[i]->getPet() != nullptr) {
            if (p_arr[i]->getPet()->getOwner() == a_arr[ind -1].getOwner()) {
                p_arr[i]->setPet(nullptr);
                break;
            }
        }
    }
}

void ini(Person* const* const p_arr, const size_t size) {

    for (size_t i = 0; i < size; i++) {
        gen_data(p_arr[i]);
    }
}
void edit(Person* const* const p_arr, size_t ind){
    ind = ind-1;
    std::string line;
    std::cout<<"\nPodaj dane np. Imie;Nazwisko;Wiek\n";
    std::cin.ignore();
    getline(std::cin, line);
    std::cout<<"\n\n";
    std::stringstream ss(line);
    std::string name, surname, agetmp;
    getline(ss, name, ';');
    getline(ss, surname, ';');
    ss >> agetmp;
    for (char z : name){
        if(!isalpha(z)) {
            std::cout << "Nieprawidlowy znak w imieniu!\n";
            return;
        }
    }
    for (char z : surname){
        if(!isalpha(z)){
            std::cout<<"Nieprawidlowy znak w nazwisku!\n";
            return;
        }
    }
    for (char z : agetmp){
        if(!isdigit(z)){
            std::cout<<"Nieprawidlowy znak w wieku!\n";
            return;
        }
    }
    unsigned int age = stoi(agetmp);
    p_arr[ind]->setName(name);
    p_arr[ind]->setSurname(surname);
    p_arr[ind]->setAge(age);

}
void copy(Animal* a_arr, Animal*& tmp_a, const size_t size) {
    tmp_a = new Animal [size];
    if (size > 0) {
        for (size_t i = 0; i < size; i++) {
            tmp_a[i] = a_arr[i];
        }
    }
}

void copy(Person** p_arr, Person**& tmp, const size_t size) {
    tmp = new Person * [size];
    if (size > 0) {
        for (size_t i = 0; i < size; i++) {
            tmp[i] = create(*p_arr[i]);
        }
    }
}

void add(Animal*& a_arr, size_t& size) {
    auto tmp = new Animal[size + 1];
    for (size_t i = 0; i < size; i++) {
        tmp[i] = a_arr[i];
    }
    delete[] a_arr;
    a_arr = tmp;
    size++;
}

void add(Person**& p_arr, size_t& size) {
    auto tmp = new Person * [size + 1];
    if (size == 0) {
        create(tmp[size]);
    }
    else {
        for (size_t i = 0; i < size; i++) {
            tmp[i] = p_arr[i];
        }
        create(tmp[size]);
        delete[] p_arr;
    }
    p_arr = tmp;
    size++;
}

unsigned int counter(Person** p_arr, const size_t size, const unsigned int p_age) {
    int count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (p_arr[i]->getAge() == p_age) {
            count++;
        }
    }
    return count;
}

unsigned int counter(Person** p_arr, const size_t size, const std::string p_name) {
    int count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (p_arr[i]->getName() == p_name) {
            count++;
        }
    }
    return count;
}

unsigned int counter(Animal* a_arr, const size_t size, const unsigned int a_age) {
    int count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (a_arr[i].getAge() == a_age) {
            count++;
        }
    }
    return count;
}

unsigned int counter(Animal* a_arr, const size_t size, const std::string a_name) {
    int count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (a_arr[i].getName() == a_name) {
            count++;
        }
    }
    return count;
}

void search(Person** p_arr, const size_t size, const std::string p_name) {
    unsigned int count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (p_arr[i]->getName() == p_name) {
            ++count;
            std::cout << "\n===================================================\n";
            std::cout << " " << count << ".\n";
            view(p_arr[i]);
        }
    }
}

void search(Person** p_arr, const size_t size, const unsigned int p_age) {
    unsigned int count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (p_arr[i]->getAge() == p_age) {
            ++count;
            std::cout << "\n===================================================\n";
            std::cout << " " << count << ".\n";
            view(p_arr[i]);
        }
    }
}

void search(Animal* a_arr, const size_t size, const std::string a_name) {
    unsigned int count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (a_arr[i].getName() == a_name) {
            ++count;
            std::cout << "\n===================================================\n";
            std::cout << " " << count << ".\n";
            view(a_arr[i]);
        }
    }
}

void search(Animal* a_arr, const size_t size, const unsigned int a_age) {
    unsigned int count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (a_arr[i].getAge() == a_age) {
            ++count;
            std::cout << "\n===================================================\n";
            std::cout << " " << count << ".\n";
            view(a_arr[i]);
        }
    }
}


bool cmp_age_p(Person* p1, Person* p2) {return (p1->getAge() < p2->getAge());}

bool cmp_name_p(Person* p1, Person* p2) {
    if (p1->getName() < p2->getName()) return true;
    else if (p1->getName() > p2->getName()) return false;
    else return (p1->getAge() < p2->getAge());
}

bool cmp_age_a(Animal p1, Animal p2) {return (p1.getAge() < p2.getAge());}

bool cmp_name_a(Animal p1, Animal p2) {
    if (p1.getName() < p2.getName()) return true;
    else if (p1.getName() > p2.getName()) return false;
    else return (p1.getAge() < p2.getAge());
}


void sort(Person**& p_arr, size_t size, bool flag) {
    if (flag) std::sort(p_arr, p_arr + size, cmp_name_p);
    else std::sort(p_arr, p_arr + size, cmp_age_p);
}

void sort(Animal*& a_arr, size_t size, bool flag) {
    if (flag) std::sort(a_arr, a_arr + size, cmp_name_a);
    else std::sort(a_arr, a_arr + size, cmp_age_a);
}

double getAverage_age(Person** p_arr, size_t size){
    double sum = 0;
    for (size_t i = 0; i < size; i++){
         sum+= p_arr[i]->getAge();
    }
    return(sum/static_cast<double>(size));
}
double getAverage_age(Animal* a_arr, size_t size){
    double sum = 0;
    for (size_t i = 0; i < size; i++){
        sum+= a_arr[i].getAge();
    }
    return(sum/static_cast<double>(size));
}