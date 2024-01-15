#ifndef NEWCOMPLEX2_H
#define NEWCOMPLEX2_H

#include <iostream>

class Complex
{
private:
    // Data members
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

    // Stream operators
    friend std::ostream& operator<< (std::ostream&, const Complex&);
    friend std::istream& operator>> (std::istream&, Complex&);

};

// Arithmetic operators
Complex operator+ (const Complex&, const Complex&);
Complex operator- (const Complex&, const Complex&);
Complex operator* (const Complex&, const Complex&);
Complex operator/ (const Complex&, const Complex&);

#endif // NEWCOMPLEX2_H