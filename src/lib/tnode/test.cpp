#include <tnode.h>
#include <gtest/gtest.h>
#include <string>

using namespace sof;

TEST(TNODE, create) {
  {
    node<int, int> node{4};

    EXPECT_EQ(node.KeyValue().first, 4);
    EXPECT_EQ(node.KeyValue().second, 0);
  }

  {
    std::string a {"Hello world!"};
    node<int, std::string> node{5, a};
    
    EXPECT_EQ(node.KeyValue().first, 5);
    EXPECT_EQ(node.KeyValue().second, a);
  }

  {
    node<int, int> parent{2};
    node<int, int>::Family f {&parent, nullptr, nullptr};
    node<int, int> node{4, 5, f};

    EXPECT_EQ(&node.root(), &parent);
  }
}

TEST(TNODE, copy) {
  {
    
  }
}
