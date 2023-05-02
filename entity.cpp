#include <string>
#include <iostream>
#include <vector>

// A function that takes a min and max, x and y and give you a value between that.
int random(int x, int y) {
    return (rand() % (y - x)) + x;
}

// entity class, general outline for all mobs, npcs, bosses and the player
class entity {
    public:
        std::string named;
        double hitPoints;
        double maxHitPoints;
        int defencePoints;
        int attackPoints;
        int luckPoints;
        int actionPoints;
        int staminaPoints;
        // std::vector<std::string> actions = {": Attack - 3 stamina",": Block + 5 stamina", ": Parry and thrust - 2 Stamina"};
        bool damageStep(entity& attacker);
        void stats();

        entity(std::string name, int stage) {
            named = name;
            hitPoints = random(10 + stage * 2, 30 + stage * 2);
            maxHitPoints = hitPoints;
            defencePoints = random(1 + stage, 5 + stage);
            attackPoints = random(1 + stage, 5 + stage);
            luckPoints = random(1 + stage, 5 + stage);
            actionPoints = random(1 + stage, 2 + stage);
            staminaPoints = 10;
        }
};

// player class, given to the player and there respective characters
class player : public entity {
    public: 
        int level;
        int exp;
        void levelUp();

        // -Ask about the contstructor
        player(std::string name, int stage) 
        : entity(name, stage) {
            level = 1;
            exp = 0;
        }
};

// A function that runs through calculations, having a phase deciding dodge or crit, then calculating damage
bool entity::damageStep(entity& attacker) {
    double modifier = random(1,100);

    if (100 - luckPoints <= modifier) {
        modifier = 0;
        std::cout << "Miss!" << std::endl;
    }
    else if (modifier <= attacker.luckPoints) {
        modifier = 1.5;
        std::cout << "Critcal Hit!" << std::endl;
    }

    std::cout << ((2 * attacker.attackPoints) - (2 * defencePoints)) + 1 * modifier;
    std::cout << " Damage Done!" << std::endl;
    hitPoints -= ((2 * attacker.attackPoints) - (2 * defencePoints)) + 1 * modifier;

    if (hitPoints < 0) {
        std::cout << "Dead!" << std::endl;
    }

    std::cout << "Remaining HP: " <<  hitPoints << std::endl;
    return true;
}

// A function that randomly decides level up bonuses for a player
void player::levelUp() {
    level += 1;  
    hitPoints += random(0, 5);
    maxHitPoints = hitPoints;
    defencePoints += random(0,3);
    attackPoints += random(0,3);
    luckPoints += random(0,2);
    actionPoints += random(0,1);
    std::cout << "Level Up!" << std::endl;
    stats();
}

// A function to display all the stats of a entity
void entity::stats() {
    std::cout << "Hit Points: " << hitPoints << std::endl << "Defence: " << defencePoints << std::endl << "Attack: "<< attackPoints << std::endl << "Luck: " << luckPoints << std::endl << "Action Speed: " << actionPoints << std::endl;
}

