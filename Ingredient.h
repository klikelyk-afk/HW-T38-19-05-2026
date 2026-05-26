#pragma once
#include <string>
#include <iostream>

class Ingredient {
private:
    std::string name;
    int cookTime;

public:
    Ingredient();
    Ingredient(std::string name, int cookTime);

    std::string getName() const;
    int getCookTime() const;

    bool operator>=(const Ingredient& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Ingredient& ing);
};