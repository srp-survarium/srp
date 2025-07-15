void __thiscall Scaleform::Render::Rect<float>::UnionRect(
        Scaleform::Render::Rect<float> *this,
        Scaleform::Render::Rect<float> *pdest,
        const Scaleform::Render::Rect<float> *r)
{
  double x1; // st7
  double x2; // st7
  double y1; // st7
  float rb; // [esp+8h] [ebp+8h]
  float rc; // [esp+8h] [ebp+8h]
  float rd; // [esp+8h] [ebp+8h]
  float ra; // [esp+8h] [ebp+8h]

  if ( r->x1 >= (double)this->x1 )
    x1 = this->x1;
  else
    x1 = r->x1;
  rb = x1;
  pdest->x1 = rb;
  if ( r->x2 >= (double)this->x2 )
    x2 = r->x2;
  else
    x2 = this->x2;
  rc = x2;
  pdest->x2 = rc;
  if ( r->y1 >= (double)this->y1 )
    y1 = this->y1;
  else
    y1 = r->y1;
  rd = y1;
  pdest->y1 = rd;
  if ( r->y2 >= (double)this->y2 )
    ra = r->y2;
  else
    ra = this->y2;
  pdest->y2 = ra;
}


void __thiscall Scaleform::Render::Rect<double>::UnionRect(
        Scaleform::Render::Rect<double> *this,
        Scaleform::Render::Rect<double> *pdest,
        const Scaleform::Render::Rect<double> *r)
{
  long double x1; // st7
  long double x2; // st7
  long double y1; // st7
  long double y2; // st7

  if ( r->x1 >= this->x1 )
    x1 = this->x1;
  else
    x1 = r->x1;
  pdest->x1 = x1;
  if ( r->x2 >= this->x2 )
    x2 = r->x2;
  else
    x2 = this->x2;
  pdest->x2 = x2;
  if ( r->y1 >= this->y1 )
    y1 = this->y1;
  else
    y1 = r->y1;
  pdest->y1 = y1;
  if ( r->y2 >= this->y2 )
    y2 = r->y2;
  else
    y2 = this->y2;
  pdest->y2 = y2;
}
