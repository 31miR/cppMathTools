#include "function.hpp"

std::vector<double> linspace(double begin, double end, int ammount) {
    if (ammount < 1) throw 0;
    if (ammount == 1) return std::vector<double>{(end + begin) / 2};
    double space = (end - begin) / (ammount-1);
    std::vector<double> res;
    res.reserve(ammount);
    for (int i = 0; i < ammount; ++i) {
        res.push_back(begin);
        begin += space;
    }
    return res;
}