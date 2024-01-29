#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/Peasant.hpp"


void    redirect_all_stdout(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Peasant, test_Peasant_class_implementation, .init = redirect_all_stdout)
{
    {
        Peasant peasant("Gildas", 42);
        Peasant peasant2(peasant);
        Peasant peasant3("TEST", 110);
        Peasant peasant4("TEST2", -5);

        cr_assert(peasant.getName() == "Gildas");

        cr_assert(peasant.getHp() == 100);
        peasant.setHp(110);
        cr_assert(peasant.getHp() == 100);
        peasant.setHp(-1);
        cr_assert(peasant.getHp() == 0);
        peasant.setHp(100);
        cr_assert(peasant.getHp() == 100);

        cr_assert(peasant.getPower() == 42);
        peasant.setPower(110);
        cr_assert(peasant.getPower() == 100);
        peasant.setPower(-42);
        cr_assert(peasant.getPower() == 0);
        peasant.setPower(42);
        cr_assert(peasant.getPower() == 42);
        
        cr_assert(peasant.getName() == peasant2.getName());
        cr_assert(peasant.getHp() == peasant2.getHp());
        cr_assert(peasant.getPower() == peasant2.getPower());
    }

    cr_assert_stdout_eq_str
    (
        "Gildas goes for an adventure.\n"
        "TEST goes for an adventure.\n"
        "TEST2 goes for an adventure.\n"
        "TEST2 is back to his crops.\n"
        "TEST is back to his crops.\n"
        "Gildas is back to his crops.\n"
        "Gildas is back to his crops.\n"
    );
}

Test(Peasant, test_Peasant_attack, .init = redirect_all_stdout)
{
    {
        Peasant peasant("Gildas", 42);

        cr_assert(peasant.attack() == 5);
        cr_assert(peasant.getPower() == 32);

        peasant.setPower(0);
        cr_assert(peasant.attack() == 0);
        cr_assert(peasant.getPower() == 0);

        peasant.setHp(0);
        cr_assert(peasant.attack() == 0);
        cr_assert(peasant.getHp() == 0);

    }

    cr_assert_stdout_eq_str
    (
        "Gildas goes for an adventure.\n"
        "Gildas tosses a stone.\n"
        "Gildas is out of power.\n"
        "Gildas is out of combat.\n"
        "Gildas is back to his crops.\n"
    );
}

Test(Peasant, test_Peasant_special, .init = redirect_all_stdout)
{
    {
        Peasant peasant("Gildas", 42);

        cr_assert(peasant.getPower() == 42);
        cr_assert(peasant.special() == 0);
        cr_assert(peasant.getPower() == 42);
        peasant.setPower(0);
        cr_assert(peasant.special() == 0);

    }

    cr_assert_stdout_eq_str
    (
        "Gildas goes for an adventure.\n"
        "Gildas doesn't know any special move.\n"
        "Gildas is out of power.\n"
        "Gildas is back to his crops.\n"
    );
}

Test(Peasant, test_Peasant_rest, .init = redirect_all_stdout)
{
    {
        Peasant peasant("Gildas", 42);

        cr_assert(peasant.getPower() == 42);
        peasant.rest();
        cr_assert(peasant.getPower() == 72);
        peasant.rest();
        cr_assert(peasant.getPower() == 100);
    }

    cr_assert_stdout_eq_str
    (
        "Gildas goes for an adventure.\n"
        "Gildas takes a nap.\n"
        "Gildas takes a nap.\n"
        "Gildas is back to his crops.\n"
    );
}