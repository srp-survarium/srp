void __thiscall Scaleform::String::operator=(Scaleform::String *this, const wchar_t *pwstr)
{
  volatile LONG *v3; // ebx
  int EncodeStringSize; // edi
  Scaleform::MemoryHeap *pData; // eax
  unsigned int v6; // edi
  int *v7; // eax

  v3 = (volatile LONG *)(this->HeapTypeBits & 0xFFFFFFFC);
  if ( pwstr )
    EncodeStringSize = Scaleform::UTF8Util::GetEncodeStringSize(pwstr, -1);
  else
    EncodeStringSize = 0;
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
  if ( EncodeStringSize )
  {
    v7 = (int *)pData->Alloc(pData, EncodeStringSize + 12, 0);
    *((_BYTE *)v7 + EncodeStringSize + 8) = 0;
    *v7 = EncodeStringSize;
    v7[1] = 1;
    v6 = (unsigned int)v7;
  }
  else
  {
    InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1);
    v6 = (unsigned int)&Scaleform::String::NullData;
  }
  Scaleform::UTF8Util::EncodeString((char *)(v6 + 8), pwstr, -1);
  this->HeapTypeBits = v6 | this->HeapTypeBits & 3;
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
}
