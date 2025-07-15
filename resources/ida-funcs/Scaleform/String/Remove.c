void __thiscall Scaleform::String::Remove(Scaleform::String *this, unsigned int posAt, int removeLength)
{
  volatile LONG *v4; // esi
  int v5; // ebp
  unsigned int v6; // edi
  int Length; // eax
  const char *ByteIndex; // edi
  unsigned int v9; // edx
  Scaleform::MemoryHeap *pData; // eax
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  int index; // [esp+14h] [ebp+4h]
  const char *v14; // [esp+18h] [ebp+8h]

  v4 = (volatile LONG *)(this->HeapTypeBits & 0xFFFFFFFC);
  v5 = *v4 & 0x7FFFFFFF;
  v6 = v5;
  if ( *(int *)v4 >= 0 )
  {
    Length = Scaleform::UTF8Util::GetLength((char *)v4 + 8, *v4 & 0x7FFFFFFF);
    if ( Length == v5 )
      *v4 |= 0x80000000;
    v6 = Length;
  }
  if ( posAt < v6 )
  {
    if ( posAt + removeLength > v6 )
      removeLength = v6 - posAt;
    ByteIndex = Scaleform::UTF8Util::GetByteIndex(posAt, (char *)v4 + 8, v5);
    v14 = Scaleform::UTF8Util::GetByteIndex(removeLength, (char *)v4 + (_DWORD)ByteIndex + 8, v5 - (_DWORD)ByteIndex);
    v9 = *v4 & 0x80000000;
    pData = 0;
    v11 = this->HeapTypeBits & 3;
    index = v9;
    if ( v11 )
    {
      v12 = v11 - 1;
      if ( v12 )
      {
        if ( v12 == 1 )
          pData = (Scaleform::MemoryHeap *)this[1].pData;
      }
      else
      {
        pData = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
        v9 = index;
      }
    }
    else
    {
      pData = Scaleform::Memory::pGlobalHeap;
    }
    this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy2(
                                         this,
                                         pData,
                                         v5 - (_DWORD)v14,
                                         v9,
                                         (const __m128i *)(v4 + 2),
                                         (unsigned int)ByteIndex,
                                         (const __m128i *)&v14[this->HeapTypeBits + 8 + (_DWORD)ByteIndex],
                                         v5 - (_DWORD)v14 - (_DWORD)ByteIndex)
                       | this->HeapTypeBits & 3;
    if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  }
}
