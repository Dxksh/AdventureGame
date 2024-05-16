#ifndef CHARACTER_H
#define CHARACTER_H

#include "Location.h"
#include <string>
#include <vector>

// Character base class
class Character {
private:
    std::string name;
    int hitPoints;
public:
    Character();
    Character(std::string name, int hitPoints);
    void setName(std::string name);
    std::string getName() const;
    void setHitPoints(int hitPoints);
    int getHitPoints() const;
    void takeHit(int damage);
    void increaseHitpoints(int hp);
    };

// Monster class derived from Character
class Monster : public Character {
private:
    Location* currentLocation;
public:
    Monster();
    Monster(std::string name, int hitPoints);
    void setCurrentLocation(Location* locationPtr);
    Location* getCurrentLocation();
};

// Player class derived from Character
class Player : public Character {
private:
    int score;
    // Vectors to store player's inventory
    std::vector<Weapon*> weapons;
    std::vector<Potion*> potions;
    std::vector<Treasure*> treasures;
    std::vector<Armour*> armours;
    // Store player's current location
    Location* currentLocation;
public:
    Player();

    // Score setters and getter
    void setScore(int score);
    int getScore() const;
    void increaseScore();

    // Current location setter and getter
    void setCurrentLocation(Location* locationPtr);
    Location* getCurrentLocation();

    // Add items to inventory
    void addWeapon(Weapon* weapon);
    void addPotion(Potion* potion);
    void addTreasure(Treasure* treasure);
    void addArmour(Armour* armour);

    // Item getters
    std::vector<Weapon*> getWeapons();
    std::vector<Potion*> getPotions();
    std::vector<Treasure*> getTreasures();
    std::vector<Armour*> getArmour();

    bool move(Player& player, std::string direction);
    void clearPotions();
};

#endif // CHARACTER_H
