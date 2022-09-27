#include <iostream>
#include <vector>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
}

BinarySearchTree::~BinarySearchTree()
{
}

Node* BinarySearchTree::insertNode(int val, Node* node)
{
  if(node == nullptr)
  {
    node = new Node();
    node->data = val;
    return node;
  }
  if(val < node->data)
  {
    node->left = insertNode(val, node->left);
  }
  else
  {
    node->right = insertNode(val, node->right);
  }
  return node;
}

Node* BinarySearchTree::minValueNode(Node* node)
{
  Node* curr = node;
  while(curr && curr->left != nullptr)
  {
    curr = curr->left;
  }

  return curr;
  
}

Node* BinarySearchTree::removeNode(int val, Node* node)
{
  if(node == nullptr)
  {
    return node;
  }
  if(val < node->data)
  {
    node->left = removeNode(val, node->left);
  }
  else if(val > node->data)
  {
    node->right = removeNode(val, node->right);
  }
  else 
  {
    if(node->left == nullptr)
    {
      Node* temp = node->right;
      node = nullptr;
      delete node;
      return temp;
    }
    else if(node->right == nullptr)
    {
      Node *temp = node->left;
      node = nullptr;
      delete node;
      return temp;
    }
  
    Node* temp = minValueNode(node->right);
    node->data = temp->data;
  
    node->right = removeNode( temp->data, node->right);
  }

  return node;
}
//Move all the way left
//get position
//Move to the right
void BinarySearchTree::inOrderTraversal(Node* node)
{
  if(node != nullptr)
  {
    inOrderTraversal(node->left);
    
    std::cout << node->data << " -> ";

    inOrderTraversal(node->right);
  }
}
//move all the way left
//move to the right
//get position
void BinarySearchTree::postOrderTraversal(Node* node)
{
  if(node != nullptr)
  {
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    std::cout << node->data << " -> ";
  }
}
