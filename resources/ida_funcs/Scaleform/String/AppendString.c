void __thiscall Scaleform::String::AppendString(Scaleform::String *this, char *putf8str, unsigned int utf8StrSz)
{
  char *v3; // edx
  unsigned int v5; // ebp
  volatile LONG *v6; // esi
  Scaleform::MemoryHeap *pData; // eax
  unsigned int v8; // edi
  unsigned int v9; // ecx
  unsigned int v10; // ecx

  v3 = putf8str;
  if ( putf8str )
  {
    v5 = utf8StrSz;
    if ( utf8StrSz )
    {
      if ( utf8StrSz == -1 )
        v5 = strlen(putf8str);
      v6 = (volatile LONG *)(this->HeapTypeBits & 0xFFFFFFFC);
      pData = 0;
      v8 = *v6 & 0x7FFFFFFF;
      v9 = this->HeapTypeBits & 3;
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
          v3 = putf8str;
        }
      }
      else
      {
        pData = Scaleform::Memory::pGlobalHeap;
      }
      this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy2(
                                           this,
                                           pData,
                                           v5 + v8,
                                           0,
                                           (char *)v6 + 8,
                                           v8,
                                           v3,
                                           v5)
                         | this->HeapTypeBits & 3;
      if ( InterlockedExchangeAdd(v6 + 1, -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v6);
    }
  }
}


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
