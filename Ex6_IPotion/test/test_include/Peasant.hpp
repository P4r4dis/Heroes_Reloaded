#ifndef                     __PEASANT_HPP__
    #define                 __PEASANT_HPP__

#define PEASANT_HP 100
#define PEASANT_POWER 100

#define PEASANT_ATK_COST_POWER 10
#define PEASANT_ATK_DAMAGE 5

#define PEASANT_SPC_COST_POWER 0
#define PEASANT_SPC_DAMAGE 0

#define PEASANT_CURE_COST_POWER 0
#define PEASANT_CURE_POWER 30

#include <iostream>
#include "ICharacter.hpp"

class                       Peasant : public ICharacter {
    public:
        Peasant(const std::string &name, int power);
        Peasant(const Peasant &obj);
        ~Peasant(void);

        const std::string &getName() const;
        int getHp(void) const;
        int getPower(void) const;

        void setHp(int hp);
        void setPower(int power);

        bool                    isOutForAtk(void);
        bool                    isOutForSpc(void);
        bool                    isOutForRest(void);

        int                     attack(void);
        int                     special(void);
        void                    rest(void);

        void                    damage(int damage);

        void                    drink(const PoisonPotion& potion);
        void                    drink(const PowerPotion& potion);
        void                    drink(const HealthPotion& potion);
        void                    drink(const IPotion& potion);
    private:
        std::string             _name;
        int                     _hp;
        int                     _power;
};
#endif //                   !__PEASANT_HPP__