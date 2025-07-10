void __cdecl Scaleform::Render::Math2D::PointOnQuadCurve(
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float t,
        float *x,
        float *y)
{
  double v9; // st2
  float x12; // [esp+4h] [ebp+4h]
  float x2a; // [esp+Ch] [ebp+Ch]
  float x2b; // [esp+Ch] [ebp+Ch]
  float y12; // [esp+1Ch] [ebp+1Ch]

  x12 = x1 + (x2 - x1) * t;
  v9 = t;
  y12 = (y2 - y1) * t + y1;
  x2a = x2 + (x3 - x2) * v9;
  *x = (x2a - x12) * v9 + x12;
  x2b = y2 + (y3 - y2) * v9;
  *y = v9 * (x2b - y12) + y12;
}
