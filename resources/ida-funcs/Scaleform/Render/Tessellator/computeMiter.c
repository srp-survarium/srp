char __thiscall Scaleform::Render::Tessellator::computeMiter(
        Scaleform::Render::Tessellator *this,
        const Scaleform::Render::TessVertex *v1,
        const Scaleform::Render::TessVertex *v2,
        const Scaleform::Render::TessVertex *v3,
        Scaleform::Render::TessVertex *newVer1,
        Scaleform::Render::TessVertex *newVer2)
{
  double v10; // st7
  double v11; // st7
  bool v12; // cl
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st6
  float ay; // [esp+4h] [ebp-70h]
  float v19; // [esp+8h] [ebp-6Ch]
  float by; // [esp+Ch] [ebp-68h]
  float v21; // [esp+10h] [ebp-64h]
  float cy; // [esp+14h] [ebp-60h]
  float v23; // [esp+18h] [ebp-5Ch]
  float dy; // [esp+1Ch] [ebp-58h]
  float epsilon; // [esp+28h] [ebp-4Ch]
  float x; // [esp+3Ch] [ebp-38h] BYREF
  float y; // [esp+40h] [ebp-34h] BYREF
  float v28; // [esp+44h] [ebp-30h]
  float v29; // [esp+48h] [ebp-2Ch]
  float v30; // [esp+4Ch] [ebp-28h]
  float v31; // [esp+50h] [ebp-24h]
  float v32; // [esp+54h] [ebp-20h]
  float v33; // [esp+58h] [ebp-1Ch]
  float v34; // [esp+5Ch] [ebp-18h]
  float v35; // [esp+60h] [ebp-14h]
  double v36; // [esp+64h] [ebp-10h]
  double v37; // [esp+6Ch] [ebp-8h]
  float v38; // [esp+78h] [ebp+4h]
  float v39; // [esp+78h] [ebp+4h]
  char v40; // [esp+78h] [ebp+4h]
  float v41; // [esp+7Ch] [ebp+8h]
  float v42; // [esp+7Ch] [ebp+8h]
  float v43; // [esp+7Ch] [ebp+8h]
  float v44; // [esp+7Ch] [ebp+8h]
  float v45; // [esp+7Ch] [ebp+8h]
  float v46; // [esp+7Ch] [ebp+8h]
  bool v47; // [esp+7Ch] [ebp+8h]
  float v48; // [esp+7Ch] [ebp+8h]
  float v49; // [esp+7Ch] [ebp+8h]
  float v50; // [esp+7Ch] [ebp+8h]
  float v51; // [esp+7Ch] [ebp+8h]
  float v52; // [esp+80h] [ebp+Ch]
  float v53; // [esp+80h] [ebp+Ch]

  x = v2->x;
  y = v2->y;
  v38 = v2->x - v1->x;
  v41 = v2->y - v1->y;
  v42 = v41 * v41 + v38 * v38;
  v43 = sqrt(v42);
  v28 = v43;
  v39 = v3->x - v2->x;
  v44 = v3->y - v2->y;
  v45 = v44 * v44 + v39 * v39;
  v46 = sqrt(v45);
  v29 = v46;
  v52 = Scaleform::Render::Math2D::TurnRatio<Scaleform::Render::TessVertex,Scaleform::Render::TessVertex,Scaleform::Render::TessVertex>(
          v1,
          v2,
          v3,
          v28,
          v46);
  v47 = v52 < 0.0;
  v40 = 0;
  v34 = (v29 + v28) * this->IntersectionEpsilon;
  v31 = (v2->y - v1->y) * this->EdgeAAWidth / v28;
  v30 = (v1->x - v2->x) * this->EdgeAAWidth / v28;
  v33 = (v3->y - v2->y) * this->EdgeAAWidth / v29;
  v32 = (v2->x - v3->x) * this->EdgeAAWidth / v29;
  v53 = fabs(v52);
  if ( v53 >= 0.125 )
  {
    v37 = v2->x + v33;
    v36 = v2->x + v31;
    epsilon = v34;
    v34 = v3->y + v32;
    dy = v34;
    v34 = v33 + v3->x;
    v23 = v34;
    v34 = v32 + v2->y;
    cy = v34;
    v34 = v37;
    v21 = v34;
    v34 = v2->y + v30;
    by = v34;
    v34 = v36;
    v19 = v34;
    v34 = v30 + v1->y;
    ay = v34;
    v34 = v31 + v1->x;
    if ( Scaleform::Render::Math2D::Intersection(v34, ay, v19, by, v21, cy, v23, dy, &x, &y, epsilon) )
    {
      v35 = x - v2->x;
      v34 = y - v2->y;
      v35 = v34 * v34 + v35 * v35;
      v35 = sqrt(v35);
      v12 = v47;
      if ( v47 )
      {
        v13 = this->EdgeAAWidth * 4.0;
      }
      else
      {
        v14 = v28;
        if ( v29 <= (double)v28 )
          v14 = v29;
        v48 = v14;
        v13 = v48 / v53;
      }
      v49 = v13;
      if ( v49 < (double)v35 )
      {
        if ( newVer2 )
        {
          if ( v12 )
            v15 = 2.0;
          else
            v15 = 0.0;
          v50 = v15;
          v40 = 1;
          x = v36 - v50 * v30;
          y = v30 + v2->y + v50 * v31;
          v16 = v32;
          newVer2->x = v50 * v32 + v37;
          newVer2->y = v16 + v2->y - v50 * v33;
        }
        else
        {
          v51 = v49 / v35;
          x = (x - v2->x) * v51 + v2->x;
          y = v51 * (y - v2->y) + v2->y;
        }
      }
    }
    else
    {
      x = v2->x;
      y = v2->y;
    }
  }
  else
  {
    v10 = v2->x;
    if ( v29 >= (double)v28 )
    {
      x = v10 + v33;
      v11 = v2->y + v32;
    }
    else
    {
      x = v10 + v31;
      v11 = v2->y + v30;
    }
    y = v11;
  }
  newVer1->x = x;
  newVer1->y = y;
  return v40;
}
