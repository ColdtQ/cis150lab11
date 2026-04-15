#include <iostream>
using namespace std;

int main() {
    int numStaff = 5;
    int numCust = 9;
    int totalInStore;

    int* staffPtr = &numStaff;
    int* custPtr = &numCust;
    int* totalPtr = &totalInStore;

    cout << "The number of staff in the store is: " << *staffPtr << endl;
    cout << "The number of customers in the store is: " << *custPtr << endl;

    *custPtr += 15;
    cout << "15 more customers entered the store." << endl;
    cout << "Updated number of customers: " << *custPtr << endl;

    *staffPtr -= 4;
    cout << "4 staff members went on break." << endl;
    cout << "Updated number of staff: " << *staffPtr << endl;

    *totalPtr = *staffPtr + *custPtr;
    cout << "Total number of people now in the store: " << *totalPtr << endl;

    return 0;
}
