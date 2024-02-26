
#include "../include/ICharacter.hpp"
#include "../include/Peasant.hpp"
#include "../include/Knight.hpp"
#include "../include/Enchanter.hpp"
#include "../include/Priest.hpp"
#include "../include/Paladin.hpp"


int main(void)
{
    ICharacter      *peasant = new Peasant("Gildas", 42);
    PoisonPotion    poison_potion;
    PowerPotion     power_potion;
    HealthPotion    health_potion;
    IPotion&        potion = health_potion;

    std::cout   << peasant->getName() << ": " << peasant->getHp()
                << "HP, " << peasant->getPower() << " PP." << std::endl;
    peasant->drink(poison_potion);
    std::cout   << peasant->getName() << ": " << peasant->getHp()
                << "HP, " << peasant->getPower() << " PP." << std::endl;   
    peasant->drink(potion);
    std::cout   << peasant->getName() << ": " << peasant->getHp()
                << "HP, " << peasant->getPower() << " PP." << std::endl;

    delete peasant;
    
    return 0;
}