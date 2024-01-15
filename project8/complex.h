#ifndef COMPLEX_H
#define COMPLEX_H

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

    // Display function
    void displayComplexNumber() const;

    // Arithmetic operators
    Complex add (const Complex&) const;
    Complex subtract (const Complex&) const;
    Complex multiply(const Complex&) const;
    Complex divide (const Complex&) const;

};

#endif // COMPLEX_H