#include <string>
#include <iostream>
#include <unistd.h>
#include "entity.cpp"

int main() {
    bool on = true;

    std::string name;
    std::cin >> name;
    player p(name);
    entity mob("mob");

    mob.damageStep(p);

    return 0;
}
