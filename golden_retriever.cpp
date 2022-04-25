#include "dog.h"
#include "golden_retriever.h"
#include "rasa.h"

//constructori
Golden_Retriever::Golden_Retriever(std::string nume, int varsta, int greutate, std::string jucarie,
               std::string culoare, std::string mancare, std::string activitate) :
        dog (std::move(nume), varsta, greutate), fav_toy(std::move(jucarie)),
        color(std::move(culoare)), fav_meal(std::move(mancare)), fav_activity(std::move(activitate)){}
Golden_Retriever::Golden_Retriever() : dog() {}

//metode virtuale pure supraincarcate
Rasa Golden_Retriever::getRasa() const {
    return Rasa::Golden_Retriever;
}
std::string Golden_Retriever::get_size() const {
    return "big";
}
std::string Golden_Retriever::get_country() const {
    return "Scotland";
}

//getters
std::string Golden_Retriever::get_favToy() const {
    return fav_toy;
}
std::string Golden_Retriever::get_color() const {
    return color;
}
std::string Golden_Retriever::get_favMeal() const {
    return fav_meal;
}
std::string Golden_Retriever::get_favActivity() const {
    return fav_activity;
}

//setters
void Golden_Retriever::set_favToy(std::string jucarie) {
    fav_toy = std::move(jucarie);
}
void Golden_Retriever::set_color(std::string culoare) {
    color = std::move(culoare);
}
void Golden_Retriever::set_favMeal(std::string mancare) {
    fav_meal = std::move(mancare);
}
void Golden_Retriever::set_favActivity(std::string activitate) {
    fav_activity = std::move(activitate);
}

void Golden_Retriever::print(std::ostream &fout) const {
    dog::print(fout);
    std::cout << "\n" << "My favorite toy is " << get_favToy();
    std::cout << "\n" << "My color is" << get_color();
    std::cout << "\n" << "My favorite meal is " << get_favMeal();
    std::cout << "\n" << "My favorite activity is " << get_favActivity();
    std::cout<< "\n\n";
}

//cc + op=
Golden_Retriever::Golden_Retriever(const Golden_Retriever &gold) : dog(gold.getName(), gold.getAge(), gold.getWeight()), fav_toy(gold.get_favToy()),
                                     color(gold.get_color()), fav_meal(gold.get_favMeal()), fav_activity(gold.get_favActivity()) {}

Golden_Retriever &Golden_Retriever::operator=(const Golden_Retriever &rhs) {
    if (this != &rhs) {
        dog::operator=(rhs);
        fav_toy = rhs.fav_toy;
        fav_meal = rhs.fav_meal;
        fav_activity = rhs.fav_activity;
        color = rhs.color;
    }
    return *this;
}