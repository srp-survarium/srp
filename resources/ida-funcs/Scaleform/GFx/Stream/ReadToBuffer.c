unsigned int __thiscall Scaleform::GFx::Stream::ReadToBuffer(
        Scaleform::GFx::Stream *this,
        unsigned __int8 *pdestBuf,
        unsigned int sz)
{
  unsigned int v4; // ebp
  unsigned int Pos; // ecx
  unsigned int DataSize; // eax
  int v7; // edi
  unsigned int v8; // eax
  unsigned __int8 *v9; // ebx
  int v10; // eax

  v4 = 0;
  if ( !this->DataSize )
  {
    this->FilePos = this->pInput.pObject->Tell(this->pInput.pObject);
    this->ResyncFile = 0;
  }
  Pos = this->Pos;
  DataSize = this->DataSize;
  v7 = sz;
  if ( Pos >= DataSize )
  {
    v9 = pdestBuf;
  }
  else
  {
    v8 = DataSize - Pos;
    v4 = sz;
    if ( sz >= v8 )
      v4 = v8;
    memmove((int)pdestBuf, (const __m128i *)&this->pBuffer[Pos], v4);
    this->Pos += v4;
    v7 = sz - v4;
    v9 = &pdestBuf[v4];
  }
  if ( this->Pos >= this->DataSize )
  {
    this->DataSize = 0;
    this->Pos = 0;
  }
  if ( v7 )
  {
    v10 = this->pInput.pObject->Read(this->pInput.pObject, v9, v7);
    this->FilePos += v10;
    v4 += v10;
    if ( v10 < v7 )
      memset((int)&v9[v10], 0, v7 - v10);
  }
  return v4;
}
