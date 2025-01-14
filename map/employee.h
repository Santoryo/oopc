#pragma once

#include <string>
#include <iostream>

class Employee {
public:
    std::string name;
    std::string position;
    unsigned int age;

    Employee(const std::string& name, const std::string& position, unsigned int age) : name(name), position(position), age(age) {};
    Employee() {};
};

std::ostream &operator<<(std::ostream& os, const Employee& employee) {
    return os << employee.name << " (" << employee.position << ", " << employee.age << ")";
}