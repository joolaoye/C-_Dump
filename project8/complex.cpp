// Implementation file for the Complex class

#include <iostream> // Needed for string, cout and cin
#include <cmath> // Needed for round
#include "complex.h" // Needed for the Complex class

/**
* Initializes the data members of an Employee object with default values
* @pre None
* @post The Employee object is created with default values for its attributes
*/
Complex::Complex()
{
    this->x = 0;
    this->y = 0;
}

/**
* Initializes the data members of an Complex number with the provided input parameters
* @pre Valid input parameters for the real, and imaginary coordinates
* @post The Complex number is created with the provided input parameters for its attributes
*/
Complex::Complex(double x, double y)
{
    this->x = x;
    this->y = y;
}

/**
* Updates the real coordinate of the Complex number with the provided input parameter
* @pre A valid non-empty input parameter for the real coordinate
* @post The Complex number's real coordinate is updated with the provided input parameter
*/
void Complex::setReal(double x)
{
    this->x = x;
}

/**
* Updates the imaginary coordinate of the Complex number with the provided input parameter
* @pre A valid non-empty input parameter for the imaginary coordinate
* @post The Complex number's imaginary coordinate is updated with the provided input parameter
*/
void Complex::setImaginary(double y)
{
    this->y = y;
}

/**
* Returns the real coordinate of the Complex number
* @pre None
* @post Returns the real coordinate of the Complex number
*/
double Complex::getReal() const
{
    return this->x;
}

/**
* Returns the imaginary coordinate of the Complex number
* @pre None
* @post Returns the imaginary coordinate of the Complex number
*/
double Complex::getImaginary() const
{
    return this->y;
}

/**
* Outputs the coordinates of a Complex number to the console,
* @pre None
* @post The Complex number's real and imaginary coordinates 
* are displayed to the console
*/
void Complex::displayComplexNumber() const
{
    std::string sign = " + ";

    if (this->y < 0)
    {
        sign = " ";
    }

    std::cout << this->x  << sign << this->y << "i" << std::endl;
}

/**
* Sums two Complex numbers
* @pre Both Complex numbers should be valid and properly initialized
* @post The function returns a new Complex number which is the sum
* of the two Complex numbers
*/
Complex Complex::add (const Complex& complexnumber) const
{
    Complex sum;

    sum.x = this->x + complexnumber.x;
    sum.y = this->y + complexnumber.y;

    return sum;
}

/**
* Subtracts two Complex numbers
* @pre Both Complex numbers should be valid and properly initialized
* @post The function returns a new Complex number which is the difference
* of the two Complex numbers
*/
Complex Complex::subtract (const Complex& complexnumber) const
{
    Complex difference;

    difference.x = this->x - complexnumber.x;
    difference.y = this->y - complexnumber.y;

    return difference;
}

/**
* Multiplies two Complex numbers
* @pre Both Complex numbers should be valid and properly initialized
* @post The function returns a new Complex number which is the product
* of the two Complex numbers
*/
Complex Complex::multiply (const Complex& complexnumber) const
{
    Complex product;

    product.x = (this->x * complexnumber.x) - (this->y * complexnumber.y);
    product.y = (this->x * complexnumber.y) + (this->y * complexnumber.x);

    return product;
}

/**
* Divides two Complex numbers
* @pre Both Complex numbers should be valid and properly initialized
* @post The function returns a new Complex number which is the quotient
* of the two Complex numbers
*/
Complex Complex::divide (const Complex& complexnumber) const
{
    Complex quotient;

    double divisor = (complexnumber.x * complexnumber.x) + (complexnumber.y * complexnumber.y);
    quotient.x = ((this->x * complexnumber.x) + (this->y * complexnumber.y)) / divisor;
    quotient.x = round(quotient.x * 100) / 100.0;
    quotient.y = ((this->y * complexnumber.x) - (this->x * complexnumber.y)) / divisor;
    quotient.y = round(quotient.y * 100) / 100.0;

    return quotient;
}
