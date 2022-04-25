#include "dog.h"
#include "pug.h"
#include "rasa.h"

//constructori
Pug::Pug(std::string nume, int varsta, int greutate, std::string jucarie,
               std::string culoare, std::string mancare, std::string activitate) :
        dog (std::move(nume), varsta, greutate), fav_toy(std::move(jucarie)),
        color(std::move(culoare)), fav_meal(std::move(mancare)), fav_activity(std::move(activitate)){}
Pug::Pug() : dog() {}

//metode virtuale pure supraincarcate
Rasa Pug::getRasa() const {
    return Rasa::Pug;
}
std::string Pug::get_size() const {
    return "small";
}
std::string Pug::get_country() const {
    return "China";
}

//getters
std::string Pug::get_favToy() const {
    return fav_toy;
}
std::string Pug::get_color() const {
    return color;
}
std::string Pug::get_favMeal() const {
    return fav_meal;
}
std::string Pug::get_favActivity() const {
    return fav_activity;
}

//setters
void Pug::set_favToy(std::string jucarie) {
    fav_toy = std::move(jucarie);
}
void Pug::set_color(std::string culoare) {
    color = std::move(culoare);
}
void Pug::set_favMeal(std::string mancare) {
    fav_meal = std::move(mancare);
}
void Pug::set_favActivity(std::string activitate) {
    fav_activity = std::move(activitate);
}

void Pug::print(std::ostream &fout) const {
    dog::print(fout);
    std::cout << "\n" << "My favorite toy is " << get_favToy();
    std::cout << "\n" << "My color is" << get_color();
    std::cout << "\n" << "My favorite meal is " << get_favMeal();
    std::cout << "\n" << "My favorite activity is " << get_favActivity();
}

//cc + op=
Pug::Pug(const Pug &pug) : dog(pug.getName(), pug.getAge(), pug.getWeight()), fav_toy(pug.get_favToy()),
                                     color(pug.get_color()), fav_meal(pug.get_favMeal()), fav_activity(pug.get_favActivity()) {}

Pug &Pug::operator=(const Pug &rhs) {
    if (this != &rhs) {
        dog::operator=(rhs);
        fav_toy = rhs.fav_toy;
        fav_meal = rhs.fav_meal;
        fav_activity = rhs.fav_activity;
        color = rhs.color;
    }
    return *this;
}