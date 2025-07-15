void __thiscall Scaleform::StringLH::CopyConstructHelper(Scaleform::StringLH *this, const Scaleform::String *src)
{
  unsigned int v3; // esi
  Scaleform::MemoryHeap *v4; // ebp
  Scaleform::MemoryHeap *pData; // eax
  unsigned int v6; // ecx
  unsigned int v7; // ecx

  v3 = src->HeapTypeBits & 0xFFFFFFFC;
  v4 = (Scaleform::MemoryHeap *)((int (__stdcall *)(Scaleform::StringLH *))Scaleform::Memory::pGlobalHeap->GetAllocHeap)(this);
  pData = 0;
  v6 = src->HeapTypeBits & 3;
  if ( v6 )
  {
    v7 = v6 - 1;
    if ( v7 )
    {
      if ( v7 == 1 )
        pData = (Scaleform::MemoryHeap *)src[1].pData;
    }
    else
    {
      pData = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, src);
    }
  }
  else
  {
    pData = Scaleform::Memory::pGlobalHeap;
  }
  if ( pData == v4 )
  {
    InterlockedExchangeAdd((volatile LONG *)(v3 + 4), 1);
    this->HeapTypeBits = v3 | 1;
  }
  else
  {
    this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy1(
                                         this,
                                         v4,
                                         *(_DWORD *)v3 & 0x7FFFFFFF,
                                         *(_DWORD *)v3 & 0x80000000,
                                         (const __m128i *)(v3 + 8),
                                         *(_DWORD *)v3 & 0x7FFFFFFF)
                       | 1;
  }
}
