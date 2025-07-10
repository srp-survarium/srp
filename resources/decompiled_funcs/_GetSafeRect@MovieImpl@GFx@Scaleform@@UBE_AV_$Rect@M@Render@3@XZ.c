Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::MovieImpl::GetSafeRect(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *v2; // eax

  v2 = result;
  *result = this->SafeRect;
  return v2;
}
