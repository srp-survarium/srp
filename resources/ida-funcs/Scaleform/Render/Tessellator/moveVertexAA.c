void __thiscall Scaleform::Render::Tessellator::moveVertexAA(
        Scaleform::Render::Tessellator *this,
        const Scaleform::Render::TessVertex *refVer,
        Scaleform::Render::TessVertex *aaVer,
        const Scaleform::Render::TessVertex *v2,
        const Scaleform::Render::TessVertex *v3)
{
  double v6; // st7
  double v7; // st6
  double v8; // st5
  double v9; // st4
  double v10; // st3
  double v11; // st2
  double v12; // st2
  double v13; // st2
  double v14; // st7
  double v15; // st6
  float v16; // [esp+14h] [ebp+Ch]
  float v17; // [esp+18h] [ebp+10h]
  float v18; // [esp+18h] [ebp+10h]
  float v19; // [esp+18h] [ebp+10h]
  float v20; // [esp+18h] [ebp+10h]
  float v21; // [esp+18h] [ebp+10h]
  float v22; // [esp+18h] [ebp+10h]
  float v23; // [esp+18h] [ebp+10h]
  float v24; // [esp+18h] [ebp+10h]
  float v25; // [esp+18h] [ebp+10h]
  float v26; // [esp+18h] [ebp+10h]
  float v27; // [esp+18h] [ebp+10h]
  float v28; // [esp+18h] [ebp+10h]
  float v29; // [esp+18h] [ebp+10h]
  float v30; // [esp+18h] [ebp+10h]

  v6 = v3->y - v2->y;
  v7 = aaVer->x - refVer->x;
  v8 = v3->x - v2->x;
  v17 = v7 * v6 - (aaVer->y - refVer->y) * v8;
  v9 = v17;
  v18 = fabs(v17);
  v10 = v18;
  v19 = refVer->x - aaVer->x;
  v20 = fabs(v19);
  v11 = v20;
  v21 = refVer->y - aaVer->y;
  v22 = fabs(v21);
  v12 = v11 + v22;
  v23 = v2->x - v3->x;
  v24 = fabs(v23);
  v13 = v12 + v24;
  v25 = v2->y - v3->y;
  v26 = fabs(v25);
  v27 = (v13 + v26) * this->IntersectionEpsilon;
  if ( v27 > v10
    || (v28 = v8 * (refVer->y - v2->y) - v6 * (refVer->x - v2->x), v14 = v7, v29 = v28 / v9, v15 = v29, v29 <= 0.0)
    || v15 >= 1.0 )
  {
    aaVer->x = refVer->x;
    aaVer->y = refVer->y;
  }
  else
  {
    v30 = v14 * v15 + refVer->x;
    v16 = v15 * (aaVer->y - refVer->y) + refVer->y;
    aaVer->x = v30 + (refVer->x - v30) * 0.125;
    aaVer->y = 0.125 * (refVer->y - v16) + v16;
  }
}
