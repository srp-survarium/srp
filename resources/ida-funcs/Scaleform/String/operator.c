void __thiscall Scaleform::String::operator=(Scaleform::String *this, const Scaleform::String *src)
{
  Scaleform::MemoryHeap *pData; // ebp
  Scaleform::MemoryHeap *v4; // eax
  unsigned int v5; // edi
  volatile LONG *v6; // ebx

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
  v4 = 0;
  v5 = src->HeapTypeBits & 0xFFFFFFFC;
  v6 = (volatile LONG *)(this->HeapTypeBits & 0xFFFFFFFC);
  if ( (src->HeapTypeBits & 3) != 0 )
  {
    if ( (src->HeapTypeBits & 3) == 1 )
    {
      v4 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, src);
    }
    else if ( (src->HeapTypeBits & 3) == 2 )
    {
      v4 = (Scaleform::MemoryHeap *)src[1].pData;
    }
  }
  else
  {
    v4 = Scaleform::Memory::pGlobalHeap;
  }
  if ( pData == v4 )
  {
    this->HeapTypeBits = v5 | this->HeapTypeBits & 3;
    InterlockedExchangeAdd((volatile LONG *)(v5 + 4), 1);
  }
  else
  {
    this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy1(
                                         this,
                                         pData,
                                         *(_DWORD *)v5 & 0x7FFFFFFF,
                                         *(_DWORD *)v5 & 0x80000000,
                                         (char *)(v5 + 8),
                                         *(_DWORD *)v5 & 0x7FFFFFFF)
                       | this->HeapTypeBits & 3;
  }
  if ( InterlockedExchangeAdd(v6 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v6);
}


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


void __thiscall Scaleform::String::operator=(Scaleform::String *this, char *pstr)
{
  if ( pstr )
    Scaleform::String::AssignString(this, pstr, strlen(pstr));
  else
    Scaleform::String::AssignString(this, 0, 0);
}


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


bool __thiscall Scaleform::String::operator==(Scaleform::String *this, const Scaleform::String *str)
{
  return strcmp(
           (const char *)((this->HeapTypeBits & 0xFFFFFFFC) + 8),
           (const char *)((str->HeapTypeBits & 0xFFFFFFFC) + 8)) == 0;
}


bool __thiscall Scaleform::String::operator==(Scaleform::String *this, const char *str)
{
  return strcmp((const char *)((this->HeapTypeBits & 0xFFFFFFFC) + 8), str) == 0;
}


bool __thiscall Scaleform::String::operator!=(Scaleform::String *this, const char *str)
{
  return strcmp((const char *)((this->HeapTypeBits & 0xFFFFFFFC) + 8), str) != 0;
}


Scaleform::String *__thiscall Scaleform::String::operator+(
        Scaleform::String *this,
        Scaleform::String *result,
        const Scaleform::String *src)
{
  Scaleform::String::String(result, this);
  Scaleform::String::operator+=(result, src);
  return result;
}


Scaleform::String *__thiscall Scaleform::String::operator+(
        Scaleform::String *this,
        Scaleform::String *result,
        char *str)
{
  char *v3; // eax

  Scaleform::String::String(result, this);
  v3 = str;
  if ( !str )
    v3 = (char *)&buf;
  Scaleform::String::AppendString(result, v3, 0xFFFFFFFF);
  return result;
}


void __thiscall Scaleform::String::operator+=(Scaleform::String *this, const Scaleform::String *src)
{
  unsigned int HeapTypeBits; // ecx
  unsigned int v4; // esi
  int v5; // ebp
  unsigned int v6; // edi
  Scaleform::MemoryHeap *pData; // eax
  unsigned int v8; // ebp
  int v9; // ecx
  int v10; // ecx
  int srcSize; // [esp+10h] [ebp-4h]
  unsigned int lflag; // [esp+18h] [ebp+4h]

  HeapTypeBits = this->HeapTypeBits;
  v4 = HeapTypeBits & 0xFFFFFFFC;
  v6 = src->HeapTypeBits & 0xFFFFFFFC;
  v5 = *(_DWORD *)(HeapTypeBits & 0xFFFFFFFC);
  lflag = v5 & *(_DWORD *)v6 & 0x80000000;
  pData = 0;
  v8 = v5 & 0x7FFFFFFF;
  v9 = HeapTypeBits & 3;
  srcSize = *(_DWORD *)v6 & 0x7FFFFFFF;
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
    }
  }
  else
  {
    pData = Scaleform::Memory::pGlobalHeap;
  }
  this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy2(
                                       this,
                                       pData,
                                       v8 + srcSize,
                                       lflag,
                                       (char *)(v4 + 8),
                                       v8,
                                       (char *)(v6 + 8),
                                       srcSize)
                     | this->HeapTypeBits & 3;
  if ( InterlockedExchangeAdd((volatile LONG *)(v4 + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
}
