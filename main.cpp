#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <memory>

//exceptii
class InvalidAge : public std::exception {
public:
    InvalidAge() = default;

    const char *what() const noexcept override {
        return "Varsta invalida!";
    }
};
class InvalidWeight : public std::exception {
public:
    InvalidWeight() = default;

    const char *what() const noexcept override {
        return "Greutate invalida!";
    }
};
class ambele : public std::exception {
public:
    ambele() = default;

    const char *what() const noexcept override {
        return "Varsta si greutate invalide!";
    }
};

enum class Rasa {
    Bichon,
    Beagle,
    Rottweiler,
    Golden_Retriever,
    Pug
};

class dog {
    std::string  name;
    int age, weight;
public:
    dog(std::string nume_caine, int varsta, int greutate) : name(std::move(nume_caine)), age(varsta), weight(greutate){
        if (greutate <= 0 and varsta <= 0) throw ambele();
        else if (greutate <= 0) throw InvalidWeight();
        else if (varsta <= 0) throw InvalidAge();
    }

    dog(){}

    virtual ~dog() = default;
    virtual Rasa getRasa() const = 0;

    //getters
    std::string getName() const{
        return name;
    }
    int getAge() const {
        return age;
    };
    int getWeight() const{
        return weight;
    }

    //setters
    void setName(std::string nume_nou){
        name = std::move(nume_nou);
    }
    void setAge(int new_age){
        age = new_age;
    }
    void setWeight(int new_weight){
        weight = new_weight;
    }

    //metode virtuale pure
    virtual std::string get_size() const = 0;
    virtual std::string get_country() const = 0;

    virtual void print(std::ostream &fout) const {
        fout << "Hello! I am "<<name<<", i am from "<<get_country()<<" and i am a "<<get_size()<<" dog.";
    }


};

std::ostream& operator<<(std::ostream &fout, const dog *dogg){
    dogg->print(fout);
    return fout;
}

class Bichon : public dog{
    std::string fav_toy, color, fav_meal, fav_activity;
public:
    Bichon(std::string nume, int varsta, int greutate, std::string jucarie,
           std::string culoare, std::string mancare, std::string activitate) :
           dog (std::move(nume), varsta, greutate), fav_toy(std::move(jucarie)),
           color(std::move(culoare)), fav_meal(std::move(mancare)), fav_activity(std::move(activitate)){}

    Bichon() : dog() {}

    Rasa getRasa() const override {
        return Rasa::Bichon;
    }
    std::string get_size() const override {
        return "small";
    }
    std::string get_country() const override {
        return "Italy";
    }

    //getters
    std::string get_favToy() const {
        return fav_toy;
    }
    std::string get_color() const {
        return color;
    }
    std::string get_favMeal() const {
        return fav_meal;
    }
    std::string get_favActivity() const {
        return fav_activity;
    };

    //setters
    void set_favToy(std::string jucarie) {
        Bichon::fav_toy = std::move(jucarie);
    }
    void set_color(std::string culoare) {
        Bichon::color = std::move(culoare);
    }
    void set_favMeal(std::string mancare) {
        Bichon::fav_meal = std::move(mancare);
    }
    void set_favActivity(std::string activitate) {
        Bichon::fav_activity = std::move(activitate);
    }

    void print(std::ostream &fout) const override {
        dog::print(fout);
        std::cout << "\n" << "My favorite toy is " << get_favToy();
        std::cout << "\n" << "My color is" << get_color();
        std::cout << "\n" << "My favorite meal is " << get_favMeal();
        std::cout << "\n" << "My favorite activity is " << get_favActivity();
    }

