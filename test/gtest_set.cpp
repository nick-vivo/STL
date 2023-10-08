#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <set.h>

TEST(ALL, all)
{
    mstd::Set<int> set = {1, 2, 3};

    mstd::List<int> ls = set.get_list();

    ASSERT_EQ(ls[0], 1);
    ASSERT_EQ(ls[1], 2);
    ASSERT_EQ(ls[2], 3);

    ASSERT_EQ(ls[3], 1);

    mstd::Set setb = set;

    ls = setb.get_list();

    ASSERT_EQ(ls[0], 1);
    ASSERT_EQ(ls[1], 2);
    ASSERT_EQ(ls[2], 3);

    ASSERT_EQ(ls[3], 1);

    setb.erase(3);

    ls = setb.get_list();

    ASSERT_EQ(ls[0], 1);
    ASSERT_EQ(ls[1], 2);
    ASSERT_EQ(ls[2], 1);

    ASSERT_EQ(ls[3], 2);

    setb.erase(0);
    ls = setb.get_list();

    ASSERT_EQ(ls[0], 1);
    ASSERT_EQ(ls[1], 2);
    ASSERT_EQ(ls[2], 1);

    ASSERT_EQ(ls[3], 2);

    setb.insert(3);
    setb.insert(3);
    setb.insert(3);
    
    ls = setb.get_list();
    ASSERT_EQ(ls[0], 1);
    ASSERT_EQ(ls[1], 2);
    ASSERT_EQ(ls[2], 3);

    ASSERT_EQ(ls[3], 1);


}