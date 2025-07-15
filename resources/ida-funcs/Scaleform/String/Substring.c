Scaleform::String *__thiscall Scaleform::String::Substring(
        Scaleform::String *this,
        Scaleform::String *result,
        unsigned int start,
        unsigned int end)
{
  unsigned int v5; // esi
  int v6; // edi
  unsigned int Length; // eax
  unsigned int v8; // esi
  const char *ByteIndex; // eax
  __m128i *v11; // esi
  const char *v12; // eax
  int v13; // [esp-4h] [ebp-14h]

  v5 = this->HeapTypeBits & 0xFFFFFFFC;
  v6 = *(_DWORD *)v5 & 0x7FFFFFFF;
  if ( *(int *)v5 >= 0 )
  {
    Length = Scaleform::UTF8Util::GetLength((char *)(v5 + 8), *(_DWORD *)v5 & 0x7FFFFFFF);
    if ( Length == v6 )
      *(_DWORD *)v5 |= 0x80000000;
  }
  else
  {
    Length = *(_DWORD *)v5 & 0x7FFFFFFF;
  }
  if ( start >= Length || start >= end )
  {
    result->HeapTypeBits = (unsigned int)&Scaleform::String::NullData;
    InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1);
    return result;
  }
  else
  {
    v8 = this->HeapTypeBits & 0xFFFFFFFC;
    if ( *(int *)v8 >= 0 )
    {
      ByteIndex = Scaleform::UTF8Util::GetByteIndex(start, (char *)(v8 + 8), *(_DWORD *)v8 & 0x7FFFFFFF);
      v13 = (*(_DWORD *)v8 & 0x7FFFFFFF) - (_DWORD)ByteIndex;
      v11 = (__m128i *)&ByteIndex[v8 + 8];
      v12 = Scaleform::UTF8Util::GetByteIndex(end - start, v11->m128i_i8, v13);
      result->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy1(
                                             result,
                                             Scaleform::Memory::pGlobalHeap,
                                             (unsigned int)v12,
                                             0,
                                             v11,
                                             (unsigned int)v12);
    }
    else
    {
      result->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy1(
                                             result,
                                             Scaleform::Memory::pGlobalHeap,
                                             end - start,
                                             0,
                                             (const __m128i *)(v8 + start + 8),
                                             end - start);
    }
    return result;
  }
}
