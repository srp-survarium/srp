void __thiscall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this)
{
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *pContainer; // edi
  unsigned int v2; // esi
  bool *Data; // edx

  pContainer = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)this->pContainer;
  v2 = pContainer->Size + 1;
  if ( v2 >= pContainer->Size )
  {
    if ( v2 >= pContainer->Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        pContainer,
        pContainer,
        v2 + (v2 >> 2));
  }
  else if ( v2 < pContainer->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      pContainer,
      pContainer,
      pContainer->Size + 1);
  }
  Data = pContainer->Data;
  pContainer->Size = v2;
  Data[v2 - 1] = 0;
}
