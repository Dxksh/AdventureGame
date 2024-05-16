#include "Character.h"
#include "Location.h"
#include <algorithm> // for std::find_if
#include <iostream>  // for std::cout, std::endl

// Character class

// Default constructor
Character::Character() : name(""), hitPoints(0) {}

// Parameterized constructor
Character::Character(std::string name, int hitPoints) : name(name), hitPoints(hitPoints) {}


// Details setters and getters
void Character::setName(std::string name) {
    this->name = name;
}

std::string Character::getName() const {
    return name;
}

void Character::setHitPoints(int hitPoints) {
    this->hitPoints = hitPoints;
}

int Character::getHitPoints() const {
    return hitPoints;
}


// Damage inflicted on Character
void Character::takeHit(int damage) {
    hitPoints -= damage;
}

void Character::increaseHitpoints(int hp) {
    hitPoints += hp;
}


// Monster class

// Default constructor
Monster::Monster() : Character() {}

// Parameterized constructor
Monster::Monster(std::string name, int hitPoints) : Character(name, hitPoints) {}

// Monster's current location setter and getter
void Monster::setCurrentLocation(Location* locationPtr) {
    currentLocation = locationPtr;
}

Location *Monster::getCurrentLocation() {
    return currentLocation;
}


// Player class

// Default constructor
Player::Player() : Character(), score(0), currentLocation((Location *) "") {}

// Player score setter and getter
void Player::setScore(int score) {
    this->score = score;
}

int Player::getScore() const {
    return score;
}

// Player's current location setter and getter

void Player::setCurrentLocation(Location* locationPtr) {
    currentLocation = locationPtr;
}

Location* Player::getCurrentLocation() {
    return currentLocation;
}


// Add items to player's inventory
void Player::addWeapon(Weapon* weapon) {
    weapons.push_back(weapon);
}

void Player::addPotion(Potion* potion) {
    potions.push_back(potion);
}

void Player::addTreasure(Treasure* treasure) {
    treasures.push_back(treasure);
}

void Player::addArmour(Armour *armour) {
    armours.push_back(armour);
}

// Item getters
std::vector<Weapon *> Player::getWeapons() {
    return weapons;
}

std::vector<Potion *> Player::getPotions() {
    return potions;
}

std::vector<Treasure *> Player::getTreasures() {
    return treasures;
}

std::vector<Armour *> Player::getArmour() {
    return armours;
}

// Remove all potions from inventory after drinking
void Player::clearPotions() {
    potions.clear();
}

void Player::increaseScore() {
    score+=1;
}

// Player movement on map
bool Player::move(Player& player, std::string direction) {
    // Get player's current location
    Location* currentLocationPtr = player.getCurrentLocation();
    // Get exits in current location
    std::map<std::string, Location*> currentExits = currentLocationPtr->getExits();

    // Iterate through exits
    for (auto it = currentExits.begin(); it != currentExits.end(); it++) {

        // If exit matches user's chosen direction, then move there
        if (it->first == direction) {
            player.setCurrentLocation(it->second);
            return true;
        }

        if (it == --currentExits.end()) {
            std::cout << "Invalid input. No exit in that direction." << std::endl;
        }
    }
    return false;
}




