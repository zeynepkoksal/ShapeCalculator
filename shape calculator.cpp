#include <iostream>
#include <string>
#include <stdexcept> 
using namespace std;

const double PI = 3.14159; 

class Shape {
public:
    virtual string getName() {
        return "Shape class";
    }

    virtual void calcArea() {
        cout << "Area of the shape not calculated in this function." << endl;
    }

    virtual void calcPerimeter() {
        cout << "Perimeter of the shape cannot be calculated in this function." << endl;
    }

    virtual ~Shape() {} 
};

class Circle : public Shape {
private:
    string name = "Circle";
    double radius;

public:
    string getName() override {
        return name;
    }

    void setRadius(double r) {
        radius = r;
    }

    void calcArea() override {
        cout << "Area of the circle is " << PI * radius * radius << endl;
    }

    void calcPerimeter() override {
        cout << "Perimeter of the circle is " << 2 * PI * radius << endl;
    }
};

class Rectangle : public Shape {
private:
    string name = "Rectangle";
    double side1;
    double side2;

public:
    string getName() override {
        return name;
    }

    void setSides(double s1, double s2) {
        side1 = s1;
        side2 = s2;
    }

    void calcArea() override {
        cout << "Area of the rectangle is " << side1 * side2 << endl;
    }

    void calcPerimeter() override {
        cout << "Perimeter of the rectangle is " << 2 * (side1 + side2) << endl;
    }
};

void chooseCalc(Shape& shape) {
    char operation;
    cout << "Would you like to calculate area or perimeter for " << shape.getName() << endl;
    cin >> operation;

    if (operation == 'a') {
        shape.calcArea();
    } else if (operation == 'p') {
        shape.calcPerimeter();
    } else {
        cout << operation << " choice is invalid. Please enter a for area and p for perimeter" << endl;
    }
}

int main() {
    Circle circle;
    circle.setRadius(5.0);

    Rectangle rectangle;
    rectangle.setSides(4.0, 5.0);

    Shape* shapes[2] = { &circle, &rectangle };

    for (int i = 0; i < 2; i++) {
        chooseCalc(*shapes[i]);
        cout << endl;
    }

    return 0;
}

