#include <iostream>

using namespace std;

int get_int(int = 0, string ="");

int calculate_int_year(int x, int y);

int count = 0;

int main()
{
    int a = get_int(0,"Start Size: "), b = get_int(a,"End Size: "), c = calculate_int_year(a,b);

    cout << c << endl;
}

int get_int(int i, string s){
    int n;
    count++;

    do{
    cout << s;
    cin >> n;
        
    }
    while (n < 9 || n < i);

    return n;
}

int calculate_int_year(int x, int y){
    int year = 0;

    while (x < y){
        int n = x;
        year++;
        x +=(n / 3);
        x -= (n/4);

    }

    return year;
}