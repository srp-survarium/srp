Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::Rect<float>::Intersect(
        Scaleform::Render::Rect<float> *this,
        float left,
        float top,
        float right,
        float bottom)
{
  double x2; // st5
  double v6; // st4
  bool v7; // c0
  bool v8; // c3
  double x1; // st4
  Scaleform::Render::Rect<float> *result; // eax
  double y2; // st7
  double y1; // st6
  float v13; // [esp+Ch] [ebp-4h]
  float v14; // [esp+Ch] [ebp-4h]
  float v15; // [esp+Ch] [ebp-4h]
  float v16; // [esp+Ch] [ebp-4h]
  float v17; // [esp+Ch] [ebp-4h]

  if ( top <= (double)this->y2
    && this->y1 <= (double)bottom
    && (x2 = right, this->x1 <= (double)right)
    && (v6 = this->x2, v7 = left < v6, v8 = left == v6, x1 = left, v7 || v8) )
  {
    if ( this->x1 > x1 )
      x1 = this->x1;
    v14 = x1;
    this->x1 = v14;
    if ( this->x2 <= x2 )
      x2 = this->x2;
    v15 = x2;
    this->x2 = v15;
    if ( this->y1 <= (double)top )
    {
      y1 = top;
      y2 = bottom;
    }
    else
    {
      y2 = bottom;
      y1 = this->y1;
    }
    v16 = y1;
    this->y1 = v16;
    if ( this->y2 <= y2 )
      y2 = this->y2;
    v17 = y2;
    result = this;
    this->y2 = v17;
  }
  else
  {
    result = this;
    this->x1 = 0.0;
    this->y1 = 0.0;
    v13 = 0.0 + 0.0;
    this->x2 = v13;
    this->y2 = v13;
  }
  return result;
}
