#include "../test_include/Knight.hpp"

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

