#ifndef RAYAPP_H
#define RAYAPP_H

#include "Midi.h"
#include "raylib.h"


class RayApp {
public:
    void setup();
    void update(double t, double dt);
    void draw() const;

private:
    Vector2 ballPosition = {};
    float ballRadius = 0.0f;
    Vector2 ballSpeed = {};
    bool pause = false;
    int framesCounter = 0;
    MIDI midi;
};


#endif //RAYAPP_H
