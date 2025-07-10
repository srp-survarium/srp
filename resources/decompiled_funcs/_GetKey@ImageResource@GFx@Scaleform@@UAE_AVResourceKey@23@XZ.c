Scaleform::GFx::ResourceKey *__thiscall Scaleform::GFx::ImageResource::GetKey(
        Scaleform::GFx::ImageResource *this,
        Scaleform::GFx::ResourceKey *result)
{
  Scaleform::GFx::ResourceKey::ResourceKey(result, &this->Key);
  return result;
}
