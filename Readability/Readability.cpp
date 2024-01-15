#include <iostream>
#include <tuple>
#include <cmath>
#include <string>


std::string get_string(std::string=": ");

std::tuple<int,int,int> count(std::string);

int main(){

    std::string word = get_string("Text: ");

    auto [letters, words, sentences] = count(word);

    auto L = (letters / (float) words) * 100, S = (sentences / (float) words) * 100;

    int index = std::round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1){

    std::cout << "Before Grade 1" << std::endl;
    }

    else if (index > 15){
        std::cout << "Grade 16+" << std::endl;
    }

    else{
        std::cout << "Grade " << index << std::endl;
    }

}

std::string get_string(std::string prompt){
    std::string input;

    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

std::tuple<int,int,int> count(std::string s){
    auto letters = 0;
    auto words = 1;
    auto sentences = 0;

    auto start = s.find_first_not_of(" \t\n");
    auto end = s.find_last_not_of(" \t\n");

    for(int i = start; i <= end;i++){
        auto ascii = (int) s[i];

        if ((ascii <= 90 && ascii >= 65) || (ascii <= 122 && ascii >= 97)){
            letters += 1;
        }

        else if ((ascii == 32)){
            words += 1;
        }

        else if ((ascii == 33) || (ascii == 46) || (ascii == 63)){
            sentences += 1;
        }
    }


    return std::make_tuple(letters,words,sentences);
}