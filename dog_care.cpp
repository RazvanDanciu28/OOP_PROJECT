#include <memory>
#include <vector>
#include "dog_care.h"

const std::vector<std::shared_ptr<dog>> &DogCare::GetDogs() {
    return dogs;
}
void DogCare::addDog(const std::shared_ptr<dog> &dogg) {
    dogs.push_back(dogg);
}
void DogCare::deleteDog(const int i_dog) {
    for (int i = i_dog; i < dogs.size() - 1; i++){
        dogs[i] = dogs[i+1];
    }
    dogs.pop_back();
}
const std::shared_ptr<dog> &DogCare::get_ndog(int n) {
    return dogs[n];
}
void DogCare::printAllDogs() {
    for (auto &it: dogs){
        std::cout<<it<<"\n";
    }
}
void DogCare::print_all_small_dogs() {
    for (auto &it: dogs) {
        if (it->get_size() != "small") continue;
        std::cout<<it<<"\n";
    }
}
void DogCare::print_all_medium_dogs() {
    for (auto &it: dogs) {
        if (it->get_size() != "medium") continue;
        std::cout<<it<<"\n";
    }
}
void DogCare::print_all_big_dogs() {
    for (auto &it: dogs) {
        if (it->get_size() != "big") continue;
        std::cout<<it<<"\n";
    }
}