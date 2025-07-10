void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index,
        unsigned int *val)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v5; // esi
  unsigned int *v6; // eax

  pHeap = this->Data.pHeap;
  v5 = this->Data.Size + 1;
  if ( v5 >= this->Data.Size )
  {
    if ( v5 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        v5 + (v5 >> 2));
  }
  else if ( v5 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this,
      pHeap,
      v5);
  }
  this->Data.Size = v5;
  if ( index < v5 - 1 )
    memmove(
      (unsigned __int8 *)&this->Data.Data[index + 1],
      (unsigned __int8 *)&this->Data.Data[index],
      4 * (v5 - index) - 4);
  v6 = &this->Data.Data[index];
  if ( v6 )
    *v6 = *val;
}
