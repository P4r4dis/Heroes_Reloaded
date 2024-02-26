#ifndef     __POISONPOTION_HPP__
    #define __POISONPOTION_HPP__

    #define POISON_DAMAGE 50
    #include "Peasant.hpp"
    class PoisonPotion
    {
    private:
        /* data */
    public:
        PoisonPotion(void);
        ~PoisonPotion();

        int getPoisonDamage(void) const;
    };
#endif //   !__POISONPOTION_HPP__
