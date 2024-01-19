#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <memory>
#include <vector>
#include <iomanip>

#include "PassTable.h"
#include "Animal.h"
#include "Person.h"
#include "Family.h"
#include "gen.h"


void create(std::shared_ptr<Person>& person) {
    person = std::make_shared<Person>();
}
void create(std::shared_ptr<Animal>& animal) {
    animal = std::make_shared<Animal>();
}

void create(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size) {
    a_arr.reserve(size);
    for(int i = 0; i<size;++i){
        a_arr.push_back(std::make_shared<Animal>());
    }
}
void create(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size){
    p_arr.reserve(size);
    for(int i = 0; i<size;++i){
        p_arr.push_back(std::make_shared<Person>());
    }
}

void del(std::vector<std::shared_ptr<Animal>>& a_arr, size_t& size){
    a_arr.clear();
    size = 0;
}

void del(std::vector<std::shared_ptr<Person>>& p_arr, size_t& size) {
    p_arr.clear();
    size = 0;
}

void del(std::vector<std::shared_ptr<Animal>>& a_arr, size_t& size, unsigned int index) {
    index = index - 1;
    if (index <= size) {
        std::vector<std::shared_ptr<Animal>> temp;
        temp.reserve(size-1);
        for (size_t i = 0; i < size; ++i)
            if (i != index) {
                temp.push_back(a_arr[i]);
            }
        //delete[] p_arr;
        a_arr.clear();
        a_arr = temp;
        --size;
    }
}

void del(std::vector<std::shared_ptr<Person>>& p_arr, size_t& size, unsigned int index) {
    index = index - 1;
    if (index <= size) {
        std::vector<std::shared_ptr<Person>> temp;
        temp.reserve(size-1);
        for (size_t i = 0; i < size; ++i)
            if (i != index) {
                temp.push_back(p_arr[i]);
            }
        //delete[] p_arr;
        p_arr.clear();
        p_arr = temp;
        --size;
    }
}

void view(std::shared_ptr<Person> p) {
    std::cout << "\n===================================================\n";
    std::cout << "\n   imie:  " << p->getName() << "\n   nazwisko:  " << p->getSurname() << "\n   wiek: " << p->getAge() << "\n   plec: " <<p->getGender();
    if(p->getPet()!=nullptr)std::cout<<"   pet: "<<p->getPet()->getName()<<"\n\n";
    else std::cout<<"   pupil: -brak-\n\n";
    std::cout<<"   Ilosc pieniedzy: "<<p->getMoney()->getQuantity()<<p->getMoney()->getName();
    std::cout<<"\n   ID: "<<p->getId();
    std::cout<<"\n   pass: "<<p->getPass();
    std::cout << "\n===================================================\n";
}

void view(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size) {
    std::cout << "\n###################################################\n\n";
    for (int i = 0; i < size; i++) {
        if (i != 0) std::cout << "\n===================================================\n";
        std::cout << " " << i + 1 << ". " << "\n   imie:  " << p_arr[i]->getName() << "\n   nazwisko:  " << p_arr[i]->getSurname() << "\n   wiek: " << p_arr[i]->getAge() << "\n   plec: " <<p_arr[i]->getGender();
        if(p_arr[i]->getPet()!=nullptr)std::cout<<"   pet: "<<p_arr[i]->getPet()->getName()<<"\n\n";
        else std::cout<<"   pupil: -brak-\n\n";
        std::cout<<"   Ilosc pieniedzy: "<<p_arr[i]->getMoney()->getQuantity()<<p_arr[i]->getMoney()->getName();
        std::cout<<"\n\n ID: "<<p_arr[i]->getId();
        std::cout<<"\n pass: "<<p_arr[i]->getPass();
    }
    std::cout<<std::setprecision(6)<<"\nsredni wiek osob: "<<getAverage_age(p_arr, size)<<"\n";
    std::cout << "\n###################################################\n";
    std::cout << "\n";
}

void view(std::shared_ptr<Animal> a) {
    std::cout << "\n   gatunek: "<<a->getSpecies()<<"\n   imie:  " << a->getName() << "\n   wiek: " << a->getAge() << "\n";
    std::cout << "\n\n";
}

