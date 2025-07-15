double __cdecl Scaleform::Render::Math2D::LinePointDistance(float x1, float y1, float x2, float y2, float x, float y)
{
  float v7; // [esp+0h] [ebp-Ch]
  float v8; // [esp+4h] [ebp-8h]
  float v9; // [esp+8h] [ebp-4h]
  float v10; // [esp+8h] [ebp-4h]
  float v11; // [esp+10h] [ebp+4h]
  float v12; // [esp+10h] [ebp+4h]
  float v14; // [esp+18h] [ebp+Ch]

  v8 = x2 - x1;
  v7 = y2 - y1;
  v9 = v7 * v7 + v8 * v8;
  v10 = sqrt(v9);
  if ( v10 == 0.0 )
  {
    v14 = x - x1;
    v11 = y - y1;
    v12 = v11 * v11 + v14 * v14;
    return (float)sqrt(v12);
  }
  else
  {
    return (float)(((x - x2) * v7 - (y - y2) * v8) / v10);
  }
}
