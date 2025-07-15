double __cdecl Scaleform::Render::Math2D::CalcPointOnQuadCurve1D(float x1, float x2, float x3, float t)
{
  float v5; // [esp+4h] [ebp+4h]
  float v7; // [esp+8h] [ebp+8h]

  v5 = x1 + (x2 - x1) * t;
  v7 = x2 + (x3 - x2) * t;
  return (float)(t * (v7 - v5) + v5);
}
