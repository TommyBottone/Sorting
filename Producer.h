#include "Singleton.h"
#include "BinarySearchTree.h"
#include <vector>
#include <mutex>
#include <thread>
#include <future>

class Producer : public Singleton
{
public:
  Producer();
  ~Producer();
  void doProducing();
private:
  std::vector<std::future<void>> _threads;
};