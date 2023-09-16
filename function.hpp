#pragma once
#include <vector>

std::vector<double> linspace(double begin, double end, int ammount);

template<typename T>
std::vector<T> numeric_diff(const std::vector<T>& x, const std::vector<T>& y) {
    if (y.size() != x.size() || x.size() == 0 || x.size() == 1) throw 0;
    std::vector<T> res;
    res.reserve(y.size());
    for (int i = 0; i < x.size() - 1; ++i) {
        res.push_back( (y[i+1] - y[i]) / (x[i+1]-x[i]) );
    }
    res.push_back(res.back());
    return res;
}

template<typename T, class func>
std::vector<T> apply_func(const std::vector<T>& x, func f) {
    std::vector<T> res;
    res.reserve(x.size());
    for(auto& i : x) res.push_back(f(i));
    return res;
}