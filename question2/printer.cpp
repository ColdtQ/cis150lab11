#include "printer.h"
#include <iostream>
using namespace std;

Printer::Printer(int cols) {
    columns = cols;
}

void Printer::printLine(string line) {
    if (static_cast<int>(line.length()) > columns) {
        throw static_cast<int>(line.length());
    }

    cout << line << endl;
}
