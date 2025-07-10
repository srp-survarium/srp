void __thiscall Scaleform::String::AppendString(Scaleform::String *this, const wchar_t *pstr, int len)
{
  volatile LONG *v4; // esi
  unsigned int v5; // edi
  int EncodeStringSize; // ebp
  Scaleform::MemoryHeap *pData; // eax
  Scaleform::String::DataDesc *v8; // ebp

  if ( pstr )
  {
    v4 = (volatile LONG *)(this->HeapTypeBits & 0xFFFFFFFC);
    v5 = *v4 & 0x7FFFFFFF;
    EncodeStringSize = Scaleform::UTF8Util::GetEncodeStringSize(pstr, len);
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
    v8 = Scaleform::String::AllocDataCopy1(this, pData, v5 + EncodeStringSize, 0, (char *)v4 + 8, v5);
    Scaleform::UTF8Util::EncodeString(&v8->Data[v5], pstr, len);
    this->HeapTypeBits = (unsigned int)v8 | this->HeapTypeBits & 3;
    if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  }
}
