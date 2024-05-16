#include "Location.h"
#include <iostream>

// Default constructor
Location::Location() {}

// Parameterized constructor
Location::Location(std::string name, std::string description) {
    setName(name);
    setDescription(description);
}

// Name setter
void Location::setName(std::string n) {
    name = n;
}

// Name getter
std::string Location::getName() const {
    return name;
}

// Description setter
void Location::setDescription(std::string description) {
    this->description = description;
}

// Description getter
std::string Location::getDescription() const {
    return description;
}

// Exit getter
std::map<std::string, Location*> Location::getExits()  {
    return exits;
}

// Add exit to exit vector
void Location::addExit(std::string exit, Location* destination) {
    exits.insert({exit, destination});
}

// Add potion to potion vector
void Location::addPotion(Potion* potion) {
    potions.push_back(potion);
}

// Add treasure to treasure vector
void Location::addTreasure(Treasure* treasure) {
    treasures.push_back(treasure);
}

// Add weapon to weapon vector
void Location::addWeapon(Weapon* weapon) {
    weapons.push_back(weapon);
}

// Add armour to armour vector
void Location::addArmour(Armour *armour) {
    armours.push_back(armour);
}

// Get all potions in location
std::vector<Potion *> Location::getPotions() {
    return potions;
}

// Get all treasures in location
std::vector<Treasure *> Location::getTreasures() {
    return treasures;
}

// Get all weapons in location
std::vector<Weapon *> Location::getWeapons() {
    return weapons;
}

// Get all armour in location
std::vector<Armour *> Location::getArmour() {
    return armours;
}

// Clear all potions in location
void Location::clearPotions() {
    //std::cout << "Potions cleared.";
    potions.clear();
}

// Clear all treasures in location
void Location::clearTreasures() {
    //std::cout << "Treasures cleared.";
    treasures.clear();
}

// Clear all weapons in location
void Location::clearWeapons() {
    //std::cout << "Weapons cleared.";
    weapons.clear();
}

// Clear all armours in location
void Location::clearArmours() {
    armours.clear();
}




