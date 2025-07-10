void __thiscall Scaleform::ArrayBase<Scaleform::ArrayData<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayData<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> > *this,
        const int *val)
{
  unsigned int v3; // esi
  int *Data; // edx

  v3 = this->Data.Size + 1;
  if ( v3 >= this->Data.Size )
  {
    if ( v3 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)this,
        this,
        v3 + (v3 >> 2));
  }
  else if ( v3 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)this,
      this,
      this->Data.Size + 1);
  }
  Data = this->Data.Data;
  this->Data.Size = v3;
  if ( &Data[v3] != (int *)4 )
    Data[v3 - 1] = *val;
}
