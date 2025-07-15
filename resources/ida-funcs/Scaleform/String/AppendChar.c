void __thiscall Scaleform::String::AppendChar(Scaleform::String *this, unsigned int ch)
{
  volatile LONG *v3; // edi
  unsigned int v4; // ebx
  Scaleform::MemoryHeap *pData; // eax
  int pindex; // [esp+Ch] [ebp-Ch] BYREF
  char pbuffer[8]; // [esp+10h] [ebp-8h] BYREF

  v3 = (volatile LONG *)(this->HeapTypeBits & 0xFFFFFFFC);
  v4 = *v3 & 0x7FFFFFFF;
  pindex = 0;
  Scaleform::UTF8Util::EncodeChar(pbuffer, &pindex, ch);
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
  this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy2(
                                       this,
                                       pData,
                                       v4 + pindex,
                                       0,
                                       (const __m128i *)(v3 + 2),
                                       v4,
                                       (const __m128i *)pbuffer,
                                       pindex)
                     | this->HeapTypeBits & 3;
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
}
