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
  float v12; // [esp+8h] [ebp+4h]
  float y1; // [esp+8h] [ebp+4h]
  float v14; // [esp+8h] [ebp+4h]
  float x2; // [esp+8h] [ebp+4h]
  float v16; // [esp+8h] [ebp+4h]
  float y2; // [esp+8h] [ebp+4h]

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
  v12 = v3;
  this->x1 = v12;
  y1 = this->y1;
  v5 = y;
  if ( y <= (double)y1 )
  {
    v6 = y;
  }
  else
  {
    v5 = y1;
    v6 = y;
  }
  v14 = v5;
  this->y1 = v14;
  x2 = this->x2;
  if ( x2 > v4 )
    v4 = x2;
  v7 = v6;
  v8 = v4;
  v9 = v7;
  v16 = v8;
  this->x2 = v16;
  y2 = this->y2;
  result = this;
  if ( y2 <= v7 )
    y2 = v9;
  this->y2 = y2;
  return result;
}
