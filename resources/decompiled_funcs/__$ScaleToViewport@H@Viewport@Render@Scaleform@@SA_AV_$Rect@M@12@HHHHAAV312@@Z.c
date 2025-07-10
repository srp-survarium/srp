Scaleform::Render::Rect<float> *__cdecl Scaleform::Render::Viewport::ScaleToViewport<int>(
        Scaleform::Render::Rect<float> *result,
        int left,
        int top,
        int width,
        int height,
        Scaleform::Render::Rect<float> *bounds)
{
  Scaleform::Render::Rect<float> *v6; // eax
  double v7; // st5
  float v8; // [esp+Ch] [ebp-4h]
  float v9; // [esp+Ch] [ebp-4h]

  v6 = result;
  v8 = (float)width;
  v7 = v8;
  result->x1 = (bounds->x1 + 1.0) * v8 * 0.5;
  v9 = (float)height;
  result->y1 = (1.0 - bounds->y2) * v9 * 0.5;
  result->x2 = v7 * (bounds->x2 + 1.0) * 0.5;
  result->y2 = 0.5 * ((1.0 - bounds->y1) * v9);
  return v6;
}
