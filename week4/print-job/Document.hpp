#pragma once

#include <string>

class Document
{
private:
    std::string name;
    int numPages;

public:
    Document()
    {
        this->name = "";
        this->numPages = 0;
    };

    Document(const std::string name, const int pages)
    {
        this->name = name;
        this->numPages = pages;
    }

    std::string getName()
    {
        return this->name;
    }

    int getPages()
    {
        return this->numPages;
    }
};
