#ifndef                 __ENCHANTER_HPP__
    #define             __ENCHANTER_HPP__

#include "Peasant.hpp"

#define ENCHANTER_ATK_COST_POWER 0
#define ENCHANTER_ATK_DMG 0
class                   Enchanter : public Peasant
{
    public:
        Enchanter(const std::string &name, int power);
        Enchanter(const Enchanter &obj);
        ~Enchanter(void);

        int             attack(void);
};
#endif //               !__ENCHANTER_HPP__