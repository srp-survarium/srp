BOOL __thiscall Scaleform::GFx::GFxSystemFontResourceKey::operator==(
        Scaleform::GFx::GFxSystemFontResourceKey *this,
        Scaleform::GFx::GFxSystemFontResourceKey *other)
{
  return !strcmp(
            (const char *)((this->FontName.HeapTypeBits & 0xFFFFFFFC) + 8),
            (const char *)((other->FontName.HeapTypeBits & 0xFFFFFFFC) + 8))
      && this->pFontProvider.pObject == other->pFontProvider.pObject
      && this->CreateFontFlags == other->CreateFontFlags;
}
