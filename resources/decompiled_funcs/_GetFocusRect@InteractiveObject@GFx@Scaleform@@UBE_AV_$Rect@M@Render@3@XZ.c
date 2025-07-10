Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::InteractiveObject::GetFocusRect(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *(__thiscall *GetBounds)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Rect<float> *, const Scaleform::Render::Matrix2x4<float> *); // eax
  float v4[8]; // [esp+Ch] [ebp-20h] BYREF

  GetBounds = this->GetBounds;
  v4[0] = 1.0;
  v4[1] = 0.0;
  v4[2] = 0.0;
  v4[3] = 0.0;
  v4[4] = 0.0;
  v4[6] = 0.0;
  v4[7] = 0.0;
  v4[5] = 1.0;
  GetBounds(this, result, (const Scaleform::Render::Matrix2x4<float> *)v4);
  return result;
}
