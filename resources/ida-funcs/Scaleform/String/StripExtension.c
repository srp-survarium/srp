Scaleform::String *__thiscall Scaleform::String::StripExtension(Scaleform::String *this)
{
  char *v3; // [esp-Ch] [ebp-14h]
  const char *v4; // [esp+4h] [ebp-4h] BYREF

  v3 = (char *)((this->HeapTypeBits & 0xFFFFFFFC) + 8);
  v4 = 0;
  Scaleform::ScanFilePath(v3, 0, &v4);
  if ( v4 )
    Scaleform::String::AssignString(
      this,
      (const __m128i *)((this->HeapTypeBits & 0xFFFFFFFC) + 8),
      (unsigned int)&v4[-(this->HeapTypeBits & 0xFFFFFFFC) - 8]);
  return this;
}
