#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ifstream fin1;
    fin1.open("s04_v1_42_1.txt");
    std::vector<int> first;
    int x;
    while (fin1 >> x) {
        first.push_back(x);
    }
    fin1.close();

    std::ifstream fin2;
    fin2.open("s04_v1_42_2.txt");
    std::vector<int> second;
    while (fin2 >> x) {
        second.push_back(x);
    }
    fin2.close();

    std::cout << "В первом векторе: " << first.size() << " чисел\n";
    std::cout << "Во втором векторе: " << second.size() << " чисел\n";


    std::vector<int> seen1;
    std::vector<std::pair<int, int> > freq1_loop;
    for (int x : first) {
        bool already = false;
        for (int j = 0; j < (int)seen1.size(); j++) {
            if (seen1[j] == x) {
                already = true;
            }
        }
        if (already == false) {
            int kol = 0;
            for (int j = 0; j < (int)first.size(); j++) {
                if (first[j] == x) {
                    kol = kol + 1;
                }
            }
            seen1.push_back(x);
            freq1_loop.push_back(std::make_pair(x, kol));
        }
    }

    std::vector<int> seen2;
    std::vector<std::pair<int, int> > freq2_loop;
    for (int x : second) {
        bool already = false;
        for (int j = 0; j < (int)seen2.size(); j++) {
            if (seen2[j] == x) {
                already = true;
            }
        }
        if (already == false) {
            int kol = 0;
            for (int j = 0; j < (int)second.size(); j++) {
                if (second[j] == x) {
                    kol = kol + 1;
                }
            }
            seen2.push_back(x);
            freq2_loop.push_back(std::make_pair(x, kol));
        }
    }

    std::vector<int> uniq1;
    for (int i = 0; i < (int)first.size(); i++) {
        bool already = false;
        for (int j = 0; j < (int)uniq1.size(); j++) {
            if (uniq1[j] == first[i]) {
                already = true;
            }
        }
        if (already == false) {
            uniq1.push_back(first[i]);
        }
    }
    std::vector<std::pair<int, int> > freq1_algo;
    for (int i = 0; i < (int)uniq1.size(); i++) {
        int kol = std::count(first.begin(), first.end(), uniq1[i]);
        freq1_algo.push_back(std::make_pair(uniq1[i], kol));
    }

    std::vector<int> uniq2;
    for (int i = 0; i < (int)second.size(); i++) {
        bool already = false;
        for (int j = 0; j < (int)uniq2.size(); j++) {
            if (uniq2[j] == second[i]) {
                already = true;
            }
        }
        if (already == false) {
            uniq2.push_back(second[i]);
        }
    }
    std::vector<std::pair<int, int> > freq2_algo;
    for (int i = 0; i < (int)uniq2.size(); i++) {
        int kol = std::count(second.begin(), second.end(), uniq2[i]);
        freq2_algo.push_back(std::make_pair(uniq2[i], kol));
    }

    std::cout << "\nЧастоты первого вектора (цикл):\n";
    for (std::vector<std::pair<int, int> >::iterator it = freq1_loop.begin();
         it != freq1_loop.end(); it++) {
        std::cout << "  " << it->first << " - " << it->second << " раз\n";
    }
    std::cout << "Частоты первого вектора (std::count):\n";
    for (std::vector<std::pair<int, int> >::iterator it = freq1_algo.begin();
         it != freq1_algo.end(); it++) {
        std::cout << "  " << it->first << " - " << it->second << " раз\n";
    }

    std::cout << "\nЧастоты второго вектора (цикл):\n";
    for (std::vector<std::pair<int, int> >::iterator it = freq2_loop.begin();
         it != freq2_loop.end(); it++) {
        std::cout << "  " << it->first << " - " << it->second << " раз\n";
    }
    std::cout << "Частоты второго вектора (std::count):\n";
    for (std::vector<std::pair<int, int> >::iterator it = freq2_algo.begin();
         it != freq2_algo.end(); it++) {
        std::cout << "  " << it->first << " - " << it->second << " раз\n";
    }

    int sum1a = std::accumulate(first.begin(), first.end(), 0);
    int sum1b = std::accumulate(first.begin(), first.end(), 0, std::plus<int>());
    int sum2a = std::accumulate(second.begin(), second.end(), 0);
    int sum2b = std::accumulate(second.begin(), second.end(), 0, std::plus<int>());
    std::cout << "\nСумма первого: " << sum1a << " (и " << sum1b << ")\n";
    std::cout << "Сумма второго: " << sum2a << " (и " << sum2b << ")\n";

    int first10a = std::accumulate(first.begin(), first.begin() + 10, 0);
    int first10b = std::accumulate(second.begin(), second.begin() + 10, 0);
    std::cout << "Сумма первых 10 первого: " << first10a << "\n";
    std::cout << "Сумма первых 10 второго: " << first10b << "\n";


    int op1 = std::accumulate(first.begin(), first.end(), 0,
                              [](int sum, int y) { return (y % 2 == 0) ? sum + y : sum - y; });
    int op2 = std::accumulate(second.begin(), second.end(), 0,
                              [](int sum, int y) { return (y % 2 == 0) ? sum + y : sum - y; });
    std::cout << "  первый = " << op1 << ", второй = " << op2 << "\n";

    std::cout << "\nВо втором векторе 2 и более раз:\n";
    for (std::vector<std::pair<int, int> >::iterator it = freq2_algo.begin();
         it != freq2_algo.end(); it++) {
        if (it->second >= 2) {
            std::cout << "  " << it->first << "\n";
        }
    }

    std::cout << "В первом векторе больше 3 раз:\n";
    for (std::vector<std::pair<int, int> >::iterator it = freq1_algo.begin();
         it != freq1_algo.end(); it++) {
        if (it->second > 3) {
            std::cout << "  " << it->first << "\n";
        }
    }

    std::cout << "\nПересечение (способ с циклом):\n";
    for (std::vector<std::pair<int, int> >::iterator it = freq2_algo.begin();
         it != freq2_algo.end(); it++) {
        if (it->second >= 2) {
            int v_first = std::count(first.begin(), first.end(), it->first);
            if (v_first > 3) {
                std::cout << "  число " << it->first
                          << ": в первом = " << v_first
                          << ", во втором = " << it->second << "\n";
            }
        }
    }

    std::vector<std::pair<int, int> > podhod;
    for (std::vector<std::pair<int, int> >::iterator it = freq2_algo.begin();
         it != freq2_algo.end(); it++) {
        if (it->second >= 2) {
            podhod.push_back(std::make_pair(it->first, it->second));
        }
    }

    std::vector<std::pair<int, int> > result;
    std::copy_if(podhod.begin(), podhod.end(), std::back_inserter(result),
                 [&](const std::pair<int, int>& p) {
                     int v_first = std::count(first.begin(), first.end(), p.first);
                     if (v_first > 3) {
                         return true;
                     } else {
                         return false;
                     }
                 });

    std::cout << "Пересечение (способ с copy_if и лямбдой):\n";
    for (std::vector<std::pair<int, int> >::iterator it = result.begin();
         it != result.end(); it++) {
        int v_first = std::count(first.begin(), first.end(), it->first);
        std::cout << "  число " << it->first
                  << ": в первом = " << v_first
                  << ", во втором = " << it->second << "\n";
    }

    return 0;
}