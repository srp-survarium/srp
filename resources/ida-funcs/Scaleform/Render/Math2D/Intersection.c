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
  float v18; // [esp+Ch] [ebp+Ch]
  float v19; // [esp+18h] [ebp+18h]
  float v20; // [esp+18h] [ebp+18h]

  v11 = ax;
  v12 = bx - ax;
  v13 = dy - cy;
  v14 = by - ay;
  v15 = dx - cx;
  v18 = v13 * v12 - v15 * v14;
  v17 = fabs(v18);
  if ( epsilon > (double)v17 )
    return 0;
  v19 = v15 * (ay - cy) - v13 * (v11 - cx);
  v20 = v19 / v18;
  *x = v11 + v12 * v20;
  result = 1;
  *y = ay + v14 * v20;
  return result;
}
