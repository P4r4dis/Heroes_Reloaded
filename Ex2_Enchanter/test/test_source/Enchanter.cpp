#include "../test_include/Enchanter.hpp"

Enchanter::Enchanter(const std::string &name, int power)    :
                                                                Peasant(name,
                                                                        power)
{
    std::cout << getName() << " learns magic from his spellbook." << std::endl;
}

Enchanter::Enchanter(const Enchanter &obj)  :   Peasant(obj.getName(), 
                                                        obj.getPower())
{}

Enchanter::~Enchanter(void)
{
    std::cout << getName() << " closes his spellbook." << std::endl;
}

int                 Enchanter::attack(void)
{
    if (!isOut())
    {
        setPower(getPower() - ENCHANTER_ATK_COST_POWER);
        std::cout << getName() << " don't know how to fight." << std::endl;
        return ENCHANTER_ATK_DMG;
    }
    else
        return ENCHANTER_ATK_DMG;
}

int                 Enchanter::special(void)
{
    if (!isOut())
    {
        setPower(getPower() - ENCHANTER_SPC_COST_POWER);
        std::cout << getName() << " casts a fireball." << std::endl;
        return ENCHANTER_SPC_DMG;
    }
    else
        return 0;
}