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

const float Circle::perimeter()
{
  float perimeter = 0;

  perimeter = PI * 2 * _radius;
  //this is pretty much a circumference

  return perimeter;
}

const float Circle::area()
{
  float area = 0;

  area = PI * (_radius * _radius);

  return area;
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


const float Triangle::perimeter()
{
  float perimeter = 0;

  perimeter = _side1 + _side2 + _side3;

  return perimeter;
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

const float Rectangle::perimeter()
{
  float perimeter = 0;

  perimeter = (_length * 2) + (_width * 2);

  return perimeter;
}

const float Rectangle::area()
{
  float area = 0;

  area = _length * _width;

  return area;
}