#include <iostream>
#include <memory>
#include <array>
#include <random>
#include <vector>
#include <list>
#include <deque>
#include "add.h"
#include <fstream>

using T1 = int;
using T2 = double;


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

    // контейнеры 

    const int M = 10;
    const int N = 200;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-N,N);



    std::array<T1, M> arr1;
    std::vector<T1> vec(M);
    std::list<T1> list;
    std::deque<T1> deq(M);

    for (int i = 0; i < M; i++) {
        arr1[i] = dist(gen);
    }
    for (int i = 0; i < M; i++) {
        vec[i] = dist(gen);
    }
    for (int i = 0; i < M; i++) {
        list.push_back(dist(gen));
    }
    for (int i = 0; i < M; i++) {
        deq[i] = dist(gen);
    }

    int C = dist(gen);

    std::vector<T2> resArr;
    std::list<T2> resVec;
    std::deque<T2> resList;
    std::array<T2, M> resDeq;

    
    for (int i = 0; i < M; i++) {
        resArr.push_back(extended::Add<T1, T2>(arr1[i], C));
    }

    
    for (std::vector<T1>::iterator it = vec.begin(); it != vec.end(); it++) {
        resVec.push_back(extended::Add<T1, T2>(*it, C));
    }


    for (T1 x : list) {
        resList.push_back(extended::Add<T1, T2>(x, C));
    }

    for (int i = 0; i < M; i++) {
        resDeq[i] = extended::Add<T1, T2>(deq[i], C);
    }

    std::vector<std::string> rows;
    std::list<T1>::iterator itList = list.begin();
    std::list<T2>::iterator itResVec = resVec.begin();
    for (int i = 0; i < M; i++, itList++, itResVec++) {
        std::string stroka = "| " + std::to_string(i);
        stroka += " | " + std::to_string(arr1[i]);
        stroka += " | " + std::to_string(vec[i]);
        stroka += " | " + std::to_string(*itList);
        stroka += " | " + std::to_string(deq[i]);
        stroka += " | " + std::to_string(resArr[i]);
        stroka += " | " + std::to_string(*itResVec);
        stroka += " | " + std::to_string(resList[i]);
        stroka += " | " + std::to_string(resDeq[i]);
        stroka += " |";
        rows.push_back(stroka);
    }

    std::ofstream fout("table.md");
    fout << "| # | Array | Vector | List | Deque | Array->Vec | Vec->List | List->Deque | Deque->Array |\n";
    fout << "|---|-------|--------|------|-------|------------|-----------|-------------|--------------|\n";
    for (std::vector<std::string>::iterator it = rows.begin(); it != rows.end(); it++) {
        fout << *it << "\n";
    }
    fout.close();



    return 0;
}