double __cdecl Scaleform::Render::Math2D::TurnRatio<Scaleform::Render::TessVertex,Scaleform::Render::TessVertex,Scaleform::Render::TessVertex>(
        const Scaleform::Render::TessVertex *v1,
        const Scaleform::Render::TessVertex *v2,
        const Scaleform::Render::TessVertex *v3,
        float len1,
        float len2)
{
  double v6; // st7
  float v8; // [esp+0h] [ebp-4h]
  float v9; // [esp+8h] [ebp+4h]
  float v10; // [esp+Ch] [ebp+8h]
  float v11; // [esp+Ch] [ebp+8h]
  float v13; // [esp+10h] [ebp+Ch]

  v8 = v2->x - v1->x;
  v9 = v2->y - v1->y;
  v13 = v3->x - v2->x;
  v10 = v3->y - v2->y;
  v6 = v10;
  v11 = (v13 * v8 + v10 * v9) / (len1 * len2 + len1 * len2);
  if ( v8 * v6 < v9 * v13 )
    v11 = 1.0 - v11;
  return (float)(v11 - 0.5);
}
