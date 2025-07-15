const Scaleform::Render::Cxform *__thiscall Scaleform::GFx::AS2::ColorTransformObject::GetCxform(
        Scaleform::GFx::AS2::ColorTransformObject *this,
        Scaleform::Render::Cxform *result)
{
  qmemcpy(result, &this->mColorTransform, sizeof(Scaleform::Render::Cxform));
  Scaleform::Render::Cxform::Normalize(result);
  return result;
}
