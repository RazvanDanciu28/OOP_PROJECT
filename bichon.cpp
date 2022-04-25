#include "dog.h"
#include "bichon.h"
#include "rasa.h"

#include "dog.cpp"

//constructori
Bichon::Bichon(std::string nume, int varsta, int greutate, std::string jucarie,
       std::string culoare, std::string mancare, std::string activitate) :
       dog (std::move(nume), varsta, greutate), fav_toy(std::move(jucarie)),
       color(std::move(culoare)), fav_meal(std::move(mancare)), fav_activity(std::move(activitate)){}
Bichon::Bichon() : dog() {}

//metode virtuale pure supraincarcate
Rasa Bichon::getRasa() const {
    return Rasa::Bichon;
}
std::string Bichon::get_size() const {
    return "small";
}
std::string Bichon::get_country() const {
    return "Italy";
}

//getters
std::string Bichon::get_favToy() const {
    return fav_toy;
}
std::string Bichon::get_color() const {
    return color;
}
std::string Bichon::get_favMeal() const {
    return fav_meal;
}
std::string Bichon::get_favActivity() const {
    return fav_activity;
}

//setters
void Bichon::set_favToy(std::string jucarie) {
    fav_toy = std::move(jucarie);
}
void Bichon::set_color(std::string culoare) {
    color = std::move(culoare);
}
void Bichon::set_favMeal(std::string mancare) {
    fav_meal = std::move(mancare);
}
void Bichon::set_favActivity(std::string activitate) {
    fav_activity = std::move(activitate);
}

void Bichon::print(std::ostream &fout) const {
    dog::print(fout);
    std::cout << "\n" << "My favorite toy is " << get_favToy();
    std::cout << "\n" << "My color is" << get_color();
    std::cout << "\n" << "My favorite meal is " << get_favMeal();
    std::cout << "\n" << "My favorite activity is " << get_favActivity();
    std::cout<< "\n\n";
}

//cc + op=
Bichon::Bichon(const Bichon &bich) : dog(bich.getName(), bich.getAge(), bich.getWeight()), fav_toy(bich.get_favToy()),
                                     color(bich.get_color()), fav_meal(bich.get_favMeal()), fav_activity(bich.get_favActivity()) {}

Bichon &Bichon::operator=(const Bichon &rhs) {
    if (this != &rhs) {
        dog::operator=(rhs);
        fav_toy = rhs.fav_toy;
        fav_meal = rhs.fav_meal;
        fav_activity = rhs.fav_activity;
        color = rhs.color;
    }
    return *this;
}