    friend std::ostream &operator<<(std::ostream &fout, const Bichon &bich){
        bich.print(fout);
        return fout;
    }
    friend std::istream &operator>>(std::istream &fin, Bichon &bich) {
        std::string nume, jucarie, activitate, mancare, culoare;
        int varsta, greutate;

        std::cout<<"Introdu nume, varsta, greutate, jucarie, culoare, mancare, activitate:"<<"\n";

        std::getline(fin, nume);
        fin>>varsta>>greutate;
        fin.get();

        std::getline(fin, jucarie);
        std::getline(fin, culoare);
        std::getline(fin, mancare);
        std::getline(fin, activitate);

        bich.setName(nume);
        bich.setAge(varsta);
        bich.setWeight(greutate);
        bich.set_favToy(jucarie);
        bich.set_color(culoare);
        bich.set_favMeal(mancare);
        bich.set_favActivity(activitate);
    }

    Bichon(const Bichon &bich) : dog(bich.getName(), bich.getAge(), bich.getWeight()), fav_toy(bich.get_favToy()),
                                color(bich.get_color()), fav_meal(bich.get_favMeal()), fav_activity(bich.get_favActivity()) {}


    Bichon& operator=(const Bichon &rhs){
        if (this != &rhs) {
            dog::operator=(rhs);
            fav_toy = rhs.fav_toy;
            fav_meal = rhs.fav_meal;
            fav_activity = rhs.fav_activity;
            color = rhs.color;
        }
        return *this;
    }

};

class Beagle : public dog {
    std::string fav_toy, fav_meal, color, fav_activity;
public:
    Beagle(std::string nume, int varsta, int greutate, std::string jucarie,
           std::string culoare, std::string mancare, std::string activitate) :
           dog (std::move(nume), varsta, greutate), fav_toy(std::move(jucarie)),
           color(std::move(culoare)), fav_meal(std::move(mancare)), fav_activity(std::move(activitate)){}

    Beagle() : dog() {}

    Rasa getRasa() const override {
        return Rasa::Beagle;
    }
    std::string get_size() const override {
        return "medium";
    }
    std::string get_country() const override {
        return "England";
    }

    //getters
    std::string get_favToy() const {
        return fav_toy;
    };
    std::string get_favMeal() const {
        return fav_meal;
    }
    std::string get_favActivity() const {
        return fav_activity;
    }
    std::string get_color() const {
        return color;
    }

    //setters
    void set_favToy(std::string jucarie) {
        Beagle::fav_toy = std::move(jucarie);
    }
    void set_favMeal(std::string mancare) {
        Beagle::fav_meal = std::move(mancare);
    }
    void set_favActivity(std::string activitate) {
        Beagle::fav_activity = std::move(activitate);
    }
    void set_color(std::string culoare) {
        Beagle::color = std::move(culoare);
    }

    void print (std::ostream &fout) const override {
        dog::print(fout);
        std::cout << "\n" << "My favorite toy is " << get_favToy();
        std::cout << "\n" << "My color is" << get_color();
        std::cout << "\n" << "My favorite meal is " << get_favMeal();
        std::cout << "\n" << "My favorite activity is " << get_favActivity();
    }

    friend std::ostream &operator<<(std::ostream &fout, const Beagle &beg){
        beg.print(fout);
        return fout;
    }
    friend std::istream &operator>>(std::istream &fin, Beagle &beg) {
        std::string nume, jucarie, activitate, mancare, culoare;
        int varsta, greutate;

        std::cout<<"Introdu nume, varsta, greutate, jucarie, culoare, mancare, activitate:"<<"\n";

        std::getline(fin, nume);
        fin>>varsta>>greutate;
        fin.get();

        std::getline(fin, jucarie);
        std::getline(fin, culoare);
        std::getline(fin, mancare);
        std::getline(fin, activitate);

        beg.setName(nume);
        beg.setAge(varsta);
        beg.setWeight(greutate);
        beg.set_favToy(jucarie);
        beg.set_color(culoare);
        beg.set_favMeal(mancare);
        beg.set_favActivity(activitate);
    }


    //CC + op =
    Beagle(const Beagle &beg) : dog(beg.getName(), beg.getAge(), beg.getWeight()), fav_toy(beg.get_favToy()),
                                 color(beg.get_color()), fav_meal(beg.get_favMeal()), fav_activity(beg.get_favActivity()) {}

