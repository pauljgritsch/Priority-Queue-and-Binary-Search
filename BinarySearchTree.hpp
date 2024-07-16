//
// Name : Paul Gritsch
// SSID : 1220449
// A05:  Submission Date: 12/10/23
//
#pragma once
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <class KeyType , class ValueType>
struct TreeNode {
  KeyType key;
  ValueType value;
  TreeNode<KeyType, ValueType>* parent = nullptr;
  TreeNode<KeyType, ValueType>* right = nullptr;
  TreeNode<KeyType, ValueType>* left = nullptr;
};


// add remove ( optional , not needed for the A5 insert and find testing
template <class KeyType, class ValueType>
class BinarySearchTree {
  public:
    //default contructor
    BinarySearchTree() : root(nullptr), count(0) {};

    //recursive helper for destrutor to delete nodes
    void destroy(TreeNode<KeyType, ValueType>*& t){
      if (t != nullptr){
        destroy(t->left);
        destroy(t->right);
        delete t;
        count--;
      }
    }

    //destructor
    ~BinarySearchTree(){destroy(root);}

    //insert item into the tree, go left if lesser, right if greater until empty space
    void insert(KeyType key, ValueType value ){
    insert_helper(root, key, value);
    count++;
  }

    //returns the min(left - most leaf)
    KeyType min_key(){
      TreeNode<KeyType, ValueType>* root_copy = root;
      while (root_copy->left != nullptr){
        root_copy = root_copy->left;
      }
      return root_copy->key;
    }

    //returns the max (right - most leaf)
    KeyType max_key(){
      TreeNode<KeyType, ValueType>* root_copy = root;
      while (root_copy->right != nullptr){
        root_copy = root_copy->right;
      }
      return root_copy->key;
    }

    //recursive helper function for search
    bool search_helper(TreeNode<KeyType, ValueType>* t, KeyType key){
      if (t == nullptr){
        return false;
      }
      else if (t->key == key){
        return true;
      }
      else if (key < t->key){
        return search_helper(t->left, key);
      }
      else{
        return search_helper(t->right, key);
      }
    }

    //recursive or iterative key search
    bool search(KeyType key){
      TreeNode<KeyType, ValueType>* root_copy = root;
      return search_helper(root_copy, key);
    }


    void print_inorder() {inorder(root);}
    void print_postorder() {postorder(root);}
    void print_preorder() {preorder(root);}

    void display(const std::string& prefix, const TreeNode<KeyType, ValueType>* node, bool isLess){
        if( node != nullptr )
        {
            std::cout << prefix;

            std::cout << (isLess ? "├──" : "└──" );

            // print the value of the node
            std::cout << node->key << std::endl;

            // enter the next tree level - left and right branch
            // display( prefix + (isLess ? "│   " : "    "), node->left, true);
            // display( prefix + (isLess ? "│   " : "    "), node->right, false);
            display( prefix + (isLess ? "│   " : "    "), node->right, true);
            display( prefix + (isLess ? "│   " : "    "), node->left, false);
        }
    }

    void display(){
      display("", root, false);
    }

    int size(){return count;}

  private:
    //recursive inorder traversal
    void inorder(TreeNode<KeyType, ValueType>* n){
      if (n == nullptr){
        return;
      }
      inorder(n->left);
      std::cout << n->key << " ";
      inorder(n->right);
    }

    //recursive postorder traversal
    void postorder(TreeNode<KeyType, ValueType>* n){
      if (n != nullptr){
        postorder(n->left);
        postorder(n->right);
        std::cout << n->key << " ";
      }
    }

    //recursive preorder traversal
    void preorder(TreeNode<KeyType, ValueType>* n){
      if (n != nullptr){
        std::cout << n->key << " ";
        preorder(n->left);
        preorder(n->right);
      }
    }

    //recursive insert helper function
    void insert_helper(TreeNode<KeyType, ValueType>*& root, KeyType key, ValueType value){
      if (root == nullptr){
        root = new TreeNode<KeyType, ValueType>;
        root->key = key;
        root->value = value;
      }
      else {
        if (key <= root->key){
          insert_helper(root->left, key, value);
        }
        else{
          insert_helper(root->right, key, value);
        }
      }
    }

    //trees root
    TreeNode<KeyType, ValueType>* root = nullptr;  

    //node count
    int count = 0;
};

#endif