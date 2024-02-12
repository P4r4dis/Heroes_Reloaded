#include "../include/Peasant.hpp"
#include "../include/Knight.hpp"
#include "../include/Enchanter.hpp"
#include "../include/Priest.hpp"


int main(void)
{
    Priest priest("Trichelieu", 20);

    priest.attack();
    priest.special();
    priest.rest();
    priest.damage(50);
    return 0;
}