    Beagle& operator=(const Beagle &rhs){
        if (this != &rhs) {
            dog::operator=(rhs);
            fav_toy = rhs.fav_toy;
            fav_meal = rhs.fav_meal;
            fav_activity = rhs.fav_activity;
            color = rhs.color;
        }
        return *this;
    }

};

class Rotweiller  : public dog {
    std::string fav_toy, fav_meal, color, fav_activity;
public:
    Rotweiller(std::string nume, int varsta, int greutate, std::string jucarie,
                std::string culoare, std::string mancare, std::string activitate) :
                dog (std::move(nume), varsta, greutate), fav_toy(std::move(jucarie)),
                color(std::move(culoare)), fav_meal(std::move(mancare)), fav_activity(std::move(activitate)){}

    Rotweiller() : dog() {}

    Rasa getRasa() const override {
        return Rasa::Rottweiler;
    }
    std::string get_size() const override {
        return "big";
    }
    std::string get_country() const override {
        return "Germany";
    }

    //getters
    std::string get_favToy() const {
        return fav_toy;
    };
    std::string get_favMeal() const {
        return fav_meal;
    }
    std::string get_favActivity() const {
        return fav_activity;
    }
    std::string get_color() const {
        return color;
    }

    //setters
    void set_favToy(std::string jucarie) {
        Rotweiller::fav_toy = std::move(jucarie);
    }
    void set_favMeal(std::string mancare) {
        Rotweiller::fav_meal = std::move(mancare);
    }
    void set_favActivity(std::string activitate) {
        Rotweiller::fav_activity = std::move(activitate);
    }
    void set_color(std::string culoare) {
        Rotweiller::color = std::move(culoare);
    }

    void print (std::ostream &fout) const override {
        dog::print(fout);
        std::cout << "\n" << "My favorite toy is " << get_favToy();
        std::cout << "\n" << "My color is" << get_color();
        std::cout << "\n" << "My favorite meal is " << get_favMeal();
        std::cout << "\n" << "My favorite activity is " << get_favActivity();
    }

    friend std::ostream &operator<<(std::ostream &fout, const Rotweiller &rot){
        rot.print(fout);
        return fout;
    }
    friend std::istream &operator>>(std::istream &fin, Rotweiller &rot) {
        std::string nume, jucarie, activitate, mancare, culoare;
        int varsta, greutate;

        std::cout<<"Introdu nume, varsta, greutate, jucarie, culoare, mancare, activitate:"<<"\n";

        std::getline(fin, nume);
        fin>>varsta>>greutate;
        fin.get();

        std::getline(fin, jucarie);
        std::getline(fin, culoare);
        std::getline(fin, mancare);
        std::getline(fin, activitate);

        rot.setName(nume);
        rot.setAge(varsta);
        rot.setWeight(greutate);
        rot.set_favToy(jucarie);
        rot.set_color(culoare);
        rot.set_favMeal(mancare);
        rot.set_favActivity(activitate);
    }

    //CC + op =
    Rotweiller(const Rotweiller &rot) : dog(rot.getName(), rot.getAge(), rot.getWeight()), fav_toy(rot.get_favToy()),
                                       color(rot.get_color()), fav_meal(rot.get_favMeal()), fav_activity(rot.get_favActivity()) {}

    Rotweiller& operator=(const Rotweiller &rhs){
        if (this != &rhs) {
            dog::operator=(rhs);
            fav_toy = rhs.fav_toy;
            fav_meal = rhs.fav_meal;
            fav_activity = rhs.fav_activity;
            color = rhs.color;
        }
        return *this;
    }

};

