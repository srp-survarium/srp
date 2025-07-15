bool __cdecl Scaleform::Render::Math2D::CheckQuadIntersection(
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float x,
        float y)
{
  double v8; // st7
  double v9; // st6
  double v10; // st5
  double v12; // st4
  double v13; // st7
  double v14; // st6
  bool v15; // bl
  float v16; // [esp+4h] [ebp-50h]
  float v17; // [esp+Ch] [ebp-48h]
  float v18; // [esp+14h] [ebp-40h]
  Scaleform::Render::Math2D::QuadCoordType c2; // [esp+24h] [ebp-30h] BYREF
  Scaleform::Render::Math2D::QuadCoordType c1; // [esp+3Ch] [ebp-18h] BYREF
  float dy; // [esp+64h] [ebp+10h]
  float dya; // [esp+64h] [ebp+10h]
  float dyb; // [esp+64h] [ebp+10h]
  float dyc; // [esp+64h] [ebp+10h]
  float dyd; // [esp+64h] [ebp+10h]
  float dye; // [esp+64h] [ebp+10h]

  v8 = y2;
  v9 = y1;
  v10 = y3;
  if ( y1 <= (double)y2 && v10 >= v8 )
    return Scaleform::Render::Math2D::CheckMonoQuadIntersection(x1, y1, x2, y2, x3, y3, x, y);
  dy = v8 + v8 - v9 - v10;
  if ( dy == 0.0 )
    v12 = -1.0;
  else
    v12 = (v8 - v9) / dy;
  dya = v12;
  v17 = v8;
  Scaleform::Render::Math2D::SubdivideQuadCurve<Scaleform::Render::Math2D::QuadCoordType>(
    x1,
    y1,
    x2,
    v17,
    x3,
    y3,
    dya,
    &c1,
    &c2);
  if ( c1.y3 < (double)c1.y1 )
  {
    dyb = c1.x1;
    c1.x1 = c1.x3;
    c1.x3 = dyb;
    dyc = c1.y1;
    c1.y1 = c1.y3;
    c1.y3 = dyc;
  }
  v13 = c2.y1;
  v14 = c2.y3;
  if ( c2.y3 < (double)c2.y1 )
  {
    dyd = c2.x1;
    c2.x1 = c2.x3;
    c2.x3 = dyd;
    dye = c2.y1;
    c2.y1 = c2.y3;
    c2.y3 = dye;
    v13 = c2.y1;
    v14 = dye;
  }
  v18 = v14;
  v16 = v13;
  v15 = Scaleform::Render::Math2D::CheckMonoQuadIntersection(c2.x1, v16, c2.x2, c2.y2, c2.x3, v18, x, y);
  return Scaleform::Render::Math2D::CheckMonoQuadIntersection(c1.x1, c1.y1, c1.x2, c1.y2, c1.x3, c1.y3, x, y) != v15;
}
