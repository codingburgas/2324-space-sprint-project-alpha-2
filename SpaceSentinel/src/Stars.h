#pragma once // Include pragma once instead of include guards

#include <raylib.h>

class Star {
public:
    Star(const Vector2& position);
    void Update();
    void Draw() const;

private:
    Vector2 position;
};
