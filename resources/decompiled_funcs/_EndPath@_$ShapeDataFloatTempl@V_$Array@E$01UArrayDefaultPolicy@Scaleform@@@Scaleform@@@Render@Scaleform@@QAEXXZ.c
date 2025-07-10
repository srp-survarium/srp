void __thiscall Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *Data; // edi
  unsigned int v3; // esi
  char *v4; // eax

  Data = (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v3 = Data->Size + 1;
  if ( v3 >= Data->Size )
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
      Data->Size + 1);
  }
  v4 = &Data->Data[v3 - 1];
  Data->Size = v3;
  if ( v4 )
    *v4 = 6;
  this->Status = Status_EndPath;
}
