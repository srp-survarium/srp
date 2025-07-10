void __thiscall Scaleform::GFx::AS3::Impl::Value2StrCollector::operator()(
        Scaleform::GFx::AS3::Impl::Value2StrCollector *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::AS3::Value *v3; // ebp
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  bool v6; // zf
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::ArrayDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *Pairs; // esi
  unsigned int *p_RefCount; // edi
  Scaleform::GFx::ASStringNode *v10; // ebx
  Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long> *v11; // eax
  Scaleform::GFx::ASString str; // [esp+8h] [ebp-4h] BYREF

  v3 = v;
  pStringManager = this->Vm->StringManagerRef->pStringManager;
  str.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  v6 = !Scaleform::GFx::AS3::Value::Convert2String(v3, (Scaleform::GFx::AS3::CheckResult *)&v, &str)->Result;
  pNode = str.pNode;
  if ( !v6 )
  {
    ++str.pNode->RefCount;
    Pairs = this->Pairs;
    p_RefCount = &pNode->RefCount;
    v10 = pNode;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &Pairs->Data,
      Pairs->Data.pHeap,
      Pairs->Data.Size + 1);
    v11 = &Pairs->Data.Data[Pairs->Data.Size - 1];
    if ( &Pairs->Data.Data[Pairs->Data.Size] != (Scaleform::GFx::AS3::Impl::Triple<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value const *,unsigned long> *)12 )
    {
      v11->First.pNode = v10;
      ++*p_RefCount;
      v11->Second = v3;
      v11->Third = ind;
    }
    v6 = (*p_RefCount)-- == 1;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    pNode = str.pNode;
  }
  if ( !--pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
