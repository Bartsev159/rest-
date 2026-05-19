// =========================
// main.cpp
// =========================

#include <iostream>

// подключение модулей
#include "camera.cpp"
#include "ai_assistant.cpp"

class RobotSystem {
private:
    Camera camera;

    AIAssistant ai;

public:

    void run(int steps) {

        for (int i = 0; i < steps; i++) {

            Frame frame =
                camera.captureFrame();

            camera.printFrameInfo(
                frame
            );

            std::string decision =
                ai.analyzeFrame(
                    frame
                );

            ai.printAnalysis(
                frame,
                decision
            );

            if (
                decision ==
                "BOOST_MODE"
            ) {

                std::cout
                    << "[BOOST] "
                    << "Propeller module activated"
                    << std::endl;
            }

            std::cout
                << "----------------------"
                << std::endl;
        }
    }
};

int main() {

    RobotSystem system;

    system.run(20);

    return 0;
}
