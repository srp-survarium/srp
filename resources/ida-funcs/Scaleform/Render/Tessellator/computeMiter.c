char __thiscall Scaleform::Render::Tessellator::computeMiter(
        Scaleform::Render::Tessellator *this,
        const Scaleform::Render::TessVertex *v1,
        const Scaleform::Render::TessVertex *v2,
        const Scaleform::Render::TessVertex *v3,
        Scaleform::Render::TessVertex *newVer1,
        Scaleform::Render::TessVertex *newVer2)
{
  double x; // st7
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
  float v25; // [esp+28h] [ebp-4Ch]
  float xi; // [esp+3Ch] [ebp-38h] BYREF
  float yi; // [esp+40h] [ebp-34h] BYREF
  float len1; // [esp+44h] [ebp-30h]
  float len2; // [esp+48h] [ebp-2Ch]
  float dy1; // [esp+4Ch] [ebp-28h]
  float dx1; // [esp+50h] [ebp-24h]
  float dy2; // [esp+54h] [ebp-20h]
  float dx2; // [esp+58h] [ebp-1Ch]
  float epsilon; // [esp+5Ch] [ebp-18h]
  float d1; // [esp+60h] [ebp-14h]
  double v36; // [esp+64h] [ebp-10h]
  double v37; // [esp+6Ch] [ebp-8h]
  float bevela; // [esp+78h] [ebp+4h]
  float bevelb; // [esp+78h] [ebp+4h]
  char bevel; // [esp+78h] [ebp+4h]
  float kb; // [esp+7Ch] [ebp+8h]
  float kc; // [esp+7Ch] [ebp+8h]
  float kd; // [esp+7Ch] [ebp+8h]
  float ke; // [esp+7Ch] [ebp+8h]
  float kf; // [esp+7Ch] [ebp+8h]
  float kg; // [esp+7Ch] [ebp+8h]
  bool k; // [esp+7Ch] [ebp+8h]
  float kh; // [esp+7Ch] [ebp+8h]
  float ka; // [esp+7Ch] [ebp+8h]
  float ki; // [esp+7Ch] [ebp+8h]
  float kj; // [esp+7Ch] [ebp+8h]
  float turna; // [esp+80h] [ebp+Ch]
  float turn; // [esp+80h] [ebp+Ch]

  xi = v2->x;
  yi = v2->y;
  bevela = v2->x - v1->x;
  kb = v2->y - v1->y;
  kc = kb * kb + bevela * bevela;
  kd = sqrt(kc);
  len1 = kd;
  bevelb = v3->x - v2->x;
  ke = v3->y - v2->y;
  kf = ke * ke + bevelb * bevelb;
  kg = sqrt(kf);
  len2 = kg;
  turna = Scaleform::Render::Math2D::TurnRatio<Scaleform::Render::TessVertex,Scaleform::Render::TessVertex,Scaleform::Render::TessVertex>(
            v1,
            v2,
            v3,
            len1,
            kg);
  k = turna < 0.0;
  bevel = 0;
  epsilon = (len2 + len1) * this->IntersectionEpsilon;
  dx1 = (v2->y - v1->y) * this->EdgeAAWidth / len1;
  dy1 = (v1->x - v2->x) * this->EdgeAAWidth / len1;
  dx2 = (v3->y - v2->y) * this->EdgeAAWidth / len2;
  dy2 = (v2->x - v3->x) * this->EdgeAAWidth / len2;
  turn = fabs(turna);
  if ( turn >= 0.125 )
  {
    v37 = v2->x + dx2;
    v36 = v2->x + dx1;
    v25 = epsilon;
    epsilon = v3->y + dy2;
    dy = epsilon;
    epsilon = dx2 + v3->x;
    v23 = epsilon;
    epsilon = dy2 + v2->y;
    cy = epsilon;
    epsilon = v37;
    v21 = epsilon;
    epsilon = v2->y + dy1;
    by = epsilon;
    epsilon = v36;
    v19 = epsilon;
    epsilon = dy1 + v1->y;
    ay = epsilon;
    epsilon = dx1 + v1->x;
    if ( Scaleform::Render::Math2D::Intersection(epsilon, ay, v19, by, v21, cy, v23, dy, &xi, &yi, v25) )
    {
      d1 = xi - v2->x;
      epsilon = yi - v2->y;
      d1 = epsilon * epsilon + d1 * d1;
      d1 = sqrt(d1);
      v12 = k;
      if ( k )
      {
        v13 = this->EdgeAAWidth * 4.0;
      }
      else
      {
        v14 = len1;
        if ( len2 <= (double)len1 )
          v14 = len2;
        kh = v14;
        v13 = kh / turn;
      }
      ka = v13;
      if ( ka < (double)d1 )
      {
        if ( newVer2 )
        {
          if ( v12 )
            v15 = 2.0;
          else
            v15 = 0.0;
          ki = v15;
          bevel = 1;
          xi = v36 - ki * dy1;
          yi = dy1 + v2->y + ki * dx1;
          v16 = dy2;
          newVer2->x = ki * dy2 + v37;
          newVer2->y = v16 + v2->y - ki * dx2;
        }
        else
        {
          kj = ka / d1;
          xi = (xi - v2->x) * kj + v2->x;
          yi = kj * (yi - v2->y) + v2->y;
        }
      }
    }
    else
    {
      xi = v2->x;
      yi = v2->y;
    }
  }
  else
  {
    x = v2->x;
    if ( len2 >= (double)len1 )
    {
      xi = x + dx2;
      v11 = v2->y + dy2;
    }
    else
    {
      xi = x + dx1;
      v11 = v2->y + dy1;
    }
    yi = v11;
  }
  newVer1->x = xi;
  newVer1->y = yi;
  return bevel;
}
