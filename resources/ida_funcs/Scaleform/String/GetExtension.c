Scaleform::String *__thiscall Scaleform::String::GetExtension(Scaleform::String *this, Scaleform::String *result)
{
  unsigned int HeapTypeBits; // ecx
  const char *ext; // [esp+0h] [ebp-4h] BYREF

  ext = (const char *)this;
  HeapTypeBits = this->HeapTypeBits;
  ext = 0;
  Scaleform::ScanFilePath((const char *)((HeapTypeBits & 0xFFFFFFFC) + 8), 0, &ext);
  Scaleform::String::String(result, (char *)ext);
  return result;
}
