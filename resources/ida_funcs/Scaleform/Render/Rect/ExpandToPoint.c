Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::Rect<float>::ExpandToPoint(
        Scaleform::Render::Rect<float> *this,
        float x,
        float y)
{
  double v3; // st6
  double v4; // st7
  double v5; // st5
  double v6; // st6
  double v7; // rt2
  double v8; // st6
  double v9; // st7
  Scaleform::Render::Rect<float> *result; // eax
  float x1; // [esp+0h] [ebp-4h]
  float xd; // [esp+8h] [ebp+4h]
  float xa; // [esp+8h] [ebp+4h]
  float xe; // [esp+8h] [ebp+4h]
  float xb; // [esp+8h] [ebp+4h]
  float xf; // [esp+8h] [ebp+4h]
  float xc; // [esp+8h] [ebp+4h]

  x1 = this->x1;
  v3 = x;
  if ( x <= (double)x1 )
  {
    v4 = x;
  }
  else
  {
    v3 = x1;
    v4 = x;
  }
  xd = v3;
  this->x1 = xd;
  xa = this->y1;
  v5 = y;
  if ( y <= (double)xa )
  {
    v6 = y;
  }
  else
  {
    v5 = xa;
    v6 = y;
  }
  xe = v5;
  this->y1 = xe;
  xb = this->x2;
  if ( xb > v4 )
    v4 = xb;
  v7 = v6;
  v8 = v4;
  v9 = v7;
  xf = v8;
  this->x2 = xf;
  xc = this->y2;
  result = this;
  if ( xc <= v7 )
    xc = v9;
  this->y2 = xc;
  return result;
}
