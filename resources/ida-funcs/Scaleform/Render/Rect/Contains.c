BOOL __thiscall Scaleform::Render::Rect<float>::Contains(
        Scaleform::Render::Rect<float> *this,
        const Scaleform::Render::Rect<float> *r)
{
  return r->x2 <= (double)this->x2
      && r->y2 <= (double)this->y2
      && r->x1 >= (double)this->x1
      && r->y1 >= (double)this->y1;
}


BOOL __thiscall Scaleform::Render::Rect<float>::Contains(
        Scaleform::Render::Rect<float> *this,
        const Scaleform::Render::Point<float> *pt)
{
  return this->x2 >= (double)pt->x
      && this->x1 <= (double)pt->x
      && this->y2 >= (double)pt->y
      && this->y1 <= (double)pt->y;
}


BOOL __thiscall Scaleform::Render::Rect<double>::Contains(
        Scaleform::Render::Rect<double> *this,
        const Scaleform::Render::Rect<double> *r)
{
  return r->x2 <= this->x2 && r->y2 <= this->y2 && r->x1 >= this->x1 && r->y1 >= this->y1;
}


BOOL __thiscall Scaleform::Render::Rect<double>::Contains(
        Scaleform::Render::Rect<double> *this,
        const Scaleform::Render::Point<double> *pt)
{
  return this->x2 >= pt->x && this->x1 <= pt->x && this->y2 >= pt->y && this->y1 <= pt->y;
}


BOOL __thiscall Scaleform::Render::Rect<double>::Contains(
        Scaleform::Render::Rect<double> *this,
        long double x,
        long double y)
{
  return x <= this->x2 && x >= this->x1 && y <= this->y2 && y >= this->y1;
}
