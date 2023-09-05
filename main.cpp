#include <iostream>
#include <cmath>

class Shape {
  double xC;
  double yC;
  int color;
 public:
  Shape() : xC(0.0), yC(0.0), color(0) {}
  Shape(double xC, double yC, int color) { this->xC = xC, this->yC = yC, this->color = color; }
  void setShape() {
	std::cout << "Enter coordinates for the center < X > and < Y >: ";
	std::cin >> xC >> yC;
	std::cout << "Enter color for the circle: "
			  << "NONE-0, RED-1, BLUE-2, GREEN-3: ";
	std::cin >> color;
  }
  void showShape() const {
	std::cout << "---------------------------------------------------------------------------\n"
			  << "Coordinates center < X > " << xC << ":" << " < Y > " << yC
			  << "\tColor: " << getColor() << std::endl;
  }
  double getX() const { return xC; }
  double getY() const { return yC; }

  std::string getColor() const {
	if (color == 0) return "NONE";
	else if (color == 1) return "RED";
	else if (color == 2) return "BLUE";
	else if (color == 3) return "GREEN";
	else return "Error!";
  }
};

class Circle : private Shape {
  double radius{};
 public:
  void setShape() {
	Shape::setShape();
	std::cout << "Enter radius for the circle: ";
	std::cin >> radius;
  }

  double area() const { return atan(1) * 4 * radius; }
  void getRange() {
	std::cout << "Top point: X = " << getX() << " Y = " << getY() + radius << '\n'
			  << "Low point: X = " << getX() << " Y = " << getY() - radius << '\n';
  }

  void showShape() {
	Shape::showShape();
	std::cout << "Area of circle: " << area() << '\n';
	getRange();
  }
};
class Triangle : private Shape {
  double length{};
 public:
  void setShape() {
	Shape::setShape();
	std::cout << "Enter edge for the triangle: ";
	std::cin >> length;
  }
  double area() const { return length * length * std::sqrt(3) / 4; }

  void getRange() {
	std::cout << "Top point: X = " << getX() << " Y = " << getY() + length / 2 << '\n'
			  << "Low point: X = " << getX() << " Y = " << getY() - length / 2 << '\n';
  }
  void showShape() {
	Shape::showShape();
	std::cout << "Area of triangle: " << area() << '\n';
	getRange();
  }
};
class Square : private Shape {
  double length{};
 public:
  void setShape() {
	Shape::setShape();
	std::cout << "Enter side of square: ";
	std::cin >> length;
  }
  double area() const { return length * length; }

  void getRange() {
	std::cout << "Top point: X = " << getX() << " Y = " << getY() + length / 2 << '\n'
			  << "Low point: X = " << getX() << " Y = " << getY() - length / 2 << '\n';
  }
  void showShape() {
	Shape::showShape();
	std::cout << "Area of square: " << area() << '\n';
	getRange();
  }
};
class Rectangle : private Shape {
  double width{};
  double height{};
 public:
  void setShape() {
	Shape::setShape();
	std::cout << "Enter width and height rectangle: ";
	std::cin >> width >> height;
  }
  double area() const { return width * height; }

  void getRange() {
	std::cout << "Top point: X = " << getX() << " Y = " << getY() + height / 2 << '\n'
			  << "Low point: X = " << getX() << " Y = " << getY() - height / 2 << '\n';
  }
  void showShape() {
	Shape::showShape();
	std::cout << "Area of rectangle: " << area() << '\n';
	getRange();
  }
};
int main() {
  char ch;
  Circle c;
  Square s;
  Triangle t;
  Rectangle r;
  std::cout << "\nEnter the command:\n"
			<< "(C)ircle, (S)quare, (T)riangle, (R)ectangle, (E)xit.\n";
  do {
	std::cin >> ch;
	switch (ch) {
	  case 'C'://if circle
		c.setShape();
		c.showShape();
		break;
	  case 'S'://if square
		s.setShape();
		s.showShape();
		break;
	  case 'T'://if triangle
		t.setShape();
		t.showShape();
		break;
	  case 'R'://if rectangle
		r.setShape();
		r.showShape();
		break;
	  default:if (ch != 'E') std::cout << "Enter error. Repeat please.\n";
		continue;
	}
  } while (ch != 'E');
  return 0;
}
