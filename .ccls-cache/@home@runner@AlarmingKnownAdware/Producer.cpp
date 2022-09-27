#include <iostream>
#include "Producer.h"
#include <chrono>

static const int ADD_SLEEP  = 1000;
static const int GET_SLEEP  = 5000;

static bool running = false;
static std::vector<int> q;
static bool qSize();
static std::mutex mtx;
Node *tree;

Producer::Producer()
{
}

Producer::~Producer()
{
  running = false;
  std::cout<<"\nIn order: \n";
  BinarySearchTree::inOrderTraversal(tree);
  std::cout<<"\nPost order: \n";
  BinarySearchTree::postOrderTraversal(tree);
}

void Producer::doProducing()
{
  running = true;

  auto producingThread = []()
  {
    while(running)
    {
      mtx.lock();
      q.emplace_back(RandomIntGenerator::instance().rNum()); 
      mtx.unlock();
      std::this_thread::sleep_for(std::chrono::milliseconds(ADD_SLEEP));
    }
  };

  auto consumingThread = []()
  {
    while(running)
    {
      if(!qSize())
      {
        std::this_thread::sleep_for(std::chrono::milliseconds(GET_SLEEP));
        continue;
      }
      
      mtx.lock();

        
      if(qSize())
      {
        int val = q[0];
        tree = BinarySearchTree::insertNode(val,  tree);
        std::cerr<<".";
        q.erase(q.begin());
      }
      mtx.unlock();
    }
  };
  
  _threads.emplace_back(std::async(std::launch::async, producingThread));
  _threads.emplace_back(std::async(std::launch::async, consumingThread));
}

bool qSize()
{
  return q.size() > 0 ? true : false;
}