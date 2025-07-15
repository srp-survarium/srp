char *__thiscall Scaleform::GFx::Stream::ReadString(Scaleform::GFx::Stream *this, Scaleform::MemoryHeap *pheap)
{
  unsigned int v2; // ebp
  __m128i *Data; // ebx
  signed int v5; // eax
  unsigned int Pos; // eax
  unsigned int v7; // esi
  unsigned __int8 *v8; // eax
  void *v10; // edi
  unsigned __int8 v11; // [esp+13h] [ebp-Dh]
  Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+14h] [ebp-Ch] BYREF

  v2 = 0;
  Data = 0;
  this->UnusedBits = 0;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  while ( 1 )
  {
    v5 = this->DataSize - this->Pos;
    this->UnusedBits = 0;
    if ( v5 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(this, 1);
    Pos = this->Pos;
    v11 = this->pBuffer[Pos];
    this->Pos = Pos + 1;
    v7 = v2 + 1;
    if ( !v11 )
      break;
    if ( v7 >= v2 )
    {
      if ( v7 >= pheapAddr.Policy.Capacity )
      {
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v7 + (v7 >> 2));
        goto LABEL_10;
      }
    }
    else if ( v7 < pheapAddr.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        v2 + 1);
LABEL_10:
      Data = (__m128i *)pheapAddr.Data;
    }
    v8 = &Data->m128i_u8[v2++];
    pheapAddr.Size = v7;
    if ( &Data->m128i_i8[v7] != (char *)1 )
      *v8 = v11;
  }
  if ( v7 >= v2 )
  {
    if ( v7 >= pheapAddr.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        v7 + (v7 >> 2));
LABEL_18:
      Data = (__m128i *)pheapAddr.Data;
    }
  }
  else if ( v7 < pheapAddr.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &pheapAddr,
      &pheapAddr,
      v2 + 1);
    goto LABEL_18;
  }
  if ( &Data->m128i_i8[v7] != (char *)1 )
    Data->m128i_i8[v2] = 0;
  if ( v2 == -1 )
  {
    if ( Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
    return 0;
  }
  else
  {
    v10 = pheap->Alloc(pheap, v2 + 1, 0);
    memcpy((int)v10, Data, v2 + 1);
    if ( Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
    return (char *)v10;
  }
}


char __thiscall Scaleform::GFx::Stream::ReadString(Scaleform::GFx::Stream *this, Scaleform::String *pstr)
{
  unsigned int v2; // ebp
  __m128i *Data; // ebx
  signed int v5; // eax
  unsigned int Pos; // eax
  unsigned int v7; // esi
  unsigned __int8 *v8; // eax
  unsigned __int8 v10; // [esp+13h] [ebp-Dh]
  Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+14h] [ebp-Ch] BYREF

  v2 = 0;
  Data = 0;
  this->UnusedBits = 0;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  while ( 1 )
  {
    v5 = this->DataSize - this->Pos;
    this->UnusedBits = 0;
    if ( v5 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(this, 1);
    Pos = this->Pos;
    v10 = this->pBuffer[Pos];
    this->Pos = Pos + 1;
    v7 = v2 + 1;
    if ( !v10 )
      break;
    if ( v7 >= v2 )
    {
      if ( v7 >= pheapAddr.Policy.Capacity )
      {
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &pheapAddr,
          &pheapAddr,
          v7 + (v7 >> 2));
        goto LABEL_10;
      }
    }
    else if ( v7 < pheapAddr.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        v2 + 1);
LABEL_10:
      Data = (__m128i *)pheapAddr.Data;
    }
    v8 = &Data->m128i_u8[v2++];
    pheapAddr.Size = v7;
    if ( &Data->m128i_i8[v7] != (char *)1 )
      *v8 = v10;
  }
  if ( v7 >= v2 )
  {
    if ( v7 >= pheapAddr.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        v7 + (v7 >> 2));
LABEL_18:
      Data = (__m128i *)pheapAddr.Data;
    }
  }
  else if ( v7 < pheapAddr.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &pheapAddr,
      &pheapAddr,
      v2 + 1);
    goto LABEL_18;
  }
  if ( &Data->m128i_i8[v7] != (char *)1 )
    Data->m128i_i8[v2] = 0;
  if ( v2 == -1 )
  {
    Scaleform::String::Clear(pstr);
    if ( Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
    return 0;
  }
  else
  {
    Scaleform::String::AssignString(pstr, Data, v2);
    if ( Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
    return 1;
  }
}
