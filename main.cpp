#include <string>
#include <iostream>
#include <cctype>
#include <unistd.h>
#include "entity.cpp"

void damagePhase() {

}

int main() {
    bool running = true;
    std::cout << "Welcome to the Mentor game!" << std::endl;

    std::string name;
    std::cin >> name;
    player p(name);
    
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
