double __cdecl Scaleform::Render::Math2D::CalcPointOnQuadCurve1D(float x1, float x2, float x3, float t)
{
  float x1a; // [esp+4h] [ebp+4h]
  float x2a; // [esp+8h] [ebp+8h]

  x1a = x1 + (x2 - x1) * t;
  x2a = x2 + (x3 - x2) * t;
  return (float)(t * (x2a - x1a) + x1a);
}
