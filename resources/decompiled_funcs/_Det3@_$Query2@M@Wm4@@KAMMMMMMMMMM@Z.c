double __cdecl Wm4::Query2<float>::Det3(
        float fX0,
        float fY0,
        float fZ0,
        float fX1,
        float fY1,
        float fZ1,
        float fX2,
        float fY2,
        float fZ2)
{
  double v9; // st7
  double v10; // st3
  double v11; // rtt
  float fZ0a; // [esp+Ch] [ebp+Ch]
  float fZ0b; // [esp+Ch] [ebp+Ch]
  float fZ0c; // [esp+Ch] [ebp+Ch]

  v9 = fZ0;
  fZ0a = fZ0 * fY2 - fY0 * fZ2;
  v10 = fZ0a * fX1;
  fZ0b = fZ2 * fY1 - fY2 * fZ1;
  v11 = v10 + fZ0b * fX0;
  fZ0c = fZ1 * fY0 - fY1 * v9;
  return (float)(v11 + fZ0c * fX2);
}
