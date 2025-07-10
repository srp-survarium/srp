double __cdecl Scaleform::Render::Math2D::SlopeRatio(float x1, float y1, float x2, float y2)
{
  double v4; // st7
  double v5; // st6
  float x1a; // [esp+4h] [ebp+4h]
  float denb; // [esp+Ch] [ebp+Ch]
  float denc; // [esp+Ch] [ebp+Ch]
  float den; // [esp+Ch] [ebp+Ch]
  float dena; // [esp+Ch] [ebp+Ch]

  x1a = x2 - x1;
  denb = y2 - y1;
  v4 = denb;
  v5 = x1a * x1a;
  denc = denb * denb + v5;
  den = denc + denc;
  if ( den == 0.0 )
    return 0.0;
  dena = v5 / den;
  if ( x1a < 0.0 )
    dena = -dena;
  if ( v4 > 0.0 )
    dena = 1.0 - dena;
  return (float)(dena - 0.5);
}
