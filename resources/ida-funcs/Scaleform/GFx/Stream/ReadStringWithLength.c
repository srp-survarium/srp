char *__thiscall Scaleform::GFx::Stream::ReadStringWithLength(
        Scaleform::GFx::Stream *this,
        Scaleform::MemoryHeap *pheap)
{
  signed int v3; // eax
  unsigned int Pos; // eax
  unsigned __int8 v5; // cl
  int v6; // ebp
  int v8; // edi
  _BYTE *i; // ebx
  signed int v10; // eax
  unsigned int v11; // eax
  unsigned __int8 v12; // cl

  v3 = this->DataSize - this->Pos;
  this->UnusedBits = 0;
  if ( v3 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 1);
  Pos = this->Pos;
  v5 = this->pBuffer[Pos];
  v6 = v5;
  this->Pos = Pos + 1;
  if ( !v5 )
    return 0;
  v8 = 0;
  for ( i = pheap->Alloc(pheap, v5 + 1, 0); v8 < v6; ++v8 )
  {
    v10 = this->DataSize - this->Pos;
    this->UnusedBits = 0;
    if ( v10 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer(this, 1);
    v11 = this->Pos;
    v12 = this->pBuffer[v11];
    this->Pos = v11 + 1;
    i[v8] = v12;
  }
  i[v8] = 0;
  return i;
}


char __thiscall Scaleform::GFx::Stream::ReadStringWithLength(Scaleform::GFx::Stream *this, Scaleform::String *pstr)
{
  signed int v3; // eax
  unsigned int Pos; // eax
  unsigned __int8 v5; // cl
  Scaleform::String::InitStruct src; // [esp+4h] [ebp-8h] BYREF
  Scaleform::GFx::Stream *v8; // [esp+8h] [ebp-4h]

  v3 = this->DataSize - this->Pos;
  this->UnusedBits = 0;
  if ( v3 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(this, 1);
  Pos = this->Pos;
  v5 = this->pBuffer[Pos];
  this->Pos = Pos + 1;
  if ( v5 )
  {
    src.__vftable = (Scaleform::String::InitStruct_vtbl *)&`Scaleform::GFx::Stream::ReadStringWithLength'::`2'::StringReader::`vftable';
    v8 = this;
    Scaleform::String::AssignString(pstr, &src, v5);
    return 1;
  }
  else
  {
    Scaleform::String::Clear(pstr);
    return 0;
  }
}
