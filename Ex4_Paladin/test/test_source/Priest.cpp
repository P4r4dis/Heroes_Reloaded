#include "../test_include/Priest.hpp"

Priest::Priest(const std::string &name, int power)  : Peasant(name, power),
                                                        Enchanter(name, power)
{
    std::cout << getName() << " enters in the order." << std::endl;
}

Priest::Priest(const Priest &obj)   :   Peasant(obj.getName(), obj.getPower()),
                                        Enchanter(obj.getName(), obj.getPower())
{
}

Priest::~Priest(void)
{
    std::cout << getName() << " finds peace." << std::endl;
}

void                Priest::rest(void)
{
    if (getHp() <= 0)
        std::cout << getName() << " is out of combat." << std::endl;
    else
    {
        setHp(getHp() + PRIEST_BASE_CURE_HP);
        setPower(getPower() + PRIEST_BASE_CURE_POWER);
        std::cout << getName() << " prays." << std::endl;
    }
}