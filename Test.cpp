#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;
using namespace doctest;

TEST_CASE("simple containers' functions")
{
    MagicalContainer container;
    CHECK_NOTHROW(container.addElement(17));
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    CHECK_EQ(container.size(), 5);
    CHECK_NOTHROW(container.removeElement(9));// Removing non-existing element
    CHECK_EQ(container.size(), 4);
    CHECK_THROWS_AS(container.addElement(17), std::invalid_argument); // Adding existing element
}

TEST_CASE("AscendingIterator")
{
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::AscendingIterator ascIter(container);
    CHECK_EQ(*ascIter, 2);
    // Iterate and check values
    CHECK_EQ(*(++ascIter), 3);
    CHECK_EQ(*(++ascIter), 9);
    CHECK_EQ(*(++ascIter), 17);
    CHECK_EQ(*(++ascIter), 25);
    MagicalContainer::AscendingIterator ascIter2(container);
    CHECK_NOTHROW(MagicalContainer::AscendingIterator ascIterdem(ascIter));
    auto it = ascIter.begin(), it2 = ascIter2.end();
    CHECK_EQ(*it, 2);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 3);
    CHECK_FALSE(ascIter != ascIter2);
    CHECK_FALSE(!(ascIter2 == ascIter));
    CHECK_GT(*it2, *it);

}

TEST_CASE("SideCrossIterator")
{
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::SideCrossIterator crossIter(container);
    MagicalContainer::SideCrossIterator crossIter2(container);
    CHECK_NOTHROW(MagicalContainer::SideCrossIterator crossIterdem(crossIter));
    auto it = crossIter.begin(), it2 = crossIter2.end();
    CHECK_EQ(*it, 2);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 25);
    CHECK_FALSE(crossIter != crossIter2);
    CHECK_FALSE(!(crossIter2 == crossIter));
    CHECK_GT(*it, *it2);
}

TEST_CASE("PrimeIterator")
{
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::PrimeIterator primeIter(container);
    MagicalContainer::PrimeIterator primeIter2(container);
    CHECK_NOTHROW(MagicalContainer::PrimeIterator crossIterdem(primeIter));
    auto it = primeIter.begin(), it2 = primeIter2.end();
    CHECK_EQ(*it, 2);
    CHECK_NOTHROW(++it);
    CHECK_EQ(*it, 3);
    CHECK_FALSE(primeIter != primeIter2);
    CHECK_FALSE(!(primeIter2 == primeIter));
    CHECK_GT(*it2, *it);
}






