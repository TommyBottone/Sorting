#include "SmartPtr.h"
#include "Sort.h"
#include "Producer.h"
#include "Shape.h"
#include <iostream>
#include <algorithm>

void sorting();
void produce();
void shapes();

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
  shapes();
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

void shapes()
{
  std::vector<Shape> shapes;
  std::srand(time(0));
  for(int i = 0; i < 20; i++)
  {
    int r = rand() % (int)Shape::RECTANGLE;
    switch(r)
    {
      case Shape::CIRCLE:
      {
        Circle c;
        shapes.push_back(c);
        break;
      }
      case Shape::LINE:
      {
        Line l;
        shapes.push_back(l);
        break;
      }
      case Shape::TRIANGLE:
      {
        Triangle t;
        shapes.push_back(t);
        break;
      }
      case Shape::RECTANGLE:
      {
        Rectangle r;
        shapes.push_back(r);
        break;
      }
    }
  }

  for(auto s : shapes)
  {
    std::cout << "Shape: " + s.toString() << std::endl;
  }
}