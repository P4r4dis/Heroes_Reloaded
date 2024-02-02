#include "../test_include/Priest.hpp"

Priest::Priest(const std::string &name, int power)  : Enchanter(name, power)
{
    std::cout << getName() << " enters in the order." << std::endl;
}

Priest::Priest(const Priest &obj)   :   Enchanter(obj.getName(), obj.getPower())
{
}

Priest::~Priest(void)
{
    std::cout << getName() << " finds peace." << std::endl;
}