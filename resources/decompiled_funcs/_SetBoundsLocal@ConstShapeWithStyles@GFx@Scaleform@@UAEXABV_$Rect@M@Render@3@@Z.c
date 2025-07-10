void __thiscall Scaleform::GFx::ConstShapeWithStyles::SetBoundsLocal(
        Scaleform::GFx::ConstShapeWithStyles *this,
        const Scaleform::Render::Rect<float> *r)
{
  float x2; // [esp+0h] [ebp-8h]
  float y2; // [esp+4h] [ebp-4h]
  float ra; // [esp+Ch] [ebp+4h]

  ra = r->y1;
  x2 = r->x2;
  y2 = r->y2;
  this->Bound.x1 = r->x1;
  this->Bound.y1 = ra;
  this->Bound.x2 = x2;
  this->Bound.y2 = y2;
}