void view(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size) {
    std::cout << "\n###################################################\n\n";
    std::shared_ptr<Item> item = Animal::getItem();
    for (int i = 0; i < size; i++) {
        if (i != 0) std::cout << "\n===================================================\n";
        std::cout << " " << i + 1 << ". " <<"\n   gatunek: " << a_arr[i]->getSpecies()<< "\n   imie:  " << a_arr[i]->getName() << "\n   wiek: " << a_arr[i]->getAge();
        if(a_arr[i]->getOwner() != nullptr) std::cout << "\n   wlasciciel: " << a_arr[i]->getOwner()->getName()<< "\n\n";
        else if(a_arr[i]->getOwner() == nullptr) std::cout<<"\n   wlasciciel: -brak-\n\n";
        std::cout<<"Ulubiona zabawka: "<<a_arr[i]->getToy()->getName()<<" ilosc: "<<a_arr[i]->getToy()->getQuantity();
        if(a_arr[i]->getOwner()!=nullptr)std::cout<<"\n\n"<<item->getName()<<"  ilosc: "<<item->getQuantity();
    }
    std::cout<< std::setprecision(6) << "\nsredni wiek zwierzat: "<<getAverage_age(a_arr, size)<<"\n";
    std::cout << "\n###################################################\n";
    std::cout << "\n";
}

void gen_data(std::shared_ptr<Person>& person) {
    person->setName(name_gen());
    person->setSurname(surname_gen());
    person->setGender(gender_gen(person->getName()));
    person->setAge(age_gen());
    person->setPet(nullptr);
    person->setPetFlag(false);
    person->setId(string_gen(6));
    person->setPass(size_t_gen(1000, 9999));
    std::shared_ptr<Item> money = std::make_shared<Money>("PLN", size_t_gen(0, 99999)); //polimorfizm
    person->setMoney(money);
}

void gen_data(std::shared_ptr<Animal>& animal) {
    animal->setName(petName_gen());
    animal->setSpecies(species_gen());
    animal->setAge(a_age_gen());
    animal->setOwner(nullptr);
    std::shared_ptr<Item> toy = std::make_shared<Toy>("Gumowa kaczka", size_t_gen(1, 4));
    animal->setToy(toy);
}

void ini(std::shared_ptr<Person>& person) {gen_data(person);}


void ini(std::shared_ptr<Animal>& animal) {gen_data(animal);}

std::ostream& operator<<(std::ostream& output, Person& person) {
    output << "\n===================================================\n";
    output << "\n   imie:  " << person.getName() << "\n   nazwisko:  " << person.getSurname() << "\n   wiek: " << person.getAge() << "\n   plec: " << person.getGender();
    output << "\n\n";
    return output;
}

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
void ini(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        gen_data(a_arr[i]);
    }
}
void ini_pet(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size, std::vector<std::shared_ptr<Animal>>& a_arr, const size_t a_size) {
    if (!p_arr.empty() && !a_arr.empty() && p_arr[0]->getAge() != 0 && a_arr[0]->getAge() != 0) {
        for (size_t i = 0; i < size; i++) {
            size_t random = size_t_gen(0, 1);
            bool loop1 = true;
            unsigned int cnt = 0;
            while (loop1) {
                unsigned int random4 = size_t_gen(0, a_size-1);
                if (random == 1 && p_arr[i]->getPet() == nullptr && a_arr[random4]->getOwner() == nullptr) {
                    p_arr[i]->setPet(a_arr[random4]);
                    p_arr[i]->setPetFlag(true);
                    a_arr[random4]->setOwner(p_arr[i]);
                    loop1 = false;
                }
                ++cnt;
                if (cnt == a_size) loop1 = false;
            }
        }
    }
}

void n_ini_pet(std::vector<std::shared_ptr<Person>>& p_arr, std::vector<std::shared_ptr<Animal>>& a_arr, size_t size, size_t a_size){
    if(!p_arr.empty()) {
        for (size_t i = 0; i < size; ++i) {
            if(p_arr[i]->isPetFlag()){
                for(size_t j = 0; j<a_size;j++) {
                    if(a_arr[j]->getOwner() == p_arr[i])p_arr[i]->setPet(a_arr[j]);
                }
            }
        }
    }
}
void d_ini_pet(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size){
    for (size_t i = 0; i < size; i++){
        if(p_arr[i]->getPet() != nullptr) {
            p_arr[i]->setPet(nullptr);
        }
    }
}
void d_ini_pet(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size){
    for (size_t i = 0; i < size; i++){
        if(a_arr[i]->getOwner()!= nullptr) {
            a_arr[i]->setOwner(nullptr);
        }
    }
}
void d_ini_pet(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size, std::vector<std::shared_ptr<Person>>& p_arr, const unsigned int ind){
    for(size_t i = 0; i<size;i++){
        if(a_arr[i]->getOwner() != nullptr) {
            if (a_arr[i]->getOwner() == p_arr[ind - 1]) {
                a_arr[i]->setOwner(nullptr);
                break;
            }
        }
    }
}

