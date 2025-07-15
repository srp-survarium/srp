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
  float x1a; // [esp+4h] [ebp-50h]
  float x2a; // [esp+Ch] [ebp-48h]
  float x3a; // [esp+14h] [ebp-40h]
  Scaleform::Render::Math2D::QuadCoordType c2; // [esp+24h] [ebp-30h] BYREF
  Scaleform::Render::Math2D::QuadCoordType c1; // [esp+3Ch] [ebp-18h] BYREF
  float v21; // [esp+64h] [ebp+10h]
  float v22; // [esp+64h] [ebp+10h]
  float v23; // [esp+64h] [ebp+10h]
  float v24; // [esp+64h] [ebp+10h]
  float v25; // [esp+64h] [ebp+10h]
  float v26; // [esp+64h] [ebp+10h]

  v8 = y2;
  v9 = y1;
  v10 = y3;
  if ( y1 <= (double)y2 && v10 >= v8 )
    return Scaleform::Render::Math2D::CheckMonoQuadIntersection(x1, y1, x2, y2, x3, y3, x, y);
  v21 = v8 + v8 - v9 - v10;
  if ( v21 == 0.0 )
    v12 = -1.0;
  else
    v12 = (v8 - v9) / v21;
  v22 = v12;
  x2a = v8;
  Scaleform::Render::Math2D::SubdivideQuadCurve<Scaleform::Render::Math2D::QuadCoordType>(
    x1,
    y1,
    x2,
    x2a,
    x3,
    y3,
    v22,
    &c1,
    &c2);
  if ( c1.y3 < (double)c1.y1 )
  {
    v23 = c1.x1;
    c1.x1 = c1.x3;
    c1.x3 = v23;
    v24 = c1.y1;
    c1.y1 = c1.y3;
    c1.y3 = v24;
  }
  v13 = c2.y1;
  v14 = c2.y3;
  if ( c2.y3 < (double)c2.y1 )
  {
    v25 = c2.x1;
    c2.x1 = c2.x3;
    c2.x3 = v25;
    v26 = c2.y1;
    c2.y1 = c2.y3;
    c2.y3 = v26;
    v13 = c2.y1;
    v14 = v26;
  }
  x3a = v14;
  x1a = v13;
  v15 = Scaleform::Render::Math2D::CheckMonoQuadIntersection(c2.x1, x1a, c2.x2, c2.y2, c2.x3, x3a, x, y);
  return Scaleform::Render::Math2D::CheckMonoQuadIntersection(c1.x1, c1.y1, c1.x2, c1.y2, c1.x3, c1.y3, x, y) != v15;
}
