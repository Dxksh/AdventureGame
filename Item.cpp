#include "Item.h"

// Item class

// Default constructor
Item::Item() : name("") {}

// Parameterized constructor
Item::Item(std::string name) : name(name) {}

// Name setter
void Item::setName(std::string name) {
    this->name = name;
}

// Name getter
std::string Item::getName() const {
    return name;
}


// Potion class

// Default constructor
Potion::Potion() : Item(), strength(0) {}

// Parameterized constructor
Potion::Potion(std::string name, int strength) : Item(name), strength(strength) {}

// Potion strength setter
void Potion::setStrength(int strength) {
    this->strength = strength;
}

// Potion strength getter
int Potion::getStrength() const {
    return strength;
}


// Weapon class

// Default constructor
Weapon::Weapon() : Item(), power(0) {}

// Parameterized constructor
Weapon::Weapon(std::string name, int power) : Item(name), power(power) {}

// Weapon power setter
void Weapon::setPower(int power) {
    this->power = power;
}

// Weapon power getter
int Weapon::getPower() const {
    return power;
}


// Treasure class

// Default constructor
Treasure::Treasure() : Item(), value(0) {}

// Parameterized constructor
Treasure::Treasure(std::string name, int value) : Item(name), value(value) {}

// Treasure value setter
void Treasure::setValue(int value) {
    this->value = value;
}

// Treasure value getter
int Treasure::getValue() const {
    return value;
}


// Armour class

// Default constructor
Armour::Armour() : Item(), protection(0){}

// Parameterized constructor
Armour::Armour(std::string name, int protection) : Item(name), protection(protection){}

// Armour protection setter
void Armour::setProtection(int protection) {
    this->protection = protection;
}

// Armour protection getter
int Armour::getProtection() {
    return protection;
}
