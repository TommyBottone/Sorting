#include<iostream>
#include <memory>
  
static struct AllocationMetric
  {
      uint32_t totalAllocated = 0;
      uint32_t totalFree = 0;
      inline uint32_t currentUsage() { return (totalAllocated - totalFree);}
  } _allocationMetric;

struct MemTracker
{
  void* operator new(size_t size)
  {
    _allocationMetric.totalAllocated += size;
    std::cout << "Allocating " << _allocationMetric.currentUsage() << " bytes\n";
    return malloc(size);
  }
  void operator delete (void* memory, size_t size)
  {
    _allocationMetric.totalFree += size;
    std::cout << "Freeing " << _allocationMetric.currentUsage() << " bytes\n";
    free(memory);
  }
};