#include <iostream>
#include "Producer.h"
#include <chrono>

static const int ADD_SLEEP  = 1000;
static const int GET_SLEEP  = 5000;

static bool running = false;
static std::vector<int> q;
static void enqueue(int v);
static int dequeue();
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
      enqueue(r);
      mtx.unlock();
      std::this_thread::sleep_for(std::chrono::milliseconds(ADD_SLEEP));
    }
  };

  auto consumingThread = []()
  {
    while(running)
    {
      if(qSize() == 0)
      {
        std::this_thread::sleep_for(std::chrono::milliseconds(GET_SLEEP));
        continue;
      }
      
      mtx.lock();
      int val = dequeue();
      tree = BinarySearchTree::insertNode(val,  tree);
      std::cerr<<".";
      mtx.unlock();
    }
  };
  
  _threads.push_back(std::async(std::launch::async, producingThread));
  _threads.push_back(std::async(std::launch::async, consumingThread));
}

void enqueue(int v) 
{ 
  q.push_back(v); 
}

int dequeue() 
{
  int retVal = 0;
  
  if(q.size() > 0)
  {
    retVal = q[0];
    q.erase(q.begin());
  }
  
  return retVal;
}

bool qSize()
{
  return q.size();
}