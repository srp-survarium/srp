void __thiscall Scaleform::String::operator+=(Scaleform::String *this, const Scaleform::String *src)
{
  unsigned int HeapTypeBits; // ecx
  unsigned int v4; // esi
  int v5; // ebp
  unsigned int v6; // edi
  Scaleform::MemoryHeap *pData; // eax
  unsigned int v8; // ebp
  int v9; // ecx
  int v10; // ecx
  int srcSize; // [esp+10h] [ebp-4h]
  unsigned int lflag; // [esp+18h] [ebp+4h]

  HeapTypeBits = this->HeapTypeBits;
  v4 = HeapTypeBits & 0xFFFFFFFC;
  v6 = src->HeapTypeBits & 0xFFFFFFFC;
  v5 = *(_DWORD *)(HeapTypeBits & 0xFFFFFFFC);
  lflag = v5 & *(_DWORD *)v6 & 0x80000000;
  pData = 0;
  v8 = v5 & 0x7FFFFFFF;
  v9 = HeapTypeBits & 3;
  srcSize = *(_DWORD *)v6 & 0x7FFFFFFF;
  if ( v9 )
  {
    v10 = v9 - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
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
  this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy2(
                                       this,
                                       pData,
                                       v8 + srcSize,
                                       lflag,
                                       (char *)(v4 + 8),
                                       v8,
                                       (char *)(v6 + 8),
                                       srcSize)
                     | this->HeapTypeBits & 3;
  if ( InterlockedExchangeAdd((volatile LONG *)(v4 + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
}