void d_ini_pet(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size, std::vector<std::shared_ptr<Animal>> a_arr, const unsigned int ind){
    for(size_t i = 0; i<size;i++){
        if(p_arr[i]->getPet() != nullptr) {
            if (p_arr[i]->getPet()->getOwner() == a_arr[ind -1]->getOwner()) {
                p_arr[i]->setPet(nullptr);
                break;
            }
        }
    }
}

void ini(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size) {
    for (size_t i = 0; i < size; i++) {
        gen_data(p_arr[i]);
    }
}

void edit(std::vector<std::shared_ptr<Person>>& p_arr, size_t ind){
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
void edit(std::shared_ptr<Person>& p){
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
    p->setName(name);
    p->setSurname(surname);
    p->setAge(age);
}

//void copy(std::vector<std::shared_ptr<Animal>>& a_arr, std::vector<std::shared_ptr<Animal>>& tmp_a, const size_t size) {
//    tmp_a.reserve(size);
//    if (size > 0) {
//        for (size_t i = 0; i < size; i++) {
//            tmp_a.push_back(a_arr[i]);
//        }
//    }
//}

//void copy(std::vector<std::shared_ptr<Person>>& p_arr, std::vector<std::shared_ptr<Person>>& tmp, const size_t size) {
//    //tmp = new Person * [size];
//    tmp.reserve(size);
//    if (size > 0) {
//        for (size_t i = 0; i < size; i++) {
//            tmp.push_back(std::make_shared<Person>(*p_arr[i]));
//        }
//    }
//}

void add(std::vector<std::shared_ptr<Animal>>& a_arr, size_t& size) {
    std::vector<std::shared_ptr<Animal>> tmp;
    std::shared_ptr<Animal> tmp_a;
    tmp.reserve(size+1);
    if (size == 0) {
        create(tmp_a);
        tmp.push_back(tmp_a);
    }
    else {
        for (size_t i = 0; i < size; i++) {
            //tmp[i] = p_arr[i];
            tmp.push_back(a_arr[i]);
        }
        create(tmp_a);
        tmp.push_back(tmp_a);
        // delete[] p_arr;
    }
    a_arr.clear();
    a_arr = tmp;
    ++size;
}

void add(std::vector<std::shared_ptr<Person>>& p_arr, size_t& size) {
    std::vector<std::shared_ptr<Person>> tmp;
    tmp.reserve(size+1);
    std::shared_ptr<Person> tmp_p;
    if (size == 0) {
        create(tmp_p);
        tmp.push_back(tmp_p);
    }
    else {
        for (size_t i = 0; i < size; i++) {
            //tmp[i] = p_arr[i];
            tmp.push_back(p_arr[i]);
        }
        create(tmp_p);
        tmp.push_back(tmp_p);
       // delete[] p_arr;
    }
    p_arr.clear();
    p_arr = tmp;
    ++size;
}

unsigned int counter(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size, const unsigned int p_age) {
    int count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (p_arr[i]->getAge() == p_age) {
            count++;
        }
    }
    return count;
}

unsigned int counter(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size, const std::string p_name) {
    int count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (p_arr[i]->getName() == p_name) {
            count++;
        }
    }
    return count;
}

unsigned int counter(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size, const unsigned int a_age) {
    int count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (a_arr[i]->getAge() == a_age) {
            count++;
        }
    }
    return count;
}

unsigned int counter(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size, const std::string a_name) {
    int count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (a_arr[i]->getName() == a_name) {
            count++;
        }
    }
    return count;
}

void search(std::vector<std::shared_ptr<Person>>& p_arr, const std::string p_name) {
    unsigned int count = 0;
    for (size_t i = 0; i < p_arr.size(); ++i) {
        if (p_arr[i]->getName() == p_name) {
            ++count;
            std::cout << "\n===================================================\n";
            std::cout << " " << count << ".\n";
            view(p_arr[i]);
        }
    }
}

