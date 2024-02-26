#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/Peasant.hpp"
#include "../test_include/Knight.hpp"
#include "../test_include/Enchanter.hpp"
#include "../test_include/Priest.hpp"
#include "../test_include/Paladin.hpp"
#include "../test_include/ICharacter.hpp"


void redirect_all_stdout(void)
{
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

    cr_assert_stdout_eq_str(
        "Gildas goes for an adventure.\n"
        "TEST goes for an adventure.\n"
        "TEST2 goes for an adventure.\n"
        "TEST2 is back to his crops.\n"
        "TEST is back to his crops.\n"
        "Gildas is back to his crops.\n"
        "Gildas is back to his crops.\n");
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

    cr_assert_stdout_eq_str(
        "Gildas goes for an adventure.\n"
        "Gildas tosses a stone.\n"
        "Gildas is out of power.\n"
        "Gildas is out of combat.\n"
        "Gildas is back to his crops.\n");
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
        peasant.setHp(0);
        cr_assert(peasant.special() == 0);


    }

    cr_assert_stdout_eq_str(
        "Gildas goes for an adventure.\n"
        "Gildas doesn't know any special move.\n"
        "Gildas is out of power.\n"
        "Gildas is out of combat.\n"
        "Gildas is back to his crops.\n");
}

Test(Peasant, test_Peasant_rest, .init = redirect_all_stdout)
{
    {
        Peasant peasant("Gildas", 42);

        cr_assert(peasant.getPower() == 42);
        peasant.rest();
        cr_assert(peasant.getPower() == 72);
        peasant.setHp(0);
        peasant.rest();
        cr_assert(peasant.getPower() == 72);
    }

    cr_assert_stdout_eq_str(
        "Gildas goes for an adventure.\n"
        "Gildas takes a nap.\n"
        "Gildas is out of combat.\n"
        "Gildas is back to his crops.\n");
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

    cr_assert_stdout_eq_str(
        "Gildas goes for an adventure.\n"
        "Gildas takes 50 damage.\n"
        "Gildas is out of combat.\n"
        "Gildas is out of combat.\n"
        "Gildas is out of combat.\n"
        "Gildas is back to his crops.\n");
}

Test(Peasant, test_Peasant_mainFunction, .init = redirect_all_stdout)
{
    {
        Peasant peasant("Gildas", 42);
        peasant.damage(50);
        cr_assert(peasant.getHp() == 50);
        peasant.damage(100);
        cr_assert(peasant.getHp() == 0);
        peasant.damage(20);
        cr_assert(peasant.getHp() == 0);
    }

    cr_assert_stdout_eq_str(
        "Gildas goes for an adventure.\n"
        "Gildas takes 50 damage.\n"
        "Gildas is out of combat.\n"
        "Gildas is out of combat.\n"
        "Gildas is out of combat.\n"
        "Gildas is back to his crops.\n");
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

    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur goes for an adventure.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n");
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
        knight.setHp(0);
        cr_assert(knight.attack() == 0);
    }

    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur strikes with his sword.\n"
        "Arthur is out of power.\n"
        "Arthur is out of combat.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n");
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
        knight.setHp(0);
        cr_assert(knight.special() == 0);
    }

    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur impales his ennemy.\n"
        "Arthur is out of power.\n"
        "Arthur is out of combat.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n");
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
        knight.setHp(0);
        knight.rest();
    }

    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur strikes with his sword.\n"
        "Arthur is out of power.\n"
        "Arthur eats.\n"
        "Arthur impales his ennemy.\n"
        "Arthur eats.\n"
        "Arthur eats.\n"
        "Arthur is out of combat.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n");
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

    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur strikes with his sword.\n"
        "Arthur is out of power.\n"
        "Arthur eats.\n"
        "Arthur impales his ennemy.\n"
        "Arthur takes 50 damage.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n");
}

Test(Knight, test_Knight_mainFunction, .init = redirect_all_stdout)
{
    {
        Knight knight("Arthur", 20);

        cr_assert(knight.attack() == 20);
        cr_assert(knight.special() == 0);
        knight.rest();
        cr_assert(knight.special() == 50);
        knight.damage(50);
    }

    cr_assert_stdout_eq_str(
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Arthur strikes with his sword.\n"
        "Arthur is out of power.\n"
        "Arthur eats.\n"
        "Arthur impales his ennemy.\n"
        "Arthur takes 50 damage.\n"
        "Arthur takes off his armor.\n"
        "Arthur is back to his crops.\n");
}

