double __cdecl Scaleform::Render::Math2D::SlopeRatio(float x1, float y1, float x2, float y2)
{
  double v4; // st7
  double v5; // st6
  float v7; // [esp+4h] [ebp+4h]
  float v8; // [esp+Ch] [ebp+Ch]
  float v9; // [esp+Ch] [ebp+Ch]
  float v10; // [esp+Ch] [ebp+Ch]
  float v11; // [esp+Ch] [ebp+Ch]

  v7 = x2 - x1;
  v8 = y2 - y1;
  v4 = v8;
  v5 = v7 * v7;
  v9 = v8 * v8 + v5;
  v10 = v9 + v9;
  if ( v10 == 0.0 )
    return 0.0;
  v11 = v5 / v10;
  if ( v7 < 0.0 )
    v11 = -v11;
  if ( v4 > 0.0 )
    v11 = 1.0 - v11;
  return (float)(v11 - 0.5);
}
