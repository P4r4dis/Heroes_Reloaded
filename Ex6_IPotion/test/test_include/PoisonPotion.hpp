#ifndef     __POISONPOTION_HPP__
    #define __POISONPOTION_HPP__

    #define POISON_DAMAGE 50
    #include "IPotion.hpp"
    class PoisonPotion :  virtual public IPotion
    {
    private:
        /* data */
    public:
        PoisonPotion(void);
        ~PoisonPotion();

        int getValuePotion(void) const;
    };
#endif //   !__POISONPOTION_HPP__
