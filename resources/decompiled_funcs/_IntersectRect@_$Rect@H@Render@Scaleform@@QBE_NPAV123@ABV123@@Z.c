char __thiscall Scaleform::Render::Rect<int>::IntersectRect(
        Scaleform::Render::Rect<int> *this,
        Scaleform::Render::Rect<int> *pdest,
        const Scaleform::Render::Rect<int> *r)
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
