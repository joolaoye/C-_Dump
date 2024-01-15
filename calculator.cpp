#include <iostream>
#include <cmath> // For the power function

int get_int(std::string prompt); // Function gets integer 
char get_char(std::string prompt); // Function gets operator

int main(){
    // Todo
}

int get_int(std::string prompt){
        int input;

        std::cout << prompt;

        while (!(std::cin >> input)){
                std::cin.clear();
                std::cin.ignore(std::streamsize("streamsize"), '\n');
                std::cout << prompt;
        }
        return input;
}


char get_char(std::string prompt){
        char input;
        std::string valid_operators = "+-/%^*";

        std::cout << prompt;

        while (!(std::cin >> input) || valid_operators.find(input) == -1 ){
                std::cin.clear();
                std::cin.ignore(std::streamsize("streamsize"), '\n');
                std::cout << prompt;
        }

        return input;
}