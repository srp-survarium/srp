void __thiscall Scaleform::GFx::AMP::AmpStream::Read(Scaleform::GFx::AMP::AmpStream *this, Scaleform::File *str)
{
  Scaleform::File *v2; // ebx
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int v5; // esi
  unsigned int Size; // eax
  unsigned int v7; // ebp
  Scaleform::ArrayLH<unsigned char,2,Scaleform::ArrayConstPolicy<0,4,1> > *p_Data; // edi
  int (__thiscall *v9)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int v10; // [esp+10h] [ebp-8h] BYREF
  Scaleform::GFx::AMP::AmpStream *v11; // [esp+14h] [ebp-4h]

  v2 = str;
  Read = str->Read;
  v5 = 0;
  v11 = this;
  v10 = 0;
  Read(str, (unsigned __int8 *)&v10, 4);
  Size = this->Data.Data.Size;
  v7 = v10;
  p_Data = &this->Data;
  if ( v10 >= Size )
  {
    if ( v10 >= p_Data->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,2>,Scaleform::ArrayConstPolicy<0,4,1>>::Reserve(
        &p_Data->Data,
        p_Data,
        v10 + (v10 >> 2));
  }
  else if ( v10 < p_Data->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,2>,Scaleform::ArrayConstPolicy<0,4,1>>::Reserve(
      &p_Data->Data,
      p_Data,
      v10);
  }
  p_Data->Data.Size = v7;
  if ( v7 )
  {
    do
    {
      v9 = v2->Read;
      LOBYTE(str) = 0;
      v9(v2, (unsigned __int8 *)&str, 1);
      p_Data->Data.Data[v5++] = (unsigned __int8)str;
    }
    while ( v5 < v7 );
  }
  v11->SeekToBegin(v11);
}
