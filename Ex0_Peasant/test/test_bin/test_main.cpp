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

        cr_assert(peasant.getName() == "Gildas");

        cr_assert(peasant.getHp() == 100);
        peasant.setHp(110);
        cr_assert(peasant.getHp() == 110);
        peasant.setHp(100);
        cr_assert(peasant.getHp() == 100);

        cr_assert(peasant.getPower() == 42);
        peasant.setPower(110);
        cr_assert(peasant.getPower() == 110);
        peasant.setPower(42);
        cr_assert(peasant.getPower() == 42);

        cr_assert(peasant.getName() == peasant2.getName());
        cr_assert(peasant.getHp() == peasant2.getHp());
        cr_assert(peasant.getPower() == peasant2.getPower());
    }

    cr_assert_stdout_eq_str
    (
        "Gildas goes for an adventure.\n"
        "Gildas is back to his crops.\n"
        "Gildas is back to his crops.\n"
    );
}

