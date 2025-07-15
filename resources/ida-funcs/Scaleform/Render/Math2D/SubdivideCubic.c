void __cdecl Scaleform::Render::Math2D::SubdivideCubic<Scaleform::Render::Math2D::CubicCurveCoord>(
        const Scaleform::Render::Math2D::CubicCurveCoord *c,
        float t,
        Scaleform::Render::Math2D::CubicCurveCoord *c1,
        Scaleform::Render::Math2D::CubicCurveCoord *c2)
{
  double v5; // st7
  double v6; // st5
  double v7; // st3
  double v8; // st6
  double v9; // st4
  double v10; // st3
  double v11; // st2
  double v12; // st7
  float v13; // [esp+0h] [ebp-18h]
  float v14; // [esp+4h] [ebp-14h]
  float y4; // [esp+4h] [ebp-14h]
  float v16; // [esp+8h] [ebp-10h]
  float v17; // [esp+8h] [ebp-10h]
  float x4; // [esp+8h] [ebp-10h]
  float v19; // [esp+Ch] [ebp-Ch]
  float v20; // [esp+Ch] [ebp-Ch]
  float v21; // [esp+10h] [ebp-8h]
  float v22; // [esp+10h] [ebp-8h]
  float y1; // [esp+14h] [ebp-4h]
  float v24; // [esp+1Ch] [ebp+4h]
  float v25; // [esp+1Ch] [ebp+4h]
  float v26; // [esp+20h] [ebp+8h]
  float v27; // [esp+20h] [ebp+8h]

  y1 = c->y1;
  v5 = t;
  v26 = (c->x2 - c->x1) * t + c->x1;
  v16 = (c->y2 - y1) * v5 + y1;
  v24 = (c->x3 - c->x2) * v5 + c->x2;
  v14 = (c->y3 - c->y2) * v5 + c->y2;
  v19 = (c->x4 - c->x3) * v5 + c->x3;
  v13 = (c->y4 - c->y3) * v5 + c->y3;
  v6 = v26;
  v21 = (v24 - v26) * v5 + v26;
  v7 = v16;
  v17 = (v14 - v16) * v5 + v16;
  v8 = v19;
  v25 = v24 + (v19 - v24) * v5;
  v9 = v7;
  v27 = v14 + (v13 - v14) * v5;
  v10 = v21;
  v22 = (v25 - v21) * v5 + v21;
  v11 = v5 * (v27 - v17) + v17;
  v12 = v17;
  v20 = v11;
  x4 = c->x4;
  y4 = c->y4;
  c1->x1 = c->x1;
  c1->y1 = y1;
  c1->x2 = v6;
  c1->y2 = v9;
  c1->x3 = v10;
  c1->y3 = v12;
  c1->x4 = v22;
  c1->y4 = v20;
  c2->x1 = v22;
  c2->y1 = v20;
  c2->x2 = v25;
  c2->y2 = v27;
  c2->x3 = v8;
  c2->y3 = v13;
  c2->x4 = x4;
  c2->y4 = y4;
}
