long double __stdcall Scaleform::GFx::NumberUtil::StringToDouble(
        __m128i *str,
        unsigned int strLen,
        Scaleform::String endIndex)
{
  Scaleform::String::DataDesc *pData; // ebx
  char *v4; // esi
  unsigned int v5; // ebp
  int v6; // eax
  char *ByteIndex; // eax
  void *v8; // edi
  unsigned int v9; // ebp
  long double result; // st7
  char *v11; // esi
  char *v12; // eax
  volatile LONG *v13; // [esp-8h] [ebp-20h]
  const __m128i *v14; // [esp-4h] [ebp-1Ch]
  int v15; // [esp-4h] [ebp-1Ch]

  pData = endIndex.pData;
  v4 = (char *)str;
  v14 = str;
  *(_DWORD *)endIndex.HeapTypeBits = 0;
  Scaleform::String::String(&endIndex, v14);
  v5 = strLen;
  v15 = strLen;
  v6 = Scaleform::GFx::ASUtils::SkipWhiteSpace(&endIndex);
  ByteIndex = Scaleform::UTF8Util::GetByteIndex(v6, v4, v15);
  v8 = (void *)(endIndex.HeapTypeBits & 0xFFFFFFFC);
  v13 = (volatile LONG *)((endIndex.HeapTypeBits & 0xFFFFFFFC) + 4);
  pData->Size = (unsigned int)ByteIndex;
  if ( InterlockedExchangeAdd(v13, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  v9 = v5 - pData->Size;
  if ( !v9 )
    return NAN;
  v11 = &v4[pData->Size];
  str = 0;
  if ( v9 > 1 )
  {
    if ( *v11 == 43 )
    {
      if ( !strncmp(v11, "+Infinity", 9u) )
      {
        pData->Size += 9;
        return INFINITY;
      }
    }
    else if ( *v11 == 45 )
    {
      if ( !strncmp(v11, "-Infinity", 9u) )
      {
        pData->Size += 9;
        return -INFINITY;
      }
    }
    else if ( *v11 == 73 && !strncmp(v11, "Infinity", 8u) )
    {
      pData->Size += 8;
      return INFINITY;
    }
  }
  result = Scaleform::SFstrtod((int)v8, v11, (char **)&str);
  v12 = (char *)str;
  pData->Size += (char *)str - v11;
  if ( v12 == v11 )
    return NAN;
  return result;
}
