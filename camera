// =========================
// camera.cpp
// =========================

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

struct Frame {
    int id;
    std::string objectType;
    bool obstacleDetected;
};

class Camera {
private:
    int frameCounter;

    std::string generateScene() {

        std::string scenes[] = {
            "road",
            "road",
            "curb",
            "puddle",
            "road",
            "obstacle"
        };

        int index = rand() % 6;

        return scenes[index];
    }

public:
    Camera() {
        frameCounter = 0;
        srand(time(0));
    }

    bool detectObstacle(
        const std::string& scene
    ) {

        if (scene == "curb") {
            return true;
        }

        if (scene == "puddle") {
            return true;
        }

        if (scene == "obstacle") {
            return true;
        }

        return false;
    }

    Frame captureFrame() {

        frameCounter++;

        Frame frame;

        frame.id = frameCounter;

        frame.objectType =
            generateScene();

        frame.obstacleDetected =
            detectObstacle(
                frame.objectType
            );

        return frame;
    }

    void printFrameInfo(
        const Frame& frame
    ) {

        std::cout
            << "[CAMERA] "
            << "Frame ID: "
            << frame.id
            << " | Object: "
            << frame.objectType
            << " | Obstacle: ";

        if (frame.obstacleDetected) {
            std::cout << "YES";
        }
        else {
            std::cout << "NO";
        }

        std::cout << std::endl;
    }
};
