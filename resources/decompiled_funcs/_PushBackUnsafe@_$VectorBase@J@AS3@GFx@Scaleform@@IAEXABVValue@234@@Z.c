void __thiscall Scaleform::GFx::AS3::VectorBase<long>::PushBackUnsafe(
        Scaleform::GFx::AS3::VectorBase<unsigned long> *this,
        const Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value::V1U v2; // ebx
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v5; // esi
  Scaleform::GFx::AS3::Value::V1U *v6; // eax

  v2 = v->value.VS._1;
  pHeap = this->ValueA.Data.pHeap;
  p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode> const *,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
  v5 = this->ValueA.Data.Size + 1;
  if ( v5 >= this->ValueA.Data.Size )
  {
    if ( v5 >= this->ValueA.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_ValueA,
        pHeap,
        v5 + (v5 >> 2));
  }
  else if ( v5 < this->ValueA.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XML>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_ValueA,
      pHeap,
      v5);
  }
  v6 = (Scaleform::GFx::AS3::Value::V1U *)&p_ValueA->Data[v5 - 1];
  p_ValueA->Size = v5;
  if ( v6 )
    *v6 = v2;
}
