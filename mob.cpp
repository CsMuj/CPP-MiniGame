#include <string>
#include <iostream>
#include <vector>

class mob {
    public:
        std::string name;
        int hitPoints = 10;
        int defencePoints = 1;
        int attackPoints = 1;
        int movePoints = 1;
        std::vector<std::string> special_skills = {"Place Holder"};
};
