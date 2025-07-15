bool __thiscall Scaleform::Render::Rect<int>::Intersects(
        Scaleform::Render::Rect<int> *this,
        const Scaleform::Render::Rect<int> *r)
{
  return this->y2 >= r->y1 && r->y2 >= this->y1 && r->x2 >= this->x1 && this->x2 >= r->x1;
}


bool __thiscall Scaleform::Render::Rect<float>::Intersects(
        Scaleform::Render::Rect<float> *this,
        const Scaleform::Render::Rect<float> *r)
{
  return r->y1 <= (double)this->y2
      && this->y1 <= (double)r->y2
      && this->x1 <= (double)r->x2
      && r->x1 <= (double)this->x2;
}
