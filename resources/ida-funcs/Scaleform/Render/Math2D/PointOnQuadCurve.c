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
  float v10; // [esp+4h] [ebp+4h]
  float v11; // [esp+Ch] [ebp+Ch]
  float v12; // [esp+Ch] [ebp+Ch]
  float v13; // [esp+1Ch] [ebp+1Ch]

  v10 = x1 + (x2 - x1) * t;
  v9 = t;
  v13 = (y2 - y1) * t + y1;
  v11 = x2 + (x3 - x2) * v9;
  *x = (v11 - v10) * v9 + v10;
  v12 = y2 + (y3 - y2) * v9;
  *y = v9 * (v12 - v13) + v13;
}