std::shared_ptr<Person> search_id(std::vector<std::shared_ptr<Person>>& p_arr, const std::string id) {
    unsigned int count = 0;
    for (size_t i = 0; i < p_arr.size(); ++i) {
        if (p_arr[i]->getId() == id) {
            return p_arr[i];
        }
    }
}


void search(std::vector<std::shared_ptr<Person>>& p_arr, const size_t size, const unsigned int p_age) {
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

void search(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size, const std::string a_name) {
    unsigned int count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (a_arr[i]->getName() == a_name) {
            ++count;
            std::cout << "\n===================================================\n";
            std::cout << " " << count << ".\n";
            view(a_arr[i]);
        }
    }
}

void search(std::vector<std::shared_ptr<Animal>>& a_arr, const size_t size, const unsigned int a_age) {
    unsigned int count = 0;
    for (size_t i = 0; i < size; ++i) {
        if (a_arr[i]->getAge() == a_age) {
            ++count;
            std::cout << "\n===================================================\n";
            std::cout << " " << count << ".\n";
            view(a_arr[i]);
        }
    }
}


bool cmp_age_p(std::shared_ptr<Person> p1, std::shared_ptr<Person> p2) {return (p1->getAge() < p2->getAge());}

bool cmp_name_p(std::shared_ptr<Person> p1, std::shared_ptr<Person> p2) {
    if (p1->getName() < p2->getName()) return true;
    else if (p1->getName() > p2->getName()) return false;
    else return (p1->getAge() < p2->getAge());
}

bool cmp_age_a(std::shared_ptr<Animal>& p1, std::shared_ptr<Animal>& p2) {return (p1->getAge() < p2->getAge());}

bool cmp_name_a(std::shared_ptr<Animal>& p1, std::shared_ptr<Animal>& p2) {
    if (p1->getName() < p2->getName()) return true;
    else if (p1->getName() > p2->getName()) return false;
    else return (p1->getAge() < p2->getAge());
}


void sort(std::vector<std::shared_ptr<Person>>& p_arr, size_t size, bool flag) {
    if (flag) std::sort(p_arr.begin(), p_arr.end(), cmp_name_p);
    else std::sort(p_arr.begin(), p_arr.end(), cmp_age_p);
}

void sort(std::vector<std::shared_ptr<Animal>>& a_arr, size_t size, bool flag) {
    if (flag) std::sort(a_arr.begin(), a_arr.end(), cmp_name_a);
    else std::sort(a_arr.begin(), a_arr.end(), cmp_age_a);
}

double getAverage_age(std::vector<std::shared_ptr<Person>>& p_arr, size_t size){
    double sum = 0;
    for (size_t i = 0; i < size; i++){
         sum+= p_arr[i]->getAge();
    }
    return(sum/static_cast<double>(size));
}

double getAverage_age(std::vector<std::shared_ptr<Animal>> a_arr, size_t size){
    double sum = 0;
    for (size_t i = 0; i < size; i++){
        sum+= a_arr[i]->getAge();
    }
    return(sum/static_cast<double>(size));
}

void login(std::vector<std::shared_ptr<Person>> p_arr, std::shared_ptr<PassTable> passtable, bool passFlag){
    std::string id;
    int choice = 0;
    unsigned int pin = 0;
        std::cout << "Podaj ID: \n";
        std::cin >> id;
        std::cout<<"Podaj 4 cyfrowy PIN: \n";
        std::cin>>pin;
        if(passtable!= nullptr) passFlag = passtable->check(id, pin);
        if(passFlag){
            system("cls");
            auto person = search_id(p_arr, id);
            bool loop = true;
            while(loop) {
            view(person);
                std::cout << "\n\n1. Edytuj dane\n2. Zmien pin\n3. Wyjdz\n\n";
                std::cin >> choice;
                if (choice == 1) {
                    edit(person);
                } else if (choice == 2){
                    std::cout<<"Wprowadz nowy pin (4 cyfry):\n";
                    std::cin>>pin;
                    person->setPass(pin);
                    passtable->getHash()->remove(id);
                    passtable->getHash()->put(id, pin);
                } else if (choice == 3){
                    loop = false;
                }
                system("pause");
                system("cls");
            }
            return;
        } else{
            std::cout<<"Niepoprawne ID lub haslo!\n";
            return;
        }
    }