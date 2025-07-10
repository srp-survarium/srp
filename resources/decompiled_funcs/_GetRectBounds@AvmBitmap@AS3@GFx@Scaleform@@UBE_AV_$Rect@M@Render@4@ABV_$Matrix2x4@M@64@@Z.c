Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::AS3::AvmBitmap::GetRectBounds(
        Scaleform::GFx::AS3::AvmBitmap *this,
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Matrix2x4<float> *transform)
{
  this->GetBounds(this, result, transform);
  return result;
}
