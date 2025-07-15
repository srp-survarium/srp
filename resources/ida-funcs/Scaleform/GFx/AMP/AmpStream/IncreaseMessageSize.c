void __thiscall Scaleform::GFx::AMP::AmpStream::IncreaseMessageSize(
        Scaleform::GFx::AMP::AmpStream *this,
        unsigned int newSize)
{
  unsigned int Size; // eax
  unsigned int v3; // edi
  Scaleform::ArrayLH<unsigned char,2,Scaleform::ArrayConstPolicy<0,4,1> > *p_Data; // esi

  Size = this->Data.Data.Size;
  if ( Size )
    v3 = Size + newSize;
  else
    v3 = newSize + 4;
  p_Data = &this->Data;
  if ( v3 >= this->Data.Data.Size )
  {
    if ( v3 >= this->Data.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,2>,Scaleform::ArrayConstPolicy<0,4,1>>::Reserve(
        &this->Data.Data,
        &this->Data,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Data.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,2>,Scaleform::ArrayConstPolicy<0,4,1>>::Reserve(
      &this->Data.Data,
      &this->Data,
      v3);
    p_Data->Data.Size = v3;
    *(_DWORD *)p_Data->Data.Data = v3;
    return;
  }
  p_Data->Data.Size = v3;
  *(_DWORD *)p_Data->Data.Data = v3;
}
