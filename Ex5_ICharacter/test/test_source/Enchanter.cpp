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

bool                    Enchanter::isOutForAtk(void)
{
    if (getHp() <= 0)
    {
        std::cout << getName() << " is out of combat." << std::endl;
        return true;
    }

    return false;
}

bool                    Enchanter::isOutForSpc(void)
{
    if (getHp() <= 0)
    {
        std::cout << getName() << " is out of combat." << std::endl;
        return true;
    }
    else if (getPower() == 0 || getPower() < ENCHANTER_SPC_COST_POWER)
    {
        std::cout << getName() << " is out of power." << std::endl;
        return true;
    }

    return false;
}

bool                    Enchanter::isOutForRest(void)
{
    if (getHp() <= 0)
    {
        std::cout << getName() << " is out of combat." << std::endl;
        return true;
    }

    return false;
}

int                     Enchanter::attack(void)
{
    if (isOutForAtk() == false)
    {
        setPower(getPower() - ENCHANTER_ATK_COST_POWER);
        std::cout << getName() << " don't know how to fight." << std::endl;
        return ENCHANTER_ATK_DAMAGE;
    }
    else
        return 0;
}

int                     Enchanter::special(void)
{
    if (isOutForSpc() == false)
    {
        setPower(getPower() - ENCHANTER_SPC_COST_POWER);
        std::cout << getName() << " casts a fireball." << std::endl;
        return ENCHANTER_SPC_DAMAGE;
    }
    else
        return 0;
}

void                    Enchanter::rest(void)
{
    if (isOutForRest() == false)
    {
        setPower(getPower() + ENCHANTER_CURE_POWER);
        setHp(getHp() + 0);
        std::cout << getName() << " meditates." << std::endl;
    }
}