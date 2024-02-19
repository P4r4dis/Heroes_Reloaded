
#include "../include/Paladin.hpp"

int main(void)
{
    Paladin paladin("Uther", 99);

    paladin.attack();
    paladin.special();
    paladin.rest();
    paladin.damage(50);
    return 0;
}