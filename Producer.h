#include "Singleton.h"
#include "BinarySearchTree.h"
#include <vector>
#include <mutex>
#include <thread>
#include <future>

class RandomIntGenerator 
{
public:
  RandomIntGenerator(const RandomIntGenerator&) = delete;
  RandomIntGenerator() {std::srand(time(0));}
  
  static RandomIntGenerator& instance() 
  {
    static RandomIntGenerator _instance;
    return _instance;
  }

  int rNum()
  {
      return rand() % 1000;
  }

private:
};

class Producer
{
public:
  Producer();
  ~Producer();
  void doProducing();
private:
  std::vector<std::future<void>> _threads;
};