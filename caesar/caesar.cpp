#include <iostream>


bool is_a_digit(char*);

int size_of_array(char*);

std::string get_string(std::string="Enter: ");

std::string rotate(std::string, int key);

int main(int argc, char* argv[]){
    if ((argc != 2) || is_a_digit(argv[1]) == 0){
        std::cout << "Usage: ./caesar key\n";
        return 1;
    }

    int key = 0;

    int len = size_of_array(argv[1]);

    for (int i = 0; i < len; i++){
            key = (10 * key) + (argv[1][i] % 48);
        }

    std::string plaintext = get_string("Plaintext:  ");

    std::string ciphertext = rotate(plaintext, key);

    std::cout << "Ciphertext: " << ciphertext << std::endl;
    

}

int size_of_array(char* s){
    int count = 0;
    for (char *p = s; *p != '\0'; ++p){
        count += 1;
    }

    return count;

}

bool is_a_digit(char* s){
    auto len = size_of_array(s);

    for (int i = 0; i < len; i++){
        if ((*(s + i) < 48 )||(*(s + i) > 57)){
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