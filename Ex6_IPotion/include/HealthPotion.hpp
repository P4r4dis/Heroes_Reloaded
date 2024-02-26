#ifndef     __HEALTHPOTION_HPP__
    #define __HEALTHPOTION_HPP__

    #define HEALTH_CURE 50
    #include "IPotion.hpp"
    class HealthPotion : virtual public IPotion
    {
    private:
        /* data */
    public:
        HealthPotion(void);
        ~HealthPotion();

        int getValuePotion(void) const;
    };
#endif //   !__HEALTHPOTION_HPP__
