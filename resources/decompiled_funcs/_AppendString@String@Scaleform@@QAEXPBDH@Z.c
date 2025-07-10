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
