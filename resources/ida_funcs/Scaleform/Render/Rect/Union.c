Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::Rect<float>::Union(
        Scaleform::Render::Rect<float> *this,
        const Scaleform::Render::Rect<float> *r)
{
  return Scaleform::Render::Rect<float>::Union(this, r->x1, r->y1, r->x2, r->y2);
}


Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::Rect<float>::Union(
        Scaleform::Render::Rect<float> *this,
        float left,
        float top,
        float right,
        float bottom)
{
  Scaleform::Render::Rect<float> pdest; // [esp+30h] [ebp-20h] BYREF
  Scaleform::Render::Rect<float> r; // [esp+40h] [ebp-10h] BYREF

  pdest.x1 = 0.0;
  pdest.y1 = 0.0;
  pdest.x2 = 0.0;
  pdest.y2 = 0.0;
  r.x1 = left;
  r.y1 = top;
  r.x2 = right;
  r.y2 = bottom;
  Scaleform::Render::Rect<float>::UnionRect(this, &pdest, &r);
  *this = pdest;
  return this;
}
