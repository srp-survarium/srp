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
  float v18; // [esp+8h] [ebp+8h]
  float v19; // [esp+8h] [ebp+8h]
  float v20; // [esp+8h] [ebp+8h]
  float v21; // [esp+Ch] [ebp+Ch]
  float v22; // [esp+Ch] [ebp+Ch]
  float v23; // [esp+18h] [ebp+18h]

  v9 = bx - ax;
  v10 = dy - cy;
  v11 = by - ay;
  v12 = dx - cx;
  v21 = v10 * v9 - v12 * v11;
  v13 = v21;
  v22 = fabs(v21);
  if ( epsilon > (double)v22 )
    return 1;
  v15 = ax - cx;
  v16 = v12 * (ay - cy);
  v17 = ay - cy;
  v18 = v16 - v10 * v15;
  v23 = v18 / v13;
  v19 = v9 * v17 - v15 * v11;
  v20 = v19 / v13;
  if ( v23 < 0.0 )
    return 0;
  return v23 <= 1.0 && v20 >= 0.0 && v20 <= 1.0;
}
