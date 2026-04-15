#include <iostream>
#include "printer.h"
using namespace std;

int main() {
    // For the first screenshot run, change 40 to 30.
    // For the final screenshot run, keep it at 40.
    Printer receiptPrinter(40);

    try {
        receiptPrinter.printLine("UMichD Smoothie Shop");
        receiptPrinter.printLine("Wolverine Wonder Drinks!");
        receiptPrinter.printLine("Try a Famous Blue and Gold Smoothie");
        receiptPrinter.printLine("Place your order now for fast Delivery");
        receiptPrinter.printLine("Phone: 313-555-Blue");
    }
    catch (int lineLength) {
        cout << "Printer error: requested line is " << lineLength
             << " characters long." << endl;
    }
    catch (...) {
        cout << "Unknown printer error occurred." << endl;
    }

    return 0;
}
