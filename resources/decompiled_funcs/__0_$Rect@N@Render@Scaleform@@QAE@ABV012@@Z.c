void __thiscall Scaleform::Render::Rect<double>::Rect<double>(
        Scaleform::Render::Rect<double> *this,
        const Scaleform::Render::Rect<double> *rc)
{
  long double y1; // st7
  long double x2; // st6
  long double y2; // st5

  y1 = rc->y1;
  x2 = rc->x2;
  y2 = rc->y2;
  this->x1 = rc->x1;
  this->y1 = y1;
  this->x2 = x2;
  this->y2 = y2;
}
