double __cdecl Scaleform::Render::Math2D::Distance(float x1, float y1, float x2, float y2)
{
  float x1a; // [esp+4h] [ebp+4h]
  float dy; // [esp+Ch] [ebp+Ch]
  float dya; // [esp+Ch] [ebp+Ch]

  x1a = x2 - x1;
  dy = y2 - y1;
  dya = dy * dy + x1a * x1a;
  return (float)sqrt(dya);
}
