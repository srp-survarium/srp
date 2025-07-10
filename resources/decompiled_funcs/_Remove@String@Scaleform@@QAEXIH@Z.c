void __thiscall Scaleform::String::Remove(Scaleform::String *this, unsigned int posAt, int removeLength)
{
  volatile LONG *v4; // esi
  int v5; // ebp
  unsigned int v6; // edi
  int Length; // eax
  unsigned int ByteIndex; // edi
  unsigned int v9; // edx
  Scaleform::MemoryHeap *pData; // eax
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  unsigned int posAta; // [esp+14h] [ebp+4h]
  int removeSize; // [esp+18h] [ebp+8h]

  v4 = (volatile LONG *)(this->HeapTypeBits & 0xFFFFFFFC);
  v5 = *v4 & 0x7FFFFFFF;
  v6 = v5;
  if ( *(int *)v4 >= 0 )
  {
    Length = Scaleform::UTF8Util::GetLength((const char *)v4 + 8, *v4 & 0x7FFFFFFF);
    if ( Length == v5 )
      *v4 |= 0x80000000;
    v6 = Length;
  }
  if ( posAt < v6 )
  {
    if ( posAt + removeLength > v6 )
      removeLength = v6 - posAt;
    ByteIndex = Scaleform::UTF8Util::GetByteIndex(posAt, (const char *)v4 + 8, v5);
    removeSize = Scaleform::UTF8Util::GetByteIndex(removeLength, (const char *)v4 + ByteIndex + 8, v5 - ByteIndex);
    v9 = *v4 & 0x80000000;
    pData = 0;
    v11 = this->HeapTypeBits & 3;
    posAta = v9;
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
        v9 = posAta;
      }
    }
    else
    {
      pData = Scaleform::Memory::pGlobalHeap;
    }
    this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy2(
                                         this,
                                         pData,
                                         v5 - removeSize,
                                         v9,
                                         (char *)v4 + 8,
                                         ByteIndex,
                                         (char *)(ByteIndex + removeSize + this->HeapTypeBits + 8),
                                         v5 - removeSize - ByteIndex)
                       | this->HeapTypeBits & 3;
    if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  }
}
