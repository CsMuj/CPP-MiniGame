#include <string>
#include <iostream>
#include <time.h>
#include "entity.cpp"

void damagePhase() {

}

void playerInitalization() {
    std::cout << "What name will you chose?" << std::endl;
    std::string name;
    std::cin >> name;
    player p(name);
    std::cout << "Here are your Stats!" << std::endl;
    p.stats();
}

int main() {
    bool running = true;
    std::cout << "Welcome to the Mentor game!" << std::endl;
    srand(time(NULL));

    playerInitalization();
    

    
    while (running == true) {
        int amount;
        std::cout << "How many battles would you like to commence? [+0.1x Mulitplier per Battle]: " << std::endl;
        std::cin >> amount;

        for (int i = 0; i == amount; i++){
            entity mob("Mob");
            mob.stats();
        }
        

    


        std::string answer;
        std::cout << std::endl << "Would you like to Continue? [y/n]" << std::endl;
        std::cin >> answer;
        running = (answer == "y" ) ? true : false;
    };
        
    return 0;
}
