#include <iostream>
#include <algorithm>
#include <cmath>


#define print(x) std::cout << x << std::endl;

int len_of_int(int);

int karatsuba_mult(int, int);

int main(){
    int num1 = 12345;
    int num2 = 123;

    print(karatsuba_mult(num1, num2))
}

int len_of_int(int num){
    auto count = 0;

    while (num > 0){
        count++;
        num /= 10;
    }

    return count;
}


int karatsuba_mult(int x, int y){
    auto m = std::max(len_of_int(x), len_of_int(y));

    if (m < 2){
        return x * y;
    }

    auto n = m / 2;

    auto divisor = (int) pow(10, n);

    auto a = x / divisor;
    auto b = x % divisor;

    auto c = y / divisor;
    auto d = y % divisor;

    auto ac = karatsuba_mult(a,c);
    auto bd = karatsuba_mult(b,d);
    auto ad_bc = karatsuba_mult((a + b), (c + d)) - ac - bd;



    return (pow(10, 2 * n) * ac) + (pow(10, n) * ad_bc) + bd;
    

}