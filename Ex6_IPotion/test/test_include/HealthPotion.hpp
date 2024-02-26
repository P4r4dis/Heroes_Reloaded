#ifndef     __HEALTHPOTION_HPP__
    #define __HEALTHPOTION_HPP__

    #define HEALTH_CURE 50
    #include "Peasant.hpp"
    class HealthPotion
    {
    private:
        /* data */
    public:
        HealthPotion(void);
        ~HealthPotion();

        int getHpCure(void) const;
    };
#endif //   !__HEALTHPOTION_HPP__
