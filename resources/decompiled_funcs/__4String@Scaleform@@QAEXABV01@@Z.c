void __thiscall Scaleform::String::operator=(Scaleform::String *this, const Scaleform::String *src)
{
  Scaleform::MemoryHeap *pData; // ebp
  Scaleform::MemoryHeap *v4; // eax
  unsigned int v5; // edi
  volatile LONG *v6; // ebx

  pData = 0;
  if ( (this->HeapTypeBits & 3) != 0 )
  {
    if ( (this->HeapTypeBits & 3) == 1 )
    {
      pData = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    }
    else if ( (this->HeapTypeBits & 3) == 2 )
    {
      pData = (Scaleform::MemoryHeap *)this[1].pData;
    }
  }
  else
  {
    pData = Scaleform::Memory::pGlobalHeap;
  }
  v4 = 0;
  v5 = src->HeapTypeBits & 0xFFFFFFFC;
  v6 = (volatile LONG *)(this->HeapTypeBits & 0xFFFFFFFC);
  if ( (src->HeapTypeBits & 3) != 0 )
  {
    if ( (src->HeapTypeBits & 3) == 1 )
    {
      v4 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, src);
    }
    else if ( (src->HeapTypeBits & 3) == 2 )
    {
      v4 = (Scaleform::MemoryHeap *)src[1].pData;
    }
  }
  else
  {
    v4 = Scaleform::Memory::pGlobalHeap;
  }
  if ( pData == v4 )
  {
    this->HeapTypeBits = v5 | this->HeapTypeBits & 3;
    InterlockedExchangeAdd((volatile LONG *)(v5 + 4), 1);
  }
  else
  {
    this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy1(
                                         this,
                                         pData,
                                         *(_DWORD *)v5 & 0x7FFFFFFF,
                                         *(_DWORD *)v5 & 0x80000000,
                                         (char *)(v5 + 8),
                                         *(_DWORD *)v5 & 0x7FFFFFFF)
                       | this->HeapTypeBits & 3;
  }
  if ( InterlockedExchangeAdd(v6 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v6);
}
