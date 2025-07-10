void __thiscall Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode>>::Value2StrCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<Scaleform::Ptr<Scaleform::GFx::ASStringNode> >::Value2StrCollector *this,
        unsigned int ind,
        const Scaleform::Ptr<Scaleform::GFx::ASStringNode> *v)
{
  Scaleform::GFx::ASStringNode *pObject; // esi
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *Pairs; // edi
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *v5; // eax
  bool v6; // zf

  pObject = v->pObject;
  ++pObject->RefCount;
  ++pObject->RefCount;
  Pairs = this->Pairs;
  Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &Pairs->Data,
    Pairs->Data.pHeap,
    Pairs->Data.Size + 1);
  v5 = &Pairs->Data.Data[Pairs->Data.Size - 1];
  if ( &Pairs->Data.Data[Pairs->Data.Size] != (Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *)8 )
  {
    v5->First.pNode = pObject;
    ++pObject->RefCount;
    v5->Second = ind;
  }
  v6 = pObject->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
  v6 = pObject->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pObject);
}
