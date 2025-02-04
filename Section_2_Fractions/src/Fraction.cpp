#include "Fraction.h"
#include <stdexcept>
#include <cstdlib>
#include <string>
#include <iostream>

// 计算最大公约数
int Fraction::GCD(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 将分数化为最简形式
void Fraction::Simplify() {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    if (numerator == 0) {
        denominator = 1;
        return;
    }
    int gcd = GCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// 构造函数：存储并简化分数
Fraction::Fraction(int a, int b)
    : numerator(a), denominator(b)
{
    Simplify();
}

// 返回当前分数的倒数
Fraction Fraction::reciprocal() const {
    return Fraction(denominator, numerator);
}

// 将分数与整数 a 相乘
Fraction Fraction::multiply(int a) const {
    return Fraction(numerator * a, denominator);
}

// 将当前分数转换为 double
double Fraction::toDouble() const {
    return static_cast<double>(numerator) / denominator;
}

// 将当前分数转换为字符串
std::string Fraction::toString() const {
    if (numerator == 0) {
        return "0";
    }
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}