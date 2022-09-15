#include <iostream>
#include <vector>

class Sort
{
public:
  Sort();
  ~Sort();
  void printList(std::vector<int> list);
  std::vector<int> createRandomList(int size = 10, int min = 0, int max = 100);
  std::vector<int> doInsertionSort(std::vector<int> list);
  std::vector<int> doSelectionSort(std::vector<int> list);
  std::vector<int> doMergeSort(std::vector<int> list);
  std::vector<int> doQuickSort(std::vector<int> list);

private:
  void mergeHelper(std::vector<int> &list, int p, int r);
  void merge(std::vector<int> &list, int p, int q, int r);
  void quickHelper(std::vector<int> &list, int startIdx, int endIdx);
  int quickSplit(std::vector<int> &list, int startIdx, int endIdx);
};