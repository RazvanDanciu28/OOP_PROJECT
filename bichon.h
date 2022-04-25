#include <iostream>
#include <string>
#include "dog.h"
#include "rasa.h"
#ifndef _bichon_h_
#define _bichon_h_

class Bichon : public dog {
    std::string fav_toy, color, fav_meal, fav_activity;
public:
    Bichon(std::string nume, int varsta, int greutate, std::string jucarie, std::string culoare, std::string mancare, std::string activitate); //c parametrizat
    Bichon(); //c neparametrizat

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
    friend std::ostream &operator<<(std::ostream &fout, const Bichon &bich){
        bich.print(fout);
        return fout;
    }
    friend std::istream &operator>>(std::istream &fin, Bichon &bich){
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

        return fin;
    }

    //cc + op=
    Bichon(const Bichon &bich);
    Bichon& operator=(const Bichon &rhs);
};


#endif