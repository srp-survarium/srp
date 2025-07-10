unsigned int __thiscall Scaleform::String::GetCharAt(Scaleform::String *this, unsigned int index)
{
  unsigned int v2; // eax
  const char *v3; // ecx
  int v4; // eax
  const char *buf; // [esp+0h] [ebp-4h] BYREF

  buf = (const char *)this;
  v2 = this->HeapTypeBits & 0xFFFFFFFC;
  v3 = (const char *)(v2 + 8);
  buf = (const char *)(v2 + 8);
  v4 = *(_DWORD *)v2;
  if ( v4 >= 0 )
    return Scaleform::UTF8Util::GetCharAt(index, v3, v4 & 0x7FFFFFFF);
  buf = &v3[index];
  return Scaleform::UTF8Util::DecodeNextChar_Advance0(&buf);
}
