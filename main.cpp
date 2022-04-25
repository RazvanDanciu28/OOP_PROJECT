#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "excpetions.h"
#include "dog.h"
#include "bichon.h"
#include "beagle.h"
#include "rotweiller.h"
#include "golden_retriever.h"
#include "pug.h"
#include "dog_care.h"

#include "bichon.cpp"
#include "beagle.cpp"
#include "rotweiller.cpp"
#include "golden_retriever.cpp"
#include "pug.cpp"
#include "exceptions.cpp"
#include "dog_care.cpp"


std::vector<std::shared_ptr<dog>> DogCare::dogs;
int main() {

    std::string comanda;
    std::cout<<"Introdu comanda"<<std::endl;
    std::cout<<"Comenzi disponibile: adauga caine, sterge caine, afiseaza caine\n";
    std::getline(std::cin, comanda);


    while (comanda != "stop"){
        if (comanda == "adauga caine"){
            std::cout<<"Ce rasa de caine adaugi? (Bichon, Rotweiller, Golden Retriever, Beagle, Pug)\n";
            std::string caine;
            std::getline(std::cin, caine);
            if (caine == "Bichon"){
                try {
                    Bichon dog;
                    std::cin>>dog;
                    auto dogg = std::make_shared<Bichon>(dog);
                    DogCare::addDog(dogg);
                }
                catch (const ambele &e){
                    std::cout<<e.what();
                }
                catch (const InvalidWeight &e){
                    std::cout<<e.what();
                }
                catch (const InvalidAge &e){
                    std::cout<<e.what();
                }
            }
            else if (caine == "Rotweiller"){
                try {
                    Rotweiller dog;
                    std::cin>>dog;
                    auto dogg = std::make_shared<Rotweiller>(dog);
                    DogCare::addDog(dogg);
                }
                catch (const ambele &e){
                    std::cout<<e.what();
                }
                catch (const InvalidWeight &e){
                    std::cout<<e.what();
                }
                catch (const InvalidAge &e){
                    std::cout<<e.what();
                }
            }
            else if (caine == "Golden Retriever"){
                try {
                    Golden_Retriever dog;
                    std::cin>>dog;
                    auto dogg = std::make_shared<Golden_Retriever>(dog);
                    DogCare::addDog(dogg);
                }
                catch (const ambele &e){
                    std::cout<<e.what();
                }
                catch (const InvalidWeight &e){
                    std::cout<<e.what();
                }
                catch (const InvalidAge &e){
                    std::cout<<e.what();
                }
            }
            else if (caine == "Beagle"){
                try {
                    Beagle dog;
                    std::cin>>dog;
                    auto dogg = std::make_shared<Beagle>(dog);
                    DogCare::addDog(dogg);
                }
                catch (const ambele &e){
                    std::cout<<e.what();
                }
                catch (const InvalidWeight &e){
                    std::cout<<e.what();
                }
                catch (const InvalidAge &e){
                    std::cout<<e.what();
                }
            }
            else {
                try {
                    Pug dog;
                    std::cin>>dog;
                    auto dogg = std::make_shared<Pug>(dog);
                    DogCare::addDog(dogg);
                }
                catch (const ambele &e){
                    std::cout<<e.what();
                }
                catch (const InvalidWeight &e){
                    std::cout<<e.what();
                }
                catch (const InvalidAge &e){
                    std::cout<<e.what();
                }
            }
        }
        else if (comanda == "sterge caine"){
            std::cout<<"Introdu cainele pe care doresti sa-l stergi\n";
            int nr_caine;
            std::cin>>nr_caine;
            std::cin.get();

            DogCare::deleteDog(nr_caine);
        }
        else {
            std::cout<<"Alege ce vrei sa afisezi: toti cainii, cainii mici, cainii medii, cainii mari\n";
            std::string tip_caine;

            std::getline(std::cin, tip_caine);
            if (tip_caine == "toti cainii") DogCare::printAllDogs();
            else if (tip_caine == "cainii mici") DogCare::print_all_small_dogs();
            else if (tip_caine == "cainii medii") DogCare::print_all_medium_dogs();
            else DogCare::print_all_big_dogs();
        }

        std::cout<<"Introdu comanda"<<std::endl;
        std::cout<<"Comenzi disponibile: adauga caine, sterge caine, afiseaza caine\n";
        std::getline(std::cin, comanda);
    }
    return 0;
}
