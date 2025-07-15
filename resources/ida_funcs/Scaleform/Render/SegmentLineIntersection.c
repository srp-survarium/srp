bool __cdecl Scaleform::Render::SegmentLineIntersection(
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
  double v17; // st3
  float v18; // [esp+4h] [ebp+4h]
  float den; // [esp+Ch] [ebp+Ch]
  float uaa; // [esp+18h] [ebp+18h]
  float ua; // [esp+18h] [ebp+18h]

  v11 = ax;
  v12 = bx - ax;
  v13 = dy - cy;
  v14 = by - ay;
  v15 = dx - cx;
  den = v13 * v12 - v15 * v14;
  v18 = fabs(den);
  if ( epsilon > (double)v18 )
    return 0;
  uaa = v15 * (ay - cy) - v13 * (v11 - cx);
  ua = uaa / den;
  v17 = ua;
  if ( ua < -0.0000099999997 || v17 > 1.00001 )
    return 0;
  *x = v11 + v12 * v17;
  result = 1;
  *y = ay + v14 * ua;
  return result;
}
