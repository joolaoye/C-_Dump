/*
Text Analyzer

Name: Joshua O Olaoye
starID: fg2784fh
Section Number: 03

Description:
This program enables user to count the number of words,
lines, characters and sentences in a file

* The program prompts the user for an input file
* The program then opens the input file
* The program calls a function that calculates the number of words, lines, characters and sentences in a file
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
    int wordCount = 0;
    int lineCount = 0;
    int charCount = 0;
    int sentenceCount = 0;
    
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

    // Count number of words, lines, characters and sentences in a file
    characterCount(fin, wordCount, lineCount, charCount, sentenceCount);

    // Display the counts accordingly
    std::cout << "Word Count: " << wordCount << std::endl;
    std::cout << "Line Count: " << lineCount << std::endl;
    std::cout << "Character Count: " << charCount << std::endl;
    std::cout << "Sentence Count: " << sentenceCount << std::endl;
}

/** 
* Computes the number of words, lines, characters, and sentences in the input file
* @pre Valid references to the input file object and variables to keep track
*      - of the number of words, lines, characters, and sentences in the input file
* @post The variables to keep track of the number of words, lines, characters, and sentences are updated
*/
void characterCount(std::ifstream& fsIn, int& countWord, int& countLine, 
int& countCharacter, int& countSentence)
{
    char aChar;
    bool inWord = false;

    while (fsIn.get(aChar))
    {
        if (!countLine)
        {
            countLine++;
        }
        
        countCharacter++;

        if (isspace(aChar))
        {
            inWord = false;
        }

        else if (!inWord)
        {
            countWord++;
            inWord = true;
        }

        if (ispunct(aChar))
        {
            countSentence++;
        }

        if (aChar == '\n')
        {
            countLine++;
        }
    }
}
