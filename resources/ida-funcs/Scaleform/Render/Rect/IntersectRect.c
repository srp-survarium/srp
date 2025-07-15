bool __thiscall Scaleform::Render::Rect<int>::IntersectRect(
        Scaleform::Render::Rect<int> *this,
        Scaleform::Render::Rect<int> *pdest,
        const Scaleform::Render::Rect<int> *r)
{
  bool result; // al
  int x1; // ecx
  int x2; // ecx
  int y1; // ecx
  int y2; // esi

  result = Scaleform::Render::Rect<int>::Intersects(this, r);
  if ( result )
  {
    x1 = r->x1;
    if ( this->x1 > r->x1 )
      x1 = this->x1;
    pdest->x1 = x1;
    x2 = this->x2;
    if ( x2 > r->x2 )
      x2 = r->x2;
    pdest->x2 = x2;
    y1 = this->y1;
    if ( y1 <= r->y1 )
      y1 = r->y1;
    pdest->y1 = y1;
    y2 = this->y2;
    if ( y2 > r->y2 )
      y2 = r->y2;
    pdest->y2 = y2;
    return 1;
  }
  return result;
}


char __thiscall Scaleform::Render::Rect<long>::IntersectRect(
        Scaleform::Render::Rect<long> *this,
        Scaleform::Render::Rect<long> *pdest,
        const Scaleform::Render::Rect<long> *r)
{
  int x1; // edx
  int x2; // edx
  int y1; // edx
  int y2; // ecx
  int v8; // eax

  if ( this->y2 < r->y1 )
    return 0;
  if ( r->y2 < this->y1 )
    return 0;
  if ( r->x2 < this->x1 )
    return 0;
  x1 = r->x1;
  if ( this->x2 < r->x1 )
    return 0;
  if ( this->x1 > x1 )
    x1 = this->x1;
  pdest->x1 = x1;
  x2 = this->x2;
  if ( x2 > r->x2 )
    x2 = r->x2;
  pdest->x2 = x2;
  y1 = this->y1;
  if ( y1 <= r->y1 )
    y1 = r->y1;
  pdest->y1 = y1;
  y2 = this->y2;
  v8 = r->y2;
  if ( y2 <= v8 )
    v8 = y2;
  pdest->y2 = v8;
  return 1;
}


bool __thiscall Scaleform::Render::Rect<float>::IntersectRect(
        Scaleform::Render::Rect<float> *this,
        Scaleform::Render::Rect<float> *pdest,
        const Scaleform::Render::Rect<float> *r)
{
  bool result; // al
  double x1; // st7
  double x2; // st7
  double y1; // st7
  float v8; // [esp+8h] [ebp+8h]
  float v9; // [esp+8h] [ebp+8h]
  float v10; // [esp+8h] [ebp+8h]
  float y2; // [esp+8h] [ebp+8h]

  if ( r->y1 > (double)this->y2 || this->y1 > (double)r->y2 || this->x1 > (double)r->x2 || r->x1 > (double)this->x2 )
    return 0;
  if ( r->x1 >= (double)this->x1 )
    x1 = r->x1;
  else
    x1 = this->x1;
  v8 = x1;
  pdest->x1 = v8;
  if ( r->x2 >= (double)this->x2 )
    x2 = this->x2;
  else
    x2 = r->x2;
  v9 = x2;
  pdest->x2 = v9;
  if ( r->y1 >= (double)this->y1 )
    y1 = r->y1;
  else
    y1 = this->y1;
  v10 = y1;
  pdest->y1 = v10;
  result = 1;
  if ( r->y2 >= (double)this->y2 )
    y2 = this->y2;
  else
    y2 = r->y2;
  pdest->y2 = y2;
  return result;
}


bool __thiscall Scaleform::Render::Rect<double>::IntersectRect(
        Scaleform::Render::Rect<double> *this,
        Scaleform::Render::Rect<double> *pdest,
        const Scaleform::Render::Rect<double> *r)
{
  bool result; // al
  long double x1; // st7
  long double x2; // st7
  long double y1; // st7
  long double y2; // st7

  if ( r->y1 > this->y2 || this->y1 > r->y2 || this->x1 > r->x2 || r->x1 > this->x2 )
    return 0;
  if ( r->x1 >= this->x1 )
    x1 = r->x1;
  else
    x1 = this->x1;
  pdest->x1 = x1;
  if ( r->x2 >= this->x2 )
    x2 = this->x2;
  else
    x2 = r->x2;
  pdest->x2 = x2;
  if ( r->y1 >= this->y1 )
    y1 = r->y1;
  else
    y1 = this->y1;
  pdest->y1 = y1;
  if ( r->y2 >= this->y2 )
    y2 = this->y2;
  else
    y2 = r->y2;
  result = 1;
  pdest->y2 = y2;
  return result;
}
