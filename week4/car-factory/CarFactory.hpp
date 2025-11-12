#pragma once

#include "Car.hpp"
#include "../../src/Queue.hpp"

class CarFactory
{
private:
    Queue<Car> carFactoryQueue;

public:
    void produceSedan()
    {
        std::string model, color;

        do
        {
            std::cout << "Enter model: ";
            std::getline(std::cin, model);
        } while (model == "");

        do
        {
            std::cout << "Enter color: ";
            std::getline(std::cin, color);
        } while (color == "");

        Car sedan("Sedan", model, color, 5);
        this->carFactoryQueue.enqueue(sedan);
        std::cout << "Add Sedan to production queue: (" << model << ", " << color << ", 5 seats).\n";
    }

    void produceSUV()
    {
        std::string model, color;

        do
        {
            std::cout << "Enter model: ";
            std::getline(std::cin, model);
        } while (model == "");

        do
        {
            std::cout << "Enter color: ";
            std::getline(std::cin, color);
        } while (color == "");

        Car suv("SUV", model, color, 7);
        this->carFactoryQueue.enqueue(suv);
        std::cout << "Add SUV to production queue: (" << model << ", " << color << ", 7 seats).\n";
    }

    void viewProductionQueue()
    {
        if (this->carFactoryQueue.isEmpty())
        {
            std::cout << "The production queue is empty.\n";
            return;
        }

        std::cout << "There are " << this->carFactoryQueue.size() << " car" << (this->carFactoryQueue.size() == 1 ? "" : "s") << " in the production queue.\n";
        Car next = this->carFactoryQueue.peek();
        std::cout << "Next car to be delivered: (type:" << next.getType() << ", model:" << next.getmodel() << ", color:" << next.getColor() << ", seat" << (next.getSeats() == 1 ? "" : "s") << ":" << next.getSeats() << ").\n";
    }

    void deliverCar()
    {
        if (this->carFactoryQueue.isEmpty())
        {
            std::cout << "No cars to deliver. The production queue is empty.\n";
            return;
        }

        Car deliveredCar = this->carFactoryQueue.dequeue();
        std::cout << "Delivered car: (type:" << deliveredCar.getType() << ", model:" << deliveredCar.getmodel() << ", color:" << deliveredCar.getColor() << ", seat" << (deliveredCar.getSeats() == 1 ? "" : "s") << ":" << deliveredCar.getSeats() << ").\n";
    }
};