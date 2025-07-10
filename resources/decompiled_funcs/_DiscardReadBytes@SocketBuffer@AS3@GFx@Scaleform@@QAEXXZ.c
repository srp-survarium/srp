void __thiscall Scaleform::GFx::AS3::SocketBuffer::DiscardReadBytes(Scaleform::GFx::AS3::SocketBuffer *this)
{
  signed int readPosition; // eax
  unsigned int v3; // edi

  readPosition = this->readPosition;
  if ( readPosition > 0 )
  {
    for ( ; readPosition < this->Data.Data.Size; ++readPosition )
      this->Data.Data.Data[readPosition - this->readPosition] = this->Data.Data.Data[readPosition];
    v3 = this->Data.Data.Size - this->readPosition;
    if ( this->Data.Data.Size < this->readPosition )
    {
      if ( v3 >= this->Data.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1>>::Reserve(
          &this->Data.Data,
          &this->Data,
          v3 + (v3 >> 2));
    }
    else if ( v3 < this->Data.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1>>::Reserve(
        &this->Data.Data,
        &this->Data,
        this->Data.Data.Size - this->readPosition);
    }
    this->Data.Data.Size = v3;
    this->readPosition = 0;
  }
}
