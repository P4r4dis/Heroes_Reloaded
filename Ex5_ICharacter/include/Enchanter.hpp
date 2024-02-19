#ifndef                 __ENCHANTER_HPP__
    #define             __ENCHANTER_HPP__

#include "Peasant.hpp"

#define ENCHANTER_ATK_COST_POWER 0
#define ENCHANTER_ATK_DMG 0

#define ENCHANTER_SPC_COST_POWER 50
#define ENCHANTER_SPC_DMG 99

#define ENCHANTER_CURE_COST_POWER 0
#define ENCHANTER_CURE_POWER 100
class                   Enchanter : virtual public Peasant
{
    public:
        Enchanter(const std::string &name, int power);
        Enchanter(const Enchanter &obj);
        ~Enchanter(void);
    
        int attack(void);
        int special(void);
        void rest(void);
        virtual bool isOut(void) override; // virtual and override
};
#endif //               !__ENCHANTER_HPP__