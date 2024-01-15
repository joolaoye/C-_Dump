#include <iostream>
#include <vector>
#include <cctype>
#include <iomanip>

int get_int(std::string=": ");

char get_char(std::string=": ");

float calc_hours(std::vector<int>, int, char);

int main(){

    int weeks = get_int("Number of weeks taking CS50: ");
    std::vector<int> hours;
    char output;

    for (int i = 0; i < weeks; i++){
       int tmp = get_int("Week " + std::to_string(i) + " HW Hours: ");
       hours.push_back(tmp);
    }

    do{
        output = std::toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (!((output == 'A') || (output == 'T')));

    std::cout << std::fixed << std::setprecision(2);
    std::cout << calc_hours(hours,weeks,output);
    

}

float calc_hours(std::vector<int> hours, int weeks, char output){
    float res = 0;

    for (int i = 0; i < weeks;i++){
        res += hours[i];
    }

    switch(output){
        case 'A':
            return res / weeks;

        case 'T':
            return res;
    }

    return res;

}

int get_int(std::string s){
    int n;

    std::cout << s;

    while (!(std::cin >> n)){
        std::cin.clear();
        std::cin.ignore(std::streamsize("streamsize"), '\n');
        std::cout << s;
    }

    return n;
}

char get_char(std::string s){
    char n;

    std::cout << s;

    while (!(std::cin >> n)){
        std::cin.clear();
        std::cin.ignore(std::streamsize("streamsize"), '\n');
        std::cout << s;
    }

    return n;
}