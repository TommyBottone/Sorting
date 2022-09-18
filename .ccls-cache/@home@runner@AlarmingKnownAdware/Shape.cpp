#include "Shape.h"

Shape::Shape()
{
  initializeMap();
}

Shape::Shape(SHAPE_TYPE type) : _type(type)
{
  initializeMap();
}

Shape::~Shape()
{
  
}
void Shape::initializeMap()
{
    _shapeMap = {
    {CIRCLE, "CIRCLE"}, 
    {LINE, "LINE"},
    {TRIANGLE, "TRIANGLE"},
    {RECTANGLE, "RECTANGLE"}};
  }

std::string Shape::toString()
{
  return _shapeMap[_type];
}

Circle::Circle() : Shape(CIRCLE)
{
  
}

Circle::Circle(float radius) : _radius(radius)
{
  Circle();
}

Circle::~Circle()
{
  
}

Line::Line(): Shape(LINE)
{
  
}
Line::Line(float length) : _length(length)
{
  Line();
}

Line::~Line()
{
  
}

Triangle::Triangle(): Shape(TRIANGLE)
{
  
}

Triangle::Triangle(float side1, float side2, float side3):
  _side1(side1),
  _side2(side2),
  _side3(side3)
{
  Triangle();
}

Triangle::~Triangle()
{
  
}

Rectangle::Rectangle():Shape(RECTANGLE)
{
  
}

Rectangle::Rectangle(float length, float width):
_length(length),
_width(width)
{
  Rectangle();
}


Rectangle::~Rectangle()
{
  
}
