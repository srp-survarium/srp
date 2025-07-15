bool __thiscall Scaleform::GFx::GFxMovieDataDefFileKeyInterface::KeyEquals(
        Scaleform::GFx::GFxMovieDataDefFileKeyInterface *this,
        Scaleform::String *hdata,
        const Scaleform::GFx::ResourceKey *other)
{
  const Scaleform::String *hKeyData; // eax

  if ( this != other->pKeyInterface )
    return 0;
  hKeyData = (const Scaleform::String *)other->hKeyData;
  return hdata[3].HeapTypeBits == hKeyData[3].HeapTypeBits
      && hdata[6].HeapTypeBits == hKeyData[6].HeapTypeBits
      && hdata[4].HeapTypeBits == hKeyData[4].HeapTypeBits
      && hdata[5].HeapTypeBits == hKeyData[5].HeapTypeBits
      && Scaleform::String::operator==(hdata + 2, hKeyData + 2);
}
