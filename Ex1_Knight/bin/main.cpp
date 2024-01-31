#include "../include/Peasant.hpp"
#include "../include/Knight.hpp"


int main(void)
{
    Knight knight("Arthur", 20);

    knight.attack();
    knight.special();
    knight.rest();
    knight.special();
    knight.damage(50);
    return 0;
}