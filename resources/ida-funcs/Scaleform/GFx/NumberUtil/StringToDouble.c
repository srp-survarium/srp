long double __stdcall Scaleform::GFx::NumberUtil::StringToDouble(
        char *str,
        unsigned int strLen,
        unsigned int *endIndex)
{
  unsigned int *v3; // ebx
  const char *v4; // esi
  unsigned int v5; // ebp
  int v6; // eax
  const char *ByteIndex; // eax
  void *v8; // edi
  unsigned int v9; // ebp
  long double result; // st7
  const char *v11; // esi
  const char *v12; // eax
  volatile LONG *v13; // [esp-8h] [ebp-20h]
  char *v14; // [esp-4h] [ebp-1Ch]
  int v15; // [esp-4h] [ebp-1Ch]

  v3 = endIndex;
  v4 = str;
  v14 = str;
  *endIndex = 0;
  Scaleform::String::String((Scaleform::String *)&endIndex, v14);
  v5 = strLen;
  v15 = strLen;
  v6 = Scaleform::GFx::ASUtils::SkipWhiteSpace((Scaleform::String *)&endIndex);
  ByteIndex = Scaleform::UTF8Util::GetByteIndex(v6, v4, v15);
  v8 = (void *)((unsigned int)endIndex & 0xFFFFFFFC);
  v13 = (volatile LONG *)(((unsigned int)endIndex & 0xFFFFFFFC) + 4);
  *v3 = (unsigned int)ByteIndex;
  if ( InterlockedExchangeAdd(v13, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  v9 = v5 - *v3;
  if ( !v9 )
    return NAN;
  v11 = &v4[*v3];
  str = 0;
  if ( v9 > 1 )
  {
    if ( *v11 == 43 )
    {
      if ( !strncmp(v11, "+Infinity", 9u) )
      {
        *v3 += 9;
        return INFINITY;
      }
    }
    else if ( *v11 == 45 )
    {
      if ( !strncmp(v11, "-Infinity", 9u) )
      {
        *v3 += 9;
        return -INFINITY;
      }
    }
    else if ( *v11 == 73 && !strncmp(v11, "Infinity", 8u) )
    {
      *v3 += 8;
      return INFINITY;
    }
  }
  result = Scaleform::SFstrtod(v11, &str);
  v12 = str;
  *v3 += str - v11;
  if ( v12 == v11 )
    return NAN;
  return result;
}
