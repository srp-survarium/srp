int __thiscall Scaleform::String::CompareNoCase(Scaleform::String *this, const Scaleform::String *str)
{
  return Scaleform::String::CompareNoCase(
           (char *)((this->HeapTypeBits & 0xFFFFFFFC) + 8),
           (char *)((str->HeapTypeBits & 0xFFFFFFFC) + 8));
}


int __stdcall Scaleform::String::CompareNoCase(char *a, char *b)
{
  return Scaleform::SFstricmp(a, b);
}


unsigned int __stdcall Scaleform::String::CompareNoCase(const char *a, const char *b, int len)
{
  int v3; // ebx
  const char *v4; // esi
  int v6; // edx
  int v7; // eax
  int v8; // edx

  v3 = len;
  if ( !len )
    return -strlen(b);
  v4 = b;
  do
  {
    v6 = *a;
    v7 = v6 + 32;
    if ( (unsigned int)(v6 - 65) > 0x19 )
      v7 = *a;
    v8 = *v4;
    ++a;
    if ( (unsigned int)(v8 - 65) <= 0x19 )
      v8 += 32;
    ++v4;
    if ( !--v3 || !v7 )
      break;
    if ( v7 != v8 )
      return v7 - v8;
  }
  while ( *v4 );
  if ( v7 == v8 && (v3 || *v4) )
    return len - strlen(b);
  return v7 - v8;
}
