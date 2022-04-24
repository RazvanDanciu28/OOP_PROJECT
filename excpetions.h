#include <exception>
#ifndef _exceptions_h_
#define _exceptions_h_

class InvalidAge : public std::exception {
public:
    InvalidAge();
    const char *what() const noexcept override;
};

class InvalidWeight : public std::exception {
public:
    InvalidWeight();
    const char *what() const noexcept override;
};

class ambele : public std::exception {
public:
    ambele();
    const char *what() const noexcept override;
};

#endif