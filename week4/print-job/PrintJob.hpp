#pragma once

#include "../../header/Queue.hpp"
#include "./Document.hpp"

#include <iostream>
#include <limits>

class PrintJob
{
private:
    Queue<Document> documents;

public:
    void addDocument()
    {
        std::string name;
        int pages;

        do
        {
            std::cout << "Enter document name: ";
            std::getline(std::cin, name);
        } while (name == "");

        do
        {
            std::cout << "Enter number of pages: ";
            std::cin >> pages;

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                pages = 0;
            }
        } while (pages <= 0);

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        Document document(name, pages);
        this->documents.enqueue(document);
        std::cout << "Document " << name << " added to print queue.\n";
    }

    void viewQueue()
    {
        if (this->documents.isEmpty())
        {
            std::cout << "The print queue is empty.\n";
            return;
        }

        std::cout << "There are " << this->documents.size() << " job" << (this->documents.size() == 1 ? "" : "s") << " waiting.\n";
        Document next = this->documents.peek();
        std::cout << "Next up: '" << next.getName() << "' (" << next.getPages() << " page" << (next.getPages() == 1 ? "" : "s") << ").\n";
    }

    void processNext()
    {
        if (this->documents.isEmpty())
        {
            std::cout << "The print queue is empty.\n";
            return;
        }

        Document next = this->documents.dequeue();
        std::cout << "Printing document '" << next.getName() << "' (" << next.getPages() << " page" << (next.getPages() == 1 ? "" : "s") << ").\n";
    }
};