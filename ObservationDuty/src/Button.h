#pragma once
#include <raylib.h>
#include "Utils.h"


#define MAX_TOUCH_POINTS 10

int Button(void)
{
    Vector2 touchPositions[MAX_TOUCH_POINTS] = { 0 };

    while (!WindowShouldClose())
    {

        int tCount = GetTouchPointCount();
        if (tCount > MAX_TOUCH_POINTS) tCount = MAX_TOUCH_POINTS;

        for (int i = 0; i < tCount; i++) touchPositions[i] = GetTouchPosition(i);
        BeginDrawing();

        for (int i = 0; i < tCount; i++)
        {

            if ((touchPositions[i].x > 0) && (touchPositions[i].y > 0))
            {

                DrawCircleV(touchPositions[i], 34, ORANGE);
                DrawText(TextFormat("%d", i), (int)touchPositions[i].x - 10, (int)touchPositions[i].y - 70, 40, BLACK);
            }
        }

        EndDrawing();
    }

    return 0;
}