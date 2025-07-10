void __thiscall Scaleform::GFx::MovieImpl::SetSafeRect(
        Scaleform::GFx::MovieImpl *this,
        const Scaleform::Render::Rect<float> *rect)
{
  float x2; // [esp+0h] [ebp-8h]
  float y2; // [esp+4h] [ebp-4h]
  float recta; // [esp+Ch] [ebp+4h]

  recta = rect->y1;
  x2 = rect->x2;
  y2 = rect->y2;
  this->SafeRect.x1 = rect->x1;
  this->SafeRect.y1 = recta;
  this->SafeRect.x2 = x2;
  this->SafeRect.y2 = y2;
}
