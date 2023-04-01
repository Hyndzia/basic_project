#include<random>

size_t size_t_gen(size_t first, size_t last){
    std::random_device seed;
    std::mt19937_64 gen(seed());
    std::uniform_int_distribution<size_t> d(first, last);
    return d(gen);
}

unsigned int age_gen(){
    std::random_device seed;
    std::mt19937_64 gen(seed());
    std::normal_distribution<double> d(42, 20);
    double tmp;
    do {tmp = d(gen);}
    while (tmp<=1);
    unsigned int age = static_cast<unsigned int>(std::floor(tmp));
    return age;
}

unsigned int a_age_gen(){
    std::random_device seed;
    std::mt19937_64 gen(seed());
    std::normal_distribution<> d(7, 3.5);
    double tmp;
    do {tmp = d(gen);}
    while (tmp<=1);
    unsigned int age= static_cast<unsigned int>(std::floor(tmp));
    return age;
}

std::string gender_gen(std::string name){
    if (name.back() == 'a') return {"Kobieta"};
    else return{"Mezczyzna"};
}

std::string species_gen() {
    static std::string tab[] = { "Kot", "Pies", "Papuga", "Zolw", "Ropucha", "Waz", "Chomik" };
    return tab[size_t_gen(0, 6)];
}

std::string name_gen() {
    static std::string tab[] = { "Jan", "Jakub", "Andrzej", "Mariusz", "Zbychu", "Ania", "Maja", "Dominika", "Alicja", "Miroslawa", "Kazimierz", "Boguslaw", "Maurycjusz", "Onufry", "Emir", "Zachariasz", "Leslaw", "Przybyslaw", "Tyberiusz", "Herbert", "Czeslawa", "Natasza", "Babeta", "Hermenegilda", "Dargomira", "Izolda", "Hiacynta", "Keira", "Wiktoria", "Salma"};
    return tab[size_t_gen(0, 29)];
}

std::string petName_gen() {
    static std::string tab[] = {"Gacek", "Ferdek", "Tostek", "Filus", "Kabanos", "Orbitek", "Gienio", "Gucio", "Momo", "Bimo", "Bilon", "Klapcio", "Chrupcio", "Hugo", "Pluto"};
    return tab[size_t_gen(0, 14)];
}
std::string surname_gen(){
    static std::string tab[] = {"Bialik", "Wegner", "Banasik", "Zaczek", "Majcher", "Antosz", "Pazio", "Kalina", "Cieszynski", "Polec", "Rosiek", "Pastusiak", "Martyniak", "Wnek", "Herman", "Zylka", "Syrek", "Rodziewicz", "Latusek", "Migas"};
    return tab[size_t_gen(0, 19)];
}