#include "dog.h"
#include "excpetions.h"
#include "rasa.h"

//constructori
dog::dog(std::string nume_caine, int varsta, int greutate) : name(std::move(nume_caine)), age(varsta), weight(greutate){
    if (greutate <= 0 and varsta <= 0) throw ambele();
    else if (greutate <= 0) throw InvalidWeight();
    else if (varsta <= 0) throw InvalidAge();
}
dog::dog() {}

//getters
std::string dog::getName() const {
    return name;
}
int dog::getAge() const {
    return age;
}
int dog::getWeight() const {
    return weight;
}

//setters
void dog::setName(std::string nume_nou) {
    name = std::move(nume_nou);
}
void dog::setAge(int new_age) {
    age = new_age;
}
void dog::setWeight(int new_weight) {
    weight = new_weight;
}

void dog::print(std::ostream &fout) const {
    fout << "Hello! I am "<<name<<", i am from "<<get_country()<<" and i am a "<<get_size()<<" dog.";
}