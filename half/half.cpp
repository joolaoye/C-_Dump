#include <iostream>
#include <iomanip>


float get_float(std::string s);

float compute_half(float a, float b, float c);

int main(){
    float bill = get_float("Bill before tax and tip: "), tax = get_float("Sale Tax Percent: "), tip = get_float("Tip percent: ");

    float ans = compute_half(bill, tax, tip);
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout <<"You will owe $" << ans << " each!"<< std::endl;

}

float get_float(std::string s){
    float n;

    std::cout << s;
    std::cin >> n;

    return n;
}

float compute_half(float a, float b, float c){
    float res = a;

    res += res * (b / 100);
    res += res * (c / 100);

    return res / 2;
}