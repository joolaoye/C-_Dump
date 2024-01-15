#include <iostream>
#include <vector>

std::vector<int> bubblesort(std::vector<int>);


int main(){
    std::vector<int> array = {4,5,7,3,8,0,2,1,6,100,-1,-100,13,9};

    array = bubblesort(array);

    std::cout << "[";

    for (int i = 0; i < array.size() - 1; i++){
        std::cout << array[i] << " ,";
    }

    std::cout << array[array.size() - 1];
    std::cout << "]";
}

std::vector<int> bubblesort(std::vector<int> nums){
    auto len = nums.size() - 1;

    for(int i = 0; i < len; i++){

        for (int j = 0; j < len - i; j++){

            if (nums[j] > nums[j + 1]){
                auto tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
            }
        }

    }

    return nums;
}