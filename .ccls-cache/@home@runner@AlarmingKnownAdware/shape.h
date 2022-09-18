class Shape
{
  enum SHAPE_TYPE
  {
      CIRCLE = 0,
      LINE,
      TRIANGLE,
      RECTANGLE
  };

  Shape();
  Shape(SHAPE_TYPE type);
  void setType(SHAPE_TYPE type);
  const inline SHAPE_TYPE getType(){return _type;}
  ~Shape();
private:
  SHAPE_TYPE _type;
};

class Circle : public Shape
{
  Circle();
  Circle(float radius);
  ~Circle();
  void setRadius(int radius);
  const inline float getRadius(){return _radius;}
private:
  float _radius;
};

class Line : public Shape
{
  Line();
  Line(float length);
  ~Line();
  void setLength(int length);
  const inline float getLength(){return _length;}
private:
  float _length;
};

class Triangle : public Shape
{
  Triangle();
  Triangle(float length1, float length2, float length3);
  ~Triangle();
  void setDimensions(int length);
  void getDimensions(float &side1, float &side2, float &side3);
private:
  float _side1;
  float _side2;
  float _side3;
};

class Rectangle : public Shape
{
  Rectangle();
  Rectangle(float length1, float length2, float length3, float length4);
  ~Rectangle();
  void setDimensions(int length);
  void getDimensions(float &side1, float &side2, float &side3, float &side4);
private:
  float _side1;
  float _side2;
  float _side3;
  float _side4;
};