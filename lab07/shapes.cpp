#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Shape 
{
 public:
  virtual ~Shape() { }
  virtual double getArea() = 0;
  virtual double getPerimeter() = 0;
  virtual string getType() = 0;
};

class RightTriangle : public Shape 
{
 public:
  RightTriangle(double b, double h) : _b(b), _h(h) { }
  ~RightTriangle() { }
  double getArea() { return 0.5*_b*_h; }
  double getPerimeter() { return sqrt(_b*_b + _h*_h) + _h + _b; }
  string getType() { return "Right Triangle"; }
private:
  double _b, _h;
};

class Rectangle : public Shape
{
	public:
		Rectangle(double b, double h) : _b(b), _h(h) { }
		~Rectangle() { }
		double getArea() { return _b*_h; }
		double getPerimeter() { return 2*_b + 2*_h; }
		string getType() { return "Rectangle"; }
	private:
		double _b, _h;
};

class Circle : public Shape
{
	public:
		Circle(double r) : _r(r) { }
		~Circle() { }
		double getArea() { return 3.14159*(_r*_r); }
		double getPerimeter() { return 2*3.14159*_r; }
		string getType() { return "Circle"; }
	private:
		double _r;
};

class Square : public Shape
{
	public:
		Square(double s) : _s(s) { }
		~Square() { }
		double getArea() { return _s*_s; }
		double getPerimeter() { return 4*_s; }
		string getType() { return "Square"; }
	private:
		double _s;
};


int main()
{
	//Shape myShape;
	
  vector<Shape *> shapeList;

  int selection = -1;
  while(selection != 0){
    cout << "Choose an option:" << endl;
    cout << "=================" << endl;
    cout << "Enter '0' to quit" << endl;
    cout << "Enter '1 base height' for a right triangle with given base and height" << endl;
    cout << "Enter '2 base height' for a rectangle with given base and height" << endl;
    cout << "Enter '3 side' for a square with given side length" << endl;
    cout << "Enter '4 radius' for a circle with given radius" << endl;
    cout << "> ";
    cin >> selection;
    // Right Triangle case
    if(selection == 1){
      double b, h;
      cin >> b >> h;
      shapeList.push_back(new RightTriangle(b,h));
    }
    // Rectangle case
    else if(selection == 2){
      double b, h;
      cin >> b >> h;
      shapeList.push_back(new Rectangle(b,h));
    }
    // Square case
    else if(selection == 3){
      double s;
      cin >> s;
      shapeList.push_back(new Square(s));
    }
    // Circle case
    else if(selection == 4){
      double r;
      cin >> r;
      shapeList.push_back(new Circle(r));
    }
  }

  for (vector<Shape *>::iterator it = shapeList.begin() ; 
       it != shapeList.end(); 
       ++it)
    {
      Shape *s = *it;
      cout << s->getType() << ": Area=" << s->getArea() << " Perim=" << s->getPerimeter() << endl;
      delete s;
    }
  return 0;
}
