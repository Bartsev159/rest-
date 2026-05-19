// =========================
// ai_assistant.cpp
// =========================

#include <iostream>
#include <string>

class AIAssistant {
private:
    int obstacleCounter;

    std::string lastDecision;

public:
    AIAssistant() {

        obstacleCounter = 0;

        lastDecision = "MOVE";
    }

    bool shouldActivateBoost(
        const Frame& frame
    ) {

        if (frame.objectType == "curb") {
            return true;
        }

        if (frame.objectType == "puddle") {
            return true;
        }

        return false;
    }

    std::string analyzeFrame(
        const Frame& frame
    ) {

        if (frame.obstacleDetected) {

            obstacleCounter++;

            if (
                shouldActivateBoost(frame)
            ) {

                lastDecision =
                    "BOOST_MODE";

                return "BOOST_MODE";
            }

            lastDecision = "STOP";

            return "STOP";
        }

        obstacleCounter = 0;

        lastDecision = "MOVE";

        return "MOVE";
    }

    void printAnalysis(
        const Frame& frame,
        const std::string& decision
    ) {

        std::cout
            << "[AI] "
            << "Frame: "
            << frame.id
            << " | Decision: "
            << decision
            << std::endl;
    }
};
