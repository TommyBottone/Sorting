#include <iostream>
#include <map>
#include "MemTrack.h"

static const float PI = 3.14159;

class Shape: public MemTracker
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
  virtual const float perimeter(){}
  virtual const float area(){}
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
  const float perimeter();
  const float area();
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
  inline float operator+(float length) {_length += length; return _length;}
  inline bool operator==(Line line)
  {
     return line.getLength() == _length; 
  }
  const float perimeter(){return 0;};
  const float area(){return 0;};
private:
  float _length;
};

class Triangle : public Shape
{
public:
  Triangle();
  Triangle(float side1, float side2, float side3);
  ~Triangle();
  inline void setDimensions(const float &side1, const float &side2, const float &side3)
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
  inline bool operator==(Triangle t)
  {
    float s1, s2, s3;
    t.getDimensions(s1,s2,s3);
    
    return _side1 == s1 && _side2 == s2 && _side3 == s3;
  }
  const float perimeter();
const float area() {return 0; /*NGL kinda difficult without height*/};
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
  void setDimensions(const float &length, const float &width)
  {
    _length = length;
    _width = width;
  }
  void getDimensions(float &length, float &width)
  {
    length = _length;
    width = _width;
  }

  inline bool operator==(Rectangle r)
  {
    float l, w;
    r.getDimensions(l, w);
    
    return _length == l && _width == w;
  }
  const float perimeter();
  const float area();
private:
  float _length;
  float _width;
};
