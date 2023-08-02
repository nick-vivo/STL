#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string.hpp>

#include <iostream>

TEST(string_strlen, all)
{
    ASSERT_EQ(mstd::strlen("std"), 3);
    ASSERT_EQ(mstd::strlen(""), 0);
    ASSERT_EQ(mstd::strlen("1"), 1);
    ASSERT_EQ(mstd::strlen("99999"), 5);
}

TEST(string_class, constructor_destructor_methods)
{
    mstd::string test("AZBUKA");
    ASSERT_STREQ(test.c_str(), "AZBUKA");
    ASSERT_EQ(test.size(), 6);
    ASSERT_EQ(test.capacity(), 7);
//CHECK CONTAINER
    ASSERT_EQ(test.at(0), 'A');
    ASSERT_EQ(test.at(1), 'Z');
    ASSERT_EQ(test.at(2), 'B');
    ASSERT_EQ(test.at(3), 'U');
    ASSERT_EQ(test.at(4), 'K');
    ASSERT_EQ(test.at(5), 'A');
    ASSERT_EQ(test[6], '\0');
//THROW
    ASSERT_ANY_THROW(test.at(6));

    
    mstd::string null("");
    ASSERT_STREQ("", null.c_str());
    ASSERT_EQ(null.size(), 0);
    ASSERT_EQ(null.capacity(), 1);

    mstd::string test_cp(test);
    ASSERT_STREQ(test_cp.c_str(), "AZBUKA");
    ASSERT_EQ(test_cp.size(), 6);
    ASSERT_EQ(test_cp.capacity(), 7);
//CHECK CONTAINER
    ASSERT_EQ(test_cp.at(0), 'A');
    ASSERT_EQ(test_cp.at(1), 'Z');
    ASSERT_EQ(test_cp.at(2), 'B');
    ASSERT_EQ(test_cp.at(3), 'U');
    ASSERT_EQ(test_cp.at(4), 'K');
    ASSERT_EQ(test_cp.at(5), 'A');
    ASSERT_EQ(test_cp[6], '\0');
//THROW
    ASSERT_ANY_THROW(test_cp.at(6));

    null = test;
    ASSERT_STREQ(null.c_str(), "AZBUKA");
    //CHECK CONTAINER
    ASSERT_EQ(null.size(), 6);
    ASSERT_EQ(null.capacity(), 7);
    ASSERT_EQ(null.at(0), 'A');
    ASSERT_EQ(null.at(1), 'Z');
    ASSERT_EQ(null.at(2), 'B');
    ASSERT_EQ(null.at(3), 'U');
    ASSERT_EQ(null.at(4), 'K');
    ASSERT_EQ(null.at(5), 'A');
    ASSERT_EQ(null[6], '\0');

    null = "NULL";
    ASSERT_EQ(null.size(), 4);
    ASSERT_EQ(null.capacity(), 7);
    ASSERT_EQ(null.at(0), 'N');
    ASSERT_EQ(null.at(1), 'U');
    ASSERT_EQ(null.at(2), 'L');
    ASSERT_EQ(null.at(3), 'L');
    ASSERT_EQ(null[4], '\0');
}

TEST(string_operators, all)
{
    mstd::string a("NULL");
    mstd::string b("NULL");
    mstd::string c("NOTN");
    char d[] = "NULL";
    ASSERT_TRUE(a == b);
    ASSERT_FALSE(a == c);
    
    ASSERT_EQ(a.size(), mstd::strlen(d));
    ASSERT_TRUE(a == d);
    ASSERT_FALSE(a == c);
}