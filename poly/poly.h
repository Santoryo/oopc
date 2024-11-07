#pragma once
#include <map>
#include <iostream>

class Poly {
    public:
        std::map<int, double> poly;
        Poly();
        Poly(double c);
        Poly(const Poly &p);
        double& operator[](int index);
        double operator()(double point) const;

        const Poly operator+(const Poly &other) const;
        const Poly operator-(const Poly &other) const;
        const Poly operator*(const Poly &other) const;

        Poly operator-() const;
};

Poly operator+(double scalar, const Poly &other);
Poly operator-(double scalar, const Poly &other);
Poly operator*(double scalar, const Poly &other);

std::ostream &operator<<(std::ostream &stream, const Poly &poly);
std::string parseCoefficient(int key, double value, bool displaySign);
bool checkIfZero(const Poly &other);