#include <iostream>

void quick_sort(int*, int, int);

void print_array(int* array, int size){
    std::cout << "{";

    for(auto i = 0; i < size; i++){
        std::cout << array[i] << " ,";
    }

    std::cout << "}" << std::endl; 

}

int main(){
    int a[6] = {8,7,6,3,4,5};

    print_array(a,6);

    quick_sort(a, 0, 5);

    print_array(a,6);

}

void quick_sort(int* array, int low, int high){
    if (high - low < 1){
        return;
    }

    int i = low - 1;
    int pivot = array[high];
    int temp;

    for (int j = low; j < high; j++){
        if (array[j] < pivot){
            i += 1;

            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }

    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    
    quick_sort(array, low, i);
    quick_sort(array, i + 2, high);
}