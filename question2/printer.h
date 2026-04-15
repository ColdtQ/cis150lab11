// CIS 150 | Date: 2026-04-15 | Trevor Romano
// this header defines the printer class interface

#ifndef PRINTER_H
#define PRINTER_H

#include <string>
using namespace std;

class Printer {
private:
    int columns;

public:
    Printer(int cols);
    void printLine(string line);
};

#endif
