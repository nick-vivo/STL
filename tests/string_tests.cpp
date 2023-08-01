#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string.hpp>

TEST(string_strlen, all)
{
    ASSERT_EQ(mstd::strlen("std"), 3);
    ASSERT_EQ(mstd::strlen(""), 0);
    ASSERT_EQ(mstd::strlen("1"), 1);
    ASSERT_EQ(mstd::strlen("99999"), 5);
}