#ifndef                     __PEASANT_HPP__
    #define                 __PEASANT_HPP__

#include <iostream>

#define BASE_HP 100
#define BASE_POWER 100
#define BASE_COST_POWER 10
#define BASE_CURE_POWER 30
#define BASE_DAMAGE 5

class                       Peasant
{
    public:    
        Peasant(const std::string &name, int power);
        Peasant(const Peasant &obj);
        ~Peasant(void);

        const std::string   &getName() const;
        int                 getHp(void) const;
        int                 getPower(void) const;

        void                setHp(int hp);
        void                setPower(int power);

        bool                isOut(void);
        int                 attack(void);
        int                 special(void);

    private:
        std::string         _name;
        int                 _hp;
        int                 _power;
};
#endif //                   !__PEASANT_HPP__

// int                 getLvl(void) const;
// const std::string   &getClass(void) const;
// const std::string   &getRace(void) const;
// int                 getStrength(void) const;
// int                 getStamina(void) const;
// int                 getIntelligence(void) const;
// int                 getSpirit(void) const;
// int                 getAgility(void) const;

// int                 setLvl(void) const;
// int                 setStrength(void) const;
// int                 setStamina(void) const;
// int                 setIntelligence(void) const;
// int                 setSpirit(void) const;
// int                 setAgility(void) const;
// int                 setPv(void) const;
// int                 setPower(void) const;