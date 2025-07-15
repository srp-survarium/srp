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
  double v16; // [esp+10h] [ebp-18h]
  float v17; // [esp+10h] [ebp-18h]
  float v18; // [esp+10h] [ebp-18h]
  double v19; // [esp+18h] [ebp-10h]
  double v20; // [esp+20h] [ebp-8h]
  float v21; // [esp+48h] [ebp+20h]
  float v22; // [esp+48h] [ebp+20h]
  float v23; // [esp+48h] [ebp+20h]
  float v24; // [esp+48h] [ebp+20h]
  float v25; // [esp+48h] [ebp+20h]
  float v26; // [esp+48h] [ebp+20h]

  v8 = y;
  v9 = y1;
  if ( y1 > (double)y )
    return 0;
  v10 = y3;
  if ( y3 <= v8 )
    return 0;
  v11 = y2;
  v21 = (x - x2) * (y2 - v9) - (x2 - x1) * (v8 - y2);
  v12 = v21 > 0.0;
  v16 = x - x3;
  v19 = v8 - v10;
  v22 = (v10 - y2) * v16 - (x3 - x2) * v19;
  v13 = v22 > 0.0;
  v20 = v10 - v9;
  v23 = v20 * v16 - (x3 - x1) * v19;
  if ( v13 && v23 > 0.0 && v12 )
    return 1;
  if ( !v13 && v23 <= 0.0 && !v12 )
    return 0;
  v17 = v9 - (v11 + v11) + v10;
  v24 = -1.0;
  if ( 0.0 == v17 )
  {
    v18 = v20;
    if ( v18 != 0.0 )
      v24 = (v8 - v9) / v18;
  }
  else
  {
    v25 = v8 * y3 + v11 * v11 - (v10 - v8) * v9 - (v8 + v8) * v11;
    if ( v25 <= 0.0 )
    {
      v15 = (v9 + (float)0.0 - y2) / v17;
    }
    else
    {
      v26 = sqrt(v25);
      v15 = (y1 + v26 - y2) / v17;
    }
    v24 = v15;
  }
  return x > Scaleform::Render::Math2D::CalcPointOnQuadCurve1D(x1, x2, x3, v24);
}
