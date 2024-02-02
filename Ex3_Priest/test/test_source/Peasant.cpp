#include "../test_include/Peasant.hpp"

Peasant::Peasant(const std::string &name, int power)    :   _name(name),
                                                            _hp(BASE_HP)
{
    if (power > BASE_POWER)
        _power = BASE_POWER;
    else if (power < 0)
        _power = 0;
    else
        _power = power;
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
    if (hp > BASE_HP)
        _hp = BASE_HP;
    else if (hp < 0)
        _hp = 0;
    else
        _hp = hp;
}

void                    Peasant::setPower(int power)
{
    if (power > BASE_POWER)
        _power = BASE_POWER;
    else if (power < 0)
        _power = 0;
    else
        _power = power;
}

bool                    Peasant::isOut(void)
{
    if (_hp <= 0)
    {
        std::cout << _name << " is out of combat." << std::endl;
        return true;
    }
    else if (_power <= BASE_COST_POWER)
    {
        std::cout << _name << " is out of power." << std::endl;
        return true;      
    }
    else
        return false;
}

int                     Peasant::attack(void)
{
    if (isOut() == false)
    {
        _power -= BASE_COST_POWER;
        std::cout << _name << " tosses a stone." << std::endl;
        return BASE_DAMAGE;
    }
    else
        return 0;
}

int                     Peasant::special(void)
{
    if (isOut() == false)
    {
        _power -= 0;
        std::cout << _name << " doesn't know any special move." << std::endl;
        return 0;
    }
    else
        return 0;

}

void                    Peasant::rest(void)
{
    if (_power >= 0 && _power <= BASE_POWER)
    {
        _power += BASE_CURE_POWER;
        if (_power > BASE_POWER)
            _power = BASE_POWER;
        std::cout << _name << " takes a nap." << std::endl;
    }
}

void                    Peasant::damage(int damage)
{
    if (isOut() == false)
    {
        _hp -= damage;
        if (isOut() == false)
            std::cout << _name << " takes " << damage << " damage." << std::endl;
        else
            isOut();
        if (_hp < 0)
            _hp = 0;
    }
}