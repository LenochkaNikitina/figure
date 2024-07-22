#include <iostream>
#include<vector>
#include <fstream>
#include <format>
#include<string>

using namespace std;

class Shape {
public:
    virtual void Show() = 0;
    virtual void Save() = 0;
    virtual void Load() = 0; 
};

class Square : public Shape {
    int x, y;
    double side;

public:
    Square(int x, int y, double side) {
        this->x = x;
        this->y = y;
        this->side = side;
    }
    void Show() override {
        cout << "Координаты вершины: " << x << ", " << y << endl;
        cout << "Длина стороны: " << side << endl;
    }

    void Save() override {
        ofstream out;
        out.open("squares.txt", ios::app);

        out << To_string();
        out << "\n";

        out.close();
    }

    void Load() override {

    }

    string To_string() {
        return format("Координаты вершины: x={}, y={}, сторона {} ", x, y, side);
    }
};

class Rectangle : public Shape {
    int x, y;
    double width;
    double length;
public:
    Rectangle(int x, int y, double width, double length) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->length = length;
    }
    void Show() override {
        cout << "Координаты вершины: " << x << ", " << y << endl;
        cout << "Ширина: " << width << "Длина: " << length << endl;
    }
    
    void Save() override {
        ofstream out;
        out.open("rectangles.txt", ios::app);

  //      out << To_string();
        out << "\n";

        out.close();
    }

    void Load() override {

    }
    /*
    string To_string() {
        return format("Координаты вершины: x={}, y={}, сторона {} \n Длина: {}, Ширина: {}",
            x, y, length, width);
    }
    */
};

class Circle :public Shape {
    int x, y;
    double radius;
public:
    Circle(int x, int y, double radius) {
        this->x = x;
        this->y = y;
        this->radius = radius;
    }
    void Show() override {
        cout << "Координаты вершины: " << x << ", " << y << endl;
        cout << "Радиус: " << radius << endl;
    }

    void Save() override {
        ofstream out;
        out.open("circless.txt", ios::app);

        out << To_string();
        out << "\n";

        out.close();
    }

    void Load() override {

    }

    string To_string() {
        return format("Координаты вершины: x={}, y={}, радиус: {} ", x, y, radius);
    }
};

class Ellipse : public Shape {
    int x, y;
    double width;
    double length;
public:
    Ellipse(int x, int y, double width, double length) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->length = length;
    }

    void Show() override {
        cout << "Координаты вершины: " << x << ", " << y << endl;
        cout << "Ширина: " << width << "Длина: " << length << endl;
    }
    
    void Save() override {
        ofstream out;
        out.open("circles.txt", ios::app);

  //      out << To_string();
        out << "\n";

        out.close();
    }

    void Load() override {

    }
    /*
    string To_string() {
        return format("Координаты вершины: x={}, y={}, сторона {} \n Длина: {}, Ширина: {}",
            x, y, length, width);
    }
    */
};

int main() {
    vector<Square> squares;
    vector<Rectangle> rectangles;
    vector<Circle> circles;
    vector<Ellipse> ellipses;

    for (int i = 0; i < 5; i++) {
        Square square(i, i * 2, i + 3);
        squares.push_back(square);
    }

    for (int i = 0; i < 5; i++) {
        squares[i].Save();
    }


    for (int i = 0; i < 5; i++) {
        Rectangle rectangle(i, i * 2, i + 3, i+2);
        rectangles.push_back(rectangle);
    }

    for (int i = 0; i < 5; i++) {
        Circle circle(i, i * 2, i + 3);
        circles.push_back(circle);
    }

    for (int i = 0; i < 5; i++) {
        circles[i].Save();
    }

    for (int i = 0; i < 5; i++) {
        Ellipse ellipse(i, i * 2, i + 3, i + 2);
        ellipses.push_back(ellipse);
    }
}

