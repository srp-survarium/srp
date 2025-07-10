void __thiscall Scaleform::String::AppendChar(Scaleform::String *this, unsigned int ch)
{
  volatile LONG *v3; // edi
  unsigned int v4; // ebx
  Scaleform::MemoryHeap *pData; // eax
  int encodeSize; // [esp+Ch] [ebp-Ch] BYREF
  char buff[8]; // [esp+10h] [ebp-8h] BYREF

  v3 = (volatile LONG *)(this->HeapTypeBits & 0xFFFFFFFC);
  v4 = *v3 & 0x7FFFFFFF;
  encodeSize = 0;
  Scaleform::UTF8Util::EncodeChar(buff, &encodeSize, ch);
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
                                       v4 + encodeSize,
                                       0,
                                       (char *)v3 + 8,
                                       v4,
                                       buff,
                                       encodeSize)
                     | this->HeapTypeBits & 3;
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
}
