void __thiscall Scaleform::String::operator=(Scaleform::String *this, const Scaleform::StringBuffer *src)
{
  unsigned int Size; // ebx
  unsigned int HeapTypeBits; // ecx
  volatile LONG *v5; // edi
  char *pData; // ebp
  Scaleform::MemoryHeap *v7; // eax
  int v8; // ecx
  int v9; // ecx

  Size = src->Size;
  HeapTypeBits = this->HeapTypeBits;
  v5 = (volatile LONG *)(HeapTypeBits & 0xFFFFFFFC);
  pData = src->pData;
  if ( !src->pData )
    pData = (char *)&buf;
  v7 = 0;
  v8 = HeapTypeBits & 3;
  if ( v8 )
  {
    v9 = v8 - 1;
    if ( v9 )
    {
      if ( v9 == 1 )
        v7 = (Scaleform::MemoryHeap *)this[1].pData;
    }
    else
    {
      v7 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    }
  }
  else
  {
    v7 = Scaleform::Memory::pGlobalHeap;
  }
  this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy1(this, v7, Size, 0, pData, Size)
                     | this->HeapTypeBits & 3;
  if ( InterlockedExchangeAdd(v5 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v5);
}
