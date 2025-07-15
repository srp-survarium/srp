Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::MorphCharacterDef::GetRectBoundsLocal(
        Scaleform::GFx::MorphCharacterDef *this,
        Scaleform::Render::Rect<float> *result,
        float morphRatio)
{
  ((void (__stdcall *)(Scaleform::Render::Rect<float> *, _DWORD))this->GetBoundsLocal)(result, LODWORD(morphRatio));
  return result;
}
