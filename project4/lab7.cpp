#include <iostream>
#include <iomanip>


void getscores(int* array);
double calcAverage(int* array);
double findLowest(int* array);
void displayResult(int average);

// Constant Declaration
const int SIZE = 10;

int main(){
    int scores[SIZE];

    getscores(scores);

    int avg = calcAverage(scores);

    std::cout << std::fixed << std::setprecision(2);

    displayResult(avg);

    std::cout << "Thanks for using our system." << std::endl;
}

void getscores(int* array){
    int num;

    std::cout << "Enter 10 test scores between 0 and 100." << std::endl;

    for (int i = 1; i <= SIZE; i++){
        std::cout << "Score #" << i << ": ";
        std::cin >> num;

        while (num < 0){
            std::cout << "Score must be in the range 0 - 100. Please re-enter score." << std::endl;
            std::cout << "Score #" << i << ": ";
            std::cin >> num;
        }

        array[i - 1] = num;
    }

    return;
}

double calcAverage(int* array){
    int lowest = findLowest(array);
    int running_sum = 0;

    for (int i = 0; i < SIZE; i++){
        running_sum += array[i];
    }

    return static_cast<double>(running_sum - lowest) / (SIZE - 1);
}

double findLowest(int* array){
    int min = array[0];

    for (int i = 1; i < SIZE; i++){
        min = (array[i] < min) ? array[i] : min;
    }

    return min;
}

void displayResult(int average){
    std::cout << "After dropping the lowest test score, the test average is " << average << std::endl;
}