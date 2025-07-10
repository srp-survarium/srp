BOOL __thiscall Scaleform::Render::Rect<float>::Contains(
        Scaleform::Render::Rect<float> *this,
        const Scaleform::Render::Rect<float> *r)
{
  return r->x2 <= (double)this->x2
      && r->y2 <= (double)this->y2
      && r->x1 >= (double)this->x1
      && r->y1 >= (double)this->y1;
}
