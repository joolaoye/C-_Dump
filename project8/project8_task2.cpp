/*
Complex Number

Name: Joshua O Olaoye
starID: fg2784fh
Section Number: 03

Description:
This program enables users to perform various arithmetic operations with complex numbers.
Users are prompted to enter two complex numbers, and the program computes and displays
the sum, difference, product, and quotient of these numbers
*/

#include <iostream> // Needed for cin and cout
#include "newComplex1.h" // Needed for the Complex class

// Function Declarations
void getTwoComplexNums(Complex&, Complex&);
void arithmeticComputation(const Complex&, const Complex&, Complex&, 
Complex&, Complex&, Complex&);
void printResults(const Complex&, const Complex&, const Complex&, 
const Complex&);

int main()
{
    // Gets two complex numbers from the user
    Complex c1;
    Complex c2;
    getTwoComplexNums(c1, c2);

    // Variables to store result of arithmetic operations between Complex numbers
    Complex sumComplexNumbers;
    Complex differenceComplexNumbers;
    Complex productComplexNumbers;
    Complex quotientComplexNumbers;

    // Performs arithmetic operations on the user inputted Complex numbers
    arithmeticComputation(c1, c2, sumComplexNumbers, differenceComplexNumbers, productComplexNumbers, quotientComplexNumbers);

    // Displays the results of the arithmetic operations to the user
    printResults(sumComplexNumbers, differenceComplexNumbers, productComplexNumbers, quotientComplexNumbers);
}

/** 
* Prompts the user to enter values for two Complex numbers
* @pre Two valid references to Complex objects
* @post The Complex objects are updated with user-input values
*/
void getTwoComplexNums(Complex& z1, Complex& z2)
{
    std::cout << "Enter the first complex as real_part imaginary_part" << std::endl;
    std::cin >> z1;

    std::cout << "Enter the second complex as real_part imaginary_part" << std::endl;
    std::cin >> z2;

    std::cout << std::endl;
    
}

/** 
* Performs addition, subtraction, multiplication and division
* on two Complex numbers
* @pre Two valid references to Complex objects to be operated.
*      Valid references for the sum, difference, product, and quotient 
*      of the arithmetic operations 
* @post The Complex objects representing the sum, difference, product, and quotient 
*       of the input complex numbers are updated accordingly
*/
void arithmeticComputation(const Complex& z1, const Complex& z2, 
    Complex& sum, Complex& difference, Complex& product, Complex& quotient)    
{
    sum = z1 + z2;
    difference = z1 - z2;
    product = z1 * z2;
    quotient = z1 / z2; 
}

/** 
* Displays the sum, difference, product, and quotient of two Complex numbers
* @pre Valid references for the sum, difference, product, and quotient of the operations
* @post The Complex objects are updated with user-input values
*/
void printResults(const Complex& sum, const Complex& difference, 
const Complex& product, const Complex& quoteient)
{
    std::cout << "c1 + c2 = " << sum;

    std::cout << "c1 - c2 = " << difference;

    std::cout << "c1 * c2 = " << product;

    std::cout << "c1 / c2 = " << quoteient;

}
