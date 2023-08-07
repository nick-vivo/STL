#include <memory.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(memory_shared_ptr, methods)
{
    mstd::shared_ptr<int> s_ptr;
    int* ptr = new int(5);

    s_ptr = ptr;

    ASSERT_EQ(ptr, nullptr);
    ASSERT_EQ(*s_ptr, 5);
    
    s_ptr.reset();
    ASSERT_EQ(s_ptr.operator->(), nullptr);
    ASSERT_EQ(s_ptr.count(), 0);
}