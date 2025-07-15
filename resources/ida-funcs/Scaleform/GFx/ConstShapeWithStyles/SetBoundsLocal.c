void __thiscall Scaleform::GFx::ConstShapeWithStyles::SetBoundsLocal(
        Scaleform::GFx::ConstShapeWithStyles *this,
        const Scaleform::Render::Rect<float> *r)
{
  float x2; // [esp+0h] [ebp-8h]
  float y2; // [esp+4h] [ebp-4h]
  float y1; // [esp+Ch] [ebp+4h]

  y1 = r->y1;
  x2 = r->x2;
  y2 = r->y2;
  this->Bound.x1 = r->x1;
  this->Bound.y1 = y1;
  this->Bound.x2 = x2;
  this->Bound.y2 = y2;
}
