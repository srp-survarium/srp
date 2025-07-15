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
  float x1a; // [esp+4h] [ebp+4h]
  float a; // [esp+8h] [ebp+8h]
  float b; // [esp+Ch] [ebp+Ch]
  float ba; // [esp+Ch] [ebp+Ch]
  float d; // [esp+10h] [ebp+10h]
  float da; // [esp+10h] [ebp+10h]
  float db; // [esp+10h] [ebp+10h]

  v6 = x2;
  a = 3.0 * x2 + x4 - x3 * 3.0 - x1;
  b = x3 - v6 * 2.0 + x1;
  d = v6 - x1;
  *t1 = -1.0;
  *t2 = -1.0;
  x1a = fabs(a);
  if ( x1a <= 0.001 )
  {
    v8 = b;
    ba = fabs(b);
    if ( ba > 0.001 )
      *t1 = -d / (2.0 * v8);
  }
  else
  {
    da = b * b - d * a;
    v7 = da;
    if ( da <= 0.0 )
    {
      if ( v7 == 0.0 )
        *t1 = -b / a;
    }
    else
    {
      db = sqrt(v7);
      *t1 = -((b - db) / a);
      *t2 = -((b + db) / a);
    }
  }
}
