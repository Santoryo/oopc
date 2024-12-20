#pragma once

#include <string>
#include <iostream>

class Book
{
public:
    std::string author;
    std::string category;
    unsigned int pageCount;
    bool isAvailable;

    Book(const std::string &author, const std::string &category, unsigned int pageCount, bool isAvailable) : 
        author(author), category(category), pageCount(pageCount), isAvailable(isAvailable) {};
    Book() {};

};

std::ostream &operator<<(std::ostream &os, Book& book)
{
    return os << "Author: " <<  book.author <<  " Category: " 
            << book.category << " Pages: " << book.pageCount 
            << " Is book available in library?: " << book.isAvailable;
}