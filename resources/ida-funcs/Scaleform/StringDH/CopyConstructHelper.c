void __thiscall Scaleform::StringDH::CopyConstructHelper(
        Scaleform::StringDH *this,
        const Scaleform::String *src,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::MemoryHeap *pData; // eax
  unsigned int v5; // esi
  Scaleform::MemoryHeap *v6; // edx

  pData = 0;
  v5 = src->HeapTypeBits & 0xFFFFFFFC;
  if ( (src->HeapTypeBits & 3) != 0 )
  {
    if ( (src->HeapTypeBits & 3) == 1 )
    {
      pData = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, src);
    }
    else if ( (src->HeapTypeBits & 3) == 2 )
    {
      pData = (Scaleform::MemoryHeap *)src[1].pData;
    }
  }
  else
  {
    pData = Scaleform::Memory::pGlobalHeap;
  }
  v6 = pheap;
  if ( !pheap )
    v6 = pData;
  this->pHeap = v6;
  if ( pData == v6 )
  {
    InterlockedExchangeAdd((volatile LONG *)(v5 + 4), 1);
    this->HeapTypeBits = v5 | 2;
  }
  else
  {
    this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy1(
                                         this,
                                         v6,
                                         *(_DWORD *)v5 & 0x7FFFFFFF,
                                         *(_DWORD *)v5 & 0x80000000,
                                         (const __m128i *)(v5 + 8),
                                         *(_DWORD *)v5 & 0x7FFFFFFF)
                       | 2;
  }
}
