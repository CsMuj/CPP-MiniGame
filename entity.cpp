#include <string>
#include <iostream>
#include <vector>

int random(int x, int y) {
    return (rand() % (y - x)) + x;
}

class entity {
    public:
        std::string named;
        double hitPoints;
        int defencePoints;
        int attackPoints;
        int luckPoints;
        int actionPoints;
        std::vector<std::string> special_skills;
        bool damageStep(entity& attacker);
        void stats();

        entity(std::string name) {
            named = name;
            hitPoints = random(10, 30);
            defencePoints = random(1,5);
            attackPoints = random(1,5);
            luckPoints = random(1,5);
            actionPoints = random(1,2);
        }
};

class player : public entity {
    public: 
        int staminaPoints;
        int level;
        void levelUp();

        player(std::string name) 
        : entity(name) {
            staminaPoints = 10;
            level = 1;
        }
};

bool entity::damageStep(entity& attacker) {
    int chance = random(1,100);

    if (100 - luckPoints <= chance) {
        chance = 0;
        std::cout << "Miss!" << std::endl;
    }
    else if (chance <= attacker.luckPoints) {
        chance = 2;
        std::cout << "Critcal Hit!" << std::endl;
    }

    hitPoints = hitPoints - ((5 * (attacker.attackPoints / 100 + 1)) / (defencePoints / 100 + 1)) * chance;

    if (hitPoints < 0) {
        std::cout << "Dead!" << std::endl;
        return false;
    }

    std::cout << "Remaining HP:  " << hitPoints << std::endl;
    return true;
}

void player::levelUp() {
    for (int i = 1; i > 1; i++) {
        level += 1;  
        hitPoints = random(10, 30);
        defencePoints = random(1,5);
        attackPoints = random(1,5);
        luckPoints = random(1,5);
        actionPoints = random(1,2);
    }

}

void entity::stats() {
    std::cout << hitPoints << std::endl << defencePoints << std::endl << attackPoints << std::endl << luckPoints << std::endl << actionPoints << std::endl;
}

