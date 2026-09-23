#include <iostream>
#include <memory>

int main() {
    // 1
    int a = 10;
    int *p {new int};

    *p = a;

    int *arr {new int[10]};

    // 2
    for (int i = 0; i < 10; i++){
        arr[i] = i;
    }
    std::cout << "Old array:" << std::endl;
    
    for (int i = 0; i < 10; i++){
        std::cout << arr[i] << std::endl;
    }
    
    delete p;
    p = nullptr;

    // 3
    int *dang_ptr {new int{10}};
    delete dang_ptr;

    // 4

    std::cout << *dang_ptr << std::endl;

    // 5
    int *new_arr {new int[11]};

    int index = 5;
    int val = 10;
    
    for (int i = 0; i < 11; i++){
        if (i < index){
            new_arr[i] = arr[i];
        } else if (i == index){
            new_arr[i] = val;
        } else  {
            new_arr[i] = arr[i-1];
        }
    }
    std::cout << "New array:" << std::endl;
    for (int i = 0; i < 11; i++){
        std::cout << new_arr[i] << std::endl;
    }
    // 6
    delete[] arr;
    arr = nullptr;
    delete[] new_arr;
    new_arr = nullptr;
    dang_ptr = nullptr;


    // умные указатели
    std::unique_ptr<int> ptr = std::make_unique<int>(10);
    std::cout << *ptr << std::endl;


}