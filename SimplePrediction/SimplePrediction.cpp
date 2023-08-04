#include <iostream>
#include <cmath>

struct Vector2D {
    float x;
    float y;
};

class SkillShotPredictor {
private:
    Vector2D targetPosition;
    Vector2D targetVelocity;
    float skillShotSpeed;
    float castingTime;

public:
    SkillShotPredictor(const Vector2D& targetPos, const Vector2D& targetVel, float speed, float castTime)
        : targetPosition(targetPos), targetVelocity(targetVel), skillShotSpeed(speed), castingTime(castTime) {}

    Vector2D predict() {
        Vector2D relativePosition = { targetPosition.x - castingTime * targetVelocity.x, targetPosition.y - castingTime * targetVelocity.y };
        float distance = std::sqrt(relativePosition.x * relativePosition.x + relativePosition.y * relativePosition.y);

        float timeToHit = distance / skillShotSpeed;

        Vector2D predictedPosition = {
            targetPosition.x + timeToHit * targetVelocity.x,
            targetPosition.y + timeToHit * targetVelocity.y
        };

        return predictedPosition;
    }
};

int main() {
    Vector2D targetPosition = { 100.0f, 50.0f };
    Vector2D targetVelocity = { 5.0f, 0.0f };
    float skillShotSpeed = 20.0f; // Travel speed of skillshot
    float castingTime = 0.5f;     // Casting time of the skill shot in seconds

    SkillShotPredictor predictor(targetPosition, targetVelocity, skillShotSpeed, castingTime);
    Vector2D predictedPosition = predictor.predict();

    std::cout << "Predicted skill shot position: (" << predictedPosition.x << ", " << predictedPosition.y << ")" << std::endl;

    return 0;
}
