#include <iostream>

char POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

std::string get_string(std::string= " ");

int compute_score(std::string);

int main(){
    std::string word1 = get_string("Player 1: ");
    std::string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        std::cout << "Player 1 wins" << std::endl;
    }
    else if (score1 < score2)
    {
        std::cout << "Player 2 wins" << std::endl;
    }
    else
    {
        std::cout << "Tie!" << std::endl;
    }
}

std::string get_string(std::string prompt){
    std::string input;

    std::cout << prompt;
    std::cin >> input;

    return input;
}

int compute_score(std::string word){
    int score = 0;

    for (int i = 0; i < word.length(); i++){
        int ascii = (int) word[i];

        if ((65 <= ascii && ascii <= 90) || (97 <= ascii && ascii <= 122)){
            score += POINTS[(ascii % 32) - 1];
        }
    }

    return score;
}