BOOL __thiscall Scaleform::Render::Rect<double>::Contains(
        Scaleform::Render::Rect<double> *this,
        const Scaleform::Render::Point<double> *pt)
{
  return this->x2 >= pt->x && this->x1 <= pt->x && this->y2 >= pt->y && this->y1 <= pt->y;
}