class Golden_Retriever : public dog {
    std::string fav_toy, fav_meal, color, fav_activity;
public:
    Golden_Retriever(std::string nume, int varsta, int greutate, std::string jucarie,
    std::string culoare, std::string mancare, std::string activitate) :
    dog (std::move(nume), varsta, greutate), fav_toy(std::move(jucarie)),
    color(std::move(culoare)), fav_meal(std::move(mancare)), fav_activity(std::move(activitate)){}

    Golden_Retriever() : dog() {}

    Rasa getRasa() const override {
        return Rasa::Golden_Retriever;
    }
    std::string get_size() const override {
        return "big";
    }
    std::string get_country() const override {
        return "Scotland";
    }

    //getters
    std::string get_favToy() const {
        return fav_toy;
    };
    std::string get_favMeal() const {
        return fav_meal;
    }
    std::string get_favActivity() const {
        return fav_activity;
    }
    std::string get_color() const {
        return color;
    }

    //setters
    void set_favToy(std::string jucarie) {
        Golden_Retriever::fav_toy = std::move(jucarie);
    }
    void set_favMeal(std::string mancare) {
        Golden_Retriever::fav_meal = std::move(mancare);
    }
    void set_favActivity(std::string activitate) {
        Golden_Retriever::fav_activity = std::move(activitate);
    }
    void set_color(std::string culoare) {
        Golden_Retriever::color = std::move(culoare);
    }

    void print (std::ostream &fout) const override {
        dog::print(fout);
        std::cout << "\n" << "My favorite toy is " << get_favToy();
        std::cout << "\n" << "My color is" << get_color();
        std::cout << "\n" << "My favorite meal is " << get_favMeal();
        std::cout << "\n" << "My favorite activity is " << get_favActivity();
    }

    friend std::ostream &operator<<(std::ostream &fout, const Golden_Retriever &gold){
        gold.print(fout);
        return fout;
    }
    friend std::istream &operator>>(std::istream &fin, Golden_Retriever &gold) {
        std::string nume, jucarie, activitate, mancare, culoare;
        int varsta, greutate;

        std::cout<<"Introdu nume, varsta, greutate, jucarie, culoare, mancare, activitate:"<<"\n";

        std::getline(fin, nume);
        fin>>varsta>>greutate;
        fin.get();

        std::getline(fin, jucarie);
        std::getline(fin, culoare);
        std::getline(fin, mancare);
        std::getline(fin, activitate);

        gold.setName(nume);
        gold.setAge(varsta);
        gold.setWeight(greutate);
        gold.set_favToy(jucarie);
        gold.set_color(culoare);
        gold.set_favMeal(mancare);
        gold.set_favActivity(activitate);
    }


    //CC + op =
    Golden_Retriever(const Golden_Retriever &gold) : dog(gold.getName(), gold.getAge(), gold.getWeight()), fav_toy(gold.get_favToy()),
                                                    color(gold.get_color()), fav_meal(gold.get_favMeal()), fav_activity(gold.get_favActivity()) {}

    Golden_Retriever& operator=(const Golden_Retriever &rhs){
        if (this != &rhs) {
            dog::operator=(rhs);
            fav_toy = rhs.fav_toy;
            fav_meal = rhs.fav_meal;
            fav_activity = rhs.fav_activity;
            color = rhs.color;
        }
        return *this;
    }
};

class Pug  : public dog {
    std::string fav_toy, fav_meal, color, fav_activity;
public:
    Pug(std::string nume, int varsta, int greutate, std::string jucarie,
               std::string culoare, std::string mancare, std::string activitate) :
            dog (std::move(nume), varsta, greutate), fav_toy(std::move(jucarie)),
            color(std::move(culoare)), fav_meal(std::move(mancare)), fav_activity(std::move(activitate)){}
    Pug() : dog() {}

    Rasa getRasa() const override {
        return Rasa::Pug;
    }
    std::string get_size() const override {
        return "small";
    }
    std::string get_country() const override {
        return "China";
    }

