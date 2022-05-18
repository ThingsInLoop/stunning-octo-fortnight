/**
 * @file tnode.h
 * @brief Implementation of sof's tree node
 * @author Sasha K.
 * @date 18 may 2022.
 */

#ifndef SOF_LIB_TNODE_H_
#define SOF_LIB_TNODE_H_

#include <utility>
 
namespace sof {
  /**
   *  @brief Node of sof's binary tree.
   *  
   *  @tparam K Type of key object
   *  @tparam T Type of mapped object
   */
  template<typename K, typename T>
  class node {
    public:
      class Family {
        /**
         * Closest nodes to current node
         */
        public:
          Family(node* parent, node* lchild = nullptr, node* rchild = nullptr) :
            parent{parent}, lchild{lchild}, rchild{rchild} {}
          
          node* parent;
          node* lchild;
          node* rchild;
      }; 

      node(K key) : key{key}, value{}, family{nullptr} {}
      node(K key, T value) : key{key}, value{value}, family{nullptr} {}
      node(K key, T value, Family family) : key{key}, value{value}, family{family} {}

      std::pair<K, T> KeyValue(void) { return std::pair<K, T>{ key, value }; }
      node& root();
    private:
      K key;
      T value;
      Family family;
  };
}

template<typename K, typename T>
sof::node<K, T>& sof::node<K, T>::root() {
  node* root = this;
  while(root->family.parent) {root = root->family.parent;}
  return *root;
}


#endif /* SOF_LIB_TNODE_HPP_ */
