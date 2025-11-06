#include <iostream>

int get(int nums[], int index) {
    return *(nums + index);
}

int main(void) {
    int nums[] = {1, 2, 3, 4, 5};

    std::cout << get(nums, 2) << "\n";
    
    return 0;
}