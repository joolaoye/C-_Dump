#ifndef NEWCOMPLEX1_H
#define NEWCOMPLEX1_H

#include <iostream>

class Complex
{
private:
    // Data Members
    double x,y;

public:
    // Constructors
    Complex();
    Complex(double, double);

    // Setters
    void setReal(double);
    void setImaginary(double);

    // Getters
    double getReal() const;
    double getImaginary() const;

    // Arithmetic operators
    Complex operator+ (const Complex&) const;
    Complex operator- (const Complex&) const;
    Complex operator* (const Complex&) const;
    Complex operator/ (const Complex&) const;

    // Stream operators
    friend std::ostream& operator<< (std::ostream&, const Complex&);
    friend std::istream& operator>> (std::istream&, Complex&);

};

#endif // NEWCOMPLEX1_H