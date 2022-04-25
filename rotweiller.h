#include <iostream>
#include <string>
#include "dog.h"
#include "rasa.h"
#ifndef _rotweiller_h_
#define _rotweiller_h_

class Rotweiller : public dog {
    std::string fav_toy, color, fav_meal, fav_activity;
public:
    Rotweiller(std::string nume, int varsta, int greutate, std::string jucarie, std::string culoare, std::string mancare, std::string activitate); //c parametrizat
    Rotweiller(); //c neparametrizat

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
    friend std::ostream &operator<<(std::ostream &fout, const Rotweiller &rot){
        rot.print(fout);
        return fout;
    }
    friend std::istream &operator>>(std::istream &fin, Rotweiller &rot){
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

        return fin;
    }

    //cc + op=
    Rotweiller(const Rotweiller &rot);
    Rotweiller& operator=(const Rotweiller &rhs);
};


#endif