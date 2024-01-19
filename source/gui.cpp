#include <iostream>
#include <cstdlib>
#include <vector>
#include <memory>

#include "Animal.h"
#include "Person.h"
#include "Family.h"
#include "Families.h"
#include "PassTable.h"

#include"gen.h"


void gui() {
    bool loop = true;

    bool flag_ini_p = false;
    bool flag_ini_a = false;
    bool flag_ini_f = false;
    bool sortFlag_p1 = false; //1 sortowanie przez imie
    bool sortFlag_a1 = false;
    bool sortFlag_p2 = false; //2 sortowanie przez wiek
    bool sortFlag_a2 = false;

    std::vector<std::shared_ptr<Person>> p_arr;
    std::vector<std::shared_ptr<Person>> tmp_p;
    //Animal *a_arr = nullptr;
    std::vector<std::shared_ptr<Animal>> a_arr;
    //Animal *tmp_a = nullptr;
    std::vector<std::shared_ptr<Animal>> tmp_a;
    std::shared_ptr<PassTable> passtab = nullptr;

    std::shared_ptr<Families> families = nullptr;
    unsigned int choice = 0;

    size_t fa_size = 0;
    size_t p_size = 0;
    size_t a_size = 0;
    size_t f_size = 0;
    size_t tmpsize_p = 0;
    size_t tmpsize_a = 0;

    while (loop) {
        std::cout << "\n###################################################\n";
        std::cout << "1. Stworz baze\n";
        std::cout << "2. Zainicjalizuj losowymi danymi\n";
        std::cout << "3. pokaz\n";
        std::cout << "4. dodaj\n";
        std::cout << "5. usun\n";
        std::cout << "6. wyszukaj\n";
        std::cout << "7. sortuj\n";
        std::cout << "8. edytuj\n";
        std::cout << "9. usun wszystkich\n";
        std::cout << "10. zapisz\n";
        std::cout << "11. zaladuj\n";
        std::cout<<"12. Panel uzytkownika\n";
        std::cout << "0. wyjdz\n";
        std::cout << "###################################################\n\n";
        std::cin >> choice;
        std::cout << "\n\n";

        switch (choice) {

            case 0: {//wyjscie

                loop = false;
                break;
            }
            case 1: {//tworzenie

                unsigned int choice0 = 0;
                std::cout << "1. Stworz baze osob\n";
                std::cout << "2. Stworz baze zwierzat\n";
                std::cout<<"3. Stworz Rodzine\n";
                std::cin >> choice0;
                if (choice0 != 1 && choice0 != 2 && choice0 != 3) {
                    std::cout << "Nieprawidlowa instrukcja!\n";
                    break;
                }
                std::cout << "\n\n";
                if (choice0 == 1) {
                    if (p_size <= 0) {
                        size_t minsize = 30; //minmax wartosci rozmiaru
                        size_t maxsize = 100;
                        /*std::cout << "podaj rozmiar: \n";
                        std::cin >> p_size;
                        if (p_size >= 10000000) {
                            std::cout << "Zbyt duzy rozmiar!\n";
                            p_size = 0;
                            break;
                        }*/
                        p_size = size_t_gen(minsize, maxsize);
                        create(p_arr, p_size);
                        std::cout << "\n\nUtworzono baze!\n\n";

                    } else std::cout << "Baza juz utworzona!\n";
                    break;
                } else if (choice0 == 2) {
                    if (a_size <= 0) {
                        /*std::cout << "podaj rozmiar: \n";
                        std::cin >> a_size;
                        if (a_size >= 10000000) {
                            std::cout << "Zbyt duzy rozmiar!\n";
                            a_size = 0;
                            break;
                        }*/
                        size_t minsize = 0; //minmax wartosci rozmiaru
                        size_t maxsize = 25;
                        a_size = size_t_gen(minsize, maxsize);
                        create(a_arr, a_size);
                        std::cout << "\n\nUtworzono baze!\n\n";
                    } else std::cout << "Baza juz utworzona!\n";
                    break;
                } else if(choice0==3){
                    if(fa_size<=0){
                        size_t size = size_t_gen(0, 15);
                        /*family = new Family(size);
                        fa_size = family->get_fSize();*/
                        families = std::make_unique<Families>(size);
                        fa_size = size;
                        std::cout<<"\n\nUtworzono baze rodzin!\n";
                    } else std::cout << "Baza juz utworzona!\n";
                }
                break;
            }
            case 2: {//inicjalizacja
                unsigned int choice0 = 0;
                std::cout << "\n1. Zainicjalizuj baze osob\n";
                std::cout << "\n2. Zainicjalizuj baze zwierzat\n";
                std::cout<<"\n3. Zainicjalizuj rodzine\n";
                std::cin >> choice0;
                if (choice0 != 1 && choice0 != 2 && choice0 != 3) {
                    std::cout << "Nieprawidlowa instrukcja!\n";
                    break;
                }
                std::cout << "\n\n";
                if (choice0 == 1) {
                    if (flag_ini_p) {
                        std::cout << "\nBaza zostala juz zainicjalizowana!\n";
                        break;
                    }
                    if (p_size <= 0) {
                        std::cout << "\nBrak osob!\n";
                        break;
                    }
                    ini(p_arr, p_size);
                    ini_pet(p_arr, p_size, a_arr, a_size);
                    flag_ini_p = true;
                    std::cout << "\nZainicjalizowano!\n\n";
                    break;
                }
                if (choice0 == 2) {
                    if (flag_ini_a) {
                        std::cout << "\nBaza zostala juz zainicjalizowana!\n";
                        break;
                    }
                    if (a_size <= 0) {
                        std::cout << "\nBrak zwierzat!\n";
                        break;
                    }
                    ini(a_arr, a_size);
                    ini_pet(p_arr, p_size, a_arr, a_size);
                    flag_ini_a = true;
                    std::cout << "\nZainicjalizowano!\n\n";
                    break;
                } else if(choice0 == 3){
                    if(flag_ini_f){
                        std::cout<<"\nRodzina zostala juz zainicjalizowana!\n";
                        break;
                    }
                    if(fa_size<= 0){
                        std::cout<<"\nBrak osob!\n";
                        break;
                    }
                    unsigned int choice1 = 0;
                    std::cout<<"1. Wygeneruj losowe nazwiska dla rodzin i zainicjalizuj ich\n";
                    std::cin>>choice1;
                    std::cout<<"\n\n";
                    if(choice1 == 1){
                        /*family->ini();
                        family->ini_familyname();
                        flag_ini_f = true;
                        break;*/
                        families->ini();
                        families->ini_familyname();
                        flag_ini_f=true;
                        break;
                    }
                    break;

                  /*  unsigned int choice1;
                    std::cout<<"1. Podaj nazwisko rodziny\n2. Wygeneruj losowe nazwisko rodziny\n";
                    std::cin>>choice1;
                    if(choice1 == 1){
                        std::string fname;
                        std::cout<<"\n\nWprowadz dane: \n";
                        std::cin>>fname;
                        std::cout<<"\n\n";
                        ini(f_arr, f_size);
                        ini_familyname(f_arr, f_size, fname);
                        flag_ini_f = true;
                        std::cout<<"Utworzono rodzine "<<fname<<" !";
                    }else if(choice1 == 2){
                        ini(f_arr, f_size);
                        ini_familyname(f_arr, f_size);
                        flag_ini_f = true;
                    }else break;
                    break;*/
                }
            }
            case 3: {//wyswietlanie
                unsigned int choice3 = 0;
                unsigned int choice0 = 0;

                std::cout << "\n\n1. Baza osob\n2. Baza zwierzat\n3. Rodzina\n";
                std::cin >> choice0;
                std::cout << "\n\n";

                if (choice0 != 1 && choice0 != 2 && choice0 != 3) {
                    std::cout << "Nieprawidlowa instrukcja!\n";
                    break;
                }

                if (choice0 == 1) {
                    if (p_size <= 0) {
                        std::cout << "Brak ludzi!\n";
                        break;
                    }
                    view(p_arr, p_size);
                } else if (choice0 == 2) {
                    if (a_size <= 0) {
                        std::cout << "Brak zwierzat!\n";
                        break;
                    }
                    view(a_arr, a_size);
                } else if(choice0 == 3){
                    if (fa_size <= 0) {
                        std::cout << "Brak osob!\n";
                        break;
                    }
                    //family->view();
                    families->view();
                }
                std::cout << "\n\n1. Posortuj obiekty wedlug imienia\n";
                std::cout << "2. Posortuj obiekty wedlug wieku\n";
                std::cout << "3. Powrot\n\n";
                std::cin >> choice3;
                std::cout << "\n\n";
                if (choice0 == 1) {
                    if (choice3 == 1) {

                        //sortowanie wedlug imienia
                        if (sortFlag_a1) {
                            std::cout << "Zwierzeta juz posortowane!\n\n";
                            break;
                        }
                        bool cmp_flag = true; //true=imie, false=wiek
                        tmpsize_p = p_size;
                        //copy(p_arr, tmp_p, tmpsize_p);
                        tmp_p = p_arr;
                        sort(tmp_p, tmpsize_p, cmp_flag);
                        view(tmp_p, tmpsize_p);
                        std::cout << "\n\n";
                        del(tmp_p, tmpsize_p);
                        break;
                    } else if (choice3 == 2) {

                        //sortowanie wedlug wieku
                        if (sortFlag_a2) {
                            std::cout << "Zwierzeta juz posortowane!\n\n";
                            break;
                        }
                        bool cmp_flag = false;
                        tmpsize_p = p_size;
                        //copy(p_arr, tmp_p, tmpsize_p);
                        tmp_p = p_arr; //wektora nie trzeba kopiowac za pomoca std:copy
                        sort(tmp_p, tmpsize_p, cmp_flag);
                        view(tmp_p, tmpsize_p);
                        std::cout << "\n\n";
                        del(tmp_p, tmpsize_p);
                        break;
                    } else break;
                }
                if (choice0 == 2) {
                    if (choice3 == 1) {

                        //sortowanie wedlug imienia
                        if (sortFlag_a1) {
                            std::cout << "Zwierzeta juz posortowane!\n\n";
                            break;
                        }
                        bool cmp_flag = true; //true=imie, false=wiek
                        tmpsize_a = a_size;
                        //copy(a_arr, tmp_a, tmpsize_a);
                        tmp_a = a_arr;
                        sort(tmp_a, tmpsize_a, cmp_flag);
                        view(tmp_a, tmpsize_a);
                        std::cout << "\n\n";
                        del(tmp_a, tmpsize_a);
                        break;
                    } else if (choice3 == 2) {

                        //sortowanie wedlug wieku
                        if (sortFlag_a2) {
                            std::cout << "Zwierzeta juz posortowane!\n\n";
                            break;
                        }
                        bool cmp_flag = false;
                        tmpsize_a = a_size;
                        //copy(a_arr, tmp_a, tmpsize_a);
                        tmp_a = a_arr;
                        sort(tmp_a, tmpsize_a, cmp_flag);
                        view(tmp_a, tmpsize_a);
                        std::cout << "\n\n";
                        del(tmp_a, tmpsize_a);
                        break;
                    } else break;
                } else break;
            }
            case 4: { //dodawanie (jezeli obiekty w tablicy zainicjalizowane to nowy obiekt tez zainicjalizowany, w przeciwnym wypadku obiekt niezainicjalizowany)
                unsigned int choice2 = 0;
                unsigned int choice0 = 0;
                std::cout << "\n1. Dodaj osobe\n2. Dodaj zwierze\n";
                std::cin >> choice0;
                if (choice0 == 1) {
                    if (p_size <= 0) {
                        std::cout << "Nie stworzono tablicy!\n";
                        std::cout << "Czy chcesz stworzyc tablice z jednym elementem?\n";
                        std::cout << "1. Tak\n2. Nie\n\n";
                        std::cin >> choice2;
                        std::cout << "\n";
                    }
                    if (choice2 == 2) break;
                    add(p_arr, p_size);
                    //if (p_arr[0]->age != 0) ini(p_arr[p_size - 1]);
                    if (flag_ini_p) ini(p_arr.back());
                    if (sortFlag_p1) sortFlag_p1 = false;
                    if (sortFlag_p2) sortFlag_p2 = false;
                    std::cout << "Dodano nowa osobe!\n\n";
                    break;
                } else if (choice0 == 2) {
                    if (a_size <= 0) {
                        std::cout << "Nie stworzono tablicy!\n";
                        std::cout << "Czy chcesz stworzyc tablice z jednym elementem?\n";
                        std::cout << "1. Tak\n2. Nie\n\n";
                        std::cin >> choice2;
                        std::cout << "\n";
                    }
                    if (choice2 == 2) break;
                    add(a_arr, a_size);
                    //if (a_arr[0].age != 0) ini(a_arr[a_size - 1]);
                    if (flag_ini_a) ini(a_arr[a_size - 1]);
                    if (sortFlag_a1) sortFlag_a1 = false;
                    if (sortFlag_a2) sortFlag_a2 = false;
                    std::cout << "Dodano nowe zwierze!\n\n";
                    break;
                }
            }
            case 5: { //usuwanie
                unsigned int choice0 = 0;
                std::cout << "\n1. Usun osobe\n2. Usun zwierze\n";
                std::cin >> choice0;
                std::cout << "\n\n";
                if (choice0 == 1) {
                    unsigned int ind = 0;
                    std::cout << "Ktora osobe usunac?\n";
                    std::cin >> ind;
                    if (ind > p_size) {
                        std::cout << "\nnieprawidlowy index!\n";
                        break;
                    }
                    std::cout << "\n";
                    d_ini_pet(a_arr, a_size, p_arr, ind);
                    del(p_arr, p_size, ind);
                    break;
                } else if (choice0 == 2) {
                    unsigned int ind = 0;
                    std::cout << "Ktore zwierze usunac?\n";
                    std::cin >> ind;
                    if (ind > a_size) {
                        std::cout << "\nnieprawidlowy index!\n";
                        break;
                    }
                    std::cout << "\n";
                    d_ini_pet(p_arr, p_size, a_arr, ind);
                    del(a_arr, a_size, ind);
                    n_ini_pet(p_arr, a_arr, p_size, a_size); //trzeba ponownie zainicjalizowac pet z powodu nowych adresow w tablicy
                    break;
                }
            }
            case 6: { //wyszukiwanie
                std::string imie;
                std::cout << "\n\n1. Wyszukaj osobe\n2. Wyszukaj zwierze\n";
                unsigned int choice0 = 0;
                std::cin >> choice0;
                if (choice0 == 1) {
                    if (p_size <= 0) {
                        std::cout << "Brak osob!\n\n";
                        break;
                    }
                    std::cout << "1. Wyszukiwanie po imieniu\n" << "2. Wyszukiwanie po wieku\n";
                    unsigned int choice1 = 0;
                    std::cin >> choice1;
                    if (choice1 == 1) {
                        std::cout << "\nPodaj imie\n";
                        std::cin >> imie;
                        size_t count = counter(p_arr, p_size, imie);
                        if (count == 0) {
                            std::cout << "\n\nBrak osoby o takim imieniu!\n\n";
                            break;
                        }
                        search(p_arr, imie);
                        std::cout << "\n\nZnaleziono " << count << " osob!\n\n";
                    } else {
                        unsigned int wiek = 0;
                        std::cout << "Podaj wiek\n\n";
                        std::cin >> wiek;
                        size_t count = counter(p_arr, p_size, wiek);
                        if (count == 0) {
                            std::cout << "\n\nBrak osoby o takim wieku!\n";
                            break;
                        }
                        search(p_arr, p_size, wiek);
                        std::cout << "\n\nZnaleziono " << count << " osob!\n\n";
                    }
                    break;
                }
                if (choice0 == 2) {
                    if (a_size <= 0) {
                        std::cout << "Brak zwierzat!\n\n";
                        break;
                    }
                    std::cout << "1. Wyszukiwanie po imieniu\n" << "2. Wyszukiwanie po wieku\n";
                    unsigned int choice1 = 0;
                    std::cin >> choice1;
                    std::cout<<"\n\n";
                    if (choice1 == 1) {
                        std::cout << "\nPodaj imie\n";
                        std::cin >> imie;
                        std::cout << "\n";
                        size_t count = counter(a_arr, a_size, imie);
                        if (count == 0) {
                            std::cout << "Brak zwierzat o takim imieniu!\n\n";
                            break;
                        }
                        search(a_arr, a_size, imie);
                        std::cout << "\nZnaleziono " << count << " zwierzat!\n\n";
                    } else {
                        unsigned int wiek = 0;
                        std::cout << "Podaj wiek\n";
                        std::cin >> wiek;
                        size_t count = counter(a_arr, a_size, wiek);
                        if (count == 0) {
                            std::cout << "Brak zwierzat o takim wieku!\n";
                            break;
                        }
                        search(a_arr, a_size, wiek);
                        std::cout << "\n\nZnaleziono " << count << " zwierzat!\n\n";
                    }
                    break;
                }
            }
            case 7: {//sort
                unsigned int choice0 = 0;
                unsigned int choice4 = 0;
                std::cout << "\n\n";
                std::cout << "1. Tablica osob\n2.Tablica zwierzat\n";
                std::cin >> choice0;
                std::cout << "\n\n";
                if (choice0 == 1) {
                    if (p_size <= 0) {
                        std::cout << "Brak osob!\n\n";
                        break;
                    }
                    std::cout<< "Uwaga! Ta opcja na stale zmieni ulozenie obiektow w tablicy, czy chcesz kontynuowac?\n\n";
                    std::cout << "1. Tak\n2. Nie\n";
                    std::cout << "\n\n";
                    std::cin >> choice4;
                    std::cout << "\n\n";
                    if (choice4 == 1) {
                        unsigned int choice5 = 0;
                        std::cout << "###################################################\n";
                        std::cout << "1. Sortuj wzgledem imienia\n2. Sortuj wzgledem wieku";
                        std::cout << "\n###################################################\n\n";
                        std::cin >> choice5;
                        std::cout << "\n\n";
                        if (choice5 == 1) {
                            if (sortFlag_p1) {
                                std::cout << "Blad! Osoby juz posortowane\n\n";
                                break;
                            }
                            sort(p_arr, p_size, true);
                            sortFlag_p1 = true;
                        } else if (choice5 == 2) {
                            if (sortFlag_p2) {
                                std::cout << "Blad! Osoby juz posortowane\n\n";
                                break;
                            }
                            sort(p_arr, p_size, false);
                            sortFlag_p2 = true;
                        } else break;
                        view(p_arr, p_size);
                        break;
                    } else break;
                }
                if (choice0 == 2) {
                    if (a_size <= 0) {
                        std::cout << "Brak zwierzat!\n\n";
                        break;
                    }
                    std::cout<< "Uwaga! Ta opcja na stale zmieni ulozenie obiektow w tablicy, czy chcesz kontynuowac?\n\n";
                    std::cout << "1. Tak\n2. Nie\n";
                    std::cout << "\n\n";
                    std::cin >> choice4;
                    if (choice4 == 1) {
                        unsigned int choice5 = 0;
                        std::cout << "\n\n###################################################\n";
                        std::cout << "1. Sortuj wzgledem imienia\n2. Sortuj wzgledem wieku";
                        std::cout << "\n###################################################\n\n";
                        std::cin >> choice5;
                        std::cout << "\n\n";
                        if (choice5 == 1) {
                            if (sortFlag_a1) {
                                std::cout << "Blad! Zwierzeta juz posortowane\n\n";
                                break;
                            }
                            sort(a_arr, a_size, true);
                            n_ini_pet(p_arr, a_arr, p_size, a_size);
                            sortFlag_a1 = true;

                        } else if (choice5 == 2) {
                            if (sortFlag_a2) {
                                std::cout << "Blad! Zwierzeta juz posortowane\n\n";
                                break;
                            }
                            sort(a_arr, a_size, false);
                            n_ini_pet(p_arr, a_arr, p_size, a_size);
                            sortFlag_a2 = true;

                        } else break;
                        view(a_arr, a_size);
                        break;
                    } else break;
                }
            }
            case 8: {
                unsigned int choice0;
                std::cout<<"\n1. Edytuj osobe\n";
                std::cin>>choice0;
                std::cout<<"\n\n";
                if (choice0 != 1) break;
                if(choice0 == 1){
                    if(p_size <= 0) break;
                    size_t ind;
                    std::cout<<"Podaj indeks\n";
                    std::cin>>ind;
                    edit(p_arr, ind);
                    break;
                }
            }
            case 9: { //clear
                unsigned int choice0 = 0;
                std::cout << "\n1. Usun wszystkie osoby\n2. Usun wszystkie zwierzeta\n3. Usuń baze rodzin\n";
                std::cin >> choice0;
                std::cout << "\n\n";
                if (choice0 == 1) {
                    if (p_size <= 0) {
                        std::cout << "Brak osob!\n";
                        break;
                    }
                    d_ini_pet(a_arr, a_size);
                    del(p_arr, p_size);
                    flag_ini_p = false;
                    sortFlag_p1 = false;
                    sortFlag_p2 = false;
                    std::cout << "Usunieto!\n";
                    break;
                } else if (choice0 == 2) {
                    if (a_size <= 0) {
                        std::cout << "Brak zwierzat!\n";
                        break;
                    }
                    d_ini_pet(p_arr, p_size);
                    del(a_arr, a_size);
                    flag_ini_a = false;
                    sortFlag_a1 = false;
                    sortFlag_a2 = false;
                    std::cout << "Usunieto!\n";
                    break;
                }
                else if (choice0 == 3) {
                    if (fa_size <= 0) {
                        std::cout << "Brak rodzin!\n";
                        break;
                    }
                    families->clear();
                    flag_ini_f = false;
                    fa_size = 0;
                    std::cout << "Usunieto!\n";
                    break;
                }
            }
            case 10: {
                unsigned int choice0 = 0;
                std::cout << "\n1. zaladuj tablice rodzin\n";
                std::cin>>choice0;
                if (choice0 == 1) {
                    if (families != nullptr) {
                        *families<<"file.dat";
                    } else std::cout << "\nTablica juz istnieje!\n";
                }
                std::cout<<"zapisano\n";
                break;
            }
            case 11: {
                unsigned int choice0 = 0;
                std::cout << "\n1. zaladuj tablice rodzin\n";
                std::cin>>choice0;
                if(choice0 == 1) {
                    if (families == nullptr) {
                        families = std::make_unique<Families>();
                        *families>>"file.dat";
                        fa_size = families->getFamCount();
                    } else if (!flag_ini_f) std::cout << "\nTablica juz istnieje!\n";
                }
                break;
            }
            case 12: {
                unsigned int choice0 = 0;
                bool passFlag = false;
                std::cout<<"\n1. Zaloguj sie\n";
                std::cin>>choice0;
                if(choice0==1){
                    if(passtab == nullptr){
                        if(flag_ini_p) {
                            passtab = std::make_shared<PassTable>(p_arr);
                        }
                    }
                        login(p_arr, passtab, passFlag);
                }
            }
            default:
                break;
        }
        system("pause");
        system("cls");
    }
  /*  if (p_size > 0) {
        del(p_arr, p_size);
    }
    if (a_size > 0) {
        del(a_arr, a_size);
    }*/
}