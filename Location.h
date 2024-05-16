#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
#include <map>
#include "Item.h"
//#include "Character.h"

class Location {
private:
    // Location details
    std::string name;
    std::string description;

    // Vectors to store exits and items in the location
    std::map<std::string, Location*> exits;
    std::vector<Potion*> potions;
    std::vector<Treasure*> treasures;
    std::vector<Weapon*> weapons;
    std::vector<Armour*> armours;
public:
    // Constructors
    Location();
    Location(std::string name, std::string description);

    // Details setters and getters
    void setName(std::string name);
    std::string getName() const;
    void setDescription(std::string description);
    std::string getDescription() const;

    // Add exits and items to location
    void addExit(std::string exit, Location* destination);
    void addPotion(Potion* potion);
    void addTreasure(Treasure* treasure);
    void addWeapon(Weapon* weapon);
    void addArmour(Armour* armour);

    // Exits and items getters and setters
    std::map<std::string, Location*> getExits();
    std::vector<Potion*> getPotions();
    std::vector<Treasure*> getTreasures();
    std::vector<Weapon*> getWeapons();
    std::vector<Armour*> getArmour();

    // Clear vectors
    void clearPotions();
    void clearTreasures();
    void clearWeapons();
    void clearArmours();
};

#endif // LOCATION_H
