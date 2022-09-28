#include <chrono>
#include <memory>
#include <iostream>

class Benchmark
{
public:
  //typedef std::chrono::time_point_cast<std::chrono::microseconds> michrosec;
  Benchmark(std::string name = "none", bool startBench = false) : _name(name), _startBench(startBench)
  {
    if(startBench)
    {
      start();
    }
  }

  ~Benchmark()
  {
    stop();
  }

  void start()
  {
    _startBench = true;
     _startTime = std::chrono::high_resolution_clock::now(); 
  }
  void stop()
  {
    if(_startBench)
    {
      auto endTime = std::chrono::high_resolution_clock::now();
  
      auto start = std::chrono::time_point_cast<std::chrono::microseconds>(_startTime).time_since_epoch().count();
      auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTime).time_since_epoch().count();
  
      auto duration = end - start;
      double ms = duration * .001;
  
      std::cout << _name << ": " << duration << "us (" << ms << "ms)\n";
    }
  }

private:
  std::chrono::time_point<std::chrono::high_resolution_clock> _startTime;
  bool _startBench;
  std::string _name;

};