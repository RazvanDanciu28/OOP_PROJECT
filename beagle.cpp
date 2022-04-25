#include "dog.h"
#include "beagle.h"
#include "rasa.h"

//constructori
Beagle::Beagle(std::string nume, int varsta, int greutate, std::string jucarie,
               std::string culoare, std::string mancare, std::string activitate) :
        dog (std::move(nume), varsta, greutate), fav_toy(std::move(jucarie)),
        color(std::move(culoare)), fav_meal(std::move(mancare)), fav_activity(std::move(activitate)){}
Beagle::Beagle() : dog() {}

//metode virtuale pure supraincarcate
Rasa Beagle::getRasa() const {
    return Rasa::Beagle;
}
std::string Beagle::get_size() const {
    return "medium";
}
std::string Beagle::get_country() const {
    return "England";
}

//getters
std::string Beagle::get_favToy() const {
    return fav_toy;
}
std::string Beagle::get_color() const {
    return color;
}
std::string Beagle::get_favMeal() const {
    return fav_meal;
}
std::string Beagle::get_favActivity() const {
    return fav_activity;
}

//setters
void Beagle::set_favToy(std::string jucarie) {
    fav_toy = std::move(jucarie);
}
void Beagle::set_color(std::string culoare) {
    color = std::move(culoare);
}
void Beagle::set_favMeal(std::string mancare) {
    fav_meal = std::move(mancare);
}
void Beagle::set_favActivity(std::string activitate) {
    fav_activity = std::move(activitate);
}

void Beagle::print(std::ostream &fout) const {
    dog::print(fout);
    std::cout << "\n" << "My favorite toy is " << get_favToy();
    std::cout << "\n" << "My color is" << get_color();
    std::cout << "\n" << "My favorite meal is " << get_favMeal();
    std::cout << "\n" << "My favorite activity is " << get_favActivity();
    std::cout<< "\n\n";
}

//cc + op=
Beagle::Beagle(const Beagle &beg) : dog(beg.getName(), beg.getAge(), beg.getWeight()), fav_toy(beg.get_favToy()),
                                     color(beg.get_color()), fav_meal(beg.get_favMeal()), fav_activity(beg.get_favActivity()) {}

Beagle &Beagle::operator=(const Beagle &rhs) {
    if (this != &rhs) {
        dog::operator=(rhs);
        fav_toy = rhs.fav_toy;
        fav_meal = rhs.fav_meal;
        fav_activity = rhs.fav_activity;
        color = rhs.color;
    }
    return *this;
}