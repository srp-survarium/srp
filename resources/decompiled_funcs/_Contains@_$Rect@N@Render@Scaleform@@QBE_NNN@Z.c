BOOL __thiscall Scaleform::Render::Rect<double>::Contains(
        Scaleform::Render::Rect<double> *this,
        long double x,
        long double y)
{
  return x <= this->x2 && x >= this->x1 && y <= this->y2 && y >= this->y1;
}
