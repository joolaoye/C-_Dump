/*
Password Validator

Name: Joshua O Olaoye
starID: fg2784fh
Section Number: 03

Description:
* This program validates a user entered password based on specific criteria.
* The validation process includes checking if the password:
* - Is at least six characters long
* - Contains at least one uppercase letter
* - Contains at least one lowercase letter
* - Contains at least one digit
*/

#include <iostream> // Needed for cin and cout
#include <cctype> // Needed for useful string functions like isalpha()

const int MAXLEN = 128; // Maximum length of a password

// Function Declaration
bool verifyPassword(char[]);

int main()
{
    char userPassword[MAXLEN]; // Buffer to store user's password

    // Continuously prompt the user until a valid password is entered
    while (true)
    {
        // Prompts user for their password
        std::cout << "Enter your password: ";
        std::cin >> userPassword;

        // Check if the entered password is valid; break out of the loop if true
        if (verifyPassword(userPassword))
        {
            break;
        }

        // // Display password requirements to the user
        std::cout << "The password should be at least six characters long" << std::endl;
        std::cout << "and should contain at least an uppercase character, lowercase character and a digit." << std::endl;
    }

    // Inform the user their password is valid
    std::cout << "Password is Valid" << std::endl;
}

/** 
* Verifies if a password has at least six characters, an uppercase character, lowercase character, and a digit
* @pre A valid pointer to C-style string representing the password 
* @post Returns true if the password is valid according to the specified criteria, else false
*/
bool verifyPassword(char password[])
{
    int charCount = 0;
    bool upperCase = false;
    bool lowerCase = false;
    bool digit = false;

    while (password[charCount] != '\0')
    {
        if (isupper(password[charCount]))
        {
            upperCase = true;
        }

        else if (islower(password[charCount]))
        {
            lowerCase = true;
        }

        else if (isdigit(password[charCount]))
        {
            digit = true;
        }

        charCount++;
    }

    return charCount >= 6 && upperCase && lowerCase && digit;
}
