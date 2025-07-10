void __thiscall Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::InsertMultipleAt(
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy> > *this,
        unsigned int index,
        unsigned int num,
        unsigned int *val)
{
  unsigned int v4; // ebp
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v7; // esi
  unsigned int v8; // ecx
  unsigned int *v9; // eax

  v4 = num;
  pHeap = this->Data.pHeap;
  v7 = num + this->Data.Size;
  if ( v7 >= this->Data.Size )
  {
    if ( v7 >= this->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this,
        pHeap,
        v7 + (v7 >> 2));
  }
  else if ( v7 < this->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)this,
      pHeap,
      v7);
  }
  this->Data.Size = v7;
  if ( index < v7 - num )
    memmove(
      (unsigned __int8 *)&this->Data.Data[index + num],
      (unsigned __int8 *)&this->Data.Data[index],
      4 * (v7 - index - num));
  if ( num )
  {
    v8 = index;
    do
    {
      v9 = &this->Data.Data[v8];
      if ( v9 )
        *v9 = *val;
      ++v8;
      --v4;
    }
    while ( v4 );
  }
}
