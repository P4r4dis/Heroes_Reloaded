#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/Peasant.hpp"
#include "../test_include/Knight.hpp"


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

Test(Peasant, test_Peasant_damage, .init = redirect_all_stdout)
{
    {
        Peasant peasant("Gildas", 42);
        peasant.damage(50);
        cr_assert(peasant.getHp() == 50);
        peasant.damage(100);
        cr_assert(peasant.getHp() == 0);
        peasant.damage(100);
        cr_assert(peasant.getHp() == 0);
    }

    cr_assert_stdout_eq_str
    (
        "Gildas goes for an adventure.\n"
        "Gildas takes 50 damage.\n"
        "Gildas is out of combat.\n"
        "Gildas is out of combat.\n"
        "Gildas is out of combat.\n"
        "Gildas is back to his crops.\n"
    );
}

Test(Peasant, test_Peasant_mainFunction, .init = redirect_all_stdout)
{
    {
        Peasant peasant("Gildas", 42);
        peasant.damage(50);
        cr_assert(peasant.getHp() == 50);
        peasant.damage(100);
        cr_assert(peasant.getHp() == 0);
        peasant.damage(100);
        cr_assert(peasant.getHp() == 0);
    }

    cr_assert_stdout_eq_str
    (
        "Gildas goes for an adventure.\n"
        "Gildas takes 50 damage.\n"
        "Gildas is out of combat.\n"
        "Gildas is out of combat.\n"
        "Gildas is out of combat.\n"
        "Gildas is back to his crops.\n"
    );
}

Test(Knight, test_Knight_class_implementation, .init = redirect_all_stdout)
{
    {
        Knight knight("Arthur", 20);

        cr_assert(knight.getName() == "Arthur");

        Knight knight2(knight);

        cr_assert(knight.getHp() == 100);
        knight.setHp(110);
        cr_assert(knight.getHp() == 100);
        knight.setHp(-1);
        cr_assert(knight.getHp() == 0);
        knight.setHp(100);
        cr_assert(knight.getHp() == 100);

        cr_assert(knight.getPower() == 20);
        knight.setPower(110);
        cr_assert(knight.getPower() == 100);
        knight.setPower(-42);
        cr_assert(knight.getPower() == 0);
        knight.setPower(20);
        cr_assert(knight.getPower() == 20);
        
        cr_assert(knight.getName() == knight2.getName());
        cr_assert(knight.getHp() == knight2.getHp());
        cr_assert(knight.getPower() == knight2.getPower());
    }

    cr_assert_stdout_eq_str
    (
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur goes for an adventure.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(Knight, test_Knight_attack, .init = redirect_all_stdout)
{
    {
        Knight knight("Arthur", 20);

        cr_assert(knight.getPower() == 20);
        cr_assert(knight.attack() == 20);
        cr_assert(knight.getPower() == 10);
        knight.setPower(0);
        cr_assert(knight.attack() == 0);
    }

    cr_assert_stdout_eq_str
    (
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur strikes with his sword.\n"
        "Arthur is out of power.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(Knight, test_Knight_special, .init = redirect_all_stdout)
{
    {
        Knight knight("Arthur", 30);

        cr_assert(knight.getPower() == 30);
        cr_assert(knight.special() == 50);
        cr_assert(knight.getPower() == 0);
        cr_assert(knight.special() == 0);
        cr_assert(knight.getPower() == 0);
    }

    cr_assert_stdout_eq_str
    (
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur impales his ennemy.\n"
        "Arthur is out of power.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(Knight, test_Knight_rest, .init = redirect_all_stdout)
{
    {
        Knight knight("Arthur", 20);

        cr_assert(knight.getPower() == 20);
        cr_assert(knight.attack() == 20);
        cr_assert(knight.getPower() == 10);
        cr_assert(knight.special() == 0);
        cr_assert(knight.getPower() == 10);
        knight.rest();
        cr_assert(knight.getPower() == 60);
        cr_assert(knight.special() == 50);
        cr_assert(knight.getPower() == 30);
        knight.rest();
        cr_assert(knight.getPower() == 80);
        knight.rest();
        cr_assert(knight.getPower() == 100);
    }

    cr_assert_stdout_eq_str
    (
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur strikes with his sword.\n"
        "Arthur is out of power.\n"
        "Arthur eats.\n"
        "Arthur impales his ennemy.\n"
        "Arthur eats.\n"
        "Arthur eats.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}

Test(Knight, test_Knight_damage, .init = redirect_all_stdout)
{
    {
        Knight knight("Arthur", 20);

        cr_assert(knight.getPower() == 20);
        cr_assert(knight.attack() == 20);
        cr_assert(knight.getPower() == 10);
        cr_assert(knight.special() == 0);
        cr_assert(knight.getPower() == 10);
        knight.rest();
        cr_assert(knight.getPower() == 60);
        cr_assert(knight.special() == 50);
        cr_assert(knight.getPower() == 30);
        knight.damage(50);
        cr_assert(knight.getHp() == 50);
    }

    cr_assert_stdout_eq_str
    (
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur strikes with his sword.\n"
        "Arthur is out of power.\n"
        "Arthur eats.\n"
        "Arthur impales his ennemy.\n"
        "Arthur takes 50 damage.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
    );
}