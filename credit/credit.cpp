#include <iostream>
#include <vector>


long long get_long();

std::vector<int> return_array(long long x);

bool isValid(std::vector<int> num);

std::string card_type(std::vector<int>);

int main(){

    long long card = get_long();

    std::vector<int> card_array = return_array(card);


    std::cout << card_type(card_array) << std::endl;

}

long long get_long(){
    long long n;
    
    std::cout << "Number: ";

    while (!(std::cin >> n)){
        std::cin.clear();

        std::cin.ignore(123,'\n');

        std::cout << "Number: ";
    }

    return n;
}

std::vector<int> return_array(long long x){

    std::vector<int> n = {};

    while (x > 0){
        
        n.push_back(x % 10);
        x /= 10;
    }

    return n;

}

bool isValid(std::vector<int> num){
    int normal_sum = 0, luhn_sum = 0;

    for (int i = 0; i < num.size(); i += 2){

        normal_sum += num.at(i);
    }

    for (int j = 1; j < num.size(); j += 2){

     int tmp = num.at(j) * 2;

        if (tmp > 9){
            luhn_sum += tmp % 10;
            luhn_sum += tmp / 10;
        }

        else{
            luhn_sum += tmp;
        }
    }

    return (normal_sum + luhn_sum) % 10 == 0;
}

std::string card_type(std::vector<int> num){
    int card_len = num.size();
    bool valid_card = isValid(num);
    std::string res = "";

    if (valid_card){

    if ((card_len == 13 || card_len == 16) && num.at(card_len - 1) == 4){
        res = "VISA";
    }
    else if ((card_len == 16) && (num[15]) == 5 && (num[14] == 1 || num[14] == 2 || num[14] == 3 || num[14] == 4|| num[14] == 5)){
        res = "MASTERCARD"; 
    }
    else if ((card_len == 15) && (num[14] == 3) && (num[13] == 4 || num[13] == 7)){
        res = "AMEX";

    }
        }

    if (!res.length()){
        res = "INVALID";
    }

    return res;


}