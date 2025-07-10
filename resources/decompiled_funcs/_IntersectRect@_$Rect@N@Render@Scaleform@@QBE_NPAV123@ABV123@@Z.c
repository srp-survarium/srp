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
