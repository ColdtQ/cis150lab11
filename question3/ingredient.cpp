#include "ingredient.h"
#include <iostream>
#include <iomanip>
using namespace std;

Ingredient::Ingredient() {
    ingredient = "";
    category = "";
    quantityAvailable = 0;
    pricePerLb = 0.0;
    reorderPoint = 0;
    supplier = "";
}

Ingredient::Ingredient(string ing, string cat, int qty, double price, int reorder, string supp) {
    ingredient = ing;
    category = cat;
    quantityAvailable = qty;
    pricePerLb = price;
    reorderPoint = reorder;
    supplier = supp;
}

void Ingredient::setIngredient(string ing) {
    ingredient = ing;
}

void Ingredient::setCategory(string cat) {
    category = cat;
}

void Ingredient::setQuantityAvailable(int qty) {
    quantityAvailable = qty;
}

void Ingredient::setPricePerLb(double price) {
    pricePerLb = price;
}

void Ingredient::setReorderPoint(int reorder) {
    reorderPoint = reorder;
}

void Ingredient::setSupplier(string supp) {
    supplier = supp;
}

string Ingredient::getIngredient() const {
    return ingredient;
}

string Ingredient::getCategory() const {
    return category;
}

int Ingredient::getQuantityAvailable() const {
    return quantityAvailable;
}

double Ingredient::getPricePerLb() const {
    return pricePerLb;
}

int Ingredient::getReorderPoint() const {
    return reorderPoint;
}

string Ingredient::getSupplier() const {
    return supplier;
}

double Ingredient::totalCost() const {
    return quantityAvailable * pricePerLb;
}

bool Ingredient::needsReorder() const {
    return quantityAvailable < reorderPoint;
}

void Ingredient::PrintAll() const {
    cout << left << setw(18) << ingredient
         << setw(12) << category
         << right << setw(10) << quantityAvailable
         << setw(12) << fixed << setprecision(2) << pricePerLb
         << setw(16) << reorderPoint
         << "  " << left << supplier << endl;
}
