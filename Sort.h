#include <iostream>
#include <vector>

class Sort {
public:
  Sort();
  ~Sort();
  void printList(const std::vector<int> &list);
  std::vector<int> createRandomList(const int &size = 10, const int &min = 0,
                                    const int &max = 100);
  std::vector<int> doInsertionSort(std::vector<int> list);
  std::vector<int> doSelectionSort(std::vector<int> list);
  std::vector<int> doMergeSort(std::vector<int> list);
  std::vector<int> doQuickSort(std::vector<int> list);

private:
  void mergeHelper(std::vector<int> &list, const int &min, const int &max);
  void merge(std::vector<int> &list, const int &min, const int &size,  const int &max);
  void quickHelper(std::vector<int> &list, const int &startIdx, const int &endIdx);
  int quickSplit(std::vector<int> &list, const int &startIdx, const int &endIdx);
};