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
  std::cout<<std::endl<<"In order: " << std::endl;
  BinarySearchTree::inOrderTraversal(tree);
  std::cout<<std::endl<<"Post order: " << std::endl;
  BinarySearchTree::postOrderTraversal(tree);
}

void Producer::doProducing()
{
  running = true;

  auto producingThread = []()
  {
    while(running)
    {
      std::srand(time(0));
      int r = rand() % 1000;
      mtx.lock();
      q.emplace_back(r); 
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