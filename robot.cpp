#include <iostream>

class Robot {
public:
    double x;
    double y;
    double speed;

    Robot() {
        x = 0;
        y = 0;
        speed = 1;
    }

    void move() {
        x += speed;
        y += speed;
    }

    void boost() {
        speed = 3;
        x += speed;
        y += speed;
    }

    void resetSpeed() {
        speed = 1;
    }

    void print() {
        std::cout
            << "[ROBOT] "
            << "x=" << x
            << " y=" << y
            << " speed=" << speed
            << std::endl;
    }
};
