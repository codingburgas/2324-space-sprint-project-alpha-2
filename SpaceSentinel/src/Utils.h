#pragma once
#include <raylib.h>



inline Color operator!(const Color& color)
{
    Color newColor;
    newColor.r = 255 - color.r;
    newColor.g = 255 - color.g;
    newColor.b = 255 - color.b;
    newColor.a = color.a;

    return newColor;
}

inline Color operator-(const Color& color1, const Color& color2)
{
    Color newColor;

    if (color1.r < color2.r) newColor.r = 0;
    else newColor.r = color1.r - color2.r;

    if (color1.g < color2.g) newColor.g = 0;
    else newColor.g = color1.g - color2.g;

    if (color1.b < color2.b) newColor.b = 0;
    else newColor.b = color1.b - color2.b;

    newColor.a = 255;

    return newColor;
}

inline void DrawTextCentered(const Font& font, const char* text, const Vector2& pos, const float& fontSize, const Color& fontColor)
{
    DrawTextEx(font, text, Vector2(GetRenderWidth() / 100.f * pos.x - MeasureTextEx(font, text, fontSize, 2).x / 2.f, GetRenderHeight() / 100.f * pos.y - MeasureTextEx(font, text, fontSize, 2).y / 2.f), fontSize, 2, fontColor);
}


inline void DrawTextSCentered(const Font& font, const char* text, const Vector2& pos, const float& fontSize, const Color& fontColor)
{
    DrawTextEx(font, text, Vector2(GetRenderWidth() / 100.f * (pos.x - 0.2f) - MeasureTextEx(font, text, fontSize, 2).x / 2.f, GetRenderHeight() / 100.f * (pos.y + 0.2f) - MeasureTextEx(font, text, fontSize, 2).y / 2.f), fontSize, 2, fontColor - Color(150, 150, 150, 255));

    DrawTextEx(font, text, Vector2(GetRenderWidth() / 100.f * pos.x - MeasureTextEx(font, text, fontSize, 2).x / 2.f, GetRenderHeight() / 100.f * pos.y - MeasureTextEx(font, text, fontSize, 2).y / 2.f), fontSize, 2, fontColor);
}