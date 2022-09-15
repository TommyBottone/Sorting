#include "Singleton.h"
#include <vector>
#include <mutex>
#include <thread>

class Producer : public Singleton
{
public:
  Producer();
  ~Producer();
  void doProducing();
private:
  std::thread _enQthread;
  std::thread _deQThread;

};