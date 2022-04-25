#include <iostream>
#include <string>
#include "dog.h"
#include "rasa.h"
#ifndef _beagle_h_
#define _beagle_h_

class Beagle : public dog {
    std::string fav_toy, color, fav_meal, fav_activity;
public:
    Beagle(std::string nume, int varsta, int greutate, std::string jucarie, std::string culoare, std::string mancare, std::string activitate); //c parametrizat
    Beagle(); //c neparametrizat

    //metodele virtuale pure supraincarcate
    Rasa getRasa() const override;
    std::string get_size() const override;
    std::string get_country() const override;

    //getters
    std::string get_favToy() const;
    std::string get_color() const;
    std::string get_favMeal() const;
    std::string get_favActivity() const;

    //setters
    void set_favToy(std::string jucarie);
    void set_color(std::string culoare);
    void set_favMeal(std::string mancare);
    void set_favActivity(std::string activitate);

    void print (std::ostream &fout) const override;
    friend std::ostream &operator<<(std::ostream &fout, const Beagle &beg){
        beg.print(fout);
        return fout;
    }
    friend std::istream &operator>>(std::istream &fin, Beagle &beg){
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

        return fin;
    }

    //cc + op=
    Beagle(const Beagle &bich);
    Beagle& operator=(const Beagle &rhs);
};


#endif