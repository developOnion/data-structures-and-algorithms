#include "./PrintJob.hpp"

int main()
{
    PrintJob printer;

    int choice;
    do
    {
        std::cout << "\n============Printer Program==============\n";
        std::cout << "1. Add Document\n2. View Print Queue\n3. Process Next Document\n4. Exit\n";
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
            printer.addDocument();
            break;
        case 2:
            printer.viewQueue();
            break;
        case 3:
            printer.processNext();
            break;
        case 4:
            std::cout << "Exiting printer program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}