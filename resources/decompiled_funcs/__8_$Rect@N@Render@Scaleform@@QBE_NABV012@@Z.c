BOOL __thiscall Scaleform::Render::Rect<double>::operator==(
        Scaleform::Render::Rect<double> *this,
        const Scaleform::Render::Rect<double> *r)
{
  return r->x1 == this->x1 && r->x2 == this->x2 && r->y1 == this->y1 && r->y2 == this->y2;
}
