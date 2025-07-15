void __cdecl Scaleform::Render::Math2D::CubicCurveExtremum(
        float x1,
        float x2,
        float x3,
        float x4,
        float *t1,
        float *t2)
{
  double v6; // st5
  long double v7; // st4
  double v8; // st5
  float v9; // [esp+4h] [ebp+4h]
  float v10; // [esp+8h] [ebp+8h]
  float v11; // [esp+Ch] [ebp+Ch]
  float v12; // [esp+Ch] [ebp+Ch]
  float v13; // [esp+10h] [ebp+10h]
  float v14; // [esp+10h] [ebp+10h]
  float v15; // [esp+10h] [ebp+10h]

  v6 = x2;
  v10 = 3.0 * x2 + x4 - x3 * 3.0 - x1;
  v11 = x3 - v6 * 2.0 + x1;
  v13 = v6 - x1;
  *t1 = -1.0;
  *t2 = -1.0;
  v9 = fabs(v10);
  if ( v9 <= 0.001 )
  {
    v8 = v11;
    v12 = fabs(v11);
    if ( v12 > 0.001 )
      *t1 = -v13 / (2.0 * v8);
  }
  else
  {
    v14 = v11 * v11 - v13 * v10;
    v7 = v14;
    if ( v14 <= 0.0 )
    {
      if ( v7 == 0.0 )
        *t1 = -v11 / v10;
    }
    else
    {
      v15 = sqrt(v7);
      *t1 = -((v11 - v15) / v10);
      *t2 = -((v11 + v15) / v10);
    }
  }
}
