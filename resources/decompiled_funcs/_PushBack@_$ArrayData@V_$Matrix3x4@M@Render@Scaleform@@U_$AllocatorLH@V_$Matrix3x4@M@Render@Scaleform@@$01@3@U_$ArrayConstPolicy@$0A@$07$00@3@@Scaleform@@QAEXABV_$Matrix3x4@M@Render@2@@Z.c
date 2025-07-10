void __thiscall Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::PushBack(
        Scaleform::ArrayData<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        Scaleform::Render::Matrix3x4<float> *val)
{
  unsigned int v3; // esi
  Scaleform::Render::Matrix3x4<float> *Data; // eax
  unsigned __int8 *v5; // eax

  v3 = this->Size + 1;
  if ( v3 >= this->Size )
  {
    if ( v3 >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        this,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Matrix3x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix3x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
      this,
      this,
      this->Size + 1);
  }
  Data = this->Data;
  this->Size = v3;
  v5 = (unsigned __int8 *)&Data[v3 - 1];
  if ( v5 )
    memcpy(v5, (unsigned __int8 *)val, 0x30u);
}
