#ifndef ITEM_H
#define ITEM_H

#include <string>

// Item base class
class Item {
private:
    std::string name;
public:
    Item();
    Item(std::string name);
    void setName(std::string name);
    std::string getName() const;
};

// Potion class derived from Item
class Potion : public Item {
private:
    int strength;
public:
    Potion();
    Potion(std::string name, int strength);
    void setStrength(int strength);
    int getStrength() const;
};

// Weapon class derived from Item
class Weapon : public Item {
private:
    int power;
public:
    Weapon();
    Weapon(std::string name, int power);
    void setPower(int power);
    int getPower() const;
};

// Treasure class derived from Item
class Treasure : public Item {
private:
    int value;
public:
    Treasure();
    Treasure(std::string name, int value);
    void setValue(int value);
    int getValue() const;
};

// Armour class derived from Item
class Armour : public Item {
private:
    int protection;
public:
    Armour();
    Armour(std::string name, int protection);
    void setProtection(int protection);
    int getProtection();
};

#endif // ITEM_H