Test(Enchanter, test_Enchanter_class_implementation, .init = redirect_all_stdout)
{
    {
        Enchanter enchanter("Merlin", 20);

        cr_assert(enchanter.getName() == "Merlin");

        Enchanter enchanter2(enchanter);

        cr_assert(enchanter.getHp() == 100);
        enchanter.setHp(110);
        cr_assert(enchanter.getHp() == 100);
        enchanter.setHp(-1);
        cr_assert(enchanter.getHp() == 0);
        enchanter.setHp(100);
        cr_assert(enchanter.getHp() == 100);

        cr_assert(enchanter.getPower() == 20);
        enchanter.setPower(110);
        cr_assert(enchanter.getPower() == 100);
        enchanter.setPower(-42);
        cr_assert(enchanter.getPower() == 0);
        enchanter.setPower(20);
        cr_assert(enchanter.getPower() == 20);

        cr_assert(enchanter.getName() == enchanter2.getName());
        cr_assert(enchanter.getHp() == enchanter2.getHp());
        cr_assert(enchanter.getPower() == enchanter2.getPower());
    }

    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin goes for an adventure.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n");
}

Test(Enchanter, test_Enchanter_attack, .init = redirect_all_stdout)
{
    {
        Enchanter enchanter("Merlin", 20);

        cr_assert(enchanter.getPower() == 20);
        cr_assert(enchanter.attack() == 0);
        cr_assert(enchanter.getPower() == 20);
        enchanter.setHp(0);
        cr_assert(enchanter.attack() == 0);
        enchanter.isOutForAtk();
    }

    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin don't know how to fight.\n"
        "Merlin is out of combat.\n"
        "Merlin is out of combat.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n");
}

Test(Enchanter, test_Enchanter_special, .init = redirect_all_stdout)
{
    {
        Enchanter enchanter("Merlin", 50);

        cr_assert(enchanter.getPower() == 50);
        cr_assert(enchanter.special() == 99);
        cr_assert(enchanter.getPower() == 0);
        cr_assert(enchanter.special() == 0);
        cr_assert(enchanter.getPower() == 0);
        enchanter.setHp(0);
        cr_assert(enchanter.special() == 0);

    }

    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin casts a fireball.\n"
        "Merlin is out of power.\n"
        "Merlin is out of combat.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n");
}

Test(Enchanter, test_Enchanter_rest, .init = redirect_all_stdout)
{
    {
        Enchanter enchanter("Merlin", 20);

        cr_assert(enchanter.getPower() == 20);
        cr_assert(enchanter.attack() == 0);
        cr_assert(enchanter.getPower() == 20);

        cr_assert(enchanter.special() == 0);
        cr_assert(enchanter.getPower() == 20);
        enchanter.rest();
        cr_assert(enchanter.getPower() == 100);
        cr_assert(enchanter.special() == 99);
        cr_assert(enchanter.getPower() == 50);
        enchanter.rest();
        cr_assert(enchanter.getPower() == 100);
    }

    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin don't know how to fight.\n"
        "Merlin is out of power.\n"
        "Merlin meditates.\n"
        "Merlin casts a fireball.\n"
        "Merlin meditates.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n");
}

Test(Enchanter, test_Enchanter_main, .init = redirect_all_stdout)
{
    {
        Enchanter enchanter("Merlin", 20);

        cr_assert(enchanter.getPower() == 20);
        cr_assert(enchanter.attack() == 0);
        cr_assert(enchanter.getPower() == 20);

        cr_assert(enchanter.special() == 0);
        cr_assert(enchanter.getPower() == 20);

        enchanter.rest();
        cr_assert(enchanter.getPower() == 100);

        cr_assert(enchanter.special() == 99);
        cr_assert(enchanter.getPower() == 50);

        enchanter.damage(50);
        cr_assert(enchanter.getHp() == 50);
    }

    cr_assert_stdout_eq_str(
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Merlin don't know how to fight.\n"
        "Merlin is out of power.\n"
        "Merlin meditates.\n"
        "Merlin casts a fireball.\n"
        "Merlin takes 50 damage.\n"
        "Merlin closes his spellbook.\n"
        "Merlin is back to his crops.\n");
}

Test(Priest, test_Priest_class_implementation, .init = redirect_all_stdout)
{
    {
        Priest priest("Trichelieu", 20);

        cr_assert(priest.getName() == "Trichelieu");

        Priest priest2(priest);

        cr_assert(priest.getHp() == 100);
        priest.setHp(110);
        cr_assert(priest.getHp() == 100);
        priest.setHp(-1);
        cr_assert(priest.getHp() == 0);
        priest.setHp(100);
        cr_assert(priest.getHp() == 100);

        cr_assert(priest.getPower() == 20);
        priest.setPower(110);
        cr_assert(priest.getPower() == 100);
        priest.setPower(-42);
        cr_assert(priest.getPower() == 0);
        priest.setPower(20);
        cr_assert(priest.getPower() == 20);

        cr_assert(priest.getName() == priest2.getName());
        cr_assert(priest.getHp() == priest2.getHp());
        cr_assert(priest.getPower() == priest2.getPower());
    }

    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n");
}

