#include "../include/Knight.hpp"

Knight::Knight(const std::string &name, int power) : Peasant(name, power)
{
    std::cout << getName() << " vows to protect the kingdom." << std::endl;
}

Knight::Knight(const Knight &obj) : Peasant(obj.getName(), obj.getPower())
{
}

Knight::~Knight(void)
{
    std::cout << getName() << " takes off his armor." << std::endl;
}


bool                    Knight::isOutForAtk(void)
{
    if (getHp() <= 0)
    {
        std::cout << getName() << " is out of combat." << std::endl;
        return true;
    }
    else if (getPower() < KNIGHT_ATK_COST_POWER)
    {
        std::cout << getName() << " is out of power." << std::endl;
        return true;
    }

    return false;
}

bool                    Knight::isOutForSpc(void)
{
    if (getHp() <= 0)
    {
        std::cout << getName() << " is out of combat." << std::endl;
        return true;
    }
    else if (getPower() == 0 || getPower() < KNIGHT_SPC_COST_POWER)
    {
        std::cout << getName() << " is out of power." << std::endl;
        return true;
    }

    return false;
}

bool                    Knight::isOutForRest(void)
{
    if (getHp() <= 0)
    {
        std::cout << getName() << " is out of combat." << std::endl;
        return true;
    }

    return false;
}

int                     Knight::attack(void)
{
    if (isOutForAtk() == false)
    {
        setPower(getPower() - KNIGHT_ATK_COST_POWER);
        std::cout << getName() << " strikes with his sword." << std::endl;
        return KNIGHT_ATK_DAMAGE;
    }
    else
        return 0;
}

int                     Knight::special(void)
{
    if (isOutForSpc() == false)
    {
        setPower(getPower() - KNIGHT_SPC_COST_POWER);
        std::cout << getName() << " impales his ennemy." << std::endl;
        return KNIGHT_SPC_DAMAGE;
    }
    else
        return 0;
}

void                    Knight::rest(void)
{
    if (isOutForRest() == false)
    {
        setPower(getPower() + KNIGHT_CURE_POWER);
        setHp(getHp() + 0);
        std::cout << getName() << " eats." << std::endl;
    }
}