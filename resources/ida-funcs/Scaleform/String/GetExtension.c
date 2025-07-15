Scaleform::String *__thiscall Scaleform::String::GetExtension(Scaleform::String *this, Scaleform::String *result)
{
  unsigned int HeapTypeBits; // ecx
  Scaleform::String *v4; // [esp+0h] [ebp-4h] BYREF

  v4 = this;
  HeapTypeBits = this->HeapTypeBits;
  v4 = 0;
  Scaleform::ScanFilePath((char *)((HeapTypeBits & 0xFFFFFFFC) + 8), 0, (const char **)&v4);
  Scaleform::String::String(result, (const __m128i *)v4);
  return result;
}
