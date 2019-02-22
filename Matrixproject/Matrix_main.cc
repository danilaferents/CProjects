#include <stdio.h>
#include "gtest/gtest.h"

GTEST_API_ int main(int argc, char **argv) {
    printf("Running main() from gtest_main.cc\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

//g++ -std=c++11 -stdlib=libc++  Massife_Tests.cpp  Massife.cpp All_main.cc  Ring_Tests.cpp  Ring.cpp Stack_Tests.cpp  Stack.cpp Rectangle_Tests.cpp  Rectangle.cpp  String_Tests.cpp  String.cpp -lgtest -lpthread -o Tests
