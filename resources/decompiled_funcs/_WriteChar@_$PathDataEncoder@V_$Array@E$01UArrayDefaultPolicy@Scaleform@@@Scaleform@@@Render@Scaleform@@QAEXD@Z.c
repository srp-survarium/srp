void __thiscall Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteChar(
        Scaleform::Render::PathDataEncoder<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        char v)
{
  Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *Data; // edi
  unsigned int v3; // esi
  char *v4; // edx

  Data = (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v3 = this->Data->Data.Size + 1;
  if ( v3 >= this->Data->Data.Size )
  {
    if ( v3 >= Data->Policy.Capacity )
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Data,
        Data,
        v3 + (v3 >> 2));
  }
  else if ( v3 < Data->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      Data,
      Data,
      this->Data->Data.Size + 1);
  }
  v4 = Data->Data;
  Data->Size = v3;
  if ( &v4[v3] != (char *)1 )
    v4[v3 - 1] = v;
}
