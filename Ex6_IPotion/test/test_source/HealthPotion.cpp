#include "../test_include/HealthPotion.hpp"

HealthPotion::HealthPotion(void)
{
}

HealthPotion::~HealthPotion()
{
}
    
int    HealthPotion::getHpCure(void) const
{
    return HEALTH_CURE;
}
    