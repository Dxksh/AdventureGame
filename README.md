# AdventureGame

This is a basic command-line Adventure Game using C++ and OOP Methods.

About the game: 

1. The game has a fantasy theme, in a style similar to Dungeons and Dragons, consisting 1 of a player that can navigate a series of connected locations (using commands North, South, East, West or N,S,E,W). 
2. The player can collect items such as treasure, potions, weapons and armour, and engage in combat with monsters. 
3. The player’s score in the game increases when they defeat a monster. 
4. The objective of the game is to achieve a high score (by defeating monsters) and to defeat the ’end of level boss’. 
5. The player can leave the game at any point by typing quit. 
6. The player can type inventory or inv to see a list of all the items they hold. 
7. The player can type fight to engage in combat with a monster, or type collect to collect all items in the current room.

The locations are connected as per the map shown below: 

<img width="554" alt="Screenshot 2024-05-16 at 16 42 43" src="https://github.com/Dxksh/AdventureGame/assets/87981776/a1ff906c-ab30-4412-899c-45114c92642e">


There are various items scattered around the map as shown below:

<img width="629" alt="Screenshot 2024-05-16 at 16 44 08" src="https://github.com/Dxksh/AdventureGame/assets/87981776/f1d65238-4ed6-4d5b-9a7a-4ddf582eb69b">


There are also many monsters hiding in locations around the map as shown below: 

<img width="213" alt="Screenshot 2024-05-16 at 16 44 36" src="https://github.com/Dxksh/AdventureGame/assets/87981776/bf528755-4512-4469-8670-5777054796eb">

The rules of combat:
1. Both Monster and Player have a hitpoint value. Once a character’s hitpoint value reaches 0, that character is defeated.
2. The Monster strikes first.
3. Their damage to the player is determined by rolling a standard dice and multiplying the result by 2. (So result can be 0-12).
4. The player’s hitpoint total is reduced by the damage inflicted by the Monster.
5. The player then strikes back -  a dice is rolled, and this is modified by the weapon with the highest power rating. So if the player has a sword with a power of 10, 10 is added to the dice roll to determine damage done to the monster.
6. This cycle continues until either the player or the enemy reaches 0 hitpoints.
7. After each round, the hitpoints of each combatant are displayed to the user.
8. If the player is defeated, the player’s score is shown and the game ends.

There is also a boss monster in the cave. When the boss is defeated, the game ends.


