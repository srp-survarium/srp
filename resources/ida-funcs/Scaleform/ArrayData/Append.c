void __thiscall Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH<unsigned char,2>,Scaleform::ArrayConstPolicy<0,4,1>>::Append(
        Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH<unsigned char,2>,Scaleform::ArrayConstPolicy<0,4,1> > *this,
        unsigned __int8 *other,
        unsigned int count)
{
  unsigned int Size; // edi
  unsigned __int8 *v6; // eax
  unsigned int v7; // esi

  if ( count )
  {
    Size = this->Size;
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,2>,Scaleform::ArrayConstPolicy<0,4,1>>::ResizeNoConstruct(
      this,
      this,
      Size + count);
    v6 = &this->Data[Size];
    v7 = count;
    do
    {
      if ( v6 )
        *v6 = *other;
      ++other;
      ++v6;
      --v7;
    }
    while ( v7 );
  }
}


void __thiscall Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1>>::Append(
        Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1> > *this,
        unsigned __int8 *other,
        unsigned int count)
{
  unsigned int Size; // edi
  unsigned __int8 *v6; // eax
  unsigned int v7; // esi

  if ( count )
  {
    Size = this->Size;
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1>>::ResizeNoConstruct(
      this,
      this,
      Size + count);
    v6 = &this->Data[Size];
    v7 = count;
    do
    {
      if ( v6 )
        *v6 = *other;
      ++other;
      ++v6;
      --v7;
    }
    while ( v7 );
  }
}
