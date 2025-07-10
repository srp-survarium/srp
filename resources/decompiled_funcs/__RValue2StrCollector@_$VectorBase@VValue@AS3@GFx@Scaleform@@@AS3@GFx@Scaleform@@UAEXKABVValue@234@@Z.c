void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Value2StrCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Value2StrCollector *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value *v)
{
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::AS3::Value *v5; // ecx
  bool v6; // zf
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *Pairs; // esi
  unsigned int *p_RefCount; // edi
  Scaleform::GFx::ASStringNode *v10; // ebx
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *v11; // eax
  Scaleform::GFx::ASString str; // [esp+4h] [ebp-4h] BYREF

  pStringManager = this->Vm->StringManagerRef->pStringManager;
  v5 = v;
  str.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  v6 = !Scaleform::GFx::AS3::Value::Convert2String(v5, (Scaleform::GFx::AS3::CheckResult *)&v, &str)->Result;
  pNode = str.pNode;
  if ( !v6 )
  {
    ++str.pNode->RefCount;
    Pairs = this->Pairs;
    p_RefCount = &pNode->RefCount;
    v10 = pNode;
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &Pairs->Data,
      Pairs->Data.pHeap,
      Pairs->Data.Size + 1);
    v11 = &Pairs->Data.Data[Pairs->Data.Size - 1];
    if ( &Pairs->Data.Data[Pairs->Data.Size] != (Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *)8 )
    {
      v11->First.pNode = v10;
      ++*p_RefCount;
      v11->Second = ind;
    }
    v6 = (*p_RefCount)-- == 1;
    if ( v6 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    pNode = str.pNode;
  }
  if ( !--pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
