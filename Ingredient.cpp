#include "Ingredient.h"

Ingredient::Ingredient() {
    name = "Unknown";
    cookTime = 0;
}

Ingredient::Ingredient(std::string name, int cookTime) {
    this->name = name;
    this->cookTime = cookTime;
}

std::string Ingredient::getName() const { return name; }
int Ingredient::getCookTime() const { return cookTime; }

bool Ingredient::operator>=(const Ingredient& other) const {
    return this->cookTime <= other.cookTime;
}

std::ostream& operator<<(std::ostream& os, const Ingredient& ing) {
    os << ing.name << " (" << ing.cookTime << "s)";
    return os;
}