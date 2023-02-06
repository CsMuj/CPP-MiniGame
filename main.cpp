#include <string>
#include <iostream>
#include <time.h>
#include "entity.cpp"

int random(int x, int y) {
    return (rand() % (y - x)) + x;
}

int main() {
    bool on = true;

    std::string name;
    std::cin >> name;
    player p = {name, random(10, 30), random(1,5), random(1,5), random(1,5), random(1,2)};
    // while (on) {

    std::cout << "My player's stamina is " << p.staminaPoints << "\n";
    // };

    return 0;
}
