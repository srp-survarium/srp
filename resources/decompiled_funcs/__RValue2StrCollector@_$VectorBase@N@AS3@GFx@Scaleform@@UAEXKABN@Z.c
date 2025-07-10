void __thiscall Scaleform::GFx::AS3::VectorBase<double>::Value2StrCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<double>::Value2StrCollector *this,
        unsigned int ind,
        long double *v)
{
  long double *v3; // edx
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  bool v6; // bl
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *Pairs; // esi
  unsigned int *p_RefCount; // edi
  Scaleform::GFx::ASStringNode *v10; // ebx
  unsigned int Size; // edx
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *v12; // eax
  Scaleform::GFx::ASString str; // [esp+8h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value v15; // [esp+Ch] [ebp-10h] BYREF

  v3 = v;
  pStringManager = this->Vm->StringManagerRef->pStringManager;
  str.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  v15.value.VNumber = *v3;
  v15.Flags = 4;
  v15.Bonus.pWeakProxy = 0;
  v6 = !Scaleform::GFx::AS3::Value::Convert2String(&v15, (Scaleform::GFx::AS3::CheckResult *)&v, &str)->Result;
  if ( (v15.Flags & 0x1F) > 9 )
  {
    if ( (v15.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v15);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v15);
  }
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
    Size = Pairs->Data.Size;
    v12 = &Pairs->Data.Data[Size - 1];
    if ( &Pairs->Data.Data[Size] != (Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *)8 )
    {
      v12->First.pNode = v10;
      ++*p_RefCount;
      v12->Second = ind;
    }
    if ( (*p_RefCount)-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    pNode = str.pNode;
  }
  if ( !--pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