Test(Priest, test_Priest_attack, .init = redirect_all_stdout)
{
    {
        Priest priest("Trichelieu", 20);

        cr_assert(priest.attack() == 0);
    }

    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu don't know how to fight.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n");
}

Test(Priest, test_Priest_special, .init = redirect_all_stdout)
{
    {
        Priest priest("Trichelieu", 20);

        cr_assert(priest.attack() == 0);
        cr_assert(priest.special() == 0);
        priest.setPower(100);
        cr_assert(priest.getPower() == 100);
        cr_assert(priest.special() == 99);
    }

    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu don't know how to fight.\n"
        "Trichelieu is out of power.\n"
        "Trichelieu casts a fireball.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n");
}

Test(Priest, test_Priest_rest, .init = redirect_all_stdout)
{
    {
        Priest priest("Trichelieu", 20);

        cr_assert(priest.attack() == 0);
        cr_assert(priest.special() == 0);
        priest.rest();
        cr_assert(priest.getHp() == 100);
        cr_assert(priest.getPower() == 100);
        priest.setHp(0);
        priest.rest();
    }

    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu don't know how to fight.\n"
        "Trichelieu is out of power.\n"
        "Trichelieu prays.\n"
        "Trichelieu is out of combat.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n");
}

Test(Priest, test_Priest_damage, .init = redirect_all_stdout)
{
    {
        Priest priest("Trichelieu", 20);

        cr_assert(priest.attack() == 0);
        cr_assert(priest.special() == 0);
        priest.rest();
        cr_assert(priest.getHp() == 100);
        cr_assert(priest.getPower() == 100);
        priest.damage(50);
    }

    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu don't know how to fight.\n"
        "Trichelieu is out of power.\n"
        "Trichelieu prays.\n"
        "Trichelieu takes 50 damage.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n");
}

Test(Priest, test_Priest_main, .init = redirect_all_stdout)
{
    {
        Priest priest("Trichelieu", 20);

        cr_assert(priest.attack() == 0);
        cr_assert(priest.special() == 0);
        priest.rest();
        cr_assert(priest.getHp() == 100);
        cr_assert(priest.getPower() == 100);
        priest.damage(50);
    }

    cr_assert_stdout_eq_str(
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Trichelieu don't know how to fight.\n"
        "Trichelieu is out of power.\n"
        "Trichelieu prays.\n"
        "Trichelieu takes 50 damage.\n"
        "Trichelieu finds peace.\n"
        "Trichelieu closes his spellbook.\n"
        "Trichelieu is back to his crops.\n");
}

