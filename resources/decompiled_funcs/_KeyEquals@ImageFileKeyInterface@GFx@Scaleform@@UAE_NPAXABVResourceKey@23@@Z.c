bool __thiscall Scaleform::GFx::ImageFileKeyInterface::KeyEquals(
        Scaleform::GFx::ImageFileKeyInterface *this,
        _DWORD *hdata,
        const Scaleform::GFx::ResourceKey *other)
{
  _DWORD *hKeyData; // eax

  if ( this != other->pKeyInterface )
    return 0;
  hKeyData = other->hKeyData;
  return hdata[2] == hKeyData[2]
      && hdata[3] == hKeyData[3]
      && hdata[4] == hKeyData[4]
      && Scaleform::String::operator==(
           (Scaleform::String *)(hdata[5] + 16),
           (const Scaleform::String *)(hKeyData[5] + 16));
}
