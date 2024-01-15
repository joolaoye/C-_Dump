#include <iostream>
#include <vector>


std::vector<int> select_sort(std::vector<int>);

int main(){
    std::vector<int> array = {4,5,7,3,8,0,2,1,6,100,-1,-100,13,9};

    array = select_sort(array);

    std::cout << "[";

    for (int i = 0; i < array.size() - 1; i++){
        std::cout << array[i] << " ,";
    }

    std::cout << array[array.size() - 1];
    std::cout << "]";
}

std::vector<int> select_sort(std::vector<int> nums){
    auto len = nums.size();

    for (int i = 0; i < len - 1; i++){
        auto index = i;
        for (int j = i + 1; j < len; j++){
            if (nums[j] < nums[index]){
                index = j;
            }
        }

        auto tmp = nums[i];
        nums[i] = nums[index];
        nums[index] = tmp;
    }

    return nums;
}