#include <iostream>
#include <math.h>

int convert(char* input);

std::string get_string(std::string="Enter: ");

int len(char* s);

int main(){
    std::string tmp = get_string("Enter a positive integer: ");
    char* input = &tmp[0];

    for (int i = 0; i < len(input); i++){
        if (*(input + i) < 48 || *(input + i) > 57){
            std::cout << "Invalid Input!" << std::endl;
            return 1;
        }
    }

    std::cout << convert(input) << std::endl;
}

std::string get_string(std::string prompt){
    std::string val;

    std::cout << prompt;
    std::getline(std::cin, val);


    return val;
}

int len(char* s){
    auto count = 0;
    for (char *p = s; *p != '\0'; ++p){
        count += 1;
    }

    return count;
}


int convert(char* input){
    if (len(input) == 0){
        return (*(input) % 48);
    }

    auto power = len(input) - 1;


    return (pow(10.0, power) * (*(input) % 48)) + convert((input + 1));
}