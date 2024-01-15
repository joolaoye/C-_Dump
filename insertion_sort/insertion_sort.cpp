#include <iostream>
#include <vector>

std::vector<int> insertion_sort(std::vector<int>);

int main(){
    std::vector<int> nums = {3,1,8,2,4,5,0,6,7};

    nums = insertion_sort(nums);

    std::cout << '['; 

    for (int i = 0; i < nums.size();i++){
        std::cout << nums[i] << " ,";
    }
    std::cout << ']' << std::endl;
}

std::vector<int> insertion_sort(std::vector<int> nums){
    for (int i = 1; i < nums.size();i++){
        int current = nums[i];

        int j = i - 1;

        while (j >= 0 && nums[j] > current){
            nums[j + 1] = nums[j];
            j -= 1;
        }

        nums[j + 1] = current;
    }

    return nums;
}