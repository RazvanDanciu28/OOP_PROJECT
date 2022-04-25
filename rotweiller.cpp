#include "dog.h"
#include "rotweiller.h"
#include "rasa.h"

//constructori
Rotweiller::Rotweiller(std::string nume, int varsta, int greutate, std::string jucarie,
               std::string culoare, std::string mancare, std::string activitate) :
        dog (std::move(nume), varsta, greutate), fav_toy(std::move(jucarie)),
        color(std::move(culoare)), fav_meal(std::move(mancare)), fav_activity(std::move(activitate)){}
Rotweiller::Rotweiller() : dog() {}

//metode virtuale pure supraincarcate
Rasa Rotweiller::getRasa() const {
    return Rasa::Rotweiller;
}
std::string Rotweiller::get_size() const {
    return "big";
}
std::string Rotweiller::get_country() const {
    return "Germany";
}

//getters
std::string Rotweiller::get_favToy() const {
    return fav_toy;
}
std::string Rotweiller::get_color() const {
    return color;
}
std::string Rotweiller::get_favMeal() const {
    return fav_meal;
}
std::string Rotweiller::get_favActivity() const {
    return fav_activity;
}

//setters
void Rotweiller::set_favToy(std::string jucarie) {
    fav_toy = std::move(jucarie);
}
void Rotweiller::set_color(std::string culoare) {
    color = std::move(culoare);
}
void Rotweiller::set_favMeal(std::string mancare) {
    fav_meal = std::move(mancare);
}
void Rotweiller::set_favActivity(std::string activitate) {
    fav_activity = std::move(activitate);
}

void Rotweiller::print(std::ostream &fout) const {
    dog::print(fout);
    std::cout << "\n" << "My favorite toy is " << get_favToy();
    std::cout << "\n" << "My color is" << get_color();
    std::cout << "\n" << "My favorite meal is " << get_favMeal();
    std::cout << "\n" << "My favorite activity is " << get_favActivity();
    std::cout<< "\n\n";
}

//cc + op=
Rotweiller::Rotweiller(const Rotweiller &rot) : dog(rot.getName(), rot.getAge(), rot.getWeight()), fav_toy(rot.get_favToy()),
                                     color(rot.get_color()), fav_meal(rot.get_favMeal()), fav_activity(rot.get_favActivity()) {}

Rotweiller &Rotweiller::operator=(const Rotweiller &rhs) {
    if (this != &rhs) {
        dog::operator=(rhs);
        fav_toy = rhs.fav_toy;
        fav_meal = rhs.fav_meal;
        fav_activity = rhs.fav_activity;
        color = rhs.color;
    }
    return *this;
}