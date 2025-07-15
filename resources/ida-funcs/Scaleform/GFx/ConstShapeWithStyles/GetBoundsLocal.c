Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::ConstShapeWithStyles::GetBoundsLocal(
        Scaleform::GFx::ConstShapeWithStyles *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *v2; // eax

  v2 = result;
  *result = this->Bound;
  return v2;
}
