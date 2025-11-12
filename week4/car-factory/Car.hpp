#pragma once

#include <string>

class Car
{
private:
    std::string type;
    std::string model;
    std::string color;
    int seats;

public:
    Car()
    {
        this->type = "";
        this->model = "";
        this->color = "";
        this->seats = 4;
    };

    Car(const std::string type, const std::string model, const std::string color, const int seats)
    {
        this->type = type;
        this->model = model;
        this->color = color;
        this->seats = seats;
    }

    std::string getmodel() const
    {
        return this->model;
    }

    std::string getType() const
    {
        return this->type;
    }

    std::string getColor() const
    {
        return this->color;
    }

    int getSeats() const
    {
        return this->seats;
    }
};
