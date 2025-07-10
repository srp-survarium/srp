Scaleform::String *__thiscall Scaleform::String::StripExtension(Scaleform::String *this)
{
  const char *v3; // [esp-Ch] [ebp-14h]
  const char *ext; // [esp+4h] [ebp-4h] BYREF

  v3 = (const char *)((this->HeapTypeBits & 0xFFFFFFFC) + 8);
  ext = 0;
  Scaleform::ScanFilePath(v3, 0, &ext);
  if ( ext )
    Scaleform::String::AssignString(
      this,
      (char *)((this->HeapTypeBits & 0xFFFFFFFC) + 8),
      (unsigned int)&ext[-(this->HeapTypeBits & 0xFFFFFFFC) - 8]);
  return this;
}
