#pragma once
#include <map>
#include <iostream>

class Poly {
    private:
        std::map<int, double> poly;
        bool checkIfZero() const;
        void deleteZeros();
    public:
        Poly() = default;
        Poly(double val);
        double& operator[](int index);
        double operator()(double point) const;

        Poly operator-() const;

        friend Poly operator+(const Poly &p1, const Poly &p2);
        friend Poly operator-(const Poly &p1, const Poly &p2);
        friend Poly operator*(const Poly &p1, const Poly &p2);

        friend std::ostream &operator<<(std::ostream &stream, const Poly &other);
};