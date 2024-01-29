#include "../test_include/Peasant.hpp"

Peasant::Peasant(const std::string &name, int power)    :   _name(name),
                                                            _hp(BASE_HP),
                                                            _power(power)
{
    std::cout   << _name << " goes for an adventure." << std::endl;
}

Peasant::Peasant(const Peasant &obj)    :   _name(obj._name), _hp(obj._hp),
                                            _power(obj._power)
{}

Peasant::~Peasant(void)
{
    std::cout   << _name << " is back to his crops." << std::endl;
}

const std::string       &Peasant::getName(void) const
{
    return _name;
}

int                     Peasant::getHp(void) const
{
    return _hp;
}

int                     Peasant::getPower(void) const
{
    return _power;
}

void                    Peasant::setHp(int hp)
{
    _hp = hp;
}

void                    Peasant::setPower(int power)
{
    _power = power;
}