BOOL __cdecl Scaleform::GFx::Text::operator==(
        const Scaleform::GFx::Text::StyleKey *key1,
        const Scaleform::GFx::Text::StyleKey *key2)
{
  return key1->Type == key2->Type
      && !strcmp(
            (const char *)((key1->Value.HeapTypeBits & 0xFFFFFFFC) + 8),
            (const char *)((key2->Value.HeapTypeBits & 0xFFFFFFFC) + 8));
}
