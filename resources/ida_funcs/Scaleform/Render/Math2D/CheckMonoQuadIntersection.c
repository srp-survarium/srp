bool __cdecl Scaleform::Render::Math2D::CheckMonoQuadIntersection(
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float x,
        float y)
{
  double v8; // st7
  double v9; // st6
  double v10; // st5
  double v11; // st4
  BOOL v12; // edx
  BOOL v13; // ecx
  double v15; // st7
  double denb; // [esp+10h] [ebp-18h]
  float den; // [esp+10h] [ebp-18h]
  float dena; // [esp+10h] [ebp-18h]
  double v19; // [esp+18h] [ebp-10h]
  double v20; // [esp+20h] [ebp-8h]
  float tc; // [esp+48h] [ebp+20h]
  float td; // [esp+48h] [ebp+20h]
  float t; // [esp+48h] [ebp+20h]
  float ta; // [esp+48h] [ebp+20h]
  float tb; // [esp+48h] [ebp+20h]
  float te; // [esp+48h] [ebp+20h]

  v8 = y;
  v9 = y1;
  if ( y1 > (double)y )
    return 0;
  v10 = y3;
  if ( y3 <= v8 )
    return 0;
  v11 = y2;
  tc = (x - x2) * (y2 - v9) - (x2 - x1) * (v8 - y2);
  v12 = tc > 0.0;
  denb = x - x3;
  v19 = v8 - v10;
  td = (v10 - y2) * denb - (x3 - x2) * v19;
  v13 = td > 0.0;
  v20 = v10 - v9;
  t = v20 * denb - (x3 - x1) * v19;
  if ( v13 && t > 0.0 && v12 )
    return 1;
  if ( !v13 && t <= 0.0 && !v12 )
    return 0;
  den = v9 - (v11 + v11) + v10;
  ta = -1.0;
  if ( 0.0 == den )
  {
    dena = v20;
    if ( dena != 0.0 )
      ta = (v8 - v9) / dena;
  }
  else
  {
    tb = v8 * y3 + v11 * v11 - (v10 - v8) * v9 - (v8 + v8) * v11;
    if ( tb <= 0.0 )
    {
      v15 = (v9 + (float)0.0 - y2) / den;
    }
    else
    {
      te = sqrt(tb);
      v15 = (y1 + te - y2) / den;
    }
    ta = v15;
  }
  return x > Scaleform::Render::Math2D::CalcPointOnQuadCurve1D(x1, x2, x3, ta);
}
