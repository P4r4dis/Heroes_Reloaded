#include "../test_include/Knight.hpp"

Knight::Knight(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << getName() << " vows to protect the kingdom." << std::endl;
}

Knight::Knight(const Knight &obj) : Peasant(obj.getName(), obj.getPower())
{}

Knight::~Knight(void)
{
    std::cout << getName() << " takes off his armor." << std::endl;
}

int             Knight::attack(void)
{
    if (!isOut())
    {
        setPower(getPower() - KNIGHT_ATK_COST_POWER);
        std::cout << getName() << " strikes with his sword." << std::endl;
        return KNIGHT_ATK_DMG;
    }
    else
        return 0;
}

int             Knight::special(void)
{
    if (!isOut())
    {
        setPower(getPower() - KNIGHT_SPC_COST_POWER);
        std::cout << getName() << " impales his ennemy." << std::endl;
        return KNIGHT_SPC_DMG;
    }
    else
        return 0;
}