/*
Text Analyzer

Name: Joshua O Olaoye
starID: fg2784fh
Section Number: 03

Description:
This program enables user to count the number of alphabetic characters,
digits, punctuations and whitespaces in a file

* The program prompts the user for an input file
* The program then opens the input file
* The program calls a function that computes the number of alphabetic characters, digits, punctuation marks, and whitespaces
* The program displays the obtained counts, providing a clear breakdown of the textual composition of the file
*/

#include <iostream> // Needed for cin and cout 
#include <fstream> // Needed for using files
#include <cctype> // Needed for useful string functions like isalpha()

// Function Declaration
void characterCount(std::ifstream&, int&, int&, int&, int&);

int main()
{
    // Variable Declarations
    std::string fileName;
    int alphaCount = 0;
    int digitCount = 0;
    int punctuationCount = 0;
    int whitespaceCount = 0;

    // Prompt user to enter the file name   
    std::cout << "Enter the name of the file: ";
    std::cin >> fileName;

    // Open the file 
    std::ifstream fin(fileName.c_str());

    // Check if file exists 
    if (!fin.is_open())
    {
        std::cout << "File does not exist" << std::endl;
        return 1;
    }

    // Count the number of alphabets, digits, punctuations and whitespaces in the file
    characterCount(fin, alphaCount, digitCount, punctuationCount, whitespaceCount);

    // Close the file
    fin.close();

    // Display the counts accordingly
    std::cout << "Alphabet Count: " << alphaCount << std::endl;
    std::cout << "Digits Count: " << digitCount << std::endl;
    std::cout << "Punctuation Count: " << punctuationCount << std::endl;
    std::cout << "Whitespace Count: " << whitespaceCount << std::endl;
}

/** 
* Computes the number of alphabetic characters, digits, punctuations, and whitespaces in the input file
* @pre Valid references to the input file object and variables to keep track
*      - of the number of alphabetic characters, digits, punctuations, and whitespaces in the input file
* @post The variables to keep track of the number of alphabetic characters, digits, punctuations, and whitespaces are updated
*/
void characterCount(std::ifstream& fsIn, int& countAlpha, int& countDigits, 
int& countPunctuation, int& countWhitespace)
{
    char aChar;

    while (fsIn.get(aChar))
    {
        if (isalpha(aChar))
        {
            countAlpha++;
        }

        else if (isdigit(aChar))
        {
            countDigits++;
        }

        else if (ispunct(aChar))
        {
           countPunctuation++;
        }   

        else if (isspace(aChar))
        {
            countWhitespace++;
        }
    }
}
