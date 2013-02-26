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


int main()
{
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
      // Add the rest of the code to allocate a new rectangle
      //  and add it to the shapeList

    }
    // Square case
    else if(selection == 3){
      double s;
      cin >> s;
      // Add the rest of the code to allocate a new square
      //  and add it to the shapeList

    }
    // Circle case
    else if(selection == 4){
      double r;
      cin >> r;
      // Add the rest of the code to allocate a new circle
      //  and add it to the shapeList

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
