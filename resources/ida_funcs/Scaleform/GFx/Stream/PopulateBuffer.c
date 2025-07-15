bool __thiscall Scaleform::GFx::Stream::PopulateBuffer(Scaleform::GFx::Stream *this, int size)
{
  Scaleform::File *pObject; // ecx
  unsigned int Pos; // ecx
  unsigned int DataSize; // eax
  Scaleform::File *v6; // ecx
  unsigned int v7; // eax
  int v8; // edi
  int v9; // eax
  unsigned int v10; // edx
  int v11; // ecx
  bool result; // al
  unsigned int BufferSize; // eax

  if ( !this->DataSize )
  {
    pObject = this->pInput.pObject;
    if ( pObject )
    {
      this->FilePos = pObject->Tell(pObject);
      this->ResyncFile = 0;
    }
  }
  Pos = this->Pos;
  DataSize = this->DataSize;
  if ( Pos >= DataSize )
  {
    this->DataSize = 0;
  }
  else
  {
    memmove(this->pBuffer, &this->pBuffer[Pos], DataSize - Pos);
    this->DataSize -= this->Pos;
  }
  v6 = this->pInput.pObject;
  this->Pos = 0;
  if ( v6 )
  {
    v7 = this->DataSize;
    v8 = this->BufferSize - v7;
    v9 = v6->Read(v6, &this->pBuffer[v7], v8);
    if ( v9 >= v8 )
    {
      this->DataSize += v9;
      this->FilePos += v9;
      return 1;
    }
    else
    {
      if ( v9 > 0 )
      {
        this->DataSize += v9;
        this->FilePos += v9;
      }
      memset((int)&this->pBuffer[this->DataSize], 0, this->BufferSize - this->DataSize);
      v10 = this->Pos;
      v11 = this->DataSize - v10;
      result = size <= v11;
      if ( v11 < size )
        this->DataSize = size + v10;
    }
  }
  else
  {
    this->pBuffer = this->BuiltinBuffer;
    this->BufferSize = 512;
    memset((int)this->BuiltinBuffer, 0, sizeof(this->BuiltinBuffer));
    BufferSize = this->BufferSize;
    this->FilePos += BufferSize;
    this->Pos = 0;
    this->DataSize = BufferSize;
    return 0;
  }
  return result;
}
