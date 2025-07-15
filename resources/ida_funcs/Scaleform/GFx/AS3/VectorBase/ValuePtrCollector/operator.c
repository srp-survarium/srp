void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::ValuePtrCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >::ValuePtrCollector *this,
        unsigned int __formal,
        const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v)
{
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2,Scaleform::ArrayDefaultPolicy> *Ptrs; // edi
  const Scaleform::MemoryHeap *pHeap; // eax
  unsigned int v5; // esi
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **Data; // eax
  const Scaleform::Ptr<Scaleform::GFx::ASStringNode> **v7; // eax

  Ptrs = this->Ptrs;
  pHeap = Ptrs->Data.pHeap;
  v5 = Ptrs->Data.Size + 1;
  if ( v5 >= Ptrs->Data.Size )
  {
    if ( v5 >= Ptrs->Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &Ptrs->Data,
        pHeap,
        v5 + (v5 >> 2));
  }
  else if ( v5 < Ptrs->Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &Ptrs->Data,
      pHeap,
      Ptrs->Data.Size + 1);
  }
  Data = Ptrs->Data.Data;
  Ptrs->Data.Size = v5;
  v7 = &Data[v5 - 1];
  if ( v7 )
    *v7 = v;
}
