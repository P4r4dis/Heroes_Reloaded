
#include "../include/ICharacter.hpp"
#include "../include/Peasant.hpp"
#include "../include/Knight.hpp"
#include "../include/Enchanter.hpp"
#include "../include/Priest.hpp"
#include "../include/Paladin.hpp"


int main(void)
{
    ICharacter  *peasant = new Peasant("Gildas", 42);
    ICharacter  *knight = new Knight("Arthur", 20);
    ICharacter  *enchanter = new Enchanter("Merlin", 20);
    ICharacter  *priest = new Priest("Trichelieu", 20);
    ICharacter  *paladin = new Paladin("Uther", 99);

    peasant->attack();
    knight->special();
    enchanter->rest();
    enchanter->getPower();
    priest->damage(21);

    std::cout   << paladin->getName() << ": "
                << paladin->getHp() << " health points, "
                << paladin->getPower() << " power points."
                << std::endl;

    delete peasant;
    delete knight;
    delete enchanter;
    delete priest;
    delete paladin;
    return 0;
}