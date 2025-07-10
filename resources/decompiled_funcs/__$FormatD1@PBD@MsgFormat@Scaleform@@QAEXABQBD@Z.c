void __thiscall Scaleform::MsgFormat::FormatD1<char const *>(Scaleform::MsgFormat *this, const char **v)
{
  Scaleform::StackMemPool<512,4,Scaleform::MemPoolImmediateFree> *p_MemPool; // esi
  char *BuffPtr; // eax
  unsigned int v5; // edx
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::Formatter *v7; // eax

  if ( Scaleform::MsgFormat::NextFormatter(this) )
  {
    p_MemPool = &this->MemPool;
    do
    {
      if ( this->MemPool.BuffSize < 0x14 )
      {
        pHeap = p_MemPool->pHeap;
        if ( !p_MemPool->pHeap )
          pHeap = Scaleform::Memory::pGlobalHeap;
        BuffPtr = (char *)pHeap->Alloc(pHeap, 20u, 4u, 0);
      }
      else
      {
        BuffPtr = this->MemPool.BuffPtr;
        this->MemPool.BuffPtr = (char *)(((unsigned int)(BuffPtr + 19) & 0xFFFFFFFC) + 4);
        v5 = ((unsigned int)(BuffPtr + 19) & 0xFFFFFFFC) - (_DWORD)p_MemPool;
        if ( v5 >= 0x200 )
          this->MemPool.BuffSize = 0;
        else
          this->MemPool.BuffSize = 512 - v5;
      }
      if ( BuffPtr )
        Scaleform::StrFormatter::StrFormatter((Scaleform::StrFormatter *)BuffPtr, this, *v);
      else
        v7 = 0;
      Scaleform::MsgFormat::Bind(this, v7, 1);
    }
    while ( Scaleform::MsgFormat::NextFormatter(this) );
  }
  ++this->FirstArgNum;
}
