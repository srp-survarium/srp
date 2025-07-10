Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::StaticTextDef::GetBoundsLocal(
        Scaleform::GFx::StaticTextDef *this,
        Scaleform::Render::Rect<float> *result,
        float __formal)
{
  Scaleform::Render::Rect<float> *v3; // eax

  v3 = result;
  *result = this->TextRect;
  return v3;
}
