void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<long,Scaleform::AllocatorDH<long,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int *val)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v4; // esi
  unsigned int *Data; // eax
  unsigned int *v6; // eax

  pHeap = this->Data.pHeap;
  v4 = this->Data.Size + 1;
  if ( v4 >= this->Data.Size )
  {
    if ( v4 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        v4 + (v4 >> 2));
  }
  else if ( v4 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this,
      pHeap,
      v4);
  }
  Data = this->Data.Data;
  this->Data.Size = v4;
  v6 = &Data[v4 - 1];
  if ( v6 )
    *v6 = *val;
}
