#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
using namespace std;

class Ingredient {
private:
    string ingredient;
    string category;
    int quantityAvailable;
    double pricePerLb;
    int reorderPoint;
    string supplier;

public:
    Ingredient();
    Ingredient(string ing, string cat, int qty, double price, int reorder, string supp);

    void setIngredient(string ing);
    void setCategory(string cat);
    void setQuantityAvailable(int qty);
    void setPricePerLb(double price);
    void setReorderPoint(int reorder);
    void setSupplier(string supp);

    string getIngredient() const;
    string getCategory() const;
    int getQuantityAvailable() const;
    double getPricePerLb() const;
    int getReorderPoint() const;
    string getSupplier() const;

    double totalCost() const;
    bool needsReorder() const;
    void PrintAll() const;
};

#endif
