Scaleform::GFx::ResourceId *__thiscall Scaleform::GFx::SubImageResource::GetBaseImageId(
        Scaleform::GFx::SubImageResource *this,
        Scaleform::GFx::ResourceId *result)
{
  Scaleform::GFx::ResourceId *v2; // eax

  v2 = result;
  result->Id = (unsigned int)this->BaseImageId;
  return v2;
}
