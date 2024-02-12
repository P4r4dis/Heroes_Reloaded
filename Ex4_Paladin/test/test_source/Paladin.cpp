#include "../test_include/Paladin.hpp"

Paladin::Paladin(const std::string &name, int power)    :   Peasant(name, power),
                                                            Knight(name, power),
                                                            Priest(name, power)
{
    std::cout << getName() << " fights for the light." << std::endl;
}

Paladin::Paladin(const Paladin &obj)    :   Peasant(obj.getName(), obj.getPower()),
                                            Knight(obj.getName(), obj.getPower()),
                                            Priest(obj.getName(), obj.getPower())
{}

Paladin::~Paladin(void)
{
    std::cout << getName() << " is blessed." << std::endl;
}