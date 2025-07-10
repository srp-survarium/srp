void __thiscall Scaleform::Render::Rect<double>::Rect<double>(
        Scaleform::Render::Rect<double> *this,
        long double x,
        long double y,
        const Scaleform::Render::Size<double> *sz)
{
  long double v4; // st7
  long double v5; // st5

  v4 = sz->Width + x;
  v5 = sz->Height + y;
  this->x1 = x;
  this->y1 = y;
  this->x2 = v4;
  this->y2 = v5;
}
