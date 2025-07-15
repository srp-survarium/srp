bool __cdecl Scaleform::Render::Math2D::Intersection(
        float ax,
        float ay,
        float bx,
        float by,
        float cx,
        float cy,
        float dx,
        float dy,
        float *x,
        float *y,
        float epsilon)
{
  double v11; // st6
  double v12; // st7
  double v13; // st5
  double v14; // st4
  double v15; // st2
  bool result; // al
  float v17; // [esp+4h] [ebp+4h]
  float den; // [esp+Ch] [ebp+Ch]
  float u; // [esp+18h] [ebp+18h]
  float ua; // [esp+18h] [ebp+18h]

  v11 = ax;
  v12 = bx - ax;
  v13 = dy - cy;
  v14 = by - ay;
  v15 = dx - cx;
  den = v13 * v12 - v15 * v14;
  v17 = fabs(den);
  if ( epsilon > (double)v17 )
    return 0;
  u = v15 * (ay - cy) - v13 * (v11 - cx);
  ua = u / den;
  *x = v11 + v12 * ua;
  result = 1;
  *y = ay + v14 * ua;
  return result;
}
