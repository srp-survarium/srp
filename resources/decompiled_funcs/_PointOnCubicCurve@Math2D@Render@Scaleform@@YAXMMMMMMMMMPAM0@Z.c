void __cdecl Scaleform::Render::Math2D::PointOnCubicCurve(
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float x4,
        float y4,
        float t,
        float *x,
        float *y)
{
  double v11; // st6
  double v12; // st5
  double v13; // st4
  double v14; // st3
  float x12; // [esp+4h] [ebp+4h]
  float x12a; // [esp+4h] [ebp+4h]
  float x23; // [esp+Ch] [ebp+Ch]
  float x23a; // [esp+Ch] [ebp+Ch]
  float x23b; // [esp+Ch] [ebp+Ch]
  float x23c; // [esp+Ch] [ebp+Ch]
  float x23d; // [esp+Ch] [ebp+Ch]
  float y12; // [esp+10h] [ebp+10h]
  float y23; // [esp+24h] [ebp+24h]
  float y23a; // [esp+24h] [ebp+24h]

  v11 = t;
  x12 = x1 + (x2 - x1) * t;
  v12 = y2;
  y12 = (y2 - y1) * t + y1;
  x23 = x2 + (x3 - x2) * t;
  y23 = v12 + (y3 - v12) * t;
  v13 = x23;
  x12a = (x23 - x12) * v11 + x12;
  v14 = y23;
  y23a = (y23 - y12) * v11 + y12;
  x23a = x3 + (x4 - x3) * v11;
  x23b = v13 + (x23a - v13) * v11;
  *x = (x23b - x12a) * v11 + x12a;
  x23c = y3 + (y4 - y3) * v11;
  x23d = v14 + (x23c - v14) * v11;
  *y = v11 * (x23d - y23a) + y23a;
}
