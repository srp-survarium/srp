BOOL __thiscall Scaleform::Render::Rect<float>::Contains(
        Scaleform::Render::Rect<float> *this,
        const Scaleform::Render::Point<float> *pt)
{
  return this->x2 >= (double)pt->x
      && this->x1 <= (double)pt->x
      && this->y2 >= (double)pt->y
      && this->y1 <= (double)pt->y;
}
