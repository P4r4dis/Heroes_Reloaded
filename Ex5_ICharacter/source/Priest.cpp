#include "../include/Priest.hpp"

Priest::Priest(const std::string &name, int power)  :   Peasant(name, power),
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

void                    Priest::rest(void)
{
    if (isOutForRest() == false)
    {
        setPower(getPower() + PRIEST_CURE);
        setHp(getHp() + PRIEST_CURE);
        std::cout << getName() << " prays." << std::endl;
    }
}