    //getters
    std::string get_favToy() const {
        return fav_toy;
    };
    std::string get_favMeal() const {
        return fav_meal;
    }
    std::string get_favActivity() const {
        return fav_activity;
    }
    std::string get_color() const {
        return color;
    }

    //setters
    void set_favToy(std::string jucarie) {
        Pug::fav_toy = std::move(jucarie);
    }
    void set_favMeal(std::string mancare) {
        Pug::fav_meal = std::move(mancare);
    }
    void set_favActivity(std::string activitate) {
        Pug::fav_activity = std::move(activitate);
    }
    void set_color(std::string culoare) {
        Pug::color = std::move(culoare);
    }

    void print (std::ostream &fout) const override {
        dog::print(fout);
        std::cout << "\n" << "My favorite toy is " << get_favToy();
        std::cout << "\n" << "My color is" << get_color();
        std::cout << "\n" << "My favorite meal is " << get_favMeal();
        std::cout << "\n" << "My favorite activity is " << get_favActivity();
    }

    friend std::ostream &operator<<(std::ostream &fout, const Pug &pug){
        pug.print(fout);
        return fout;
    }
    friend std::istream &operator>>(std::istream &fin, Pug &pug) {
        std::string nume, jucarie, activitate, mancare, culoare;
        int varsta, greutate;

        std::cout<<"Introdu nume, varsta, greutate, jucarie, culoare, mancare, activitate:"<<"\n";

        std::getline(fin, nume);
        fin>>varsta>>greutate;
        fin.get();

        std::getline(fin, jucarie);
        std::getline(fin, culoare);
        std::getline(fin, mancare);
        std::getline(fin, activitate);

        pug.setName(nume);
        pug.setAge(varsta);
        pug.setWeight(greutate);
        pug.set_favToy(jucarie);
        pug.set_color(culoare);
        pug.set_favMeal(mancare);
        pug.set_favActivity(activitate);
    }


    //CC + op =
    Pug(const Pug &pug) : dog(pug.getName(), pug.getAge(), pug.getWeight()), fav_toy(pug.get_favToy()),
                                        color(pug.get_color()), fav_meal(pug.get_favMeal()), fav_activity(pug.get_favActivity()) {}

    Pug& operator=(const Pug &rhs){
        if (this != &rhs) {
            dog::operator=(rhs);
            fav_toy = rhs.fav_toy;
            fav_meal = rhs.fav_meal;
            fav_activity = rhs.fav_activity;
            color = rhs.color;
        }
        return *this;
    }

};

class DogCare {
    static std::vector<std::shared_ptr<dog>> dogs;
    DogCare() = delete;

public:
    static const std::vector<std::shared_ptr<dog>> &GetDogs() {
        return dogs;
    }

    static void addDog (const std::shared_ptr<dog> &dogg) {
        dogs.push_back(dogg);
    }
    static void deleteDog (const int i_dog) {
        for (int i = i_dog; i < dogs.size(); i++){
            dogs[i] = dogs[i+1];
        }
        dogs.pop_back();
    }

    static const std::shared_ptr<dog> &get_ndog(int n){
        return dogs[n];
    }

    static void printAllDogs() {
        for (auto &it: dogs){
            std::cout<<it<<"\n";
        }
    }
    static void print_all_small_dogs() {
        for (auto &it: dogs) {
            if (it->get_size() != "small") continue;
            std::cout<<it<<"\n";
        }
    }
    static void print_all_medium_dogs() {
        for (auto &it: dogs) {
            if (it->get_size() != "medium") continue;
            std::cout<<it<<"\n";
        }
    }
    static void print_all_big_dogs() {
        for (auto &it: dogs) {
            if (it->get_size() != "big") continue;
            std::cout<<it<<"\n";
        }
    }



};

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
                catch (const InvalidWeight &e){
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
                catch (const InvalidWeight &e){
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
                catch (const InvalidWeight &e){
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
                catch (const InvalidWeight &e){
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
                catch (const InvalidWeight &e){
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

    }
    return 0;
}
