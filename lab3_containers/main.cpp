#include <iostream>
#include <array>
#include <random>
#include <vector>
#include <list>
#include <deque>
#include <fstream>

#include "../lab3_template/add.h"

int main() {
    int M = 10;
    int N = 200;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-N, N);

    std::array<double, 10> cont_arr;
    std::vector<double> cont_vec;
    std::list<double> cont_li;
    std::deque<double> cont_dec;

    for (int i = 0; i < M; i++) {
        cont_arr[i] = static_cast<double>(dist(gen));
    }

    for (int i = 0; i < M; i++) {
        cont_vec.push_back(static_cast<double>(dist(gen)));
    }

    for (int i = 0; i < M; i++) {
        cont_li.push_back(static_cast<double>(dist(gen)));
    }

    for (int i = 0; i < M; i++) {
        cont_dec.push_back(static_cast<double>(dist(gen)));
    }

    double sec_arg = static_cast<double>(dist(gen));

    std::vector<int> res_vec;
    res_vec.resize(M);

    std::list<int> res_li;

    std::deque<int> res_dec;
    res_dec.resize(M);

    std::array<int, 10> res_arr;

    for (int i = 0; i < M; i++) {
        res_vec[i] = extended::Add<double, int>(cont_arr[i], sec_arg);
    }

    for (std::vector<double>::iterator it = cont_vec.begin(); it != cont_vec.end(); it++) {
        res_li.push_back(extended::Add<double, int>(*it, sec_arg));
    }

    int k = 0;
    for (double val : cont_li) {
        if (k < M) {
            res_dec[k] = extended::Add<double, int>(val, sec_arg);
            k++;
        }
    }

    int k2 = 0;
    for (std::deque<double>::iterator it = cont_dec.begin(); it != cont_dec.end(); it++) {
        if (k2 < M) {
            res_arr[k2] = extended::Add<double, int>(*it, sec_arg);
            k2++;
        }
    }

    std::fstream fout("table.md", std::ios::out);

    fout << "| # | Array | Vector | List | Deque | Array->Vec | Vec->List | List->Deque | Deque->Array |" << std::endl;
    fout << "|---|-------|--------|------|-------|------------|-----------|-------------|--------------|" << std::endl;

    std::list<double>::iterator it_li_cur = cont_li.begin();
    std::list<int>::iterator it_r_li_cur = res_li.begin();

    for (int i = 0; i < M; i++) {
        fout << "| " << i
             << " | " << cont_arr[i]
             << " | " << cont_vec[i]
             << " | " << *it_li_cur
             << " | " << cont_dec[i]
             << " | " << res_vec[i]
             << " | " << *it_r_li_cur
             << " | " << res_dec[i]
             << " | " << res_arr[i]
             << " |" << std::endl;

        it_li_cur++;
        it_r_li_cur++;
    }

    return 0;
}