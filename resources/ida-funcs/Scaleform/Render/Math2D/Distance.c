double __cdecl Scaleform::Render::Math2D::Distance(float x1, float y1, float x2, float y2)
{
  float v5; // [esp+4h] [ebp+4h]
  float v6; // [esp+Ch] [ebp+Ch]
  float v7; // [esp+Ch] [ebp+Ch]

  v5 = x2 - x1;
  v6 = y2 - y1;
  v7 = v6 * v6 + v5 * v5;
  return (float)sqrt(v7);
}
