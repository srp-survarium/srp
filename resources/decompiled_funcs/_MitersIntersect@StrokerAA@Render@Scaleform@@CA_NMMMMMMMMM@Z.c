bool __cdecl Scaleform::Render::StrokerAA::MitersIntersect(
        float ax,
        float ay,
        float bx,
        float by,
        float cx,
        float cy,
        float dx,
        float dy,
        float epsilon)
{
  double v9; // st7
  double v10; // st5
  double v11; // st4
  double v12; // st3
  double v13; // st2
  double v15; // st0
  double v16; // st1
  double v17; // st3
  float uba; // [esp+8h] [ebp+8h]
  float ubb; // [esp+8h] [ebp+8h]
  float ub; // [esp+8h] [ebp+8h]
  float den; // [esp+Ch] [ebp+Ch]
  float dena; // [esp+Ch] [ebp+Ch]
  float ua; // [esp+18h] [ebp+18h]

  v9 = bx - ax;
  v10 = dy - cy;
  v11 = by - ay;
  v12 = dx - cx;
  den = v10 * v9 - v12 * v11;
  v13 = den;
  dena = fabs(den);
  if ( epsilon > (double)dena )
    return 1;
  v15 = ax - cx;
  v16 = v12 * (ay - cy);
  v17 = ay - cy;
  uba = v16 - v10 * v15;
  ua = uba / v13;
  ubb = v9 * v17 - v15 * v11;
  ub = ubb / v13;
  if ( ua < 0.0 )
    return 0;
  return ua <= 1.0 && ub >= 0.0 && ub <= 1.0;
}
