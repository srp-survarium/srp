Scaleform::Render::Font::NativeHintingType *__thiscall Scaleform::Render::FontProviderWinAPI::findNativeHinting(
        Scaleform::Render::FontProviderWinAPI *this,
        const char *name)
{
  int v3; // ebx
  int i; // edi

  v3 = 0;
  if ( !this->NativeHinting.Data.Size )
    return 0;
  for ( i = 0;
        Scaleform::String::CompareNoCase(
          (const char *)((this->NativeHinting.Data.Data[i].Typeface.HeapTypeBits & 0xFFFFFFFC) + 8),
          name);
        ++i )
  {
    if ( ++v3 >= this->NativeHinting.Data.Size )
      return 0;
  }
  return &this->NativeHinting.Data.Data[v3];
}
