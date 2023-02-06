#include <string>
#include <iostream>
#include <vector>

class entity {
    public:
        std::string name;
        int hitPoints = 10;
        int defencePoints = 1;
        int attackPoints = 1;
        int luckPoints = 1;
        int actionPoints = 1;
        std::vector<std::string> special_skills = {};

        entity(std::string name, int hitpoints, defencePoints, attackPoints, luckPoints, actionsPoints) {
            name = name;
            hitpoints = hitpoints
        }
};

class player : entity {
    public:
        int staminaPoints = 10;
        int level = 1;

        player(int stamina, int level, std::string name, int hitpoints) 
        : entity(name, hitpoints) {
            staminaPoints = stamina;
            level = level;
        }
    
};