#include <string>
#include <iostream>
#include <time.h>
#include "entity.cpp"

void actionStep(entity& subject1, entity& subject2) {
    std::string action = "Attack";
    int j = subject1.actionPoints; 
    int k = subject2.actionPoints;
    std::cout << "Into the frey!" << std::endl;

    for (int i = 0; j - k >= 0 and i <= 0; i++) {

        if (dynamic_cast<entity*>(&subject1)) {
            std::cout << "What will you do...? : Attack - 2 stamina : Block + 5 stamina : Wild Rush - 1 stamina " << std::endl;
            std::cin >> action;
        }
        
        if (action == "Attack" and subject1.staminaPoints > 3) {
            subject1.staminaPoints -= 3;
            subject2.damageStep(subject1);
        }
        else if (action == "Block" or not dynamic_cast<entity*>(&subject1)) {
            subject1.staminaPoints += 5;
        }
        else if (action == "Wild Rush"){
            std::cout << "Enter a number between 1 and 10 to see if you succeded Rushing!" << std::endl;
            int quickTime;
            std::cin >> quickTime; 
            if (quickTime == random(1,10)) {
                subject1.staminaPoints -= 1;
                subject2.damageStep(subject1);  
            }
        }

        if (subject2.hitPoints <= 0) {
            break;
        }
        j -= k;  
    }
}

int main() {
    std::cout << "Welcome to the Mentor game!" << std::endl;
    srand(time(NULL));

    // playerInitalization();
    std::cout << "What name will you chose?" << std::endl;
    std::string name;
    std::cin >> name;
    player pla(name, 0);
    std::cout << "Here are your Stats!" << std::endl;
    pla.stats();
    
    while (true) {
        int amount;
        std::cout << "How many battles would you like to commence? [+0.1x Mulitplier per Battle]: " << std::endl;
        std::cin >> amount;

        for (int i = 0; i != amount; i++){
            entity mob("Mob", i);
            std::cout << "Mob Stats!" << std::endl;
            mob.stats();
            std::cout << "Battle Commences!" << std::endl;

            while (pla.hitPoints >= 0 and mob.hitPoints >= 0)
            {   
                if (pla.actionPoints > mob.actionPoints or pla.actionPoints == mob.actionPoints) {
                    std::cout << "You Go!" << std::endl;
                    actionStep(pla, mob);
                }
                else {
                    std::cout << "Enemey Goes!" << std::endl;
                    actionStep(mob, pla);
                }
                    
            }
            if (mob.hitPoints <= 0) {
                std::cout << "You Win!" << std::endl;
                pla.exp += mob.hitPoints;
                if (pla.exp >= 10) {
                    for (i = pla.exp; i < 10; i -= 10)
                    pla.exp -= 10;
                    std::cout << "Level Up!" << std::endl;
                    pla.levelUp();
                    pla.stats();
                }
            }
            else {
                std::cout << "you lose.." << std::endl;
            }
            pla.hitPoints = pla.maxHitPoints;
        }
        

    


        std::string answer;
        std::cout << std::endl << "Would you like to Continue? [y/n]" << std::endl;
        std::cin >> answer;
        if (answer == "n" or answer == "no") {
            break;
        }
    };
        
    return 0;
}

