#include <iostream>
#include <string>
#include "dog.h"
#include "rasa.h"
#ifndef _golden_retriever_h_
#define _golden_retriever_h_

class Golden_Retriever : public dog {
    std::string fav_toy, color, fav_meal, fav_activity;
public:
    Golden_Retriever(std::string nume, int varsta, int greutate, std::string jucarie, std::string culoare, std::string mancare, std::string activitate); //c parametrizat
    Golden_Retriever(); //c neparametrizat

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
    friend std::ostream &operator<<(std::ostream &fout, const Golden_Retriever &gold){
        gold.print(fout);
        return fout;
    }
    friend std::istream &operator>>(std::istream &fin, Golden_Retriever &gold){
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

        return fin;
    }

    //cc + op=
    Golden_Retriever(const Golden_Retriever &gold);
    Golden_Retriever& operator=(const Golden_Retriever &rhs);
};


#endif