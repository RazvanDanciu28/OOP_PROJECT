#include <iostream>
#include <string>
#include "rasa.h"
#ifndef _dog_h_
#define _dog_h_

class dog {
    std::string name;
    int age, weight;
public:
    dog(std::string nume_caine, int varsta, int greutate); //constructor parametrizat
    dog(); //constructor neparametrizat

    virtual ~dog() = default;
    virtual Rasa getRasa() const = 0;

    //getters
    std::string getName() const;
    int getAge() const;
    int getWeight() const;

    //setters
    void setName(std::string nume_nou);
    void setAge(int new_age);
    void setWeight(int new_weight);

    //metode virtuale pure
    virtual std::string get_size() const = 0;
    virtual std::string get_country() const = 0;

    virtual void print(std::ostream &fout) const;
};

std::ostream& operator<<(std::ostream &fout, const dog *dogg){
    dogg->print(fout);
    return fout;
}

#endif