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
  float y; // [esp+14h] [ebp+Ch]
  float x; // [esp+18h] [ebp+10h]
  float xa; // [esp+18h] [ebp+10h]
  float xb; // [esp+18h] [ebp+10h]
  float xc; // [esp+18h] [ebp+10h]
  float xd; // [esp+18h] [ebp+10h]
  float xe; // [esp+18h] [ebp+10h]
  float xf; // [esp+18h] [ebp+10h]
  float xg; // [esp+18h] [ebp+10h]
  float xh; // [esp+18h] [ebp+10h]
  float xi; // [esp+18h] [ebp+10h]
  float xj; // [esp+18h] [ebp+10h]
  float xk; // [esp+18h] [ebp+10h]
  float xl; // [esp+18h] [ebp+10h]
  float xm; // [esp+18h] [ebp+10h]

  v6 = v3->y - v2->y;
  v7 = aaVer->x - refVer->x;
  v8 = v3->x - v2->x;
  x = v7 * v6 - (aaVer->y - refVer->y) * v8;
  v9 = x;
  xa = fabs(x);
  v10 = xa;
  xb = refVer->x - aaVer->x;
  xc = fabs(xb);
  v11 = xc;
  xd = refVer->y - aaVer->y;
  xe = fabs(xd);
  v12 = v11 + xe;
  xf = v2->x - v3->x;
  xg = fabs(xf);
  v13 = v12 + xg;
  xh = v2->y - v3->y;
  xi = fabs(xh);
  xj = (v13 + xi) * this->IntersectionEpsilon;
  if ( xj > v10
    || (xk = v8 * (refVer->y - v2->y) - v6 * (refVer->x - v2->x), v14 = v7, xl = xk / v9, v15 = xl, xl <= 0.0)
    || v15 >= 1.0 )
  {
    aaVer->x = refVer->x;
    aaVer->y = refVer->y;
  }
  else
  {
    xm = v14 * v15 + refVer->x;
    y = v15 * (aaVer->y - refVer->y) + refVer->y;
    aaVer->x = xm + (refVer->x - xm) * 0.125;
    aaVer->y = 0.125 * (refVer->y - y) + y;
  }
}
