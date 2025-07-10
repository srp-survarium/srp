void __thiscall Scaleform::ArrayData<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::PushBack(
        Scaleform::ArrayData<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1> > *this,
        Scaleform::Render::Matrix4x4<float> *val)
{
  unsigned int v3; // esi
  Scaleform::Render::Matrix4x4<float> *Data; // edx
  unsigned int v5; // esi

  v3 = this->Size + 1;
  if ( v3 >= this->Size )
  {
    if ( v3 >= this->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
        this,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::Matrix4x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix4x4<float>,2>,Scaleform::ArrayConstPolicy<0,8,1>>::Reserve(
      this,
      this,
      this->Size + 1);
  }
  Data = this->Data;
  this->Size = v3;
  v5 = v3 << 6;
  if ( (Scaleform::Render::Matrix4x4<float> *)((char *)Data + v5) != (Scaleform::Render::Matrix4x4<float> *)64 )
    memcpy((unsigned __int8 *)&Data[-1] + v5, (unsigned __int8 *)val, sizeof(Scaleform::Render::Matrix4x4<float>));
}
