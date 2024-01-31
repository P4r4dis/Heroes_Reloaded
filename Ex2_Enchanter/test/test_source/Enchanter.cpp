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