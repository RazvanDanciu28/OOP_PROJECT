#include <memory>
#include <vector>
#include "dog.h"

#ifndef _dog_care_h
#define _dog_care_h

class DogCare {
    static std::vector<std::shared_ptr<dog>> dogs;
    DogCare() = delete;
public:
    static const std::vector<std::shared_ptr<dog>> &GetDogs();
    static void addDog (const std::shared_ptr<dog> &dogg);
    static void deleteDog (const int i_dog);
    static const std::shared_ptr<dog> &get_ndog(int n);
    static void printAllDogs();
    static void print_all_small_dogs();
    static void print_all_medium_dogs();
    static void print_all_big_dogs();

};


#endif