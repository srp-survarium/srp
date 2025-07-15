void __thiscall Scaleform::String::String(
        Scaleform::String *this,
        Scaleform::String::InitStruct *src,
        unsigned int size)
{
  unsigned int v4; // eax

  if ( size )
  {
    v4 = (unsigned int)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, size + 12, 0);
    *(_BYTE *)(v4 + size + 8) = 0;
    *(_DWORD *)(v4 + 4) = 1;
    *(_DWORD *)v4 = size;
  }
  else
  {
    InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1);
    v4 = (unsigned int)&Scaleform::String::NullData;
  }
  this->HeapTypeBits = v4;
  src->InitString(src, (char *)((v4 & 0xFFFFFFFC) + 8), size);
}


void __thiscall Scaleform::String::String(Scaleform::String *this, const Scaleform::String *src)
{
  Scaleform::MemoryHeap *pData; // eax
  unsigned int v4; // esi

  pData = 0;
  v4 = src->HeapTypeBits & 0xFFFFFFFC;
  switch ( src->HeapTypeBits & 3 )
  {
    case 0u:
      goto LABEL_7;
    case 1u:
      pData = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, src);
      break;
    case 2u:
      pData = (Scaleform::MemoryHeap *)src[1].pData;
      break;
  }
  if ( pData != Scaleform::Memory::pGlobalHeap )
  {
    this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy1(
                                         this,
                                         Scaleform::Memory::pGlobalHeap,
                                         *(_DWORD *)v4 & 0x7FFFFFFF,
                                         *(_DWORD *)v4 & 0x80000000,
                                         (const __m128i *)(v4 + 8),
                                         *(_DWORD *)v4 & 0x7FFFFFFF);
  }
  else
  {
LABEL_7:
    this->HeapTypeBits = v4;
    InterlockedExchangeAdd((volatile LONG *)(v4 + 4), 1);
  }
}


void __thiscall Scaleform::String::String(Scaleform::String *this, const Scaleform::StringBuffer *src)
{
  const __m128i *pData; // eax

  pData = (const __m128i *)src->pData;
  if ( !src->pData )
    pData = (const __m128i *)uri;
  this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy1(
                                       this,
                                       Scaleform::Memory::pGlobalHeap,
                                       src->Size,
                                       0,
                                       pData,
                                       src->Size);
}


void __thiscall Scaleform::String::String(
        Scaleform::String *this,
        const __m128i *pdata1,
        const __m128i *pdata2,
        const __m128i *pdata3)
{
  unsigned int v4; // ebp
  unsigned int v5; // edi
  unsigned int v6; // ebx
  Scaleform::String::DataDesc *v7; // esi

  if ( pdata1 )
    v4 = strlen(pdata1->m128i_i8);
  else
    v4 = 0;
  if ( pdata2 )
    v5 = strlen(pdata2->m128i_i8);
  else
    v5 = 0;
  if ( pdata3 )
    v6 = strlen(pdata3->m128i_i8);
  else
    v6 = 0;
  v7 = Scaleform::String::AllocDataCopy2(this, Scaleform::Memory::pGlobalHeap, v4 + v6 + v5, 0, pdata1, v4, pdata2, v5);
  memcpy((int)&v7->Data[v5 + v4], pdata3, v6);
  this->HeapTypeBits = (unsigned int)v7;
}


void __thiscall Scaleform::String::String(Scaleform::String *this, const __m128i *pdata)
{
  unsigned int v3; // eax

  if ( pdata )
    v3 = strlen(pdata->m128i_i8);
  else
    v3 = 0;
  this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy1(
                                       this,
                                       Scaleform::Memory::pGlobalHeap,
                                       v3,
                                       0,
                                       pdata,
                                       v3);
}


void __thiscall Scaleform::String::String(Scaleform::String *this, const __m128i *pdata, unsigned int size)
{
  this->HeapTypeBits = (unsigned int)Scaleform::String::AllocDataCopy1(
                                       this,
                                       Scaleform::Memory::pGlobalHeap,
                                       size,
                                       0,
                                       pdata,
                                       size);
}


void __thiscall Scaleform::String::String(Scaleform::String *this, wchar_t *data)
{
  this->HeapTypeBits = (unsigned int)&Scaleform::String::NullData;
  InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1);
  if ( data )
    Scaleform::String::operator=(this, data);
}


void __thiscall Scaleform::String::String(Scaleform::String *this)
{
  this->HeapTypeBits = (unsigned int)&Scaleform::String::NullData;
  InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1);
}
