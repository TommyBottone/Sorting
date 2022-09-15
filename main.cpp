#include "SmartPtr.h"
#include "Sort.h"
#include "Producer.h"
#include <iostream>
#include <algorithm>

void sorting();
void produce();

char asciitolower(char in)
{
  if(in <= 'Z' && in >= 'A')
  {
    return in - ('Z' - 'z');
  }
  return in;
}

int main() 
{ 
  sorting(); 
  produce();

  return 0;
}

void sorting() 
{
  SmartPtr<Sort> sort(new Sort());

  std::vector<int> unsorted = sort->createRandomList();
  std::cout << "Unsorted list: ";
  sort->printList(unsorted);

  sort->doInsertionSort(unsorted);

  sort->doSelectionSort(unsorted);

  sort->doMergeSort(unsorted);

  sort->doQuickSort(unsorted);
}

void produce()
{
  SmartPtr<Producer> prod(new Producer());
  prod->doProducing();
  std::string val;
  while(val != "exit")
  {
    std::cout << "Type exit to exit" << std::endl;
    std::cin >> val;
    std::transform(val.begin(), val.end(), val.begin(), asciitolower);
    break;
  }
}