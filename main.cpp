#include "Sort.h"
#include <iostream>

void sorting();

int main() 
{ 
  sorting(); 
}

void sorting() 
{
  Sort *sort = new Sort();

  std::vector<int> unsorted = sort->createRandomList();
  std::cout << "Unsorted list: ";
  sort->printList(unsorted);

  sort->doInsertionSort(unsorted);

  sort->doSelectionSort(unsorted);

  sort->doMergeSort(unsorted);

  sort->doQuickSort(unsorted);
}