#include <iostream>
#include <map>
class Shape
{
public:
  enum SHAPE_TYPE
  {
      CIRCLE,
      LINE,
      TRIANGLE,
      RECTANGLE
  };
  
  Shape();
  Shape(SHAPE_TYPE type);
  void setType(SHAPE_TYPE type);
  const inline SHAPE_TYPE getType(){return _type;}
  ~Shape();
  std::string toString();
private:
  void initializeMap();
  std::map<SHAPE_TYPE, std::string> _shapeMap;
  SHAPE_TYPE _type;
};

class Circle : public Shape
{
public:
  Circle();
  Circle(float radius);
  ~Circle();
  inline void setRadius(int radius){_radius = radius;}
  const inline float getRadius(){return _radius;}
private:
  float _radius;
};

class Line : public Shape
{
public:
  Line();
  Line(float length);
  ~Line();
  inline void setLength(float length){_length = length;}
  const inline float getLength(){return _length;}
private:
  float _length;
};

class Triangle : public Shape
{
public:
  Triangle();
  Triangle(float side1, float side2, float side3);
  ~Triangle();
  inline void setDimensions(float side1, float side2, float side3)
  {
    _side1 = side1;
    _side2 = side2;
    _side3 = side3;
  }
  inline void getDimensions(float &side1, float &side2, float &side3)
  {
    side1 = -side1;
    side2 = _side2;
    side3 = _side3;
  }
private:
  float _side1;
  float _side2;
  float _side3;
};

class Rectangle : public Shape
{
public:
  Rectangle();
  Rectangle(float length, float width);
  ~Rectangle();
  void setDimensions(float length, float width)
  {
    _length = length;
    _width = width;
  }
  void getDimensions(float &length, float &width)
{
  length = _length;
  width = _width;
}
private:
  float _length;
  float _width;
};