#include <iostream>
#include <graphics.h>=

using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void set_x(int n);
    void set_y(int n);
    int get_x();
    int get_y();
};

void Point::set_x(int n) {
    x = n;
}

void Point::set_y(int n) {
    y = n;
}

int Point::get_x() {
    return x;
}

int Point::get_y() {
    return y;
}

class Line {
private:
    Point start;
    Point end;
public:
    Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2) {}
    void draw() {
        line(start.get_x(), start.get_y(), end.get_x(), end.get_y());
    }
};

class Rect {
private:
    Point ul;
    Point rl;
public:
    Rect(int x1, int y1, int x2, int y2) : ul(x1, y1), rl(x2, y2) {}
    void draw() {
        rectangle(ul.get_x(), ul.get_y(), rl.get_x(), rl.get_y());
    }
};
class Circle {
private:
    Point center;
    int radius;
public:
    Circle(int x, int y, int r) : center(x, y) {
        radius = r;
    }
    void draw() {
        circle(center.get_x(), center.get_y(), radius);
    }
};
class Picture {
private:
   int cNum;
   int rNum;
   int lNum;
   Circle* pCircles;
   Rect*  pRects;
   Line* pLines;
public:
    Picture(int cn, int rn, int ln, Circle* pc, Rect* pR, Line* pL)
    {

        cNum = cn;
        rNum = rn;
        lNum = ln;
        pCircles = pc;
        pRects = pR;
        pLines = pL;
    }
    void draw(){
        int i;
        for (i = 0; i < cNum; i++) {
            pCircles[i].draw();
        }

        for (i = 0; i < rNum; i++) {
            pRects[i].draw();
        }

        for (i = 0; i < lNum; i++) {
            pLines[i].draw();
        }
    }
};
int main() {
    initwindow(800, 600);

    Line lines[] = {
        Line(100, 100, 200, 100),
        Line(200, 100, 200, 200)
    };

    Rect rects[] = {
        Rect(300, 100, 400, 200)
    };

    Circle circles[] = {
        Circle(500, 300, 50),
        Circle(600, 350, 30)
    };

    Picture pic(2, 1, 2, circles, rects, lines);
    pic.draw();

    getch();
    closegraph();
    return 0;
}

