#include <iostream>
#include "camera.cpp"
#include "ai_assistant.cpp"
#include "robot.cpp"

class RobotSystem {
private:
    Camera camera;
    AIAssistant ai;
    Robot robot;

public:
    void run(int steps) {

        for (int i = 0; i < steps; i++) {

            Frame frame = camera.captureFrame();

            std::string decision =
                ai.analyzeFrame(frame);

            // 🚀 ДВИЖЕНИЕ РОБОТА
            if (decision == "MOVE") {
                robot.resetSpeed();
                robot.move();
            }

            else if (decision == "BOOST_MODE") {
                robot.boost();
            }

            else if (decision == "STOP") {
                // ничего не делаем
            }

            // вывод
            camera.printFrameInfo(frame);
            ai.printAnalysis(frame, decision);
            robot.print();

            std::cout << "------------------" << std::endl;
        }
    }
};

int main() {
    RobotSystem system;
    system.run(20);
}
