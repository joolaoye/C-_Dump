// Implementation file for the ComplexNumber class

#include <iostream> // Needed for string, cout and cin
#include <cmath> // Needed for round
#include "newComplex2.h" // Needed for the Complex class

/**
* Initializes the data members of a Complex number with default values
* @pre None
* @post The Complex number is created with default values for its attributes
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
* Sums two Complex numbers
* @pre Both Complex numbers should be valid and properly initialized
* @post The function returns a new Complex number which is the sum
* of the two Complex numbers
*/
Complex operator+ (const Complex& z1, const Complex& z2)
{
    double x = z1.getReal() + z2.getReal();
    double y = z1.getImaginary() + z2.getImaginary();

    Complex sum(x, y);

    return sum;
}

/**
* Subtracts two Complex numbers
* @pre Both Complex numbers should be valid and properly initialized
* @post The function returns a new Complex number which is the difference
* of the two Complex numbers
*/
Complex operator- (const Complex& z1, const Complex& z2)
{
    double x = z1.getReal() - z2.getReal();
    double y = z1.getImaginary() - z2.getImaginary();

    Complex difference(x, y);

    return difference;
}

/**
* Multiplies two Complex numbers
* @pre Both Complex numbers should be valid and properly initialized
* @post The function returns a new Complex number which is the product
* of the two Complex numbers
*/
Complex operator* (const Complex& z1, const Complex& z2)
{

    double x = (z1.getReal() * z2.getReal()) - (z1.getImaginary() * z2.getImaginary());
    double y = (z1.getReal() * z2.getImaginary()) + (z1.getImaginary() * z2.getReal());

    Complex product(x, y);

    return product;
}

/**
* Divides two Complex numbers
* @pre Both Complex numbers should be valid and properly initialized
* @post The function returns a new Complex number which is the quotient
* of the two Complex numbers
*/
Complex operator/ (const Complex& z1, const Complex& z2)
{
    double divisor = (z2.getReal() * z2.getReal()) + (z2.getImaginary() * z2.getImaginary());
    double x = ((z1.getReal() * z2.getReal()) + (z1.getImaginary() * z2.getImaginary())) / divisor;
    x = round(x * 100) / 100.0;
    double y = ((z1.getImaginary() * z2.getReal()) - (z1.getReal() * z2.getImaginary())) / divisor;
    y = round(y * 100) / 100.0;

    Complex quotient(x, y);

    return quotient;
}

/**
* Outputs the coordinates of a Complex number to the console,
* @pre Both the Complex number and the input stream should be valid and properly initialized
* @post The Complex number's real and imaginary coordinates 
* are displayed to the console
*/
std::ostream& operator<< (std::ostream& outputstream, const Complex& complexnumber)
{
    std::string sign = " + ";

    if (complexnumber.y < 0)
    {
        sign = " ";
    }

    outputstream << complexnumber.x  << sign << complexnumber.y << "i" << std::endl;
    return outputstream;
}   

/**
* Extracts the coordinates of a Complex number from the specified input stream,
* @pre Both the Complex number and the input stream should be valid and properly initialized
* @post The Complex number's coordinates are extracted from the specified input stream
*       and stored in the provided Complex number
*/
std::istream& operator>> (std::istream& inputstream, Complex& complexnumber)
{
    inputstream >> complexnumber.x >> complexnumber.y;
    return inputstream;
}  
