bool __thiscall Scaleform::Render::Rect<float>::Intersects(
        Scaleform::Render::Rect<float> *this,
        const Scaleform::Render::Rect<float> *r)
{
  return r->y1 <= (double)this->y2
      && this->y1 <= (double)r->y2
      && this->x1 <= (double)r->x2
      && r->x1 <= (double)this->x2;
}
