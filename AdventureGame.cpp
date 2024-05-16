#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Character.h"
#include "Item.h"
#include "Location.h"

// Create game map
void createMap(std::vector<Location>& locations, std::vector<Monster>& monsters) {
    // Create locations
    Location* cave = new Location("cave", "in a dark and damp cave.");
    Location* field = new Location("field", "in a wide open field.");
    Location* dungeon = new Location("dungeon", "in a gloomy dungeon.");
    Location* temple = new Location("temple", "in an ancient temple.");
    Location* forest = new Location("forest", "in a dense forest.");
    Location* castle = new Location("castle", "in a majestic castle.");
    Location* ruins = new Location("ruins", "among ancient ruins.");
    Location* clearing = new Location("clearing", "in a peaceful clearing.");
    Location* house = new Location("house", "in a cozy house.");
    Location* hall = new Location("hall", "in a grand hall.");
    Location* library = new Location("library", "in a vast library.");
    Location* garden = new Location("garden", "in a beautiful garden.");

    // Linking locations to their exits
    cave->addExit("W",field);
    field->addExit("W",cave);
    field->addExit("S",dungeon);
    field->addExit("E",forest);
    dungeon->addExit("N",field);
    dungeon->addExit("E",castle);
    temple->addExit("S",forest);
    temple->addExit("E",clearing);
    forest->addExit("N",temple);
    forest->addExit("W",field);
    forest->addExit("S",castle);
    castle->addExit("N",forest);
    castle->addExit("W",dungeon);
    castle->addExit("S",ruins);
    ruins->addExit("N",castle);
    clearing->addExit("W", temple);
    clearing->addExit("E", house);
    house->addExit("W", clearing);
    house->addExit("E", library);
    house->addExit("S", hall);
    hall->addExit("N", house);
    hall->addExit("E", garden);
    library->addExit("W", house);
    library->addExit("S", garden);
    garden->addExit("N", library);
    garden->addExit("W", hall);

    // Create treasures
    Treasure* emerald = new Treasure("Emerald", 40);
    Treasure* sapphire = new Treasure("Sapphire", 40);
    Treasure* diamond = new Treasure("Diamond", 60);
    Treasure* goldRing = new Treasure("Gold Ring", 40);
    Treasure* treasureChest = new Treasure("Treasure Chest", 200);
    Treasure* bagOfCoins = new Treasure("Bag of Coins", 50);
    Treasure* ruby = new Treasure("Ruby", 10);

    // Create potions
    Potion* redHealing = new Potion("Red Healing", 40);
    Potion* purpleHealing = new Potion("Purple Healing", 30);
    Potion* blueHealing = new Potion("Blue Healing", 20);

    // Create weapons
    Weapon* dagger = new Weapon("Dagger", 5);
    Weapon* sword = new Weapon("Sword", 6);
    Weapon* stick = new Weapon("Stick", 1);
    Weapon* club = new Weapon("Club", 3);
    Weapon* crossbow = new Weapon("Crossbow", 10);

    // Create armours
    Armour* helmet = new Armour("Helmet", 2);
    Armour* chestplate = new Armour("Chestplate", 4);
    Armour* leggings = new Armour("Leggings", 3);
    Armour* boots = new Armour("Boots", 1);
    Armour* shield = new Armour("Shield", 5);

    // Add treasures to locations
    cave->addTreasure(emerald);
    field->addTreasure(sapphire);
    temple->addTreasure(diamond);
    castle->addTreasure(goldRing);
    house->addTreasure(treasureChest);
    hall->addTreasure(bagOfCoins);
    garden->addTreasure(ruby);

    // Add potions to locations
    dungeon->addPotion(redHealing);
    ruins->addPotion(purpleHealing);
    hall->addPotion(blueHealing);

    // Add weapons to locations
    field->addWeapon(dagger);
    temple->addWeapon(sword);
    castle->addWeapon(stick);
    clearing->addWeapon(club);
    garden->addWeapon(crossbow);

    // Add armours to locations
    dungeon->addArmour(helmet);
    castle->addArmour(chestplate);
    forest->addArmour(leggings);
    clearing->addArmour(boots);
    library->addArmour(shield);

    // Create monsters
    Monster* goblin = new Monster("Goblin", 10);
    Monster* zombie = new Monster("Zombie", 8);
    Monster* banshee = new Monster("Banshee", 7);
    Monster* vampire = new Monster("Vampire", 9);
    Monster* dragon = new Monster("Dragon", 15);
    Monster* orc = new Monster("Orc", 12);
    Monster* spectre = new Monster("Spectre", 5);
    Monster* ghoul = new Monster("Ghoul", 10);
    Monster* boss = new Monster("BOSS", 25);

    // Add monsters to locations
    goblin->setCurrentLocation(field);
    zombie->setCurrentLocation(dungeon);
    banshee->setCurrentLocation(forest);
    vampire->setCurrentLocation(castle);
    dragon->setCurrentLocation(ruins);
    orc->setCurrentLocation(house);
    spectre->setCurrentLocation(house);
    ghoul->setCurrentLocation(garden);
    boss->setCurrentLocation(cave);

    // Adding locations to the locations vector
    locations.push_back(*cave);
    locations.push_back(*field);
    locations.push_back(*dungeon);
    locations.push_back(*temple);
    locations.push_back(*forest);
    locations.push_back(*castle);
    locations.push_back(*ruins);
    locations.push_back(*clearing);
    locations.push_back(*house);
    locations.push_back(*hall);
    locations.push_back(*library);
    locations.push_back(*garden);

    // Adding monsters to the monsters vector
    monsters.push_back(*goblin);
    monsters.push_back(*zombie);
    monsters.push_back(*banshee);
    monsters.push_back(*vampire);
    monsters.push_back(*dragon);
    monsters.push_back(*orc);
    monsters.push_back(*spectre);
    monsters.push_back(*ghoul);
    monsters.push_back(*boss);
}

