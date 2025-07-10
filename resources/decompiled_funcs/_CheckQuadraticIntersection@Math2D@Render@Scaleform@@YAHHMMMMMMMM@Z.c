int __cdecl Scaleform::Render::Math2D::CheckQuadraticIntersection(
        int styleCount,
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        float x,
        float y)
{
  double v9; // st7
  double v10; // st6
  bool v11; // zf
  int result; // eax
  float v13; // [esp+4h] [ebp-1Ch]
  float v14; // [esp+14h] [ebp-Ch]
  float y1a; // [esp+2Ch] [ebp+Ch]
  float y3a; // [esp+3Ch] [ebp+1Ch]

  v9 = y1;
  v10 = y3;
  if ( y3 < (double)y1 )
  {
    y3a = x1;
    x1 = x3;
    x3 = y3a;
    y1a = v10;
    v9 = y1a;
    v10 = y1;
  }
  v14 = v10;
  v13 = v9;
  v11 = !Scaleform::Render::Math2D::CheckQuadIntersection(x1, v13, x2, y2, x3, v14, x, y);
  result = styleCount;
  if ( !v11 )
    return styleCount ^ 1;
  return result;
}
