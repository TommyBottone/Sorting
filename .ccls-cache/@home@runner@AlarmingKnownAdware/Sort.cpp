#include "Sort.h"

Sort::Sort() {}

Sort::~Sort() {}

void Sort::printList(const std::vector<int> &list) {
  for (int i : list) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}

std::vector<int> Sort::createRandomList(const int &size, const int &min,
                                        const int &max) {
  std::vector<int> retVal;

  std::srand(time(0));
  for (int i = 0; i < size; i++) {
    int r = rand() % max + min;
    retVal.push_back(r);
  }

  return retVal;
}

// Move up the array and then check everything behind if it should be moved
// there.
std::vector<int> Sort::doInsertionSort(std::vector<int> list) {
  for (int i = 1; i < list.size(); i++) {
    int curr = list[i];
    int iter = i - 1;

    while (iter >= 0 && list[iter] > curr) {
      list[iter + 1] = list[iter];
      iter--;
    }
    list[iter + 1] = curr;
  }
  std::cout << "After insertion: ";
  printList(list);
  return list;
}
// Move up the list and then find the next value in the list. Then place that
// value at the current index
std::vector<int> Sort::doSelectionSort(std::vector<int> list) {
  int start = 0;
  while (start < list.size()) {
    int min = start;
    for (int i = start + 1; i < list.size(); i++) {
      if (list[i] < list[min]) {
        min = i;
      }
    }

    int tmp = list[start];
    list[start] = list[min];
    list[min] = tmp;
    start++;
  }

  std::cout << "After selection: ";
  printList(list);
  return list;
}

// Keep splitting the list and swapping the values in order. Then put it back
// together.
std::vector<int> Sort::doMergeSort(std::vector<int> list) {
  mergeHelper(list, 0, list.size() - 1);

  std::cout << "After merge: ";
  printList(list);
  return list;
}

// Split the list recursively
void Sort::mergeHelper(std::vector<int> &list, const int &min, const int &max) {
  if (min < max) {
    int size = (min + max) / 2;
    mergeHelper(list, min, size);
    mergeHelper(list, size + 1, max);
    merge(list, min, size, max);
  }
}

// put the list back together
void Sort::merge(std::vector<int> &list, const int &min, const int &size,
                 const int &max) {
  int sizeL = size - min + 1;
  int sizeR = max - size;
  std::vector<int> left;
  std::vector<int> right;

  for (int i = 0; i < sizeL; i++) {
    left.push_back(list[min + i]);
  }

  for (int i = 0; i < sizeR; i++) {
    right.push_back(list[size + i + 1]);
  }

  int i = 0;
  int j = 0;
  int k = min;

  for (k = min; k <= max && i < sizeL && j < sizeR; k++) {
    if (left[i] <= right[j]) {
      list[k] = left[i];
      i++;
    } else {
      list[k] = right[j];
      j++;
    }
  }

  for (i = i; i < sizeL; i++) {
    list[k] = left[i];
    k++;
  }

  for (j = j; j < sizeR; j++) {
    list[k] = right[j];
    k++;
  }
}

// pivot around a value
std::vector<int> Sort::doQuickSort(std::vector<int> list) {
  quickHelper(list, 0, list.size() - 1);

  std::cout << "After quick: ";
  printList(list);
  return list;
}

void Sort::quickHelper(std::vector<int> &list, const int &startIdx, const int &endIdx) {
  if (startIdx < endIdx) {
    int midIdx = quickSplit(list, startIdx, endIdx);
    quickHelper(list, startIdx, midIdx - 1);
    quickHelper(list, midIdx + 1, endIdx);
  }
}

int Sort::quickSplit(std::vector<int> &list, const int &startIdx,
                     const int &endIdx) {
  int retVal = 0;
  int x = list[endIdx];
  int i = startIdx - 1;

  for (int j = startIdx; j < endIdx; j++) {
    if (list[j] <= x) {
      i++;

      int tmp = list[i];
      list[i] = list[j];
      list[j] = tmp;
    }
  }

  int tmp = list[i + 1];
  list[i + 1] = list[endIdx];
  list[endIdx] = tmp;

  retVal = i + 1;
  return retVal;
}