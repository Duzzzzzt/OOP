#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>

int binary_op(int acc, int el) {
    return (el % 2 == 0) ? acc + el : acc - el;
}


int main() {
    //1
    std::ifstream fin1;
    fin1.open("s04_v1_42_1.txt");
    std::vector<int> first;
    int x;
    std::string line;
    while (fin1 >> x) {

        first.push_back(x);
        fin1.ignore();

    }
    fin1.close();

    std::ifstream fin2;
    fin2.open("s04_v1_42_2.txt");
    std::vector<int> second;
    while (fin2 >> x) {
        second.push_back(x);
        fin2.ignore();
    }
    fin2.close();

    //2
    std::cout << "first vector: "<< first.size() << " numbers\n";
    std::cout << "second vector: " << second.size() << " numbers\n";

    //3 a
    std::vector<int> vis1;
    std::vector<std::pair<int, int>> freq_vec1;

    for (int el : first) {
        int flag = 1;
        for (int i = 0; i < (int)vis1.size(); i++) {
            if (vis1[i] == el) {
                flag = 0;
            }
        }
        if (flag) {
            int cnt = 0;
            for (int i = 0; i < (int)first.size(); i++) {
                if (first[i] == el) {
                    cnt++;
                }
            }
            std::pair<int, int> p = { el,cnt };
            vis1.push_back(el);
            freq_vec1.push_back(p);
        }
        
        
    
    }



    std::vector<int> vis2;
    std::vector<std::pair<int, int>> freq_vec2;

    for (int el : second) {
        int flag = 1;
        for (int i = 0; i < (int)vis2.size(); i++) {
            if (vis2[i] == el) {
                flag = 0;
            }
        }
        if (flag) {
            int cnt = 0;
            for (int i = 0; i < (int)second.size(); i++) {
                if (second[i] == el) {
                    cnt++;
                }
            }
            std::pair<int, int> p = { el,cnt };
            vis2.push_back(el);
            freq_vec2.push_back(p);
        }



    }
    std::cout << "frequencies of 1st vector: " << std::endl;
    for (int i = 0; i < (int)freq_vec1.size(); i++) {
        
        std::cout << freq_vec1[i].first << " - " << freq_vec1[i].second << std::endl;
    }
    std::cout << "frequencies of 2nd vector: " << std::endl;
    for (int i = 0; i < (int)freq_vec2.size(); i++) {
       
        std::cout << freq_vec2[i].first << " - " << freq_vec2[i].second << std::endl;
    }


    //3 b
    std::vector<int> vis1b;
    std::vector<std::pair<int, int>> freq_vec1b;

    for (int el : first) {
        int flag = 1;
        for (int i = 0; i < (int)vis1b.size(); i++) {
            if (vis1b[i] == el) {
                flag = 0;
            }
        }
        if (flag) {
            
            std::pair<int, int> p = { el,std::count(first.begin(), first.end(), el) };
            vis1b.push_back(el);
            freq_vec1b.push_back(p);
        }
        
        
    
    }
    std::cout << "frequencies of 1st vector with algorithm: " << std::endl;
    for (int i = 0; i < (int)freq_vec1b.size(); i++) {
       
        std::cout << freq_vec1b[i].first << " - " << freq_vec1b[i].second << std::endl;
    }


    std::vector<int> vis2b;
    std::vector<std::pair<int, int>> freq_vec2b;

    for (int el : second) {
        int flag = 1;
        for (int i = 0; i < (int)vis2b.size(); i++) {
            if (vis2b[i] == el) {
                flag = 0;
            }
        }
        if (flag) {
            
            std::pair<int, int> p = { el,std::count(second.begin(), second.end(), el) };
            vis2b.push_back(el);
            freq_vec2b.push_back(p);
        }
        
        
    
    }
    std::cout << "frequencies of 2nd vector with algorithm: " << std::endl;
    for (int i = 0; i < (int)freq_vec2b.size(); i++) {
       
        std::cout << freq_vec2b[i].first << " - " << freq_vec2b[i].second << std::endl;
    }
    

    //4

    std::cout << "sum of all numbers 1st vector:" << std::endl;
    std::cout << std::accumulate(first.begin(), first.end(), 0) << std::endl;


    std::cout << "sum of all numbers 2st vector:" << std::endl;
    std::cout << std::accumulate(second.begin(), second.end(), 0) << std::endl;



    //5


    std::vector<int> sums1(first.size());
    std::partial_sum(first.begin(), first.end(), sums1.begin());
    std::cout << "sum of first 10 elements in 1st vector:" << std::endl;
    std::cout << sums1[9] << std::endl;


    std::vector<int> sums2(second.size());
    std::partial_sum(second.begin(), second.end(), sums2.begin());
    std::cout << "sum of first 10 elements in 2nd vector:" << std::endl;
    std::cout << sums2[9] << std::endl;


    // 4.II 
    // 1

    int binary_op_res1 = std::accumulate(first.begin(), first.end(), 0, binary_op);
    int binary_op_res2 = std::accumulate(second.begin(), second.end(), 0, binary_op);
    
    std::cout << "binary operation on 1st vector:" << std::endl;
    std::cout << binary_op_res1 << std::endl;
    std::cout << "binary operation on 2nd vector:" << std::endl;
    std::cout << binary_op_res2 << std::endl;

    //2
    std::vector<int> cnt_first;
    for(int i = 0; i < freq_vec1.size(); i++){
        if (freq_vec1[i].second > 3){
            cnt_first.push_back(freq_vec1[i].first);
        }
    }
    // for(int i = 0; i < cnt_first.size(); i++){
    //     std::cout << cnt_first[i];
    // }
    std::vector<int> cnt_second;
    for(int i = 0; i < freq_vec2.size(); i++){
        if (freq_vec2[i].second >= 2){
            cnt_second.push_back(freq_vec2[i].first);
        }
    }

    //3
    
    std::vector<int> dups2;
    for (int el : second)
        if (std::count(second.begin(), second.end(), el) >= 2 &&
            std::find(dups2.begin(), dups2.end(), el) == dups2.end())
            dups2.push_back(el);

    std::cout << "value | in 1st | in 2nd\n";

    // способ 1: цикл for
    for (int el : dups2) {
        int c1 = std::count(first.begin(), first.end(), el);
        if (c1 > 3) {
            int c2 = std::count(second.begin(), second.end(), el);
            std::cout << el << " | " << c1 << " | " << c2 << "\n";
        }
    }

    // способ 2: алгоритм + лямбда
    std::for_each(dups2.begin(), dups2.end(), [&](int el) {
        int c1 = std::count_if(first.begin(), first.end(), [el](int v) { return v == el; });
        if (c1 > 3) {
            int c2 = std::count_if(second.begin(), second.end(), [el](int v) { return v == el; });
            std::cout << el << " | " << c1 << " | " << c2 << "\n";
        }
    });
}