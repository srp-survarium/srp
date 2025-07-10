void __thiscall Scaleform::String::AssignString(Scaleform::String *this, char *putf8str, unsigned int size)
{
  Scaleform::MemoryHeap *pData; // eax
  volatile LONG *v5; // edi
  unsigned int v6; // ecx
  unsigned int v7; // ecx

  pData = 0;
  v5 = (volatile LONG *)(this->HeapTypeBits & 0xFFFFFFFC);
  v6 = this->HeapTypeBits & 3;
  if ( v6 )
  {
    v7 = v6 - 1;
    if ( v7 )
    {
      if ( v7 == 1 )
        pData = (Scaleform::MemoryHeap *)this[1].pData;
    }
    else
    {
      pData = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    }
  }
  else
  {
    pData = Scaleform::Memory::pGlobalHeap;
  }
  this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy1(this, pData, size, 0, putf8str, size)
                     | this->HeapTypeBits & 3;
  if ( InterlockedExchangeAdd(v5 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v5);
}
