#include "gtest/gtest.h"
#include "src/deserialize.hpp"
#include <sqlite3.h>

/*
TEST(testMath, myCubeTest)
{
    EXPECT_EQ(1000, cubic(10));
}

*/




// test_vector.cpp
void test_ros2_message(){

    auto string_msg = std::make_shared<std_msgs::msg::String>();
    string_msg->data = "Hello World"

    assert(c.x == expected.x);

}


int main(){
    test_ros2_message();
return 0;
}