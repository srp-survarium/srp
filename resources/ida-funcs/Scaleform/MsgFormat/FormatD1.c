void __thiscall Scaleform::MsgFormat::FormatD1<unsigned short>(Scaleform::MsgFormat *this, const unsigned __int16 *v)
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
      if ( this->MemPool.BuffSize < 0x50 )
      {
        pHeap = p_MemPool->pHeap;
        if ( !p_MemPool->pHeap )
          pHeap = Scaleform::Memory::pGlobalHeap;
        BuffPtr = (char *)pHeap->Alloc(pHeap, 80u, 4u, 0);
      }
      else
      {
        BuffPtr = this->MemPool.BuffPtr;
        this->MemPool.BuffPtr = (char *)(((unsigned int)(BuffPtr + 79) & 0xFFFFFFFC) + 4);
        v5 = ((unsigned int)(BuffPtr + 79) & 0xFFFFFFFC) - (_DWORD)p_MemPool;
        if ( v5 >= 0x200 )
          this->MemPool.BuffSize = 0;
        else
          this->MemPool.BuffSize = 512 - v5;
      }
      if ( BuffPtr )
        Scaleform::LongFormatter::LongFormatter((Scaleform::LongFormatter *)BuffPtr, this, *v);
      else
        v7 = 0;
      Scaleform::MsgFormat::Bind(this, v7, 1);
    }
    while ( Scaleform::MsgFormat::NextFormatter(this) );
  }
  ++this->FirstArgNum;
}


void __thiscall Scaleform::MsgFormat::FormatD1<int>(Scaleform::MsgFormat *this, int *v)
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
      if ( this->MemPool.BuffSize < 0x50 )
      {
        pHeap = p_MemPool->pHeap;
        if ( !p_MemPool->pHeap )
          pHeap = Scaleform::Memory::pGlobalHeap;
        BuffPtr = (char *)pHeap->Alloc(pHeap, 80u, 4u, 0);
      }
      else
      {
        BuffPtr = this->MemPool.BuffPtr;
        this->MemPool.BuffPtr = (char *)(((unsigned int)(BuffPtr + 79) & 0xFFFFFFFC) + 4);
        v5 = ((unsigned int)(BuffPtr + 79) & 0xFFFFFFFC) - (_DWORD)p_MemPool;
        if ( v5 >= 0x200 )
          this->MemPool.BuffSize = 0;
        else
          this->MemPool.BuffSize = 512 - v5;
      }
      if ( BuffPtr )
        Scaleform::LongFormatter::LongFormatter((Scaleform::LongFormatter *)BuffPtr, this, *v);
      else
        v7 = 0;
      Scaleform::MsgFormat::Bind(this, v7, 1);
    }
    while ( Scaleform::MsgFormat::NextFormatter(this) );
  }
  ++this->FirstArgNum;
}


void __thiscall Scaleform::MsgFormat::FormatD1<unsigned int>(Scaleform::MsgFormat *this, unsigned int *v)
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
      if ( this->MemPool.BuffSize < 0x50 )
      {
        pHeap = p_MemPool->pHeap;
        if ( !p_MemPool->pHeap )
          pHeap = Scaleform::Memory::pGlobalHeap;
        BuffPtr = (char *)pHeap->Alloc(pHeap, 80u, 4u, 0);
      }
      else
      {
        BuffPtr = this->MemPool.BuffPtr;
        this->MemPool.BuffPtr = (char *)(((unsigned int)(BuffPtr + 79) & 0xFFFFFFFC) + 4);
        v5 = ((unsigned int)(BuffPtr + 79) & 0xFFFFFFFC) - (_DWORD)p_MemPool;
        if ( v5 >= 0x200 )
          this->MemPool.BuffSize = 0;
        else
          this->MemPool.BuffSize = 512 - v5;
      }
      if ( BuffPtr )
        Scaleform::LongFormatter::LongFormatter((Scaleform::LongFormatter *)BuffPtr, this, *v);
      else
        v7 = 0;
      Scaleform::MsgFormat::Bind(this, v7, 1);
    }
    while ( Scaleform::MsgFormat::NextFormatter(this) );
  }
  ++this->FirstArgNum;
}


