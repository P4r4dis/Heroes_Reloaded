#ifndef     __POWERPOTION_HPP__
    #define __POWERPOTION_HPP__

    #define POWER_CURE 50
    #include "Peasant.hpp"
    class PowerPotion
    {
    private:
        /* data */
    public:
        PowerPotion(void);
        ~PowerPotion();

        int getPowerCure(void) const;
    };
#endif //   !__POWERPOTION_HPP__
