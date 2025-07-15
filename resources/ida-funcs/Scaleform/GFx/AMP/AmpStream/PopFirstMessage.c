char __thiscall Scaleform::GFx::AMP::AmpStream::PopFirstMessage(Scaleform::GFx::AMP::AmpStream *this)
{
  int readPosition; // edi
  unsigned int v3; // eax
  unsigned int Size; // ecx
  unsigned int v5; // ebp
  unsigned int v7; // ecx
  unsigned int v8; // ebx
  unsigned int v9; // [esp+Ch] [ebp-4h] BYREF

  readPosition = this->readPosition;
  this->readPosition = 0;
  v9 = 0;
  this->Read(this, (unsigned __int8 *)&v9, 4);
  v3 = v9;
  Size = this->Data.Data.Size;
  this->readPosition = readPosition;
  v5 = v3;
  if ( v3 > Size )
    return 0;
  for ( ; v3 < Size; ++v3 )
    this->Data.Data.Data[v3 - v5] = this->Data.Data.Data[v3];
  v7 = Size - v5;
  v8 = v7;
  if ( v7 >= this->Data.Data.Size )
  {
    if ( v7 >= this->Data.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,2>,Scaleform::ArrayConstPolicy<0,4,1>>::Reserve(
        &this->Data.Data,
        &this->Data,
        v7 + (v7 >> 2));
  }
  else if ( v7 < this->Data.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,2>,Scaleform::ArrayConstPolicy<0,4,1>>::Reserve(
      &this->Data.Data,
      &this->Data,
      v7);
  }
  this->Data.Data.Size = v8;
  this->SeekToBegin(this);
  return 1;
}
