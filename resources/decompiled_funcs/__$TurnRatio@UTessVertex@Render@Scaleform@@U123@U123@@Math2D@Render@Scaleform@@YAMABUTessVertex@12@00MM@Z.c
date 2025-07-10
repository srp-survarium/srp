double __cdecl Scaleform::Render::Math2D::TurnRatio<Scaleform::Render::TessVertex,Scaleform::Render::TessVertex,Scaleform::Render::TessVertex>(
        const Scaleform::Render::TessVertex *v1,
        const Scaleform::Render::TessVertex *v2,
        const Scaleform::Render::TessVertex *v3,
        float len1,
        float len2)
{
  double v6; // st7
  float v8; // [esp+0h] [ebp-4h]
  float ay; // [esp+8h] [ebp+4h]
  float aa; // [esp+Ch] [ebp+8h]
  float a; // [esp+Ch] [ebp+8h]
  float v3a; // [esp+10h] [ebp+Ch]

  v8 = v2->x - v1->x;
  ay = v2->y - v1->y;
  v3a = v3->x - v2->x;
  aa = v3->y - v2->y;
  v6 = aa;
  a = (v3a * v8 + aa * ay) / (len1 * len2 + len1 * len2);
  if ( v8 * v6 < ay * v3a )
    a = 1.0 - a;
  return (float)(a - 0.5);
}
