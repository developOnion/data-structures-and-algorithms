#include <iostream>

#include "./CarFactory.hpp"

int main(void)
{
    CarFactory carFactory;

    int choice;
    do
    {
        std::cout << "\n============Car Factory==============\n";
        std::cout << "1. Produce Sedan\n2. Produce SUV\n3. View Production Queue\n4. Deliver Car\n5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "\n";

        if (std::cin.fail())
        {
            std::cin.clear();
            choice = 0;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            carFactory.produceSedan();
            break;
        case 2:
            carFactory.produceSUV();
            break;
        case 3:
            carFactory.viewProductionQueue();
            break;
        case 4:
            carFactory.deliverCar();
            break;
        case 5:
            std::cout << "Exiting car factory.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}