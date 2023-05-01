#include <string>
#include <iostream>
#include <vector>
#include <format>

int random(int x, int y) {
    return (rand() % (y - x)) + x;
}

class entity {
    public:
        std::string named;
        double hitPoints;
        double maxHitPoints;
        int defencePoints;
        int attackPoints;
        int luckPoints;
        int actionPoints;
        std::vector<std::string> special_skills;
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
        }
};

class player : public entity {
    public: 
        int staminaPoints;
        int level;
        int exp;
        void levelUp();

        // Ask about the contstructor
        player(std::string name, int stage) 
        : entity(name, stage) {
            staminaPoints = 10;
            level = 1;
            exp = 0;
        }
};

bool entity::damageStep(entity& attacker) {
    int modifier = random(1,100);

    if (100 - luckPoints <= modifier) {
        modifier = 0;
        std::cout << "Miss!" << std::endl;
    }
    else if (modifier <= attacker.luckPoints) {
        modifier = 1.5;
        std::cout << "Critcal Hit!" << std::endl;
    }

    std::cout << (((2 * 15) + 10) / 250) * ((attacker.attackPoints / defencePoints) * 10 + 2) * modifier  << std::endl;
    hitPoints -= (((2 * 15) + 10) / 250) * ((attacker.attackPoints / defencePoints) * 10 + 2) * modifier;

    // if (hitPoints < 0) {
    //     std::cout << "Dead!" << std::endl;
    //     return false;
    // }

    std::cout <<  std::format("Remaining HP: \033[1;31{}\033[0m\n", hitPoints) << std::endl;
    return true;
}

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

void entity::stats() {
    std::cout << "Hit Points: " << hitPoints << std::endl << "Defence: " << defencePoints << std::endl << "Attack: "<< attackPoints << std::endl << "Luck: " << luckPoints << std::endl << "Action Speed: " << actionPoints << std::endl;
}

