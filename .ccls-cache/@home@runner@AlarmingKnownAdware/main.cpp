#include <iostream>
#include "Sort.h"
int main() 
{
  Sort *sort = new Sort();

  std::vector<int> unsorted = sort->createRandomList();
  std::cout<<"Unsorted list: ";
  sort->printList(unsorted);
  
  sort->doInsertionSort(unsorted);
  
  sort->doSelectionSort(unsorted);
  
  sort->doMergeSort(unsorted);
  
  sort->doQuickSort(unsorted);
}