// Collect items in current locations and add to player inventory
void collectItems(Player& player, Location& location) {
    // Collect all potions
    for (auto& potion : location.getPotions()) {
        player.addPotion(potion);
    }
    location.clearPotions(); // Remove all potions from the location

    // Collect all treasures
    for (auto& treasure : location.getTreasures()) {
        player.addTreasure(treasure);
    }
    location.clearTreasures(); // Remove all treasures from the location

    // Collect all weapons
    for (auto& weapon : location.getWeapons()) {
        player.addWeapon(weapon);
    }
    location.clearWeapons(); // Remove all weapons from the location

    // Collect all armours
    for (auto& armour : location.getArmour()) {
        player.addArmour(armour);
        player.increaseHitpoints(armour->getProtection());
    }
    location.clearArmours(); // Remove all armours from the location

    std::cout << "You collected all items from the location." << std::endl;
    std::cout << "_______________________________________" << std::endl;
}


// List all items in the player's inventory sorted alphabetically
void listInventory(Player& player) {
    std::cout << "_______________________________________" << std::endl;
    std::cout << "_______________________________________" << std::endl;
    std::cout << std::endl;

    std::cout << "Your inventory:" << std::endl;

    // Treasures
    std::cout << std::endl;
    std::cout << "Treasures:" << std::endl;
    std::vector<Treasure*> treasures = player.getTreasures();
    std::sort(treasures.begin(), treasures.end(), [](Treasure* a, Treasure* b) {
        return a->getName() < b->getName();
    });
    for (const auto& treasure : treasures) {
        std::cout << treasure->getName() << " (Strength: " << treasure->getValue() << ")" << std::endl;
    }

    // Potions
    std::cout << std::endl;
    std::cout << "Potions:" << std::endl;
    std::vector<Potion*> potions = player.getPotions();
    std::sort(potions.begin(), potions.end(), [](Potion* a, Potion* b) {
        return a->getName() < b->getName();
    });
    for (const auto& potion : potions) {
        std::cout << potion->getName() << " (Strength: " << potion->getStrength() << ")" << std::endl;
    }

    // Weapons
    std::cout << std::endl;
    std::cout << "Weapons:" << std::endl;
    std::vector<Weapon*> weapons = player.getWeapons();
    std::sort(weapons.begin(), weapons.end(), [](Weapon* a, Weapon* b) {
        return a->getName() < b->getName();
    });
    for (const auto& weapon : weapons) {
        std::cout << weapon->getName() << " (Strength: " << weapon->getPower() << ")" << std::endl;
    }

    // Armours
    std::cout << std::endl;
    std::cout << "Armour:" << std::endl;
    std::vector<Armour*> armours = player.getArmour();
    std::sort(armours.begin(), armours.end(), [](Armour* a, Armour* b) {
        return a->getName() < b->getName();
    });
    for (const auto& armour : armours) {
        std::cout << armour->getName() << " (Armour: " << armour->getProtection() << ")" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "_______________________________________" << std::endl;
    std::cout << "_______________________________________" << std::endl;

}

// Drink all healing potions in the player's inventory
void drinkPotions(Player& player) {
    int totalHealing = 0;
    std::vector<Potion*> potions = player.getPotions();
    for (auto& potion : potions) {
            totalHealing += potion->getStrength();
            player.clearPotions();
    }
    player.setHitPoints(player.getHitPoints() + totalHealing);
    std::cout << "You drank all healing potions. Total healing points: " << totalHealing << std::endl;
}

// Generate a random number between 1 and 6
int rollDice() {
    return (rand() % 6) + 1;
}

// Function to handle combat between player and monster
void combat(Player& player, std::vector<Monster>& monsters) {
    std::cout << "_______________________________________" << std::endl;

    // Get the monsters in the current location
    // If there are no monsters, return
    if (monsters.empty()) {
        std::cout << "No monsters to fight!" << std::endl;
        return;
    }

    // Get the player's weapon with the highest power rating
    int highestPower = 0;
    Weapon* playerWeapon = nullptr;
    for (auto& weapon : player.getWeapons()) {
        if (weapon->getPower() > highestPower) {
            highestPower = weapon->getPower();
            playerWeapon = weapon;
        }
    }

    // Combat loop
    for (auto it = monsters.begin(); it != monsters.end(); it++) {
        Monster& monster = *it;
        if(monster.getCurrentLocation() == player.getCurrentLocation()) {

            // Boss fight message
            if (player.getCurrentLocation()->getName() == "cave"){
                std::cout << "IT'S TIME FOR THE BOSS FIGHT. WINNING THIS FIGHT ENDS THE GAME AND YOU ARE CROWNED THE CHAMPION. GOOD LUCK!" << std::endl;
            }
            std::cout << "Combat with " << monster.getName() << " begins!" << std::endl;

            while (true) {
                // Monster strikes first
                int monsterDamage = rollDice() * 2;
                player.takeHit(monsterDamage);
                std::cout << "Monster hits you for " << monsterDamage << " damage." << std::endl;
                std::cout << "Your HP: " << player.getHitPoints() << ", Monster's HP: " << monster.getHitPoints() << std::endl;

                // Check if player is defeated
                if (player.getHitPoints() <= 0) {
                    std::cout << "You were defeated! Game over. Your score: " << player.getScore() << std::endl;
                    exit(0);
                }

                // Player strikes back
                int playerDamage = rollDice();
                if (playerWeapon) {
                    playerDamage += playerWeapon->getPower();
                }
                monster.takeHit(playerDamage);
                std::cout << "You hit the monster for " << playerDamage << " damage." << std::endl;
                std::cout << "Your HP: " << player.getHitPoints() << ", Monster's HP: " << monster.getHitPoints() << std::endl;

                // Check if monster is defeated
                if (monster.getHitPoints() <= 0) {
                    std::cout << "You defeated the monster!" << std::endl;
                    if (player.getCurrentLocation()->getName() == "cave"){
                        std::cout << "YOU DID IT! YOU BEAT THE BOSS! CONGRATULATIONS, YOU WIN!" << std::endl;
                        exit(0);
                    }
                    std::cout << "_______________________________________" << std::endl;
                    std::cout << std::endl;

                    it = monsters.erase(it); // Remove defeated monster from the vector
                    player.increaseScore();
                    break; // Exit combat loop
                }
            }
        }
    }
}

// Handle game loop
void gameLoop(Player& player, std::vector<Location>& locations, std::vector<Monster>& monsters) {
    std::string command;
    bool quit = false;

    // Set player's starting location to the clearing
    for (auto& location : locations) {
        if (location.getName() == "clearing") {
            player.setCurrentLocation(&location);
            break;
        }
    }

    while (!quit) {
        // Display current location description, exits, items and monsters
        for (auto& location : locations) {
            if (location.getName() == player.getCurrentLocation()->getName()) {
                // Print description
                std::string currentDescription = location.getDescription();
                std::cout << std::endl;
                std::cout << "You are " << currentDescription << std::endl;
                std::cout << std::endl;

                // Print exits
                std::cout << "Exits: ";
                std::cout << std::endl;
                for (auto& exit : location.getExits()) {
                    std::cout << exit.first << " - " << exit.second->getName() << " ";
                    std::cout << std::endl;
                }
                std::cout << std::endl;

                // Print treasures
                std::cout << "Treasures: ";
                if (location.getTreasures().empty()) {
                    std::cout << "None" << std::endl;
                } else {
                    for (auto& treasure : location.getTreasures()) {
                        std::cout << treasure->getName() << " (Value: " << treasure->getValue() << ")";
                    }
                    std::cout << std::endl;
                }

                // Print potions
                std::cout << "Potions: ";
                if (location.getPotions().empty()) {
                    std::cout << "None" << std::endl;
                } else {
                    for (auto& potion : location.getPotions()) {
                        std::cout << potion->getName() << " (Strength: " << potion->getStrength() << ")";
                    }
                    std::cout << std::endl;
                }

                // Print weapons
                std::cout << "Weapons: ";
                if (location.getWeapons().empty()) {
                    std::cout << "None" << std::endl;
                } else {
                    for (auto& weapon : location.getWeapons()) {
                        std::cout << weapon->getName() << " (Power: " << weapon->getPower() << ")";
                    }
                    std::cout << std::endl;
                }

                // Print armours
                std::cout << "Armour: ";
                if (location.getArmour().empty()) {
                    std::cout << "None" << std::endl;
                } else {
                    for (auto& armour : location.getArmour()) {
                        std::cout << armour->getName() << " (Protection: " << armour->getProtection() << ")";
                    }
                    std::cout << std::endl;
                }

                // Print monsters
                std::cout << "Monsters: ";
                int monsterCount = 0;
                for (auto& monster : monsters) {
                    if (monster.getCurrentLocation()->getName() == player.getCurrentLocation()->getName()) {
                        std::cout << monster.getName() << " (Hitpoints: " << monster.getHitPoints() << ") ";
                        monsterCount++;
                    }
                }
                if (monsterCount == 0){
                    std::cout << "None";
                }
                std::cout << std::endl;
                std::cout << std::endl;
                break;
            }
        }

        // Get command from the player
        std::cout << "Enter a direction ('quit' to end the game): ";
        std::cin >> command;

        // Check for quit command
        if (command == "quit") {
            quit = true;
        }
        else if (command == "collect") {
            // Collect all items in location
            collectItems(player, *player.getCurrentLocation());
        }
        else if (command == "inv" || command == "inventory") {
            // Display inventory
            listInventory(player);
        }
        else if (command == "drink") {
            // Drink all potions
            drinkPotions(player);
        }
        else if (command == "fight") {
            // Fight monster in location
            combat(player, monsters);
        }
        else {
            // Attempt to move the player in the specified direction
            if (player.move(player, command)) {
                std::cout << "You move " << command << "." << std::endl;
                std::cout << "_______________________________________" << std::endl;
                std::cout << std::endl;
            } else {
                std::cout << std::endl;
            }
        }

    }

    // Display player's score at the end of the game
    std::cout << "Your score: " << player.getScore() << std::endl;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(nullptr));

    // Create locations
    std::vector<Location> locations;
    std::vector<Monster> monsters;

    // Create game map
    createMap(locations, monsters);

    // Create player and set default hitpoints
    Player player;
    player.setHitPoints(15);

    // Start the game loop
    gameLoop(player, locations, monsters);

    return 0;
}