Test(Paladin, test_Paladin_class_implementation, .init = redirect_all_stdout)
{
    {
        Paladin paladin("Uther", 99);
        Paladin paladin2(paladin);

        cr_assert(paladin.getName() == "Uther");

        cr_assert(paladin.getHp() == 100);
        paladin.setHp(110);
        cr_assert(paladin.getHp() == 100);
        paladin.setHp(-1);
        cr_assert(paladin.getHp() == 0);
        paladin.setHp(100);
        cr_assert(paladin.getHp() == 100);

        cr_assert(paladin.getPower() == 99);
        paladin.setPower(110);
        cr_assert(paladin.getPower() == 100);
        paladin.setPower(-42);
        cr_assert(paladin.getPower() == 0);
        paladin.setPower(99);
        cr_assert(paladin.getPower() == 99);

        cr_assert(paladin.getName() == paladin2.getName());
        cr_assert(paladin.getHp() == paladin2.getHp());
        cr_assert(paladin.getPower() == paladin2.getPower());
    }

    cr_assert_stdout_eq_str(
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n");
}

Test(Paladin, test_Paladin_attack, .init = redirect_all_stdout)
{
    {
        Paladin paladin("Uther", 99);

        cr_assert(paladin.attack() == 20);
        cr_assert(paladin.getPower() == 89);
    }


    cr_assert_stdout_eq_str
    (
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther strikes with his sword.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

Test(Paladin, test_Paladin_special, .init = redirect_all_stdout)
{
    {
        Paladin paladin("Uther", 99);


        cr_assert(paladin.attack() == 20);
        cr_assert(paladin.special() == 99);
        cr_assert(paladin.getPower() == 39);
    }


    cr_assert_stdout_eq_str
    (
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther strikes with his sword.\n"
        "Uther casts a fireball.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

Test(Paladin, test_Paladin_rest, .init = redirect_all_stdout)
{
    {
        Paladin paladin("Uther", 99);


        cr_assert(paladin.attack() == 20);
        cr_assert(paladin.special() == 99);
        cr_assert(paladin.getPower() == 39);
        paladin.rest();
        cr_assert(paladin.getHp() == 100);
        cr_assert(paladin.getPower() == 100);
    }


    cr_assert_stdout_eq_str
    (
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther strikes with his sword.\n"
        "Uther casts a fireball.\n"
        "Uther prays.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

Test(Paladin, test_Paladin_damage, .init = redirect_all_stdout)
{
    {
        Paladin paladin("Uther", 99);


        cr_assert(paladin.attack() == 20);
        cr_assert(paladin.special() == 99);
        cr_assert(paladin.getPower() == 39);
        paladin.rest();
        cr_assert(paladin.getHp() == 100);
        cr_assert(paladin.getPower() == 100);
        paladin.damage(50);
        cr_assert(paladin.getHp() == 50);
    }


    cr_assert_stdout_eq_str
    (
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther strikes with his sword.\n"
        "Uther casts a fireball.\n"
        "Uther prays.\n"
        "Uther takes 50 damage.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}

Test(Paladin, test_Paladin_main, .init = redirect_all_stdout)
{
    {
        Paladin paladin("Uther", 99);


        cr_assert(paladin.attack() == 20);
        cr_assert(paladin.special() == 99);
        cr_assert(paladin.getPower() == 39);
        paladin.rest();
        cr_assert(paladin.getHp() == 100);
        cr_assert(paladin.getPower() == 100);
        paladin.damage(50);
        cr_assert(paladin.getHp() == 50);
    }


    cr_assert_stdout_eq_str
    (
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Uther strikes with his sword.\n"
        "Uther casts a fireball.\n"
        "Uther prays.\n"
        "Uther takes 50 damage.\n"
        "Uther is blessed.\n"
        "Uther finds peace.\n"
        "Uther closes his spellbook.\n"
        "Uther takes off his armor.\n"
        "Uther is back to his crops.\n"
    );
}


Test(ICharacter, test_ICharacter_class_implementation, .init = redirect_all_stdout)
{
    {
        ICharacter  *peasant = new Peasant("Gildas", 42);
        ICharacter  *knight = new Knight("Arthur", 20);
        ICharacter  *enchanter = new Enchanter("Merlin", 20);
        ICharacter  *priest = new Priest("Trichelieu", 20);
        ICharacter  *paladin = new Paladin("Uther", 99);

        cr_assert(peasant != nullptr);
        cr_assert(knight != nullptr);
        cr_assert(enchanter != nullptr);
        cr_assert(priest != nullptr);
        cr_assert(paladin != nullptr);
    }

    cr_assert_stdout_eq_str
    (
        "Gildas goes for an adventure.\n"
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
    );
}

Test(ICharacter, test_ICharacter_attack, .init = redirect_all_stdout)
{
    {
        ICharacter  *peasant = new Peasant("Gildas", 42);
        ICharacter  *knight = new Knight("Arthur", 20);
        ICharacter  *enchanter = new Enchanter("Merlin", 20);
        ICharacter  *priest = new Priest("Trichelieu", 20);
        ICharacter  *paladin = new Paladin("Uther", 99);

        cr_assert(peasant != nullptr);
        cr_assert(knight != nullptr);
        cr_assert(enchanter != nullptr);
        cr_assert(priest != nullptr);
        cr_assert(paladin != nullptr);

        cr_assert(peasant->attack() == 5);
    }

    cr_assert_stdout_eq_str
    (
        "Gildas goes for an adventure.\n"
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Gildas tosses a stone.\n"
    );
}

Test(ICharacter, test_ICharacter_special, .init = redirect_all_stdout)
{
    {
        ICharacter  *peasant = new Peasant("Gildas", 42);
        ICharacter  *knight = new Knight("Arthur", 20);
        ICharacter  *enchanter = new Enchanter("Merlin", 20);
        ICharacter  *priest = new Priest("Trichelieu", 20);
        ICharacter  *paladin = new Paladin("Uther", 99);

        cr_assert(peasant != nullptr);
        cr_assert(knight != nullptr);
        cr_assert(enchanter != nullptr);
        cr_assert(priest != nullptr);
        cr_assert(paladin != nullptr);

        cr_assert(peasant->attack() == 5);
        cr_assert(knight->special() == 0);

    }

    cr_assert_stdout_eq_str
    (
        "Gildas goes for an adventure.\n"
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Gildas tosses a stone.\n"
        "Arthur is out of power.\n"
    );
}

Test(ICharacter, test_ICharacter_rest, .init = redirect_all_stdout)
{
    {
        ICharacter  *peasant = new Peasant("Gildas", 42);
        ICharacter  *knight = new Knight("Arthur", 20);
        ICharacter  *enchanter = new Enchanter("Merlin", 20);
        ICharacter  *priest = new Priest("Trichelieu", 20);
        ICharacter  *paladin = new Paladin("Uther", 99);

        cr_assert(peasant != nullptr);
        cr_assert(knight != nullptr);
        cr_assert(enchanter != nullptr);
        cr_assert(priest != nullptr);
        cr_assert(paladin != nullptr);

        cr_assert(peasant->attack() == 5);
        cr_assert(knight->special() == 0);
        enchanter->rest();
        cr_assert(enchanter->getPower() == 100);
    }

    cr_assert_stdout_eq_str
    (
        "Gildas goes for an adventure.\n"
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Gildas tosses a stone.\n"
        "Arthur is out of power.\n"
        "Merlin meditates.\n"
    );
}

Test(ICharacter, test_ICharacter_damage, .init = redirect_all_stdout)
{
    {
        ICharacter  *peasant = new Peasant("Gildas", 42);
        ICharacter  *knight = new Knight("Arthur", 20);
        ICharacter  *enchanter = new Enchanter("Merlin", 20);
        ICharacter  *priest = new Priest("Trichelieu", 20);
        ICharacter  *paladin = new Paladin("Uther", 99);

        cr_assert(peasant != nullptr);
        cr_assert(knight != nullptr);
        cr_assert(enchanter != nullptr);
        cr_assert(priest != nullptr);
        cr_assert(paladin != nullptr);

        cr_assert(peasant->attack() == 5);
        cr_assert(knight->special() == 0);
        enchanter->rest();
        cr_assert(enchanter->getPower() == 100);
        priest->damage(21);
        cr_assert(priest->getHp() == 79);
    }

    cr_assert_stdout_eq_str
    (
        "Gildas goes for an adventure.\n"
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Gildas tosses a stone.\n"
        "Arthur is out of power.\n"
        "Merlin meditates.\n"
        "Trichelieu takes 21 damage.\n"
    );
}

Test(ICharacter, test_ICharacter_display_caracteristics, .init = redirect_all_stdout)
{
    {
        ICharacter  *peasant = new Peasant("Gildas", 42);
        ICharacter  *knight = new Knight("Arthur", 20);
        ICharacter  *enchanter = new Enchanter("Merlin", 20);
        ICharacter  *priest = new Priest("Trichelieu", 20);
        ICharacter  *paladin = new Paladin("Uther", 99);

        cr_assert(peasant != nullptr);
        cr_assert(knight != nullptr);
        cr_assert(enchanter != nullptr);
        cr_assert(priest != nullptr);
        cr_assert(paladin != nullptr);

        cr_assert(peasant->attack() == 5);
        cr_assert(knight->special() == 0);
        enchanter->rest();
        cr_assert(enchanter->getPower() == 100);
        priest->damage(21);
        cr_assert(priest->getHp() == 79);

        cr_assert(paladin->getName() == "Uther");
        cr_assert(paladin->getHp() == 100);
        cr_assert(paladin->getPower() == 99);

        std::cout   << paladin->getName() << ": "
                    << paladin->getHp() << " health points, "
                    << paladin->getPower() << " power points."
                    << std::endl;
    }

    cr_assert_stdout_eq_str
    (
        "Gildas goes for an adventure.\n"
        "Arthur goes for an adventure.\n"
        "Arthur vows to protect the kingdom.\n"
        "Merlin goes for an adventure.\n"
        "Merlin learns magic from his spellbook.\n"
        "Trichelieu goes for an adventure.\n"
        "Trichelieu learns magic from his spellbook.\n"
        "Trichelieu enters in the order.\n"
        "Uther goes for an adventure.\n"
        "Uther vows to protect the kingdom.\n"
        "Uther learns magic from his spellbook.\n"
        "Uther enters in the order.\n"
        "Uther fights for the light.\n"
        "Gildas tosses a stone.\n"
        "Arthur is out of power.\n"
        "Merlin meditates.\n"
        "Trichelieu takes 21 damage.\n"
        "Uther: 100 health points, 99 power points.\n"
    );
}