Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::Rect<float>::Union(
        Scaleform::Render::Rect<float> *this,
        const Scaleform::Render::Rect<float> *r)
{
  return Scaleform::Render::Rect<float>::Union(this, r->x1, r->y1, r->x2, r->y2);
}
