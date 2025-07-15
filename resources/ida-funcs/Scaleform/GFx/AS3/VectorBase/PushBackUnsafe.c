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


void __thiscall Scaleform::GFx::AS3::VectorBase<double>::PushBackUnsafe(
        Scaleform::GFx::AS3::VectorBase<double> *this,
        const Scaleform::GFx::AS3::Value *v)
{
  const Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *p_ValueA; // edi
  unsigned int v4; // esi
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *Data; // eax
  double *v6; // eax
  double VNumber; // [esp+4h] [ebp-8h]

  pHeap = this->ValueA.Data.pHeap;
  VNumber = v->value.VNumber;
  p_ValueA = (Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *)&this->ValueA;
  v4 = this->ValueA.Data.Size + 1;
  if ( v4 >= this->ValueA.Data.Size )
  {
    if ( v4 >= this->ValueA.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_ValueA,
        pHeap,
        v4 + (v4 >> 2));
  }
  else if ( v4 < this->ValueA.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_ValueA,
      pHeap,
      v4);
  }
  Data = p_ValueA->Data;
  p_ValueA->Size = v4;
  v6 = (double *)&Data[v4 - 1];
  if ( v6 )
    *v6 = VNumber;
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::PushBackUnsafe(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value> *this,
        Scaleform::GFx::AS3::Value *v)
{
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value val; // [esp+4h] [ebp-10h] BYREF

  Flags = v->Flags;
  val.Bonus.pWeakProxy = v->Bonus.pWeakProxy;
  val.value.VNumber = v->value.VNumber;
  val.Flags = Flags;
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::AddRefWeakRef(v);
    else
      Scaleform::GFx::AS3::Value::AddRefInternal(v);
  }
  Scaleform::ArrayDataDH<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
    &this->ValueA.Data,
    &val);
  if ( (val.Flags & 0x1F) > 9 )
  {
    if ( (val.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&val);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&val);
  }
}


void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::PushBackUnsafe(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> > *this,
        const Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::ASStringNode *VStr; // edi
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2,Scaleform::ArrayDefaultPolicy> *p_ValueA; // esi
  Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v4; // eax

  VStr = v->value.VS._1.VStr;
  if ( VStr )
    ++VStr->RefCount;
  p_ValueA = &this->ValueA;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::ASStringNode>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->ValueA.Data,
    this->ValueA.Data.pHeap,
    this->ValueA.Data.Size + 1);
  v4 = &p_ValueA->Data.Data[p_ValueA->Data.Size - 1];
  if ( &p_ValueA->Data.Data[p_ValueA->Data.Size] != (Scaleform::Ptr<Scaleform::GFx::ASStringNode> *)4 )
  {
    if ( VStr )
      ++VStr->RefCount;
    v4->pObject = VStr;
  }
  if ( VStr )
  {
    if ( VStr->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
  }
}
