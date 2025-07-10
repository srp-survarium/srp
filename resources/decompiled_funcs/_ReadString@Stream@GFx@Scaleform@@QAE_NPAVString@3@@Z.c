char __thiscall Scaleform::GFx::Stream::ReadString(Scaleform::GFx::Stream *this, Scaleform::String *pstr)
{
  unsigned int v2; // ebp
  char *Data; // ebx
  signed int v5; // eax
  unsigned int Pos; // eax
  unsigned int v7; // esi
  char *v8; // eax
  char c; // [esp+13h] [ebp-Dh]
  Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> buffer; // [esp+14h] [ebp-Ch] BYREF

  v2 = 0;
  Data = 0;
  this->UnusedBits = 0;
  memset(&buffer, 0, sizeof(buffer));
  while ( 1 )
  {
    v5 = this->DataSize - this->Pos;
    this->UnusedBits = 0;
    if ( v5 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(this, 1);
    Pos = this->Pos;
    c = this->pBuffer[Pos];
    this->Pos = Pos + 1;
    v7 = v2 + 1;
    if ( !c )
      break;
    if ( v7 >= v2 )
    {
      if ( v7 >= buffer.Data.Policy.Capacity )
      {
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &buffer.Data,
          &buffer,
          v7 + (v7 >> 2));
        goto LABEL_10;
      }
    }
    else if ( v7 < buffer.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &buffer.Data,
        &buffer,
        v2 + 1);
LABEL_10:
      Data = buffer.Data.Data;
    }
    v8 = &Data[v2++];
    buffer.Data.Size = v7;
    if ( &Data[v7] != (char *)1 )
      *v8 = c;
  }
  if ( v7 >= v2 )
  {
    if ( v7 >= buffer.Data.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &buffer.Data,
        &buffer,
        v7 + (v7 >> 2));
LABEL_18:
      Data = buffer.Data.Data;
    }
  }
  else if ( v7 < buffer.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &buffer.Data,
      &buffer,
      v2 + 1);
    goto LABEL_18;
  }
  if ( &Data[v7] != (char *)1 )
    Data[v2] = 0;
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
