#include <iostream>

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