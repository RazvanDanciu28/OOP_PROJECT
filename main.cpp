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

    virtual ~dog() = default;
    virtual Rasa getRasa() = 0;

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
    virtual std::string get_favToy() const = 0;
    virtual std::string get_color() const = 0;
    virtual std::string get_favMeal() const = 0;
    virtual std::string get_favActivity() const = 0;


};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
