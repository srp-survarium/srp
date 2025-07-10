Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::ConstShapeWithStyles::GetRectBoundsLocal(
        Scaleform::GFx::ConstShapeWithStyles *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *v2; // eax

  v2 = result;
  *result = this->RectBound;
  return v2;
}
