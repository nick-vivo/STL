#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector.h>

TEST(asdasd, asdasd)
{
    mstd::vector<int> a;

    a.push_back(1);

    ASSERT_EQ(a.at(0), 1);
    ASSERT_EQ(a.size(), 1);
    ASSERT_ANY_THROW(a.at(-1));
    ASSERT_ANY_THROW(a.at(1));

    a.insert(0, 3);
    ASSERT_EQ(a.at(0), 3);
    ASSERT_EQ(a.at(1), 1);
    ASSERT_EQ(a.size(), 2);
    ASSERT_ANY_THROW(a.at(-1));
    ASSERT_ANY_THROW(a.at(2));

    a.push_back(5);
    ASSERT_EQ(a.at(0), 3);
    ASSERT_EQ(a.at(1), 1);
    ASSERT_EQ(a.at(2), 5);
    ASSERT_EQ(a.size(), 3);
    ASSERT_ANY_THROW(a.at(-1));
    ASSERT_ANY_THROW(a.at(3));
    ASSERT_ANY_THROW(a.at(4));

    a.remove(0);
    ASSERT_EQ(a.at(0), 1);
    ASSERT_EQ(a.at(1), 5);
    ASSERT_ANY_THROW( a.at(2) );
    ASSERT_EQ(a.size(), 2);

    ASSERT_ANY_THROW(a.at(-1));
    ASSERT_ANY_THROW(a.at(3));
    ASSERT_ANY_THROW(a.at(2));
    a.insert(0, 3);

    a.remove(1);
    ASSERT_EQ(a.at(0), 3);
    ASSERT_EQ(a.at(1), 5);
    ASSERT_ANY_THROW( a.at(2) );
    ASSERT_EQ(a.size(), 2);

    ASSERT_ANY_THROW(a.at(-1));
    ASSERT_ANY_THROW(a.at(3));
    ASSERT_ANY_THROW(a.at(2));
    a.insert(1, 1);

    a.remove(2);
    ASSERT_EQ(a.at(0), 3);
    ASSERT_EQ(a.at(1), 1);
    ASSERT_ANY_THROW( a.at(2) );
    ASSERT_EQ(a.size(), 2);

    ASSERT_ANY_THROW(a.at(-1));
    ASSERT_ANY_THROW(a.at(3));
    ASSERT_ANY_THROW(a.at(2));
}