#include <gtest/gtest.h>
#include <iostream>
#include <string>

int main (int argc, char* argv[]) {
  if (argc > 1 && argv[1] == std::string("tests")) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }

  std::cout << "stunning-octo-fortnight\n";

  return 0;
}
