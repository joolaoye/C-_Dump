#include <iostream>
#include <vector>

int addition(std::string a, std::string b);

int main(){
    std::string s = "1101";
    std::string t = "1011";

    std::cout << addition(s,t) << std::endl;

}

int addition(std::string a, std::string b){
    std::vector<int> res;

    int n = a.length();
    int m = b.length();

    for (int i = 0; i < n;i++){
        int partial_prod = 0;
        for(int j = 0; j < m; j++){
            int tmp = ((int)a[i] % 2) * ((int)b[j] % 2);
            partial_prod = (partial_prod << 1) + tmp;

        }
        partial_prod <<= i;


        res.push_back(partial_prod);


    }

    return res.at(0);
}