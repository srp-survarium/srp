void __thiscall Scaleform::GFx::AS3::VectorBase<unsigned long>::Value2StrCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<unsigned long>::Value2StrCollector *this,
        unsigned int ind,
        Scaleform::GFx::AS3::Value::V1U *v)
{
  Scaleform::GFx::AS3::Value::V1U *v3; // edx
  Scaleform::GFx::ASStringManager *pStringManager; // eax
  Scaleform::GFx::AS3::Value::V1U v6; // eax
  bool v7; // bl
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::ArrayDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2,Scaleform::ArrayDefaultPolicy> *Pairs; // esi
  unsigned int *p_RefCount; // edi
  Scaleform::GFx::ASStringNode *v11; // ebx
  unsigned int Size; // ecx
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *v13; // eax
  Scaleform::GFx::ASString str; // [esp+8h] [ebp-14h] BYREF
  Scaleform::GFx::AS3::Value v16; // [esp+Ch] [ebp-10h] BYREF

  v3 = v;
  pStringManager = this->Vm->StringManagerRef->pStringManager;
  str.pNode = &pStringManager->EmptyStringNode;
  ++pStringManager->EmptyStringNode.RefCount;
  v6 = *v3;
  v16.Flags = 3;
  v16.Bonus.pWeakProxy = 0;
  v16.value.VS._1 = v6;
  v7 = !Scaleform::GFx::AS3::Value::Convert2String(&v16, (Scaleform::GFx::AS3::CheckResult *)&v, &str)->Result;
  if ( (v16.Flags & 0x1F) > 9 )
  {
    if ( (v16.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v16);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v16);
  }
  pNode = str.pNode;
  if ( !v7 )
  {
    ++str.pNode->RefCount;
    Pairs = this->Pairs;
    p_RefCount = &pNode->RefCount;
    v11 = pNode;
    Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &Pairs->Data,
      Pairs->Data.pHeap,
      Pairs->Data.Size + 1);
    Size = Pairs->Data.Size;
    v13 = &Pairs->Data.Data[Size - 1];
    if ( &Pairs->Data.Data[Size] != (Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *)8 )
    {
      v13->First.pNode = v11;
      ++*p_RefCount;
      v13->Second = ind;
    }
    if ( (*p_RefCount)-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    pNode = str.pNode;
  }
  if ( !--pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
