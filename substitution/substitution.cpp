#include <iostream>

int len(char*);

bool isvalid(char*);

std::string get_string(std::string="Enter: ");

std::string rotate(std::string,char*);


int main(int argc, char* argv[]){
    if (argc != 2){
        std::cout << "Usage: ./substitution key" << std::endl;
        return 1;
    }

    else if (len(argv[1]) != 26){
        std::cout << "Key must contain 26 characters." << std::endl;
        return 1;
    }

    else if (isvalid(argv[1]) == 0){
        std::cout << "Key must be alphabetic." << std::endl;
        return 1;
    }

    std::string plaintext = get_string("Plaintext: ");
    std::string ciphertext = rotate(plaintext, argv[1]);

    std::cout << ciphertext << std::endl;
}

int len(char* s){
    auto count = 0;

    for (char *p = s; *p != '\0'; ++p){
        count += 1;
    }

    return count;
}

bool isvalid(char* s){
    for (int i = 0; i < len(s); i++){
        if ((*(s + i) > 90 || *(s + i) < 65) && (*(s + i) > 122 || *(s + i) < 97)){
            return false;
        }
    }

    return true;

}

std::string get_string(std::string prompt){
    std::string input;

    std::cout << prompt;
    std::getline(std::cin, input);

    return input;
}

std::string rotate(std::string text,char* map){
    for (int i = 0; i < text.length(); i++){
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122)){

        auto mapping = *(((text[i] % 32) - 1) + map) % 32;
        mapping = ((mapping - 1) - ((text[i] % 32) - 1)) % 26;
        text[i] += mapping;
        }
    }

    return text;
}