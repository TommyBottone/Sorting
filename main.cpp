#include "SmartPtr.h"
#include "Sort.h"
#include "Producer.h"
#include "Shape.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "Benchmark.h"
void sorting();
void produce();
void shapes();

std::unordered_map<std::string, bool> procMap = 
{
  {"sorting", false},
  {"produce", false},
  {"shapes", false},
  {"benchmark", false}
};

int main(int argc, char** argv) 
{ 
  if(argc > 1)
  {
    int iter = 1;
    while(iter < argc)
    {
      procMap[argv[iter]] = true;
      iter++;
    }
  }
  Benchmark bmark("Main Benchmark");
  if(procMap["benchmark"])
  {
    bmark.start();
  }
  if(procMap["sorting"])
  {
    sorting(); 
    std::cout << std::endl;
  }
  if(procMap["produce"])
  {
    produce();
    std::cout << std::endl;
  }
  if(procMap["shapes"])
  {
    shapes();
  }
  return 0;
}

void sorting() 
{
  Benchmark sorting("sorting");
  if(procMap["benchmark"])
  {
    sorting.start();
  }
  SmartPtr<Sort> sort(new Sort());

  std::vector<int> unsorted = sort->createRandomList();
  std::cout << "Unsorted list: ";
  
  sort->printList(unsorted);

  std::async(std::launch::async,
  [&sort, unsorted]()
  {
     Benchmark insert("INSERTION");
    if(procMap["benchmark"])
    {
      insert.start();
    }
    sort->doInsertionSort(unsorted);
  });
  std::async(std::launch::async,
  [&sort, unsorted]()
  {
     Benchmark sel("SELECTION");
    if(procMap["benchmark"])
    {
      sel.start();
    }
    sort->doSelectionSort(unsorted);
  });
  std::async(std::launch::async,
  [&sort, unsorted]()
  {
    Benchmark merg("MEERGE");
    if(procMap["benchmark"])
    {
      merg.start();
    }
    sort->doMergeSort(unsorted);
  });
  std::async(std::launch::async,
  [&sort, unsorted]()
  {
    Benchmark quick("QUICK");
    if(procMap["benchmark"])
    {
      quick.start();
    }
    sort->doQuickSort(unsorted);
  });
}

void produce()
{
  Benchmark benchmark("produce");
  if(procMap["benchmark"])
  {
    //this one is kinda funny because it has to wait for user input
    benchmark.start();
  }
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
  Benchmark bshape("SHAPES");
  if(procMap["benchmark"])
  {
    bshape.start();
  }
  auto shapes = generateShapes();
  
  auto lambda = [](std::string shapeString){std::cout << "Shape: " << shapeString << "\n";};
  
  ForEach(shapes, lambda);


  Triangle* memShape = new Triangle();
  delete memShape;
  
  
}