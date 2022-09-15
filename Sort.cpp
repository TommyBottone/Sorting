#include "Sort.h"

Sort::Sort() {}

Sort::~Sort() {}

void Sort::printList(std::vector<int> list) {
  for (int i : list) {
    std::cout << i << " ";
  }
  std::cout <<std::endl;
}

std::vector<int> Sort::createRandomList(int size, int min, int max)
{
  std::vector<int> retVal;
  
  std::srand(time(0));
  for(int i = 0; i < size; i++)
  {
    int r = rand() % max + min;
    retVal.push_back(r);
  }
  
  return retVal;
}

std::vector<int> Sort::doInsertionSort(std::vector<int> list) 
{
  for (int i = 1; i < list.size(); i++) 
  {
    int curr = list[i];
    int iter = i - 1;

    while (iter >= 0 && list[iter] > curr) 
    {
      list[iter + 1] = list[iter];
      iter--;
    }
    list[iter + 1] = curr;
  }
  std::cout<< "After insertion: ";
  printList(list);
  return list;
}

std::vector<int> Sort::doSelectionSort(std::vector<int> list)
{
  int start = 0;
  while(start < list.size())
  {
    int min = start;
    for(int i = start+1; i < list.size(); i++)
    {
      if(list[i] < list[min])
      {
        min = i;
      }
    }

    int tmp = list[start];
    list[start] = list[min];
    list[min] = tmp;
    start++;
  }
  
  std::cout<< "After selection: ";
  printList(list);
  return list;
}


std::vector<int> Sort::doMergeSort(std::vector<int> list)
{
  mergeHelper(list, 0, list.size()-1);
  
  std::cout<< "After merge: ";
  printList(list);
  return list;
}

void Sort::mergeHelper(std::vector<int> &list, int p, int r)
{
  if(p < r)
  {
    int q = (p+r) / 2;
    mergeHelper(list, p, q);
    mergeHelper(list, q+1, r);
    merge(list, p, q, r);
  }
}

void Sort::merge(std::vector<int> &list, int p, int q, int r)
{
  int sizeL = q - p + 1;
  int sizeR = r - q;
  std::vector<int> left;
  std::vector<int> right;
  
  for(int i = 0; i < sizeL; i++)
  {
    left.push_back(list[p+i]);
  }
  
  for(int i = 0; i < sizeR; i++)
  {
    right.push_back(list[q+i+1]);
  }

  int i = 0;
  int j = 0;
  int k;

  for(k = p; k <= r && i < sizeL && j < sizeR; k++)
  {
    if(left[i] <= right[j])
    {
      list[k] = left[i];
      i++;
    }
    else
    {
      list[k] = right[j];
      j++;
    }
  }
  
  for(i = i; i < sizeL; i++)
  {
    list[k] = left[i];
    k++;
  }
  
  for(j = j; j < sizeR; j++)
  {
    list[k] = right[j];
    k++;
  }
}

std::vector<int> Sort::doQuickSort(std::vector<int> list)
{
  quickHelper(list, 0, list.size()-1);
  
  std::cout<< "After quick: ";
  printList(list);
  return list;
}

void Sort::quickHelper(std::vector<int> &list, int startIdx, int endIdx)
{
  if(startIdx < endIdx)
  {
    int midIdx = quickSplit(list, startIdx, endIdx);
    quickHelper(list, startIdx, midIdx - 1);
    quickHelper(list, midIdx +1, endIdx);
  }
}

int Sort::quickSplit(std::vector<int> &list, int startIdx, int endIdx)
{
  int retVal = 0;
  int x = list[endIdx];
  int i = startIdx - 1;

  for(int j = startIdx; j < endIdx; j++)
  {
    if(list[j] <= x)
    {
      i++;
      
      int tmp = list[i];
      list[i] = list[j];
      list[j] = tmp;
    }
  }
  
  int tmp = list[i+1];
  list[i+1] = list[endIdx];
  list[endIdx] = tmp;

  retVal = i + 1;
  return retVal;
}