#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>

class Student
{
private:
    int id;
    std::string name;

public:
    // constructor
    Student() {};

    Student(int id, std::string studentName)
    {
        this->id = id;
        this->name = studentName;
    }

    // getters
    int getId()
    {
        return this->id;
    }

    std::string getName()
    {
        return this->name;
    }

    // utils
    void toString()
    {
        std::cout << "ID: " << this->id << ", Name: " << this->name << "\n";
    }
};

#endif