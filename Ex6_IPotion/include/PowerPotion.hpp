#ifndef     __POWERPOTION_HPP__
    #define __POWERPOTION_HPP__

    #define POWER_CURE 50

    #include "IPotion.hpp"
    class PowerPotion : virtual public IPotion
    {
    private:
        /* data */
    public:
        PowerPotion(void);
        ~PowerPotion();

        int getValuePotion(void) const;
    };
#endif //   !__POWERPOTION_HPP__
