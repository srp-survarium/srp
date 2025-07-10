void __thiscall Scaleform::String::String(Scaleform::String *this, const Scaleform::String *src)
{
  Scaleform::MemoryHeap *pData; // eax
  unsigned int v4; // esi

  pData = 0;
  v4 = src->HeapTypeBits & 0xFFFFFFFC;
  switch ( src->HeapTypeBits & 3 )
  {
    case 0u:
      goto LABEL_7;
    case 1u:
      pData = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, src);
      break;
    case 2u:
      pData = (Scaleform::MemoryHeap *)src[1].pData;
      break;
  }
  if ( pData != Scaleform::Memory::pGlobalHeap )
  {
    this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy1(
                                         this,
                                         Scaleform::Memory::pGlobalHeap,
                                         *(_DWORD *)v4 & 0x7FFFFFFF,
                                         *(_DWORD *)v4 & 0x80000000,
                                         (char *)(v4 + 8),
                                         *(_DWORD *)v4 & 0x7FFFFFFF);
  }
  else
  {
LABEL_7:
    this->HeapTypeBits = v4;
    InterlockedExchangeAdd((volatile LONG *)(v4 + 4), 1);
  }
}
