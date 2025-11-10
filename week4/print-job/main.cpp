#include "./PrintJob.hpp"

int main()
{
    PrintJob printer;
    printer.addDocument();
    printer.addDocument();
    printer.addDocument();
    printer.viewQueue();
    printer.processNext();
    printer.viewQueue();
    printer.processNext();
    printer.viewQueue();
    printer.processNext();
    printer.viewQueue();

    return 0;
}