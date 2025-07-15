void __thiscall Scaleform::GFx::AS3::VectorBase<long>::Value2StrCollector::operator()(
        Scaleform::GFx::AS3::VectorBase<long>::Value2StrCollector *this,
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
  v16.Flags = 2;
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
