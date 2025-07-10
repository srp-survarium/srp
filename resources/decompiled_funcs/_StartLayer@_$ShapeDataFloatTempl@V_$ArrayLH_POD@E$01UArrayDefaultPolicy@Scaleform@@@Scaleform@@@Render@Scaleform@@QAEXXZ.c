void __thiscall Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartLayer(
        Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *Data; // edi
  unsigned int v3; // esi
  bool *v4; // edx

  Data = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->Data;
  v3 = Data->Size + 1;
  if ( v3 >= Data->Size )
  {
    if ( v3 >= Data->Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Data,
        Data,
        v3 + (v3 >> 2));
  }
  else if ( v3 < Data->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      Data,
      Data,
      Data->Size + 1);
  }
  v4 = Data->Data;
  Data->Size = v3;
  v4[v3 - 1] = 0;
  this->Status = Status_StartLayer;
}
