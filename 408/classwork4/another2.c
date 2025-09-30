// sushant aryal
// w10166204

#include <stdio.h>

struct Circle {
    double x, y, r;
};

struct Rectangle {
    double x, y, w, h;
};

struct Triangle {
    double x, y, base, height;
};

struct GeoObject {
    enum {CIRCLE = 0, RECTANGLE, TRIANGLE} type;
    union {
        struct Circle c;
        struct Rectangle r;
        struct Triangle t;
    } shape;
    void (*draw)(struct GeoObject);
};

void showCircle(struct GeoObject obj) {
    printf("Circle -> Position(%.2f, %.2f) Radius: %.2f\n", obj.shape.c.x, obj.shape.c.y, obj.shape.c.r);
}

void showRectangle(struct GeoObject obj) {
    printf("Rectangle -> Position(%.2f, %.2f) Width: %.2f Height: %.2f\n",
           obj.shape.r.x, obj.shape.r.y, obj.shape.r.w, obj.shape.r.h);
}

void showTriangle(struct GeoObject obj) {
    printf("Triangle -> Position(%.2f, %.2f) Base: %.2f Height: %.2f\n",
           obj.shape.t.x, obj.shape.t.y, obj.shape.t.base, obj.shape.t.height);
}

int main() {
    struct GeoObject g;

    g.type = CIRCLE;
    g.shape.c.x = 10.0;
    g.shape.c.y = 20.0;
    g.shape.c.r = 5.5;
    g.draw = showCircle;
    g.draw(g);

    g.type = RECTANGLE;
    g.shape.r.x = 30.0;
    g.shape.r.y = 40.0;
    g.shape.r.w = 15.0;
    g.shape.r.h = 25.0;
    g.draw = showRectangle;
    g.draw(g);

    g.type = TRIANGLE;
    g.shape.t.x = 50.0;
    g.shape.t.y = 60.0;
    g.shape.t.base = 12.0;
    g.shape.t.height = 7.5;
    g.draw = showTriangle;
    g.draw(g);

    return 0;
}
