bool __thiscall Scaleform::Render::Rect<float>::IntersectRect(
        Scaleform::Render::Rect<float> *this,
        Scaleform::Render::Rect<float> *pdest,
        const Scaleform::Render::Rect<float> *r)
{
  bool result; // al
  double x1; // st7
  double x2; // st7
  double y1; // st7
  float rb; // [esp+8h] [ebp+8h]
  float rc; // [esp+8h] [ebp+8h]
  float rd; // [esp+8h] [ebp+8h]
  float ra; // [esp+8h] [ebp+8h]

  if ( r->y1 > (double)this->y2 || this->y1 > (double)r->y2 || this->x1 > (double)r->x2 || r->x1 > (double)this->x2 )
    return 0;
  if ( r->x1 >= (double)this->x1 )
    x1 = r->x1;
  else
    x1 = this->x1;
  rb = x1;
  pdest->x1 = rb;
  if ( r->x2 >= (double)this->x2 )
    x2 = this->x2;
  else
    x2 = r->x2;
  rc = x2;
  pdest->x2 = rc;
  if ( r->y1 >= (double)this->y1 )
    y1 = r->y1;
  else
    y1 = this->y1;
  rd = y1;
  pdest->y1 = rd;
  result = 1;
  if ( r->y2 >= (double)this->y2 )
    ra = this->y2;
  else
    ra = r->y2;
  pdest->y2 = ra;
  return result;
}
