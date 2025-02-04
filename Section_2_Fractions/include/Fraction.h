#pragma once
#include <string>
#include <stdexcept>
#include <cstdlib>

// 声明 Fraction 类，避免在此实现具体函数
class Fraction {
private:
    int numerator;
    int denominator;

    // 私有辅助函数
    int GCD(int a, int b);
    void Simplify();

public:
    Fraction(int a, int b);
    Fraction reciprocal() const;
    Fraction multiply(int a) const;
    double toDouble() const;
    std::string toString() const;
};