double __cdecl Scaleform::Render::Math2D::LinePointDistance(float x1, float y1, float x2, float y2, float x, float y)
{
  float dy; // [esp+0h] [ebp-Ch]
  float v8; // [esp+4h] [ebp-8h]
  float da; // [esp+8h] [ebp-4h]
  float d; // [esp+8h] [ebp-4h]
  float x1b; // [esp+10h] [ebp+4h]
  float x1c; // [esp+10h] [ebp+4h]
  float x2a; // [esp+18h] [ebp+Ch]

  v8 = x2 - x1;
  dy = y2 - y1;
  da = dy * dy + v8 * v8;
  d = sqrt(da);
  if ( d == 0.0 )
  {
    x2a = x - x1;
    x1b = y - y1;
    x1c = x1b * x1b + x2a * x2a;
    return (float)sqrt(x1c);
  }
  else
  {
    return (float)(((x - x2) * dy - (y - y2) * v8) / d);
  }
}
