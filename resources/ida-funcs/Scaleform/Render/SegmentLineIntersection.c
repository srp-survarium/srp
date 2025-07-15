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
  float v19; // [esp+Ch] [ebp+Ch]
  float v20; // [esp+18h] [ebp+18h]
  float v21; // [esp+18h] [ebp+18h]

  v11 = ax;
  v12 = bx - ax;
  v13 = dy - cy;
  v14 = by - ay;
  v15 = dx - cx;
  v19 = v13 * v12 - v15 * v14;
  v18 = fabs(v19);
  if ( epsilon > (double)v18 )
    return 0;
  v20 = v15 * (ay - cy) - v13 * (v11 - cx);
  v21 = v20 / v19;
  v17 = v21;
  if ( v21 < -0.0000099999997 || v17 > 1.00001 )
    return 0;
  *x = v11 + v12 * v17;
  result = 1;
  *y = ay + v14 * v21;
  return result;
}