void __thiscall Scaleform::MsgFormat::FormatD1<float>(Scaleform::MsgFormat *this, const float *v)
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
      if ( this->MemPool.BuffSize < 0x188 )
      {
        pHeap = p_MemPool->pHeap;
        if ( !p_MemPool->pHeap )
          pHeap = Scaleform::Memory::pGlobalHeap;
        BuffPtr = (char *)pHeap->Alloc(pHeap, 392u, 4u, 0);
      }
      else
      {
        BuffPtr = this->MemPool.BuffPtr;
        this->MemPool.BuffPtr = (char *)(((unsigned int)(BuffPtr + 391) & 0xFFFFFFFC) + 4);
        v5 = ((unsigned int)(BuffPtr + 391) & 0xFFFFFFFC) - (_DWORD)p_MemPool;
        if ( v5 >= 0x200 )
          this->MemPool.BuffSize = 0;
        else
          this->MemPool.BuffSize = 512 - v5;
      }
      if ( BuffPtr )
        Scaleform::DoubleFormatter::DoubleFormatter((Scaleform::DoubleFormatter *)BuffPtr, this, *v);
      else
        v7 = 0;
      Scaleform::MsgFormat::Bind(this, v7, 1);
    }
    while ( Scaleform::MsgFormat::NextFormatter(this) );
  }
  ++this->FirstArgNum;
}


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


void __thiscall Scaleform::MsgFormat::FormatD1<Scaleform::StringDataPtr>(
        Scaleform::MsgFormat *this,
        const Scaleform::StringDataPtr *v)
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
        Scaleform::StrFormatter::StrFormatter((Scaleform::StrFormatter *)BuffPtr, this, v);
      else
        v7 = 0;
      Scaleform::MsgFormat::Bind(this, v7, 1);
    }
    while ( Scaleform::MsgFormat::NextFormatter(this) );
  }
  ++this->FirstArgNum;
}


void __thiscall Scaleform::MsgFormat::FormatD1<Scaleform::StringLH>(
        Scaleform::MsgFormat *this,
        const Scaleform::StringLH *v)
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
        Scaleform::StrFormatter::StrFormatter((Scaleform::StrFormatter *)BuffPtr, this, v);
      else
        v7 = 0;
      Scaleform::MsgFormat::Bind(this, v7, 1);
    }
    while ( Scaleform::MsgFormat::NextFormatter(this) );
  }
  ++this->FirstArgNum;
}


void __thiscall Scaleform::MsgFormat::FormatD1<bool>(Scaleform::MsgFormat *this, bool *v)
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
      if ( this->MemPool.BuffSize < 0x18 )
      {
        pHeap = p_MemPool->pHeap;
        if ( !p_MemPool->pHeap )
          pHeap = Scaleform::Memory::pGlobalHeap;
        BuffPtr = (char *)pHeap->Alloc(pHeap, 24u, 4u, 0);
      }
      else
      {
        BuffPtr = this->MemPool.BuffPtr;
        this->MemPool.BuffPtr = (char *)(((unsigned int)(BuffPtr + 23) & 0xFFFFFFFC) + 4);
        v5 = ((unsigned int)(BuffPtr + 23) & 0xFFFFFFFC) - (_DWORD)p_MemPool;
        if ( v5 >= 0x200 )
          this->MemPool.BuffSize = 0;
        else
          this->MemPool.BuffSize = 512 - v5;
      }
      if ( BuffPtr )
        Scaleform::BoolFormatter::BoolFormatter((Scaleform::BoolFormatter *)BuffPtr, this, *v);
      else
        v7 = 0;
      Scaleform::MsgFormat::Bind(this, v7, 1);
    }
    while ( Scaleform::MsgFormat::NextFormatter(this) );
  }
  ++this->FirstArgNum;
}
