#include <string>
#include <iostream>
#include <time.h>
#include "entity.cpp"

// player playerInitalization() {
//     std::cout << "What name will you chose?" << std::endl;
//     std::string name;
//     std::cin >> name;
//     player pla(name, 0);
//     std::cout << "Here are your Stats!" << std::endl;
//     pla.stats();
// }

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
            std::cout << "Battle Commences!" << std::endl;

            while (pla.hitPoints > 0 or mob.hitPoints > 0)
            {   
                std::string action;
                std::cout << "What will you do...? : Attack " << std::endl;
                std::cin >> action;
                if (action == "Attack") {
                    mob.damageStep(pla);
                }
                pla.damageStep(mob);   
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

