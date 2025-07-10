double __cdecl Scaleform::Render::Math2D::PointToSegmentPos(float x1, float y1, float x2, float y2, float x, float y)
{
  double v6; // st7
  double v7; // st3
  float dy; // [esp+4h] [ebp+4h]
  float x2a; // [esp+Ch] [ebp+Ch]

  v6 = x1;
  x2a = x2 - x1;
  dy = y2 - y1;
  v7 = dy;
  if ( x2a == 0.0 && 0.0 == v7 )
    return 0.0;
  return (float)((dy * (y - y1) + x2a * (x - v6)) / (x2a * x2a + v7 * v7));
}
