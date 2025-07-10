Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::Scale9GridInfo::AdjustBounds(
        Scaleform::Render::Scale9GridInfo *this,
        Scaleform::Render::Rect<float> *result,
        float bounds)
{
  float v3; // eax
  double v5; // st6
  double v6; // st7
  Scaleform::Render::Rect<float> *v7; // eax
  float yb1; // [esp+4h] [ebp-24h]
  float xb2; // [esp+8h] [ebp-20h]
  float yb2; // [esp+Ch] [ebp-1Ch] BYREF
  const Scaleform::Render::Rect<float> *x2; // [esp+10h] [ebp-18h] BYREF
  float y2; // [esp+14h] [ebp-14h] BYREF
  const Scaleform::Render::Rect<float> *x3; // [esp+18h] [ebp-10h] BYREF
  float y3; // [esp+1Ch] [ebp-Ch] BYREF
  const Scaleform::Render::Rect<float> *x4; // [esp+20h] [ebp-8h] BYREF
  float y4; // [esp+24h] [ebp-4h] BYREF

  v3 = bounds;
  bounds = *(float *)LODWORD(bounds);
  yb2 = *(float *)(LODWORD(v3) + 4);
  x2 = *(const Scaleform::Render::Rect<float> **)(LODWORD(v3) + 8);
  y2 = *(float *)(LODWORD(v3) + 4);
  x3 = *(const Scaleform::Render::Rect<float> **)(LODWORD(v3) + 8);
  y3 = *(float *)(LODWORD(v3) + 12);
  x4 = *(const Scaleform::Render::Rect<float> **)LODWORD(v3);
  y4 = *(float *)(LODWORD(v3) + 12);
  Scaleform::Render::Scale9GridInfo::Transform(this, &bounds, &yb2);
  Scaleform::Render::Scale9GridInfo::Transform(this, (float *)&x2, &y2);
  Scaleform::Render::Scale9GridInfo::Transform(this, (float *)&x3, &y3);
  Scaleform::Render::Scale9GridInfo::Transform(this, (float *)&x4, &y4);
  yb1 = yb2;
  v5 = bounds;
  v6 = yb2;
  xb2 = bounds;
  if ( *(float *)&x2 < (double)bounds )
    bounds = *(float *)&x2;
  if ( y2 < v6 )
    yb1 = y2;
  if ( v5 < *(float *)&x2 )
    xb2 = *(float *)&x2;
  if ( y2 > v6 )
    yb2 = y2;
  if ( bounds > (double)*(float *)&x3 )
    bounds = *(float *)&x3;
  if ( yb1 > (double)y3 )
    yb1 = y3;
  if ( xb2 < (double)*(float *)&x3 )
    xb2 = *(float *)&x3;
  if ( yb2 < (double)y3 )
    yb2 = y3;
  if ( bounds > (double)*(float *)&x4 )
    bounds = *(float *)&x4;
  if ( yb1 > (double)y4 )
    yb1 = y4;
  if ( xb2 < (double)*(float *)&x4 )
    xb2 = *(float *)&x4;
  if ( yb2 < (double)y4 )
    yb2 = y4;
  v7 = result;
  result->x1 = bounds;
  result->y1 = yb1;
  result->x2 = xb2;
  result->y2 = yb2;
  return v7;
}
