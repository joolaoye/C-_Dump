#include <iostream>

std::string rotate(std::string s, int key){
    for (int i = 0; i < s.length(); i++){
        if (s[i] >= 97 && s[i] <= 122){

        s[i] = (((s[i] % 97) + key) % 26) + 97;
        }

        else if (s[i] >= 65 && s[i] <= 90){
        s[i] = (((s[i] % 65) + key) % 26) + 65;
        }
    }

    return s;
}