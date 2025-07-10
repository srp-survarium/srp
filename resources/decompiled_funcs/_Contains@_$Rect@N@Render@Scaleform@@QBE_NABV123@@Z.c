BOOL __thiscall Scaleform::Render::Rect<double>::Contains(
        Scaleform::Render::Rect<double> *this,
        const Scaleform::Render::Rect<double> *r)
{
  return r->x2 <= this->x2 && r->y2 <= this->y2 && r->x1 >= this->x1 && r->y1 >= this->y1;
}
