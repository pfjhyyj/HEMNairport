// random generator test without specify the seed
// every run produce different result
//
// to produce constant result of same rate, specify the integer seed in the
// constructor

#include "random_helper.h"
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

using XXYY::RandomHelper;
using std::vector;
using std::cout;

constexpr uint64_t kTry = 100000;

int main(int argc, char const *argv[]) {

    if (argc != 3) {
        cout << "usage: ./test_random <comming_rate> <leaving_rate>\n";
        exit(1);
    }

    double comming_rate = atof(argv[1]), leaving_rate = atof(argv[2]);

    RandomHelper random(comming_rate, leaving_rate);
    vector<uint64_t> commings(comming_rate * 5 + 10, 0),
        leavings(leaving_rate * 5 + 10, 0);

    for (uint64_t i = 0; i++ < kTry;) {
        auto comming_num = random.GetComming();
        auto leaving_num = random.GetLeaving();
        if (comming_num < commings.size())
            ++commings[comming_num];
        if (leaving_num < leavings.size())
            ++leavings[leaving_num];
    }

    cout << "Comming distribution:\n";
    for (uint64_t i = 0; i < commings.size(); ++i) {
        cout << i << ": " << commings[i] << '\n';
    }

    cout << "\nLeaving distribution:\n";
    for (uint64_t i = 0; i < leavings.size(); ++i) {
        cout << i << ": " << leavings[i] << '\n';
    }

    return 0;
}