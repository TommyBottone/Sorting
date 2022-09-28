#include "SmartPtr.h"
#include "Sort.h"
#include "Producer.h"
#include "Shape.h"
#include <iostream>
#include <algorithm>

void sorting();
void produce();
void shapes();

int main() 
{ 
  sorting(); 
  std::cout << std::endl;
  produce();
  std::cout << std::endl;
  shapes();
  return 0;
}

void sorting() 
{
  SmartPtr<Sort> sort(new Sort());

  std::vector<int> unsorted = sort->createRandomList();
  std::cout << "Unsorted list: ";
  
  sort->printList(unsorted);

  std::async(std::launch::async,
  [&sort, unsorted]()
  {
    sort->doInsertionSort(unsorted);
  });
  std::async(std::launch::async,
  [&sort, unsorted]()
  {
    sort->doSelectionSort(unsorted);
  });
  std::async(std::launch::async,
  [&sort, unsorted]()
  {
    sort->doMergeSort(unsorted);
  });
  std::async(std::launch::async,
  [&sort, unsorted]()
  {
    sort->doQuickSort(unsorted);
  });
}

void produce()
{
  SmartPtr<Producer> prod(new Producer());
  prod->doProducing();
  
  std::string val;
  while(val != "exit")
  {
    std::cout << "Type exit to exit\n";
    std::cin >> val;
    
    std::transform(val.begin(), val.end(), val.begin(),
        [](unsigned char c){ 
            return std::tolower(c); 
    });
    
    break;
  }
}

void ForEach(const std::vector<Shape> shapes, void(*func)(std::string))
{
  for(auto shape : shapes)
  {
    func(shape.toString());
  }
}

std::vector<Shape> generateShapes()
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
        shapes.emplace_back(c);
        break;
      }
      case Shape::LINE:
      {
        Line l;
        shapes.emplace_back(l);
        break;
      }
      case Shape::TRIANGLE:
      {
        Triangle t;
        shapes.emplace_back(t);
        break;
      }
      case Shape::RECTANGLE:
      {
        Rectangle r;
        shapes.emplace_back(r);
        break;
      }
    }
  }
  return shapes;
}

void shapes()
{
  auto shapes = generateShapes();
  
  auto lambda = [](std::string shapeString){std::cout << "Shape: " << shapeString << "\n";};
  
  ForEach(shapes, lambda);


  Triangle* memShape = new Triangle();
  delete memShape;
  
  
}